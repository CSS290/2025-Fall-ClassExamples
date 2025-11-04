// Date: 10/21/2025
// Author: K. Sung
// Purpose:
//   Show how to search and insert into a linked list of directory entries
//   To illustrate, in this case, for the node implementation,
//   we can also use reference for the data member instead of pointer
// New:
//   1. Use of reference for data member in Node struct instead of pointer (not recommended in general)
//   2. Function: FindNodeToInsert() to find the insertion point based on inversed order of names


#include "../KFSLib/KFS.h"
#include <iostream>
using namespace std;

const int NAMES_PER_LINE = 5; // number of names to print per line

// Define a Node structure for the linked list
struct Node {
    dir_elm_info &data; // Reference to one dir_elm_info
        // **** NOTE: using reference here instead of pointer ****
    Node *next; // Pointer to the next node

    Node(dir_elm_info &val, Node *nxt) 
        : data(val), next(nxt) {}
        // This is a constructor!! It initializes data and next
        // The ":" syntax is an initializer list
};

// Function to print the linked list of directory entries
// head: pointer to the dummy head node of the linked list
void PrintDirList(Node *head) {
    int count = 0;
    Node *current = head->next; // dummy header
    while (current != nullptr) {
        print_dir_entry(current->data);
        current = current->next;

        // maintain the 5-per-line format
        count++;
        if (count == NAMES_PER_LINE) {
            cout << endl;
            count = 0;
        }
    }
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
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
            // ** Important: Move current to next before deleting temp **
            //   Otherwise, we may lose the reference to the next node
        delete temp; // Free the memory of the current node
    }
}

// Function to find the node after which to insert a new entry
//          insertion point is based on inversed order of names
// Parameters:
//   name - name of the directory entry to insert
//   head - pointer to the dummy head node of the list
// Precondition: head points to the first node in the list
// Postcondition: returns pointer to the node after which to insert the new entry
Node *FindNodeToInsert(const string name, Node *head) {
    Node *current = head; // Start from the dummy header
    Node *next = current->next;
    // Traverse until we find the correct position to insert
    while ((next != nullptr) && (next->data.name > name)) {
        current = next;;
        next = next->next;
    }
    return current; // Return the node after which to insert
}  


int main(int argc, char* argv[]) {
    string input_path = "."; // Default to current directory
    cout << "Your command: ";
    for (int i =0; i<argc; i++) {
        cout << argv[i] << " ";
    } 
    cout << endl;

    if (argc > 1) {
        input_path = argv[1];
    }

    if (!is_directory(input_path)) {
        cerr << "**Error**: Input path is not a valid directory: " << input_path << endl;
        return 1;   // error
    }    
    
    int num_entries = 0;
    // Get directory entries
    dir_elm_info* entries = get_directory_entries(input_path, num_entries);
    if (entries == nullptr) {
        cerr << "Failed to get directory entries." << endl;
        return 1;
    }
    cout << "Number of entries in directory '" << input_path << "': " << num_entries << endl;
    cout << "Directory entries:" << endl;
    print_dir_entries(entries, num_entries);
    cout << endl;

    // Create linked list from directory entries
    // Remember working with dummy header simplifies linked list operations
    dir_elm_info dummy;  // for the dummy header
    Node *head = new Node(dummy, nullptr); // Dummy header node
    for (int i = 0; i < num_entries; ++i) {
        Node *ptr = FindNodeToInsert(entries[i].name, head);
        Node *newNode = new Node(entries[i], nullptr);
        newNode->next = ptr->next;
        ptr->next = newNode;
            // Insert in reversed order based on name    
    }

    // Print the linked list
    cout << "Linked list of directory entries (in reversed name order):" << endl;
    PrintDirList(head);
    cout << endl << endl;

    // Clean up linked list
    DestroyList(head);  
        // Note: only release memory of the links and not the dir_elm_info structs
    head = nullptr;

    // Clean up directory entries array
    delete[] entries;

    return 0;
}
