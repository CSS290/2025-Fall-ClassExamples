// Date: 10/21/2025
// Author: K. Sung
// Purpose:
//      Illustrate the basics of linked list nodes using pointers
//      Each node contains data and a pointer to the next node
//
// From MP4, we experience the challenges of using arrays for unknown number of items
// We have to visit the entire directory structure twice, first to find out how many items there are,
// then to actually store them. This is inefficient.
// Linked lists address this by allowing dynamic memory allocation for each item as needed.


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

int main() {
    // Create nodes
    Node* firstNode = new Node(10, nullptr);    // Allocate and initialize first node
    Node* secondNode = new Node(20, nullptr);

    // Connect the two nodes
    firstNode->next = secondNode; // Link first node to second node

    // Print node data and addresses
    cout << " First Node Data: " << firstNode->data << ", Address: " << firstNode << endl;
    cout << "Second Node Data: " << secondNode->data << ", Address: " << secondNode << endl;
    cout << "First Node Next Points To Address: " << firstNode->next << endl;

    // Clean up memory
    delete firstNode;
    delete secondNode;

    return 0;
}