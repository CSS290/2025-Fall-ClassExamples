// Date: 11/3/2025
// Author: K. Sung
// Purpose:
//    Show how to insert a new node into a sorted linked list with a dummy header node
//    and maintain the sorted order
// New function:
//     InsertIntoSorted - inserts a new node into the correct position in the sorted list
//                      to maintain sorted order
// TRY:
//      valgrind ./a.out
//    to check for memory leaks


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

int main() {
    // Header
    Node *header = new Node(0, nullptr); // Dummy header node

    // Try with 10 numbers
    const int NUM_TO_INSERT = 10;
    for (int i = 0; i < NUM_TO_INSERT; i++) {
        int value = rand() % 100; // Random value between 0 and 99
        Node *new_node = new Node(value, nullptr);
        InsertIntoSorted(header, new_node);
        TraverseAndPrint("After inserting " + to_string(value) + ":", header);
    }
    cout << "After inserting " << NUM_TO_INSERT << " random numbers:\n";
    TraverseAndPrint("List", header);
    
    // Now this is how we can destroy the list properly
    DestroyList(header);
    header = nullptr; // Avoid dangling pointer
    
    return 0;
}

// Try running valgrind
//
//      valgrind ./a.out