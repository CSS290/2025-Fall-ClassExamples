// Date: 10/21/2025
// Author: K. Sung
// Purpose:
//    Show how to implement a linked list with a dummy header node
//    The dummy header node does not store meaningful data
//    This simplifies insertion [and deletion, not covered in this class] operations by avoiding special cases for head
//           Note that our previously defined functions: Print and Find need to be adjusted accordingly
//    dditionally, demonstrate how to properly destroy the list to avoid memory leaks


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

// Function to find a number in the linked list
// Parameters:
//   head - pointer to the dummy head node of the list
//   target - the number to find
// Precondition: head is reference to a dummy header node
// Postcondition: returns the position of the target in the list, or -1 if not found
int FindNumberFromList(const Node *head, int target) {
    Node *current = head->next; // Start from the first real node
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

// Function to destroy the linked list and free memory
// Parameters:
//   head - pointer to the head node of the list (dummy header, always there!)
// Precondition: head points to the first node in the list
// Postcondition: all nodes in the list are deleted and memory is freed
// NOTE:
//      we are receiving the pointer to the dummy header node
//      so that we can delete it as well
// Hint: do we know how to implement this as a recursive function?
void DestroyList(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
            // ** Important: Move current to next before deleting temp **
            //   Otherwise, we may lose the reference to the next node
        delete temp; // Free the memory of the current node
    }
}

int main() {
    // Header
    Node *header = new Node(0, nullptr); // Dummy header node
        // This nodes is always there such that we do not have to worry about inserting at head
        // I CANNOT do this:
        // Node header(0, nullptr); // This creates a local variable, which will be destroyed at the end of main
        //                          // resulting in inconsistency storage locations (Stack vs Heap) of the linked list nodes

    TraverseAndPrint("Before Insertion:", header); // Traverse and print the list

    // Insert a new node with value 5 after the first node
    InsertAfter(header, 5);
    InsertAfter(header, 15);
    TraverseAndPrint("After Insertion 5 and 15:", header); // Traverse and print the list

    Node *ptr = InsertAfter(header->next, 10); // Insert 10 after the node with 5
    TraverseAndPrint("After Insertion 10:", header); // Traverse and print the list
    
    InsertAfter(ptr, 12); // Insert 12 after the node with 10
    TraverseAndPrint("After Insertion 12:", header); // Traverse and print the
    
    // Now this is how we can destroy the list properly
    DestroyList(header);
    header = nullptr; // Avoid dangling pointer
    
    return 0;
}