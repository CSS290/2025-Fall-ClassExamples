// Date: 10/21/2025
// Author: K. Sung
// Purpose:
//      Demonstrate how to insert a node into a linked list


#include <iostream>
using namespace std;

// Define a Node structure for the linked list
struct Node {
    int data;
    Node* next; // Pointer to the next node

    Node(int val, Node* nxt) 
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
void TraverseAndPrint(string msg, Node* head) {
    Node* current = head; // Start from the head node
    cout << msg << " Data: " << endl;
    while (current != nullptr) { // Traverse until the end of the list
        cout << current->data << " ";
        current = current->next; // Move to the next node
    }
    cout << endl << endl;
}

int main() {
    // Create nodes
    Node* firstNode = new Node(10, nullptr);    // Allocate and initialize first node
    Node* secondNode = new Node(20, nullptr);

    // Connect the two nodes
    firstNode->next = secondNode; // Link first node to second node

    TraverseAndPrint("Before Insertion:", firstNode); // Traverse and print the list

    // Create a new node
    Node* newNode = new Node(15, nullptr); // New node to insert
    // Insert newNode between firstNode and secondNode
    newNode->next = firstNode->next; // newNode points to secondNode
    firstNode->next = newNode;       // firstNode points to newNode 

    TraverseAndPrint("After Insertion:", firstNode); // Traverse and print the list

    // Clean up memory
    delete firstNode;
    delete secondNode;
    delete newNode;

    return 0;
}