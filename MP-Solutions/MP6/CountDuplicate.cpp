// Created by ksung on 2025-10-27. 
// Based on MP4, the flattened dir_info array, remove the duplicate names in the same array
// and keep track of the duplicate names and their counts in a separate dup array, make sure
// the dup array is kept sorted by name.
//
// Note: keeping an array sorted requires shifting elements when inserting a new element, this 
//       may not be the most efficient way, but for learning purposes, this is acceptable.   
//

#include <iostream>
#include <string>
#include "KFSLib/KFS.h"
using namespace std;

// Constants for formatting output
const int NAME_WIDTH = 20; // Width for name display
const int INDEX_WIDTH = 4; // Width for index display

// Structure to hold duplicate information
struct dup_info {
    string name;  // duplicate name
    int count;    // count of duplicates (1: means, duplicated once in the flattened array)
};


// Function: insert_name_at
// Purpose: Insert a new duplicate name into the dup_array at the specified index
// Parameters:
//   - new_name: The name to insert
//   - index: The index at which to insert the new name
//   - dup_array: The array of duplicate information
//  - num_dups: The current number of duplicates in the array (will be updated)
// Will ensure the array remains sorted after insertion.
// Precondition: index is a valid position to insert (0 <= index) and 
//               that there is enough space in dup_array. (index <= num_dups)
void insert_name_at(string new_name, int index, dup_info *dup_array, int &num_dups) {
    if (index < num_dups) {
        // need to shift all entries from current by 1 
        // must start from the end (where the free entry is)
        for (int i = num_dups; i > index; i--) {
            dup_array[i] = dup_array[i-1];
        }
    }
    num_dups++;
    dup_array[index].name = new_name;
    dup_array[index].count = 1;
}

// Function: check_dup_array   
// Purpose: Check if a duplicate name exists in the dup_array.
//          If it exists, increment its count.  
//          If it does not exist, insert it in sorted order.
// Parameters: 
//   - dup_name: The name to check
//   - dup_array: The array of duplicate information
//   - num_dups: The current number of duplicates in the array (will be updated)
// Precondition: dup_array is sorted by name.
// Returns: The index of the duplicate name in dup_array.
int check_dup_array(string dup_name, dup_info *dup_array, int &num_dups) {
    bool foundInArray = false;
    bool foundInsertIndex = false;
    int index = 0;

    // Note: dup_array is kept sorted
    //       when looking for name in dup_array, we can stop looping as soon
    //       as there is a name that is larger than the current name 
    // We could have used binary search, but for simplicity, we will use linear search here.
    while ((!foundInArray) && (!foundInsertIndex) && (index < num_dups)) {
        foundInArray = (dup_name == dup_array[index].name);
        foundInsertIndex = (dup_name < dup_array[index].name);
        if ((!foundInArray) && (!foundInsertIndex))
            index++;  // keep looking
        // otherwise, we have found either the name, or the insert location: that is the index
    }

    if (foundInArray) {
        dup_array[index].count++;  // simply increment the count
    } else {
        // interestingly, there are two conditions here:
        //      1) foundInsertIndex is true: this is the index to insert at 
        //      2) foundInsertIndex is false: since we know foundInArray is also false,
        //               this says, we went through the entire array (index==num_dups) 
        //               and all existing names are smaller than dup_name, 
        //               so we should insert at the end. Since we know index == num_dups,
        //               we can simply use index as the insert location.
        // In both cases, index is the correct insert location.
        insert_name_at(dup_name, index, dup_array, num_dups);
    }
    return index;
}

// Function: remove_and_count_duplicate
// Purpose: Remove duplicate names from the entries array and count them in dup_array.
// Parameters:
//   - entries: The array of directory entries
//   - num_entries: The current number of entries in the array (will be updated as duplicates are removed)
//   - dup_array: The array to store duplicate information
//   - num_dups: The current number of duplicates in dup_array (will be updated as duplicates are inserted)
// Precondition: entries may contain duplicate names, 
//               dup_array has enough space to hold duplicates and num_dups is initialized to 0.
void remove_and_count_duplicate(dir_elm_info *entries, int &num_entries, dup_info *dup_array, int &num_dups) {

    if (num_entries <= 1) 
        return; // No dups possible

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
            // duplicate found: insert into duplicate array and print out the details of the duplicate
            // Note the complete identical to MP4 until this point, the only difference is that now we need to
            // keep track of the duplicate names and their counts in dup_array.
            int index = check_dup_array(entries[index_to_examine].name, dup_array, num_dups);
            cout << "** Removing from index=" << setw(INDEX_WIDTH) << right << index_to_examine 
                 << ": " << setw(NAME_WIDTH) << entries[index_to_examine].name 
                 << " Insert into index=" << index << endl;
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

    // Flatten the directory entries
    int num_entries = num_dir_entries(input_path);
    dir_elm_info* entries = new dir_elm_info[num_entries];
    int insert_index = 0;
    flatten_directory_entries(input_path, entries, insert_index);
    cout << "Before removing duplicated number of entries (files + directories)=" << num_entries << endl;
    print_dir_entries(entries, num_entries);

    // Allocate duplicate array: notice the size is at most half of num_entries
    dup_info *dup_array = new dup_info[num_entries/2];
    int dup_count = 0;

    int original_num_entries = num_entries;  // save original number of entries for reporting later
    remove_and_count_duplicate(entries, num_entries, dup_array, dup_count);


    // Show results of removing duplicates
    cout << endl;
    cout << "After removing dupliated number of entries (files + directories)=" << num_entries << endl;
    print_dir_entries(entries, num_entries);
    cout << endl;

    // Report duplicate summary
    cout << "Total removed: " << (original_num_entries - num_entries) << endl;
    cout << endl;
    cout << "Duplicate Array:" << endl;
    for (int i = 0; i < dup_count; i++) {
        cout << "  Index(" << setw(INDEX_WIDTH) << right << i << "): " 
             << setw(NAME_WIDTH) << dup_array[i].name << " Count = " << dup_array[i].count << endl;

    }

    delete[] entries; // Clean up dynamically allocated memory
    delete[] dup_array;

    return 0;
}