// File: KFS.cpp
// Created by ksung on 2025-10-03. 
// Simple function that behaves like "ls" command in Linux
//
// directory_iterator example from cppreference.com
//      https://en.cppreference.com/w/cpp/filesystem/directory_iterator.html
// directory_entry example from cppreference.com
//      https://en.cppreference.com/w/cpp/filesystem/directory_entry
// directory_entry::path example from cppreference.com
//      https://en.cppreference.com/w/cpp/filesystem/directory_entry/path
//
#include "KFS.h"

// Local constants
const int NAME_WIDTH = 25;
const int NAMES_PER_LINE = 5;


// These two functions are local to this file, not exported via the KFS.h header

// Function to count number of subdirectories in a directory
// Input: directory path (string)
// Output: number of subdirectories (int)
// Uses C++17 filesystem library
int num_subdir(const string &dir_path) {
    int count = 0;
    for (const auto& entry : fs::directory_iterator(dir_path)) {
        if (entry.is_directory()) {
            count++;
        }
    }
    return count;
}

// Function to count number of items (files + subdirectories) in a directory
// Input: directory path (string)
// Output: number of items (int)
// Uses C++17 filesystem library
int num_items(const string &dir_path) {
    int count = 0;
    for (const auto& entry : fs::directory_iterator(dir_path)) {
        count++;
    }
    return count;
}

// --- Begin exported functions ---

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


// Function to determine if the input string is a valid directory
// Input: directory path (string)
// Output: T/F if the input is a valid directory
// Uses C++17 filesystem library
bool is_directory(const string &dir_path) {
    if (!fs::exists(dir_path) || !fs::is_directory(dir_path)) {
        cerr << "Error: " << dir_path << " is not a valid directory." << endl;
        return false;
    }
    return true;
}

// Function to get directory entries
// Input: directory path (string)
// Output: array of dir_elm_info structs (dynamically allocated)
//         number of entries (by reference)
// Note: caller is responsible for deleting the returned array
// Uses C++17 filesystem library
//     #include <filesystem> included in KFS.h
dir_elm_info* get_directory_entries(const string &dir_path, int &num_entries) {
    is_directory(dir_path);

    num_entries = num_items(dir_path);
    if (num_entries == 0) {
        return nullptr;    // empty directory
    }
    
    dir_elm_info *entries = new dir_elm_info[num_entries];
    int i = 0;
    for (const auto& entry : fs::directory_iterator(dir_path)) {
        entries[i].path = entry.path().string();
        entries[i].name = entry.path().filename().string();
        entries[i].is_directory = entry.is_directory();
        i++;
    }
    return entries;
}

