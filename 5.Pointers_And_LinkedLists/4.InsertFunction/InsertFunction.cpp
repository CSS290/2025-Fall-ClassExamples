// Date: 10/21/2025
// Author: K. Sung
// Purpose:
//      Show how to implement an insert function for a linked list
//      The funciton takes in a reference to a node and inserts a new node after it
//      While there are other ways to implement insertion (such as receiving pointer to pointer),
//      this example focuses on using a reference to a node for simplicity.
//      Note: This implementation does not handle inserting at the head of the list.
//            Additionally, memory cleanup is not fully addressed here.


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
// Precondition: head points to the first node in the list or is nullptr if the list is empty
// Postcondition: prints the data of each node in the list, does not change the list
void TraverseAndPrint(string msg, Node *head) {
    Node *current = head; // Start from the head node
    cout << msg << " Data: " << endl;
    while (current != nullptr) { // Traverse until the end of the list
        cout << current->data << " ";
        current = current->next; // Move to the next node
    }
    cout << endl << endl;
}

// Function to find a number in the linked list
// Parameters:
//   head - pointer to the head node of the list
//   target - the number to find
// Precondition: head points to the first node in the list or is nullptr if the list is empty
// Postcondition: returns the position of the target in the list, or -1 if not found
int FindNumberFromList(Node *head, int target) {
    Node *current = head; // Start from the head node
    int position = 0; // Position counter

    while (current != nullptr) { // Traverse until the end of the list
        if (current->data == target) {
            return position; // Target found, return its position
        }
        current = current->next; // Move to the next node
        position++; // Increment position counter
    }
    return -1; // Target not found
}

// Function to insert a new node after the given node
// Parameters:
//   current - pointer to the node after which to insert the new node
//   newData - data for the new node
// Precondition: current is defined
// Postcondition: a new node with newData is inserted after current and 
//                the pointer to the new node is returned
Node* InsertAfter(Node *current, int newData) {
    Node *newNode = new Node(newData, nullptr);
    newNode->next = current->next; // Link newNode to the next node
        // ** This step is crucial to avoid losing the rest of the list **
    current->next = newNode;       // Link current to newNode
    return newNode;               // Return the newly created node
}


int main() {
    // Create nodes
    Node *firstNode = new Node(10, nullptr);    // Allocate and initialize first node
    Node *secondNode = new Node(20, nullptr);

    // Connect the two nodes
    firstNode->next = secondNode; // Link first node to second node

    TraverseAndPrint("Before Insertion:", firstNode); // Traverse and print the list

    // Insert a new node with value 15 after the first node
    InsertAfter(firstNode, 15);
    TraverseAndPrint("After Insertion 15:", firstNode); // Traverse and print the list

    Node *at = InsertAfter(secondNode, 25);
    TraverseAndPrint("After Insertion 25:", firstNode); // Traverse and print the

    InsertAfter(at, 30);
    TraverseAndPrint("After Insertion 30:", firstNode); // Traverse and print the

    // Issues:
    //   1. How to insert to the beginning of the list? (Need to update head pointer)
    //   2. How to remove the memory allocated for nodes? (Need to implement a delete function)

    // Clean up memory, what about the nodes created by insertions?
    delete firstNode;
    delete secondNode;

    return 0;
}