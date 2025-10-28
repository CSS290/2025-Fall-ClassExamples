// Date: 10/21/2025
// Author: K. Sung
// Purpose:
//   Show how to create a linked list of directory entries


#include "../KFSLib/KFS.h"
#include <iostream>
using namespace std;

const int NAMES_PER_LINE = 5; // number of names to print per line

// Define a Node structure for the linked list
struct Node {
    dir_elm_info *data; // Pointer to one dir_elm_info
    Node *next; // Pointer to the next node

    Node(dir_elm_info *val, Node *nxt) 
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
        print_dir_entry(*(current->data));
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
    Node *head = nullptr; // Start with an empty list
    for (int i = 0; i < num_entries; ++i) {
        head = new Node(&(entries[i]), head);
        // Insert at the front for simplicity
        // iteration from 0 will effectively reverse the order!
    }
    head = new Node(nullptr, head); // Dummy header node
        // NOTE: this link list points to the entries in the entries array
        //    so we don't need to allocate new dir_elm_info structs
        //    but if we delete the entries array, the linked list 
        //    will have dangling pointers

    // Print the linked list
    cout << "Linked list of directory entries (in reversed order):" << endl;
    PrintDirList(head);
    cout << endl << endl;

    // Clean up linked list
    DestroyList(head);  
        // Note: only release memory of the links and not the dir_elm_info structs
    head = nullptr;


    // Now, build the list again, this time following the array order
    head = nullptr; // Start with an empty list
    for (int i = num_entries - 1; i >= 0; --i) {
        head = new Node(&(entries[i]), head);
        // Since the index is from the back to the front,
        // inserting at the front will preserve the original order
    }
    head = new Node(nullptr, head); // Dummy header node   
    cout << "Linked list of directory entries (original order):" << endl;
    PrintDirList(head);
    cout << endl;   

    // Clean up linked list
    DestroyList(head);  
    head = nullptr; 

    // Clean up directory entries array
    delete[] entries;

    return 0;
}
