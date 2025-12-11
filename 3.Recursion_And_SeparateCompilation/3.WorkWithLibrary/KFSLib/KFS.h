// File: KFS.h
// Created by ksung on 2025-10-03.
// Purpose: Header file for a library to work with file system
// 
// NOTE: the allocated array must be deleted by the caller
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