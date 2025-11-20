// File: MoreList.cpp
// Created by ksung on 2025-11-10.
// Implementation of linked list to hold and manipulate integers for MP8
//
// Create list:
// Step 1:
//      .Init fixed, 
//      .Allocate an array to receive from fixed
//      .Print the array
// Step 2:
//      .Define a function to transfer from the array to a list in the same order 
//      .Print the list
// 
// Now remove:
// Step 3:
//      .Init varied
//      .Enter from varied to remove the number from the list if found, else, print not found
//      .If found, remove the node from the list, deallocate the node
//      .Print the list after each successful removal
// Step 4:
//      .At the end, deallocate the allocated array and the entire list

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

// From MP7 LinkedInt.cpp
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

// From MP7 LinkedInt.cpp
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

// From MP7 LinkedInt.cpp
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

// Function to print an array
// Input: msg - message to print before the array
//        arr - pointer to the integer array
//        size - size of the array
// Output: none
// Precondition: arr is a valid pointer to an array of given size
// Postcondition: the array is printed to standard output
void print_array(string msg, int *arr, int size) {
    cout << msg << ": ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to transfer an array to a linked list
// the integers will be in the list the same order as in the array
// Input: arr - pointer to the integer array
//        size - size of the array
// Output: pointer to the dummy header of the created linked list
// Precondition: arr is a valid pointer to an array of given size
// Postcondition: returns a pointer to the dummy header of the created linked list  
//                dynamic memory allocated for IntNode must be freed by caller
IntNode* array_to_list(int *arr, int size) {
    IntNode *head = init_dummy_header();
    IntNode *tail = head;
    for (int i = 0; i < size; i++) {
        IntNode *new_node = new IntNode(arr[i], nullptr);
        tail->next = new_node;
        tail = new_node;
    }
    return head;
}

// Function to find and remove a node with given value from the linked list
// Input: head - pointer to the dummy header of the list
//        value - integer value to find and remove
// Output: pointer to the removed node, or nullptr if not found
// Precondition: head is a valid pointer to the list
// Postcondition: if found, the node with the given value is removed from the list
//                and a pointer to the removed node is returned
//                if not found, nullptr is returned 
// Note: caller is responsible for deallocating the returned node if not nullptr
IntNode* find_and_remove(IntNode *head, int value) {
    IntNode *current = head; // dummy header
    IntNode *to_delete = nullptr;
    while ((current->next != nullptr) && (to_delete == nullptr)) {
        if (current->next->value == value) {
            to_delete = current->next;
            current->next = to_delete->next;
            to_delete->next = nullptr;
        } else {
            // only execute if needs to advance
            // if only one node left and it is the value to remove, 
            // trying to advance will access nullptr
            current = current->next;
        }
    }
    return to_delete; // nullptr if not found
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
    MP8_InputLib::set_random_seed(seed);

    // Step 1: fixed
    int fixed_count = MP8_InputLib::begin_fixed();
    cout << "Fixed count: " << fixed_count << endl;
    int *fixed_array = new int[fixed_count];
    for (int i = 0; i < fixed_count; i++) {
        fixed_array[i] = MP8_InputLib::get_next_fixed();
    }
    print_array(" Fixed array", fixed_array, fixed_count);

    // Step 2: array to list
    IntNode *int_list = array_to_list(fixed_array, fixed_count);
    print_list("List created", int_list);
    cout << endl;

    // Step 3: varied removals
    MP8_InputLib::begin_varied();
    int varied_value;
    while ((varied_value = MP8_InputLib::get_next_varied()) >= 0) {
        cout << "Attempting to remove: " << varied_value << endl;
        IntNode *removed_node = find_and_remove(int_list, varied_value);
        if (removed_node != nullptr) {
            cout << "  Found and removed: " << removed_node->value << endl;
            delete removed_node;
            removed_node = nullptr;
            print_list("  List after removal", int_list);
        } else {
            cout << "  Value " << varied_value << " not found in the list." << endl;
        }
        cout << endl;
    }
    print_list("Final list after all removals", int_list);
    cout << endl;
    // Step 4: cleanup
    delete[] fixed_array;
    destroy_list(int_list);
    return 0;
}