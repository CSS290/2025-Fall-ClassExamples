// Created by ksung on 2025-10-12. 
// Delete repeated entires from MP4 array
//
// Receives a directory path, 
//   1. finds out how many entries are in the directory and all of the subdirectories
//   2. construct the flattened array of dir_elm_info
//   3. examine and remove all entries with duplicated (simple) names


#include <iostream>
#include <string>
#include "KFSLib/KFS.h"
using namespace std;

// Algorithm:
// The idea is to separate the array into two parts:
//     1) the beginning part contains only unique entries
//     2) the remaining part contains entries yet to be examined
// The two parts of the array is separated by last_unique, which indicates the position
//        where the next unique entry should be stored.
// Initially, last_unique is set to 1, since the 0th entry is always unique.
// We will examine each entry from index 1 to num_entries-1.
// For each entry at index_to_examine, we will compare it with all entries
// in the unique part (from index 0 to last_unique-1).
//
// Function: remove_duplicate
//   entries: pointer to an array of dir_elm_info
//   num_entries: reference to the number of entries in the array
// Precondition: entries points to an array of at least num_entries elements
// Postcondition: entries contains only unique entries in the first num_entries positions
// Purpose:
// deletes repeated entries from the array  
void remove_duplicate(dir_elm_info* entries, int &num_entries) {
    if (num_entries <= 1) 
        return; // No repeats possible

    int last_unique = 1; // 0th is unique, so initially, the last unique is 1

    // must search the entire array
    for (int index_to_examine = 1; index_to_examine < num_entries; ++index_to_examine) {
        int current_index = 0;
        bool dup_found = false;

        // look at all entries that are currently unique
        while ( (!dup_found) && (current_index < last_unique) ) {
            // compare with the index_to_examine
            dup_found = (entries[index_to_examine].name == entries[current_index].name);
            current_index++;
        }
        
        if (!dup_found) { 
            // index_to_examine: is also unique
            // last_unique: is the next position to store a unique entry
            entries[last_unique] = entries[index_to_examine];
            last_unique++;  // one more unique found
        } else {
            // duplicate found, print out the details of the duplicate
            cout << "** Removing duplicated name index=" << index_to_examine << ": " << entries[index_to_examine].path << endl;
        }
            
    }
    num_entries = last_unique; // Update the size to initially,  entries
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

    // Inform the user: 
    cout << "Flattening directory: " << fs::absolute(input_path) << endl;
    cout << "And, remove all duplicated names." << endl << endl;

    int num_entries = num_dir_entries(input_path);
    dir_elm_info* entries = new dir_elm_info[num_entries];
    int insert_index = 0;
    flatten_directory_entries(input_path, entries, insert_index);  
    cout << "Before removing dupliated number of entries (files + directories)=" << num_entries << endl;
    print_dir_entries(entries, num_entries);

    int original_num_entries = num_entries;
    remove_duplicate(entries, num_entries);

    cout << endl;
    cout << "After removing dupliated number of entries (files + directories)=" << num_entries << endl;
    print_dir_entries(entries, num_entries);
    cout << endl;
    cout << "Total removed: " << (original_num_entries - num_entries) << endl;
    cout << endl;

    delete[] entries; // Clean up dynamically allocated memory
    return 0;
}