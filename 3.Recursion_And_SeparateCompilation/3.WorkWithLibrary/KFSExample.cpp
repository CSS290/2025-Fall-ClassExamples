// File: KFSExample.cpp
// Created by ksung on 2025-10-03. 
// Author: ksung
// Purpose: Example of using a library to work with file system
//     KFSLib: folder contains the KFSLib library (only one function)
//             KFS.h: header file for the library
//             KFS.o: is the library object file
//
#include "KFSLib/KFS.h"

// Function to print the content of a directory
// entries: pointer to an array of dir_elm_info structures
// num_entries: number of entries in the array
void print_dir_entries(const dir_elm_info *entries, int num_entries) {
    if (num_entries == 0) {
        cout << "is empty" << endl;
    } else {
        for (int i = 0; i < num_entries; i++) {
            cout << entries[i].name << (entries[i].is_directory ? "/ " : " ");
        }
        cout << endl;
    }
}

// Main function: receoives a directory path as a command line argument
// If no argument is provided, the current directory (".") is used
// Example usage:
//   ./KFSExample .
//   ./KFSExample /home/cssuwbstudent
//   ./KFSExample /tmp 
int main(int argc, char* argv[]) {
    string pathToCheck = ".";
    cout << "argc: " << argc << endl;
    if (argc > 1) {
        pathToCheck = argv[1];
    } 

    if (!is_directory(pathToCheck)) {
        cout << pathToCheck << " is not a directory" << endl;
        return 1;
    }
    cout << "Checking directory: " << fs::absolute(pathToCheck) << endl;
    int num_entries;
    dir_elm_info *entries = get_directory_entries(pathToCheck, num_entries);
    print_dir_entries(entries, num_entries);
    delete[] entries;   // delete the array allocated in the get_directory_entries function
        //  Will talk about this later: dynamic memory allocation
    return 0;
} 