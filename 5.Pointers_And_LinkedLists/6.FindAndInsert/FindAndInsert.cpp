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

// Function to find a node with a specific value in the linked list
// Parameters:
//   head - pointer to the dummy head node of the list
//   target - the number to find
// Precondition: head is reference to a dummy header node  
Node* FindNodeWithValue(const Node *head, int target) {
    Node *current = head->next; // Start from the first real node

    while (current != nullptr) { // Traverse until the end of the list
        if (current->data == target) {
            return current; // Target found, return its node pointer
        }
        current = current->next; // Move to the next node
    }
    return nullptr; // Target not found
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

int main() {
    // Header
    Node *header = new Node(0, nullptr); // Dummy header node
        // This nodes is always there such that we do not have to worry about inserting at head
        // I CANNOT do this:
        // Node header(0, nullptr); // This creates a local variable, which will be destroyed at the end of main
        //                          // resulting in inconsistency storage locations (Stack vs Heap) of the linked list nodes
    // Insert a new node with value 5 after the first node
    InsertAfter(header, 5);
    InsertAfter(header, 15);
    Node *ptr = InsertAfter(header->next, 10); // Insert 10 after the node with 5
    InsertAfter(ptr, 12); // Insert 12 after the node with 10
    TraverseAndPrint("Before find and insert:", header); // Traverse and print the

    // Now, demonstrate finding a node with specific value
    int target = 10;
    Node *foundNode = FindNodeWithValue(header, target);
    if (foundNode != nullptr) {
        // This checks if the node was found
        cout << "Node with value " << target << " found at address: " << foundNode << endl;
        // Insert a new node with value 11 after the found node
        InsertAfter(foundNode, 11);
        TraverseAndPrint("After Insertion 11 after found node:", header); // Traverse and print the
    } else {
        cout << "Node with value " << target << " not found in the list." << endl;
    }
    
    // Now this is how we can destroy the list properly
    DestroyList(header);
    header = nullptr; // Avoid dangling pointer
    
    return 0;
}