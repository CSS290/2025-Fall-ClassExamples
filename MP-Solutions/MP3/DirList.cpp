// Created by ksung on 2025-10-03. 
// Breadth-first-traversal of file system, print names
//
#include "KFSLib/KFS.h"

extern int num_subdir(const string &dir_path);
extern int num_items(const string &dir_path);

// function: print_dir_entries
// print the names of the entries in a directory
// if the directory is empty, print "is empty"
// parameters:
//   entries: pointer to an array of dir_elm_info structs
//   num_entries: number of entries in the array
// return: none
void print_dir_entries(const string path, string blanks, const dir_elm_info *entries, int num_entries) {
    cout << blanks << path << ": ";
    if (num_entries == 0) {
        cout << "is empty" << endl;
    } else {
        for (int i = 0; i < num_entries; i++) {
            cout << entries[i].name << (entries[i].is_directory ? "/ " : " ");
        }
        cout << endl;
    }
}

// function: depth_first_print 
// print the directory entries in depth-first order (based on recursion)
// parameters:
//   dir_path: path of the directory to print
//   depth: current depth in the directory tree (for indentation)
// return: none 
void depth_first_print(const string &dir_path, int depth) {
    int num_entries = 0;
    string blanks(depth * 2, ' ');
    // get all entries of currentdir_path
    dir_elm_info* entries = get_directory_entries(dir_path, num_entries);
    // print the entries, and then, recursively perform for each subdirectory
    print_dir_entries(dir_path, blanks, entries, num_entries);
    if (num_entries > 0) {
        for (int i = 0; i < num_entries; i++) {
            if (entries[i].is_directory) {
                depth_first_print(entries[i].path, depth + 1);
            } else {
                cout << blanks << "  " << entries[i].path << ": is a file" << endl;
            }
        }
    }
    delete[] entries;
}

// function: traverse_dir
dir_elm_info* traverse_dir(const string path_name, int &dir_size, string blanks) {
    dir_elm_info *entries = get_directory_entries(path_name, dir_size);
    print_dir_entries(path_name, blanks, entries, dir_size);
    return entries;
}

int total_sub_elms(dir_elm_info *entries, int num_entries) {
    int total = 0;
    for (int i = 0; i < num_entries; i++) {
        if (entries[i].is_directory) {
            total += num_items(entries[i].path);
        }
    }
    return total;
}

// function: breadth_first_print
// print the directory entries in breadth-first order (based on recursion)
// parameters:
//   start_path: path of the directory to print     
//   depth: current depth in the directory tree (for indentation of formatted output)
// return: none
void breadth_first_print(dir_elm_info *entries, int num_entries, int depth) {
        // Collect all subdirectory entries
    if (num_entries > 0) {
        string blanks(depth * 2, ' '); 

        int subdir_size = total_sub_elms(entries, num_entries);
        dir_elm_info *subdirs = new dir_elm_info[subdir_size];

#ifdef DEBUG
        cerr << blanks << "NumEntries:" << num_entries << " SubdirSize: " << subdir_size << endl;
#endif
        int total_copied = 0;
        for (int i = 0; i < num_entries; i++) {
            // each of the subdirectories
            if (entries[i].is_directory) {
                int info_size = 0;
                dir_elm_info *info = get_directory_entries(entries[i].path, info_size);
                print_dir_entries(entries[i].path, blanks, info, info_size);
#ifdef DEBUG
        cerr << blanks << "Info Size: " << info_size << endl;
#endif
                for (int i=0; i < info_size; i++) {
                    subdirs[total_copied++] = info[i];
                }
                delete[] info;
            } else {
                cout << blanks << entries[i].path << ": " << "is a file" << endl;
            }
        }
        delete[] entries;
        
#ifdef DEBUG
        cerr << blanks << "Total: " << total_copied 
             << " vs computedSieze=" << subdir_size << endl;
#endif

        breadth_first_print(subdirs, total_copied, depth + 1);
    }
}

// main function
// parameters:
//   argc: number of command line arguments
//   argv: array of command line arguments
// Prints the entered folder in depth-first and then in breadth-first orders
// return: always 0  
// usage: 
//      ./DirList [directory_path]
int main(int argc, char* argv[]) {
    string input_path = ".";
    cout << "argc: " << argc << endl;
    if (argc > 1) {
        input_path = argv[1];
    }

    if (!is_directory(input_path)) {
        return 1;   // error
    }

    cout << "Checking directory: " << fs::absolute(input_path) << endl;
    cout << "Depth First Print (like the \"ls -R\" command):" << endl;
    depth_first_print(input_path, 0);
    cout << "-----------" << endl << endl;
    cout << "Breadth First Print (an alternative way of printing):" << endl;
    // begin the process
    int num_entries = 1;
    dir_elm_info *entries = new dir_elm_info[1];
                            // Must allocate as an array, 
                            // as all deletion expects arrays!
        entries->path = input_path;
        entries->name = fs::path(input_path).filename().string();
        entries->is_directory = true;
    breadth_first_print(entries, num_entries, 0);
    cout << endl;
    return 0;
} 