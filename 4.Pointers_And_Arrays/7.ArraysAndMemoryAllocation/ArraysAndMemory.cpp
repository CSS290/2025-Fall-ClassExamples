// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//          Demonstrate arrays and memory allocation in C++.     
//
#include <iostream>
using namespace std;
#include <iomanip> // Required for std::setw
#include <string>

const int MSG_WIDTH = 25;
const int Num_WIDTH = 4;
const int ARRAY_SIZE = 5;

// Function to print an array with a message
void print_array(string msg, const int arr[], int size) {
    cout << setw(MSG_WIDTH) << msg << ": " << "addr=" << arr << " values=";
    for (int i = 0; i < size; ++i) {
        cout << setw(Num_WIDTH) << arr[i];
    }
    cout << endl;
}

// Function to copy one array to another
void copy_array(int dest[], const int src[], int size) {
    for (int i = 0; i < size; ++i) {
        dest[i] = src[i];
    }
}

// Function to allocate an array of given size
int* new_array(int size) {
    return new int[size]; // Caller is responsible for deleting the array
}

// Function to deallocate an array
//    Note: here, the array is passed as a pointer?!
void deallocate_array(int* &arr) { // NOTE: passing of pointer by reference!
    delete[] arr;
    arr = nullptr; // Avoid dangling pointer
                   // This is important! because the pointer in main() will also be set to nullptr
}

int main() {

    // Arrays in their simplest form
    int not_initialized[ARRAY_SIZE];  // bad practice, contains garbage values
    int set[ARRAY_SIZE] = {10, 20, 30, 40, 50};
    cout << "Simplest case of 1D arrays" << endl;
    print_array("Not Initialized", not_initialized, ARRAY_SIZE);
    print_array("Set", set, ARRAY_SIZE);
    copy_array(not_initialized, set, ARRAY_SIZE);
    print_array("After Copy", not_initialized, ARRAY_SIZE);
    cout << endl;

    // Allocated arrays: allocate and delete in main
    cout << "Allocated arrays: new and delete in main" << endl;
    int* allocated_array = new int[ARRAY_SIZE] {1, 2, 3, 4, 5}; // allocate and initialize
    print_array("Allocated Array", allocated_array, ARRAY_SIZE);
    delete [] allocated_array; // deallocate: NOTE the [] 
    print_array("After delete ** NOTE **", allocated_array, ARRAY_SIZE);
    allocated_array = nullptr; // avoid dangling pointer
    cout << endl;

    // Allocated arrays: allocate in function, delete in main
    cout << "Allocated arrays: new in function, delete in main" << endl;
    int* allocated_array2 = new_array(ARRAY_SIZE); // allocate in function
    print_array("Allocated Array2 (not initialized)", allocated_array2, ARRAY_SIZE);
    copy_array(allocated_array2, set, ARRAY_SIZE);
    print_array("After Copy", allocated_array2, ARRAY_SIZE);
    delete [] allocated_array2; // deallocate in main
    allocated_array2 = nullptr; // avoid dangling pointer
    cout << endl;

    // Allocated arrays: allocate and delete in function
    cout << "Allocated arrays: new and delete in functions" << endl;
    int* allocated_array3 = new_array(ARRAY_SIZE); // allocate in function
    print_array("Allocated Array3 (not initialized)", allocated_array3, ARRAY_SIZE);
    copy_array(allocated_array3, set, ARRAY_SIZE);
    print_array("After Copy", allocated_array3, ARRAY_SIZE);
    deallocate_array(allocated_array3); // deallocate in function
    cout << "After deallocate_array(): addr=" << allocated_array3 << endl;
    
    cout << endl;

    // in general, it is acceptable to allocate/deallocate from
    // different functions, but the best practice is to allocate
    // and deallocate in the same function.
    // This avoids confusion and potential memory leaks.

    // Should I delete [] for set?
    // delete [] set; // NO! set is not allocated by new
    // set = nullptr; // NO! set is not allocated by new
    return 0;
}