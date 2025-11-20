// File: InputLib.h
// Created by ksung on 2025-11-10.
// Header file for InputLib.cpp
// Library to provide input integers for MP8
//
// Total defined functions: 5
//
// Initialize the input system:
//     set_random_seed():     // initialize the random seed
// 
// Functions for fixed number of integers:
//     begin_fixed():         // begin fixed number of integer generation
//     get_next_fixed():      // get the next integer from the fixed set
//
// Functions for varied number of integers:
//     begin_varied():        // begin varied number of integer generation
//     get_next_varied():     // get the next integer from the varied set
//
// **MUST** 
//      call the set_random_seed function before using other functions
//      call the begin() functions before calling get_next() functions
//
// Note: with the namespace, the actual function names must be properly qualified
//       e.g., MP8_InputLib::set_random_seed()

#ifndef INPUT_LIB_H
#define INPUT_LIB_H

namespace MP8_InputLib {
    // Function prototypes
    void set_random_seed(int seed);

    // Functions to begin fixed integer generation
    // To use: 
    //      First: call begin_fixed()
    //      Then: call get_next_fixed() repeatedly to get the integers 
    int begin_fixed();      // Begin fixed integer generation, returns number of integers in the fixed set
    int get_next_fixed();   // Get the next fixed integer

    // Functions for varied number of integers
    // To use:
    //      First: call begin_varied()
    //      Then: call get_next_varied() repeatedly to get the integers
    void begin_varied();    // Begin varied integer generation, number of integers in the set is unknown
    int get_next_varied();  // Get the next varied integer, returns -1 when no more integers are available
};

// To support testing of edge cases
const int TEST_SEED_NO_FIXED_NO_VARIED = 0;
const int TEST_SEED_NO_FIXED = 1;
const int TEST_SEED_NO_VARIED = 2;
const int TEST_SEED_NO_FIXED_ONE_VARIED = 3;
const int TEST_SEED_ONE_FIXED_NO_VARIED = 4;
const int TEST_SEED_ONE_FIXED_ONE_VARIED = 5;

#endif // INPUT_LIB_H  