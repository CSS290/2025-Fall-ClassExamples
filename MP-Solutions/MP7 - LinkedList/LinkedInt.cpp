// File: LinkedIntegers.cpp
// Created by ksung on 2025-11-10.
// Implementation of linked list to hold integers for MP7
// Input integers from the MP7_InputLib:
//   from fixed number of integers, create a linked list in sorted order
//   from varied number of integers, create a second linked list in sorted order
// Merge the two sorted lists into one sorted list

#include <iostream>
#include "InputLib/InputLib.h"

using namespace std;

// Node structure for linked list
struct IntNode {
    int value;      // integer value
    IntNode *next;  // pointer to the next node
    // Constructors
    // Default constructor
    IntNode() : value(0), next(nullptr) {}
    // Parameterized constructor
    IntNode(int val, IntNode *nxt = nullptr) : value(val), next(nxt) {}
};

// Function to destroy the entire linked list and free memory
// Input: head - pointer to the head of the list
// Output: none
// Precondition: head is a valid pointer to the list
// Postcondition: all nodes in the list are deallocated
void destroy_list(IntNode *head) {
    IntNode *current = head;
    while (current != nullptr) {
        IntNode *temp = current;
        current = current->next;
        delete temp;
    }
}

// Function to initialize a dummy header node
// Input: none
// Output: pointer to the dummy header node
// Precondition: none
// Postcondition: returns a pointer to a new dummy header node
IntNode* init_dummy_header() {
    IntNode *head = new IntNode;
    head->value = -1; // dummy value: not a valid input
    head->next = nullptr;
    return head;
}

// Function to print the linked list
// Input: msg - message to print before the list
//        head - pointer to the dummy header of a list
// Output: none
// Precondition: head is a valid pointer to the list
// Postcondition: the list is printed to standard output
void print_list(string msg, IntNode *head) {
    cout << msg << ": ";
    IntNode *current = head->next; // skip dummy header
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to insert a new node into a sorted linked list
// Input: head - pointer to the dummy header of the sorted list
//        new_node - pointer to the new node to insert
// Output: none
// Precondition: head is a valid pointer to a dummy header of a sorted list
//               new_node is a valid pointer to a node
// Postcondition: new_node is inserted into the list maintaining sorted order
void insert_into_sorted(IntNode *head, IntNode *new_node) {
    IntNode *current = head;
    bool found = false;
    // Find the correct position to insert
    // NOTE: the convenience of having a dummy header
    //       no need to check for head being null
    while ((!found) && (current->next != nullptr)) {
        found = current->next->value > new_node->value;
        if (!found)
            current = current->next;
    }
    // Insert the new node
    new_node->next = current->next;
    current->next = new_node;
}   

// Function to merge two sorted linked lists into one sorted linked list
// Input: head1 - pointer to the dummy header of the first sorted list
//        head2 - pointer to the dummy header of the second sorted list
//        count - reference to an integer to count the number of comparisons made
// Output: pointer to the dummy header of the merged sorted list
// Precondition: head1 and head2 are valid pointers to dummy headers of sorted lists
// Postcondition: returns a pointer to the dummy header of the merged sorted list
// Note: head1 and head2 will be empty after the merge
//       returning a newly allocated dummy header for the merged list
IntNode *merge_sorted_lists(IntNode *head1, IntNode *head2, int& count) {
    IntNode *merged_head = init_dummy_header();
    IntNode *tail = merged_head;

    IntNode *curr1 = head1->next; // skip dummy header
    IntNode *curr2 = head2->next; // skip dummy header

    count = 0;
    // Both input lists are sorted
    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->value < curr2->value) {
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
        } else {
            tail->next = curr2;
            tail = curr2;
            curr2 = curr2->next;
        }
        count++;
    }
    // Append remaining nodes
    if (curr1 != nullptr) {
        tail->next = curr1;  // inherent the entire remaining list
    } else if (curr2 != nullptr) {
        tail->next = curr2;
    }

    head1->next = nullptr; // input list1 is now empty
    head2->next = nullptr; // input list2 is now empty

    return merged_head;
}


int main(int argc, char* argv[]) {

    unsigned int seed = 12345; // default seed
    if (argc > 1) {
        seed = atoi(argv[1]);
    } else {
        cout << "No seed provided, using default seed: " << seed << endl;
    }
    
    cout << "----- Test case with seed: " << seed << " -----" << endl;
    // seed the input system
    MP7_InputLib::set_random_seed(seed);

    // Fixed input integers
    IntNode *fixed_input_head = init_dummy_header();
    // First: loop over the fixed input integers
    int num_to_input = MP7_InputLib::begin_fixed();
    int data = -1;
    for (int i = 0; i < num_to_input; i++) {
        data = MP7_InputLib::get_next_fixed();
        // Insert the data into the sorted linked list
        IntNode *new_node = new IntNode(data, nullptr);
        insert_into_sorted(fixed_input_head, new_node);
    }
    cout << "Fixed input: " << num_to_input << " integers." << endl;
    print_list("    List", fixed_input_head);

    // Varied input integers
    IntNode *varied_input_head = init_dummy_header();
    // First: loop over the varied input integers
    MP7_InputLib::begin_varied();
    num_to_input = 0;
    data = -1;
    while ( (data = MP7_InputLib::get_next_varied()) >= 0 ) {
        IntNode *new_node = new IntNode(data, nullptr);
        // Insert the data into the linked list
        insert_into_sorted(varied_input_head, new_node);
        num_to_input++;
    }
    cout << "Varied input: " << num_to_input << " integers." << endl;
    print_list("    List", varied_input_head);

    // Merge the two lists
    int count = 0;
    IntNode *merged_head = merge_sorted_lists(fixed_input_head, varied_input_head, count);
    cout << "Merged list elements actually compared: " << count << endl;
    print_list("    List", merged_head);
    cout << endl;

    // Clean up
    delete fixed_input_head; // the rest of the list is maintained in merged list
    delete varied_input_head;

    destroy_list(merged_head); // entire list is now maintained by merged_head

    cout << "===============================" << endl << endl;

    return 0;
}