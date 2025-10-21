// Date: 10/21/2025
// Author: K. Sung
// Purpose:
//      Show how to traverse a linked list using pointers


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
// Postcondition: prints the data and address of each node in the list, does not change the list
void TraverseAndPrint(string msg, Node* head) {
    Node* current = head; // Start from the head node
    cout << msg << endl;
    while (current != nullptr) { // Traverse until the end of the list
        cout << "Node Data: " << current->data << ", Address: " << current << endl;
        current = current->next; // Move to the next node
    }
    cout << endl;
}

// Function to find a number in the linked list
// Parameters:
//   head - pointer to the head node of the list
//   target - the number to find
// Precondition: head points to the first node in the list or is nullptr if the list is empty
// Postcondition: returns the position of the target in the list, or -1 if not found
int FindNumberFromList(Node* head, int target) {
    Node* current = head; // Start from the head node
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

int main() {
    // Create nodes
    Node* firstNode = new Node(10, nullptr);    // Allocate and initialize first node
    Node* secondNode = new Node(20, nullptr);

    // Connect the two nodes
    firstNode->next = secondNode; // Link first node to second node

    // Traverse and print the list starting from firstNode
    TraverseAndPrint("From firstNode Ptr:", firstNode); // Traverse and print the list

    // Actually, we can use any pointer to traverse the list
    Node *ptr = firstNode; // head points to the first node
    TraverseAndPrint("From head Ptr:", ptr); // Traverse and print the list

    // Now, see that we can start traversing from any node
    ptr = secondNode; // head now points to the second node
    TraverseAndPrint("From head Ptr after change:", ptr); // Traverse and print the list

    //  Now, ptr is nullptr, so traversing should not print anything
    ptr = nullptr;
    TraverseAndPrint("From head Ptr after change to nullptr:", ptr); // Traverse and print the list

    cout << endl;
    cout << "Testing FindNumberFromList function:" << endl;
    // Test FindNumberFromList function
    int target = 20;
    int position = FindNumberFromList(firstNode, target);
    if (position != -1) {
        cout << "Number " << target << " found at position: " << position << endl;
    } else {
        cout << "Number " << target << " not found in the list." << endl;
    }   
    target = 30;
    position = FindNumberFromList(firstNode, target);
    if (position != -1) {
        cout << "Number " << target << " found at position: " << position << endl;
    } else {
        cout << "Number " << target << " not found in the list." << endl;
    }

    // Clean up memory
    delete firstNode;
    delete secondNode;

    return 0;
}