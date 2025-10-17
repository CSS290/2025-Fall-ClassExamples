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

