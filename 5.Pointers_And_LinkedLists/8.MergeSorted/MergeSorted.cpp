// Date: 10/21/2025
// Author: K. Sung
// Purpose:
//    Show how find an insertion node in a linked list with a dummy header node
//    Then insert a new node after the found node
//    New function:
//     FindNodeWithValue - finds and returns the pointer to the node with the specified value


#include <iostream>
using namespace std;

// Define a Node structure for the linked list
struct Node {
    int data;
    Node *next; // Pointer to the next node

    Node(int val, Node *nxt) 
        : data(val), next(nxt) {}
        // This is a constructor!! It initializes data and next
        // The ":" syntax is an initializer list
};


// Function to traverse and print the linked list
// Parameters:
//   msg - a message to print before the list
//   head - pointer to the head node of the list
// Precondition: head is reference to a dummy header node
// Postcondition: skips and head and prints the data of each node in the list, does not change the list
void TraverseAndPrint(string msg, const Node *head) {
    Node *current = head->next; // Skipping the head node
    cout << msg << " Data: " << endl;
    while (current != nullptr) { // Traverse until the end of the list
        cout << current->data << " ";
        current = current->next; // Move to the next node
    }
    cout << endl << endl;
}

// Function to destroy the linked list and free memory
// Parameters:
//   head - pointer to the head node of the list (dummy header, always there!)
// Precondition: head points to the first node in the list
// Postcondition: all nodes in the list are deleted and memory is freed
// NOTE:
//      we are receiving the pointer to the dummy header node
//      so that we can delete it as well
void DestroyList(Node *head) {
    Node *current = head;  // dummy header always there!
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
            // ** Important: Move current to next before deleting temp **
            //   Otherwise, we may lose the reference to the next node
        delete temp; // Free the memory of the current node
    }
}

// Function to insert a new node into the sorted linked list
// Parameters:
//   head - pointer to the dummy head node of the sorted list
//   new_node - pointer to the new node to insert
// Precondition: head is reference to a dummy header node  
// Postcondition: new_node is inserted into the correct position to maintain sorted order
void InsertIntoSorted(Node *head, Node *new_node) {
    Node *current = head;
    bool found = false;
    // Find the correct position to insert
    // NOTE: the convenience of having a dummy header
    //       no need to check for head being null
    while ((!found) && (current->next != nullptr)) {
        found = current->next->data > new_node->data;
        if (!found)
            current = current->next;
    }
    // Insert the new node
    new_node->next = current->next;
    current->next = new_node;
}

// Function to merge two sorted linked lists
// Parameters:
//   head1 - pointer to the dummy head node of the first sorted list
//   head2 - pointer to the dummy head node of the second sorted list
//   count - reference to an integer to store the number of comparisons made
// Precondition: head1 and head2 are reference to dummy header nodes  
// Postcondition: returns a pointer to the dummy head node of the merged sorted list
// Note: count is updated to reflect the number of comparisons made during the merge
//       because both of the lists are sorted, we may not need to compare every node
Node* MergeSortedLists(Node *head1, Node *head2, int& count) {
    Node *mergedHead = new Node(0, nullptr); // Dummy header for merged list
    Node *tail = mergedHead;

    Node *curr1 = head1->next; // skip dummy header
    Node *curr2 = head2->next; // skip dummy header

    count = 0;
    // Both input lists are sorted
    while (curr1 != nullptr && curr2 != nullptr) {
        count++;
        if (curr1->data < curr2->data) {
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
        } else {
            tail->next = curr2;
            tail = curr2;
            curr2 = curr2->next;
        }
    }
    // Append remaining nodes
    if (curr1 != nullptr) {
        tail->next = curr1;
    } else if (curr2 != nullptr) {
        tail->next = curr2;
    }

    // why do we need to perform this operation?
    head1->next = nullptr; // input list1 is now empty
    head2->next = nullptr; // input list2 is now empty

    return mergedHead;
}

// Function to build a linked list with n random integers
// Parameters:
//   n - number of integers to insert  
// Precondition: n >= 0
// Postcondition: returns pointer to the dummy head node of the built list
Node *BuildAList(int n) {
    Node *head = new Node(0, nullptr); // Dummy header node
    for (int i = 0; i < n; i++) {
        int value = rand() % 100; // Random value between 0 and 99
        Node *new_node = new Node(value, nullptr);
        InsertIntoSorted(head, new_node);
    }
    return head;
}

int main() {
    // Header
    Node *list1, *list2;
    const int MAX_SIZE = 20;

    list1 = BuildAList(rand() % MAX_SIZE); // Random size up to MAX_SIZE
    TraverseAndPrint("List 1:", list1);

    list2 = BuildAList(rand() % MAX_SIZE); // Random size up to MAX_SIZE
    TraverseAndPrint("List 2:", list2);

    int count = 0;
    Node *mergedList = MergeSortedLists(list1, list2, count);
    cout << "Number of comparisons made during merge: " << count << endl;
    TraverseAndPrint("Merged List:", mergedList);
    
    return 0;
}

// Try running valgrind
//
//      valgrind ./a.out