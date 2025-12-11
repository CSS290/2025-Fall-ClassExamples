// File: ReverseDigits.cpp
// Author: Kelvin Sung
// Date: 2025-10-05
// Description: Reverse the digits of a number
//      Input: a positive integer
//      Output: the reverse of the input integer
//      Example: Input: 12345
//               Output: 54321  
// Solution:
//      split the input into two parts: the rightmost digit and the rest of the number
//      build up the answer by attaching the rightmost digit to the right of answer
//      repeat until only one digit in input
// Two implementations:
//      1. iteratively
//      2. recursively

// Do we want to see the debug output?
// #define DEBUG   // Comment out the to turn off debug output

#include <iostream>
using namespace std;

// constant: 
//      for extracting the right most digit: (num % 10) 
//   and for attaching a digit to the right: (num * 10 + digit)
const int BASE = 10;

// Functions for detatching and attaching digits
//
// detatch_right: detatch the right most digit from num
//      input: num (by reference, so that it can be updated)
//      output: the right most digit
//      post-condition: num is updated to be the number without the right most digit
// Note: generation is used for formatted output in DEBUG mode
int detatch_right(int &num, int generation) {
    int right = num % BASE; // right most digit
    int left = num / BASE;  // the number without the right most digit
#ifdef DEBUG
    string indent(generation, '\t');
    cout << indent << "detatch_right: " << num << " into " << left << " and " << right << endl;
#endif
    num = left;
    return right;
}

// attach_right: attach a digit to the right of num
//      input: num, right (the digit to be attached)
//      output: the new number after attaching right to num
// Note: generation is used for formatted output in DEBUG mode
int attach_right(int num, int right, int generation) {
    int result = num * BASE + right;
#ifdef DEBUG
    string indent(generation, '\t');
    cout << indent << "attach_to_right: " << num << " and " 
            << right << " into " << result << endl; 
#endif
    return result;
}


// ---------- Recursive version of the solution ----------------
//
// recurse_attach_right: recursively detatch from right and attach to right
//      input: num (input number, by reference, so that it can be updated), answer (by
//             reference, so that it can be updated), generation (for debug output)
//      output: none (answer is updated by reference)
//      post-condition: recursion stops when num is less than BASE, 
//                      otherwise, continues detatching and attaching
// Note: generation is used for formatted output in DEBUG mode
void recurse_attach_right(int &num, int &answer, int &generation) {
    generation++;  
#ifdef DEBUG
    string indent(generation, '\t');
    cout << indent << "reverse_right: " << num << " answer: " << answer << endl;
#endif  
    if (num < BASE) { // only one digit left
        answer = attach_right(answer, num, generation);
        return;
    }
    int right_digit = detatch_right(num, generation); 
    answer = attach_right(answer, right_digit, generation);
    recurse_attach_right(num, answer, generation);
    return;
}

// ------------------- Main program ----------------------
int main(int argc, char* argv[]) {
    int user_input;
    if (argc > 1) {
        user_input = atoi(argv[1]);
        cout << "You have entered (from command line): " << user_input << endl;
    } else {
        cout << "Enter a number: ";
        cin >> user_input;
        cout << "You have entered: " << user_input << endl;
    }
    
    if (user_input < BASE) {
        cout << "Single digit, nothing to reverse." << endl;
        return 0;  
    }

    // variables for supporting the solutions
    int generation = 0; // for formatted output in DEBUG
    int use_num = user_input; // keep original input intact
    int answer = 0; // this is the answer to be built up
    
    // Solution:
    //      split the use_num into two parts: 
    //             right_digit is the right most digit (use_num % 10)
    //             use_num is the rest of the number (use_num / 10)
    //      build up the answer by attaching right_digit to the right of answer
    //      repeat until one digit left in use_num
    //

    // Implemenation 1: 
    //     iteratively 
    //         1. detatch a digit from the right 
    //         2. compose answer by attching the digit to the right
    //     repeat until no more digits 
    //     print the answer
    cout << "Iterative: detach from right and attach to right" << endl;
    generation = 0; // restart
    use_num = user_input; // reset
    answer = 0;
    int right_digit(0);  // both this line and the previous are initialize an integer
    while (use_num > BASE) {
        generation++;  // number of digits worked on
        right_digit = detatch_right(use_num, generation);
        answer = attach_right(answer, right_digit, generation);
    }
    // the last digit
    answer = attach_right(answer, use_num, generation);
    cout << "   Reverse of " << user_input << " is " << answer << endl;
    cout << "--------------" << endl;

    // Implementation 2: (of the same solution above)
    //    this time: recursively
    //        1. detatch a digit from the right
    //        2. compose answer by attching the digit to the right
    //    repeat until no more digits left
    //    print the answer
    cout << "Recursive: detach from right and attach to right" << endl;
    generation = 0; // restart
    use_num = user_input; // reset
    answer = 0; // reset
    recurse_attach_right(use_num, answer, generation);
    cout << "   Reverse of " << user_input << " is " << answer << endl;
    cout << "--------------" << endl;

    // Alternative solutions: 
    //   recursively detatch from the right and attach to the left
    //   print the answer
    // This is a more involved solution, as the "left" means the most significant digit
    // and, we need to keep track of how to access "the left" of the given number
    // This required keeping track of a "base" variable, which is multiplied by 10 each time
    // The base variable helps us access the left-most-digit. 
    // 
    // Here we see, many solutions to the exact same problem, each with its own merits and drawbacks.
    // There are at least MANY solutions to this problem each with at least 2 different implementations
    //
    // Solution 1: Right detach + Right attach
    //      detatch from the right and maintain an answer by attaching to the right
    //      Two solutions (above): iteratively and recursively
    // 
    // Solution 2: Right detach + Left attach
    //      detatch from the right and maintain an answer by attaching to the left
    //      solution is rather involved, not shown
    // 
    // In this case, detatching from the left requires knowing the number of digits (more invovled)
    // 
    // Solution 3: Left detach + Left attach
    // Solution 4: Left detach + Right attach
    // 
    // Two points:
    //  1. Solutions and implementations are different
    //  2. You can always solve a problem independently, without thinking of implementation
    //     But, you cannot implement without having a solution first.
    //
    // So, always derive a solution first, and then implement based on your solution
    return 0;
}