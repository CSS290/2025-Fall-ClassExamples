// Created by ksung on 2025-10-12. 
// Flattens the contents of a directory and all of its subdirectories
// Receives a directory path, 
//   1. finds out how many entries are in the directory and all of the subdirectories
//   2. fills in the entries in a dynamically allocated array of dir_elm_info
//   3. returns the pointer to the array and the number of entries via reference parameter
#include "KFSLib/KFS.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NAME_WIDTH = 25;
const int NAMES_PER_LINE = 5;

const int DEBUG_CHECK_SIZE = 8;
const int DEBUG_CHECK_INDICES[DEBUG_CHECK_SIZE] = {1, 4, 6, 9, 12, 18, 23, 70};

// Function: print_dir_entry
//   entry: a dir_elm_info struct
// Precondition: none
// Postcondition: none
// Purpose:
// prints the name of the entry formatted such that the name is aligned left
void print_dir_entry(const dir_elm_info &entry) {
    string to_print(entry.name + (entry.is_directory ? "/ " : " "));
    cout << left << setw(NAME_WIDTH) << to_print;
}

// Function: print_dir_entries
//   entries: pointer to an array of dir_elm_info
//   num_entries: number of entries in the array
// Precondiiton: entries points to an array of at least num_entries elements
// Postcondition: none
// Purpose:
// prints the names of the entries in a directory
// formatted such that each name is aligned left and occupies NAME_WIDTH-space
// and prints no more than NAMES_PER_LINE
// for directories, prints "/" after the name
void print_dir_entries(const dir_elm_info *entries, int num_entries) {
    int count = 0;
    
    for (int i = 0; i < num_entries; i++) {
        print_dir_entry(entries[i]);
        count++;
        if (count % NAMES_PER_LINE == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

// Function: num_dir_entries
//   dir_path: path to a directory
// Precondition: dir_path is a valid directory path
// Postcondition: returns number of entries in the directory and all of its subdirectories
int num_dir_entries(const string &dir_path) {
    int count = 0;
    // Get a list of all files and directories in the current directory
    dir_elm_info* entries = nullptr;
    int num_entries = 0;
    // cerr << "Getting info for: [" << dir_path << "]" << endl;
    entries = get_directory_entries(dir_path, num_entries);

    // Count the number of entries
    for (int i = 0; i < num_entries; ++i) {
        count++;
        if (entries[i].is_directory) {
            // If the entry is a directory, count its contents recursively
            count += num_dir_entries(entries[i].path);
        }
    }
    delete[] entries; // Clean up dynamically allocated memory
    return count;
}

// Function: flatten_directory_entries
//   path: path to the directory to be flattened
//   flattened_dir_info: pointer to the array to fill with flattened directory info
//   insert_index: reference to the index at which to insert the next entry
// Precondition: flattened_dir_info points to an array large enough to hold all entries
// Postcondition: flattened_dir_info is filled with the entries in the directory and its subdirectories
// Purpose:
// fills in the entries with the entries in the directory and all of its subdirectories
void flatten_directory_entries(const string &path,
                    dir_elm_info *flattened_dir_info, int &insert_index)
{
    int num_entries = 0;
    dir_elm_info* entries = get_directory_entries(path, num_entries);

#ifdef DEBUG
    cerr << "Filling entries for: [" << path << "] with " << num_entries << " entries." << endl;
#endif
    // First:  info of files skipping all directories 
    for (int i = 0; i < num_entries; ++i) {
        if (!entries[i].is_directory) {
            flattened_dir_info[insert_index++] = entries[i];
        }
    }

    // Second: info of directories and recursively fill their contents
    for (int i = 0; i < num_entries; ++i) {
        if (entries[i].is_directory) {
            flattened_dir_info[insert_index++] = entries[i];
            flatten_directory_entries(entries[i].path, flattened_dir_info, insert_index);
        }
    }
    delete[] entries; // Clean up dynamically allocated memory
}

void debug_print_entry(const dir_elm_info *entry, int num_entries, int index) {
    if (index < num_entries) {
        cout << "Entry " << index << ": ";
        print_dir_entry(entry[index]);
        cout << endl;
    } else {
        cout << "**Warning**: index(" << index << ") out of bounds of: " << num_entries << endl;
    }
}

// main function
// parameters:
//   argc: number of command line arguments
//   argv: array of command line arguments: argv[1] is the directory path
// usage:  
//      ./FlattenContent [directory_path]
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

    int num_entries = num_dir_entries(input_path);
    cout << "Total number of entries (files + directories): " << num_entries << endl;

    dir_elm_info* entries = new dir_elm_info[num_entries];
    int insert_index = 0;
    flatten_directory_entries(input_path, entries, insert_index);  
    print_dir_entries(entries, num_entries);

    // for debugging and verifying purposes
    cout << "Final debug check of entries:" << endl;
    for (size_t i = 0; i < DEBUG_CHECK_SIZE; i++)
    {
        int index = DEBUG_CHECK_INDICES[i];
        debug_print_entry(entries, num_entries, index);
    }
    
    delete[] entries;

    // later: print new and delete
    return 0;
}