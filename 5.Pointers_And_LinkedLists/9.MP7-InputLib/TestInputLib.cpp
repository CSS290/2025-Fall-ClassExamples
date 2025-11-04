// Created by ksung on 2025-11-10.
// Purpose: Demonstrate how to work with an input library that is capable of providing
//          fixed and varied number of input integers.
//          You must work with this library for MP7 - Linked List of Integers
// 
// Note: try running with seed numbers between 0 and 5 to examine edge cases 
// 

#include <iostream>
#include <string>
#include "InputLib/InputLib.h"

using namespace std;


int main(int argc, char* argv[]) {

    unsigned int seed = 12345; // default seed
    if (argc > 1) {
        seed = atoi(argv[1]);
    } else {
        cout << "No seed provided, using default seed: " << seed << endl;
    }
    
    cout << "----- Test case with seed: " << seed << " -----" << endl;
    // seed the input system
    // This function must be called before using other functions
    // Note the namespace usage
    // Seed values can be any integer, the following are predefined edge cases:
    //    If seed = 0, both fixed and varied integers will be zero
    //    If seed = 1, fixed integers will be zero
    //    If seed = 2, varied integers will be zero
    //    If seed = 3, fixed integers will be zero, varied integers will be one
    //    If seed = 4, fixed integers will be one, varied integers will be
    //    If seed = 5, fixed integers will be one, varied integers will be one
    MP7_InputLib::set_random_seed(seed);

        
    // First: loop over the fixed input integers
    int num_to_input = MP7_InputLib::begin_fixed();
    cout << "Fixed input size " << num_to_input << ": ";
    for (int i = 0; i < num_to_input; i++) {
        int data = MP7_InputLib::get_next_fixed();
        cout << "(" << (i+1) << "):" << data << "  ";

        // For MP7, you will build your fixed list here
    }
    cout << endl;

    // Varied input integers
    cout << " Varied input size: ";
    MP7_InputLib::begin_varied();
    int data = -1;
    int count = 0;
    while ( (data = MP7_InputLib::get_next_varied()) >= 0 ) {
        count++;
        cout << "(" << count << "):" << data << "  ";

        // For MP7, you will build your varied list here
    }
    cout << endl;
    
    return 0;
}