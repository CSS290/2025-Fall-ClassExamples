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
//      build up the answer by attaching the rightmost digit to the left of answer
//      repeat until only one digit left in input
// 
// This is a much more involved solution, as the "left" means the most significant digit
//      so we need to keep track of the base (1, 10, 100, ...)
// Only the recursive version is implemented here where answers in each step are kept in the 
// stack frames and combined when the recursion unwinds.
// This can be a little confusing as we are not explicitly building up the answer in each step
// but rather combining the answers in each step when the recursion unwinds.
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
//      output: true if there are still more than one digit, 
//      post-condition: num is updated to be the number without the right most digit 
//                      right is updated to be the right most digit
// Note: generation is used for formatted output in DEBUG mode
bool detatch_right(int &num, int &right, int generation) {
    right = num % BASE;
    int left = num / BASE;
#ifdef DEBUG
    string indent(generation, '\t');
    cerr << indent << "detatch_right: " << num << " into " << left << " and " << right << endl;
#endif
    num = left;
    return (num > BASE); // return true if there are still more than one digit
}

// attach_to_left: attach a digit to the left of num
//      input: left (the digit to be attached), num, base (by reference, so that it can be updated)
//      output: the new number after attaching left to num
//      post-condition: base is updated to be 10 times of its original value (get ready for 
//                      the next left digit to be attached)
// Note: generation is used for formatted output in DEBUG mode
int attach_left(int left, int num, int &base, int generation) {
    int result = base * left + num;
#ifdef DEBUG
    string indent(generation, '\t');
    cerr << indent << "attch_to_left(" << base << "): " << left << " and " 
         << num << " into " << result << endl;
#endif
    base = base * BASE;
    return result;
}

//
// recurse_attach_left: recursively detatch from right and attach to left
//      input: num (input number), 
//             base (for attching to left, by reference, so that it can be updated), 
//             generation (for debug output)
//      output: the reversed number
//      post-condition: recursion stops when num has no more digits left
// Note: generation is used for formatted output in DEBUG mode
//
// The answer to the reversal is implicitly stored in the stack frame
//       and built up when the recursion unwinds
int recurse_attach_left(int num, int &base, int &generation) {
    int right_digit;
    generation++;
#ifdef DEBUG
    string indent(generation, '\t');
    cerr << indent << "reverse_left: " << num << " base:" << base << endl;
#endif
    if (!detatch_right(num, right_digit, generation)) 
        return attach_left(right_digit, num, base, generation);
               // at this point, I can also do
               // return attach_to_right(right, num, generation);
    return attach_left(right_digit, recurse_attach_left(num, base, generation), 
                          base, generation);
}

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

    int base = 10;
    int generation = 0; // for formatted output in DEBUG
    
    if (user_input < BASE) {
        cout << "Single digit, nothing to reverse." << endl;
        return 0;  
    }
    cout << "Reverse with recursion attaching from the left: ";
#ifdef DEBUG
    cerr << endl;
#endif
    int use_num = user_input; // Reverse will alter its input num, passing my reference!
    cout << recurse_attach_left(use_num, base, generation) << endl;

    return 0;
}