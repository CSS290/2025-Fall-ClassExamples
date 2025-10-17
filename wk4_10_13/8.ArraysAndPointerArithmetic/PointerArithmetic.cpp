// Date: 10/14/2025
// Author: K. Sung
// Purpose: Demonstrate pointer arithmetic with arrays
//
#include <iostream>
using namespace std;
#include <iomanip> // Required for std::setw
#include <string>

const int MSG_WIDTH = 25;
const int FIELD_WIDTH = 15;
const int Num_WIDTH = 4;
const int ARRAY_SIZE = 5;

// Function to print an array with a message
// **** NOTE ****
//      the pointer p is incremented in the loop
//      p++ is NOT changing the address value
//          this is changing where p points to
void print_array(string msg, int arr[], int size) {
    cout << setw(MSG_WIDTH) << msg << ": " << endl;
    int *p = arr; // note that arr is treated as a pointer
    for (int i = 0; i < size; ++i) {
        cout << setw(FIELD_WIDTH) << "index=" << i
             << " addr=" << p << " value:" << setw(Num_WIDTH) << *(p++) << endl; 
             // *(p+1) or arr[i] are the same
             // p++ is the same as p = p + 1;
             // p-- is also supported (p = p - 1)
             // NOTE: on the (), precedence matters!
    }
    // NOTE: By the end of this loop, p points to arr + size
    cout << endl;
}

// Note: arraygs can be passed as a pointer or as an array
// **** NOTE ****
//       note dest: passed as a pointer, used like a array
//       note src:  passed as an array[], used like a pointer
void copy_array(int *dest, const int src[], int size) {
    for (int i = 0; i < size; ++i) {
        dest[i] = *(src+i);  // dest[i] = src[i]; also works
    }
}

int main() {

    // Arrays in their simplest form
    int set[ARRAY_SIZE] = {10, 20, 30, 40, 50};
    cout << "Simple case of 1D arrays" << endl;
    print_array("Set", set, ARRAY_SIZE);
    cout << endl;

    // Copy array, mix of array and pointer notations
    cout << "Calling copy array()" << endl;
    int* new_array = new int[ARRAY_SIZE] {1, 2, 3, 4, 5}; // allocate and initialize
    copy_array(new_array, set, ARRAY_SIZE);
    print_array("New Array after copy", new_array, ARRAY_SIZE);
    cout << endl;

    cout << "Examining ponter arithmetic and array access" << endl;
    print_array("Recall that set:", set, ARRAY_SIZE);
    cout << "  set[0]: " << set[0] << " *(set+0): " << *(set+0) << endl;
    cout << "  set[1]: " << set[1] << " *(set+1): " << *(set+1) << endl;
    cout << endl;
    int *p = &(set[2]); // or p = set + 2;
    cout << "  p = &(set[2]): " << p << "      *p: " << *p << endl;
    p++; // point to the next int
    cout << "   after p++, p: " << p << "      *p: " << *p << endl;
    p--; // point back to where it was
    cout << "   after p--, p: " << p << "      *p: " << *p << endl;
    cout << "       &(p[-2]): " << &(p[-2]) << " p[p-2] : " << p[-2] << endl;
    cout << "            p-2: " << p-2 << "  *(p-2): " << *(p-2) << endl;
    cout << endl;

    // notes on precedence!!
    p = set; // point to the beginning of the array
    cout << "Notes on precedence:" << endl;
    cout << "        p: " <<  p << "  same as: &(set[0]): " << &(set[0]) << " or   set: " << set << endl;
    cout << "    p + 1: " <<  p + 1 << "  same as: &(set[1]): " << &(set[1]) << " or set+1: " << set+1 << endl;
    cout << "       *p: " << *p << "  same as:   set[0]:" << set[0] << endl;
    cout << "   *p + 1: " << *p + 1 << "  same as: set[0]+1: " << set[0] + 1 << endl;
    cout << " *(p + 1): " << *(p + 1) << "  same as:   set[1]: " << set[1] << endl;
    cout << endl;

    // 
    cout << "This can be confusing, becuase:" << endl;
    cout << "     &set[4]:" << &set[4] << " is the same as" << endl;
    cout << "   &(set[4]):" << &(set[4]) << endl;
    cout << "ALWAYS use () to make it clear!" << endl;
    cout << endl;

    cout << "Double array example" << endl;
    // reset p to point to the beginning of the array
    p = set;
    // Finally, note that ptr+1: the actual increment depends on data type
    double dset[ARRAY_SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double *dp = dset;
    cout << "            dp: " << dp << "  *dp: " << *dp << "   p=" << p << " *p: " << *p << endl;
    dp+=1; // point to the next double
    p+=1;  // point to the next int
    cout << " after +=1, dp: " << dp << "  *dp: " << *dp << "   p=" << p << " *p: " << *p << endl;
    cout << " Notice the size difference:" << sizeof(double) << " vs " << sizeof(int) << endl;
    cout << endl;
    
    delete [] new_array;
    new_array = nullptr; // always null the pointer
    return 0;
}