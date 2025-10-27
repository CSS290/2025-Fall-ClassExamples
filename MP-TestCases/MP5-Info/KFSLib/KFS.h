// File: KFS.h
// Created by ksung on 2025-10-03.
// Purpose: Header file for a library to work with file system
// Functions exported:
//      is_directory
//      get_directory_entries
//          NOTE: the allocated array must be deleted by the caller
// New functions added for MP5:
//      print_dir_entry
//      print_dir_entries
//      num_dir_entries
//      flatten_directory_entries
//
#pragma once

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;  // shorthand for std::filesystem
using namespace std;

// Information about an element in the directory
struct dir_elm_info {     // this is the data type
    string path;            // full path name
    string name;            // file or directory name only
    bool is_directory;      // true if directory, false otherwise
};


// Function to check if a path is a valid directory
// dir_path: path to the directory to check (full or relative path)
// returns: true if dir_path is a valid directory, otherwise exits the program
bool is_directory(const string &dir_path);

// Function to get directory entries
// dir_path: path to the directory to check (full or relative path)
// num_entries: output parameter to return number of entries found
// returns: pointer to an array of dir_elm_info structures
//
// **NOTE**: the allocated array must be deleted by the caller
dir_elm_info* get_directory_entries(const string &dir_path, int &num_entries);

// new functions added for MP5
// Function: print_dir_entry
//   entry: a dir_elm_info struct
// Precondition: none
// Postcondition: none
// Purpose:
// prints the name of the entry formatted such that the name is aligned left
void print_dir_entry(const dir_elm_info &entry);

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
void print_dir_entries(const dir_elm_info *entries, int num_entries);

// Function: num_dir_entries
//   dir_path: path to a directory
// Precondition: dir_path is a valid directory path
// Postcondition: returns number of entries in the directory and all of its subdirectories
int num_dir_entries(const string &dir_path);

// Function: flatten_directory_entries
//   path: path to the directory to be flattened
//   flattened_dir_info: pointer to the array to fill with flattened directory info
//   insert_index: reference to the index at which to insert the next entry
// Precondition: flattened_dir_info points to an array large enough to hold all entries
// Postcondition: flattened_dir_info is filled with the entries in the directory and its subdirectories
// Purpose:
// fills in the entries with the entries in the directory and all of its subdirectories
void flatten_directory_entries(const string &path,
                    dir_elm_info *flattened_dir_info, int &insert_index);
