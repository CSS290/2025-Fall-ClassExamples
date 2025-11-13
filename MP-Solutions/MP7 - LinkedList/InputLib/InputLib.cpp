// File: InputLib.cpp
// Created by ksung on 2025-11-10.
// Library to provide input integers for MP7
// 
// Library has two states: 
//     1) Returns a fixed number of random integers:
//        two funtions: inform caller how many integers will be generated, and 
//                      returns one random integeres upon each request
//     2) returns unknown numbre of random integers
//        one function: returns a positive integer upon each request, if no more integers, returns a negative integer
// 

#include <iostream>
#include <string>
#include "InputLib.h"

using namespace std;

// Define the namespace, two purposes:
// First: to avoid name conflicts with other libraries
// Second: to encapsulate all the functions and variables related to InputLib
//         to clearly identify when you are calling MP7_InputLib functions
namespace MP7_InputLib {

    // Class: InputLib
    // Purpose: Encapsulates the state and behavior of the input library
    class InputLib {
        private:
            unsigned int edge_cases;        
                // when the seed is defined for one of the following edge cases, make a copy of it
                // to ensure the same behavior across multiple calls
                //
                // edge_cases values:
                //    0: means 0 both                   TEST_SEED_NO_FIXED_NO_VARIED
                //    1: means 0 fixed                  TEST_SEED_NO_FIXED
                //    2: means 0 varied                 TEST_SEED_NO_VARIED
                //    3: means 0 fixed, and 1 varied    TEST_SEED_NO_FIXED_ONE_VARIED
                //    4: means 1 fixed, and 0 varied    TEST_SEED_ONE_FIXED_NO_VARIED
                //    5: means 1 fixed, and 1 varied    TEST_SEED_ONE_FIXED_ONE_VARIED
            unsigned int random_seed;
                // This is the seed used for random number generation
                
            int fixed_to_generate; // if zero, means no more fixed number to generate
            int varied_to_generate; // if zero, means no more varied number to generate

            const int MIN_COUNTS = 4;  // minimum and maximum number of integers to generate
            const int MAX_COUNTS = 7;

            const int MIN_RANDOM_NUM = 1;    // The range of random integers to generate
            const int MAX_RANDOM_NUM = 100;

            // Function: begin
            // Purpose: Returns a random integer indicating how many integers to generate
            // Returns: A random integer in the range [MIN_COUNTS, MAX_COUNTS]
            int begin() {
                return (rand_r(&random_seed) % (MAX_COUNTS - MIN_COUNTS + 1)) + MIN_COUNTS;
            }
        
        public:
            
            // Constructor:
            InputLib() : edge_cases(0), fixed_to_generate(0), varied_to_generate(0) {}

            // Function: set_random_seed
            // Purpose: Sets the random seed for the library
            void set_random_seed(int seed) {
                random_seed = seed;
                edge_cases = seed;
            }

            // Function: begin_fixed
            // Purpose: Initializes the fixed number of integers to generate based on edge cases or randomly
            // Returns: The number of integers to generate
            int begin_fixed() { // sets fixed_to_generate to a fixed number, randomly between 10 and 20
                switch (edge_cases) {
                    case TEST_SEED_NO_FIXED_NO_VARIED:
                    case TEST_SEED_NO_FIXED:
                    case TEST_SEED_NO_FIXED_ONE_VARIED:
                        fixed_to_generate = 0;
                        break;
                    case TEST_SEED_ONE_FIXED_NO_VARIED:
                    case TEST_SEED_ONE_FIXED_ONE_VARIED :
                        fixed_to_generate = 1;
                        break;
                    default:
                        fixed_to_generate = begin();
                        break;
                }
                return fixed_to_generate;
            }

            // Function: get_next_int_fixed
            // Purpose: Returns the next random integer when the total number of integers to generate is fixed
            // Returns: A random integer in the range [1, 100]
            int get_next_fixed() {
                if (fixed_to_generate == 0) {
                    return -1; // No more integers to generate
                }
                fixed_to_generate--;
                return (rand_r(&random_seed) % MAX_RANDOM_NUM) + 1; // Random integer between 1 and 100
            }

            // Function: begin_varied
            // Purpose: Initializes the varied number of integers to generate based on edge cases or randomly
            // Returns: The number of integers to generate
            void begin_varied() { // sets varied_to_generate to a fixed number, randomly between 10 and 20
                switch (edge_cases) {
                    case TEST_SEED_NO_FIXED_NO_VARIED:
                    case TEST_SEED_NO_VARIED:
                    case TEST_SEED_ONE_FIXED_NO_VARIED:
                        varied_to_generate = 0;
                        break;
                    case TEST_SEED_NO_FIXED_ONE_VARIED:
                    case TEST_SEED_ONE_FIXED_ONE_VARIED:
                        varied_to_generate = 1;
                        break;
                    default:
                        varied_to_generate = begin();
                        break;
                }
            }

            // Function: get_next_int_varied
            // Purpose: Returns the next random integer when the total number of integers to generate is varied
            // Returns: A random integer in the range [1, 100], or -1 if no more integers to generate
            int get_next_varied() {
                if (varied_to_generate == 0) {
                    return -1; // No more integers to generate
                }
                varied_to_generate--;
                return (rand_r(&random_seed) % MAX_RANDOM_NUM) + 1; // Random integer between 1 and 100
            }
    };

    // Create a single instance of InputLib to manage state across function calls
    InputLib inputLibInstance = InputLib();

    // Public API functions that wrap around the InputLib instance

    // Function: set_random_seed
    // Purpose: Sets the random seed for the library
    void set_random_seed(int seed) {
        inputLibInstance.set_random_seed(seed);
    }

    // for fixed number of integers
    // Returns how many integers will be generated
    int begin_fixed() {
        return inputLibInstance.begin_fixed();
    }

    // Returns the next integer; if no more integers, prints error and exits
    int get_next_fixed() {
        int v = inputLibInstance.get_next_fixed();
        if (v < 0) {
            cout << "** ERROR **: No more fixed integers to generate!" << endl;
            exit(1);
        }
        return v;
    }

    // for varied number of integers
    // Initializes the varied number of integers to generate
    void begin_varied() {
        inputLibInstance.begin_varied();
    }

    // Returns the next integer; if no more integers, returns a negative integer
    int get_next_varied() {
        return inputLibInstance.get_next_varied();
    }

} // namespace MP7_InputLib