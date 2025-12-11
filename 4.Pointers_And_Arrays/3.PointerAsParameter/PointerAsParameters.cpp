// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the use of pointers as function parameters
//
#include <iostream>
using namespace std;
#include <iomanip> // Required for std::setw

const int FIELD_SIZE=30;

// Functions to swap two integers
// Different ways to pass parameters
// 1. pass by value
void swap_as_int(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. pass by reference
void swap_as_int_ref(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 3. pass by pointer
// Note: when passing addresses of integers, we need to dereference the pointers
// to access the integers they point to. Notice we are missing the dereferencing here
//       so this function does not work as intended
void swap_as_int_ptr_bad(int *a, int *b) {
    int *temp = a;
    a = b;
    b = temp;
}

// 4. pass by pointer
// Note: when passing addresses of integers, we need to dereference the pointers
// to access the integers they point to
void swap_as_int_ptr(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// int *&a: reference to a pointer to an integer
// UNTIL you really know what you are doing: DO NOT work with variables
// declared with combinations of *, &, e.g.
// int **a, *&p, etc.
void swap_as_int_ptr_ref(int *&a, int *&b) {
    int temp = *a;  // dereference a
    *a = *b;
    *b = temp;
}

// This function is incorrect because it swaps the pointers themselves
// so that after the function call, the pointers point to different integers
// instead of swapping the integers they point to
void swap_as_int_ptr_ref_bad(int *&a, int *&b) {
    int *temp = a;  // keeping a copy of the pointer a
    a = b;
    b = temp;
}

int main() {
    int aNum(10), bNum(20);
    int *aPtr = &aNum;
    int *bPtr = &bNum;
    cout << "Before" << right << setw(FIELD_SIZE) << " swap: aNum=" << aNum << " bNum=" << bNum << endl;
    cout << endl;


    // ----- swap_as_int and swap_as_int_ref
    swap_as_int(aNum, bNum);
    cout << "After " << right << setw(FIELD_SIZE) << "swap_as_int: aNum=" << aNum << " bNum=" << bNum << endl;

    aNum = 10; bNum = 20;
    swap_as_int_ref(aNum, bNum);
    cout << "After " << right << setw(FIELD_SIZE) << "   sawp_as_int_ref: aNum=" << aNum << " bNum=" << bNum << endl;
    cout << endl;

    // ----- swap_as_int_ptr_bad
    aNum = 10; bNum = 20;
    swap_as_int_ptr_bad(&aNum, &bNum);
    cout << "After " << right << setw(FIELD_SIZE) << "swap_as_int_ptr_bad: aNum=" << aNum << " bNum=" << bNum << endl;
    aNum = 10; bNum = 20;
    swap_as_int_ptr_bad(aPtr, bPtr);
    cout << "After " << right << setw(FIELD_SIZE) << "swap_as_int_ptr_bad: aNum=" << aNum << " bNum=" << bNum << endl;
    cout << endl;

    // ----- swap_as_int_ptr
    aNum = 10; bNum = 20;
    swap_as_int_ptr(&aNum, &bNum);
    cout << "After " << right << setw(FIELD_SIZE) << "swap_as_int_ptr: aNum=" << aNum << " bNum=" << bNum << endl;
    aNum = 10; bNum = 20;
    swap_as_int_ptr(aPtr, bPtr);
    cout << "After " << right << setw(FIELD_SIZE) << "swap_as_int_ptr: aNum=" << aNum << " bNum=" << bNum << endl;
    cout << endl;

    // ----- swap_as_int_ptr_ref
    aNum = 10; bNum = 20;
    // swap_as_int_ptr_ref(&aNum, &bNum); is NOT valid because
    // the function expects references to pointers, not addresses of integers,
    // the function can potentially change aPtr and bPtr to point to different addresses
    // which is not possible if we pass addresses of integers
    swap_as_int_ptr_ref(aPtr, bPtr);
    cout << "After " << right << setw(FIELD_SIZE) << "swap_as_int_ptr_ref: aNum=" << aNum << " bNum=" << bNum << endl;
    cout << endl;

    aNum = 10; bNum = 20;
    cout << "Before the last bad function call:" << endl;
    cout << "    &aNum=" << &aNum << " &bNum=" << &bNum << endl;
    cout << "     aPtr=" << aPtr << "  bPtr=" << bPtr << endl;
    swap_as_int_ptr_ref_bad(aPtr, bPtr);
    cout << "After " << right << setw(FIELD_SIZE) << "swap_as_int_ptr_ref_bad: aNum=" << aNum << " bNum=" << bNum << endl;
    cout << "    &aNum=" << &aNum << " &bNum=" << &bNum << endl;
    cout << "     aPtr=" << aPtr << "  bPtr=" << bPtr << endl;
    return 0;
}