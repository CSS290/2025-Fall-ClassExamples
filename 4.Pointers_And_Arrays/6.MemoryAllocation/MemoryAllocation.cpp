// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     To demonstrate memory allocation and deallocation in C++
//     specifically, memory allocation and deletion can occur in a function
//
// Note: This example intentionally includes some bad practices
//       to illustrate potential pitfalls.
// 
// Note: the use of valgrind is highly recommended to check for memory leaks
//
//    valgrind --leak-check=full -s ./a.out
//
#include <iostream>
using namespace std;
#include <iomanip> // Required for std::setw
#include <string>

const int MSG_WIDTH = 25;

// Function to print an array with a message
void print_pointer(const string& msg, int* p) {
    cout << setw(MSG_WIDTH) << msg << ": " << p << ", *p = " << *p << endl;
}

// Function to show memory can be allocated and returned from a funciton`
int* new_meory() {
    int *p = new int(5); // allocate memory memory and initialize to 5
    print_pointer("From new_memory", p);
    return p; // what happens if ...
              // return *p;
}

// Function to delete memory and set pointer to nullptr
void delete_memory(int* p) {
    print_pointer("delete_memory: Before", p);
    delete p;
    print_pointer("delete_memory: After", p);
    p = nullptr; // good practice
                 // But useless in this case
                 // As caller's pointer is not changed
}

// Function to show retuning the reference to memory allocated in a funciton
// is possible, but not a good idea
int& new_meory_ref() {
    int *p = new int(10); // allocate memory memory and initialize to 10
    print_pointer("From new_memory_ref", p);
    return *p; // memory is lost!
}


int main() {
    // 1. Simple case: allocation and freeing in main
    int *p = new int(10);// allocate memory memory and initialize to 10
    print_pointer("In main: After new", p);
    int a = *p; // use the memory
    cout << setw(MSG_WIDTH) << "In main: a =" << " " << a << endl;
    *p = 18;
    print_pointer("In main: Before delete", p);
    delete p; // free the memory
    print_pointer("In main: After delete! ** WHAT IS GOING ON? **", p);
    p = nullptr; // good practice
    cout << endl;        
    
    // 2. Allocated arrays in a function and return the pointer
    //    Delete in main
    cout << "Allocate in a function, return the pointer, and delete in main" << endl;
    p = new_meory();
    print_pointer("In main: After new_memory", p);
    *p = 100;
    print_pointer("In main: Before delete", p);
    delete p; // free the memory
    p = nullptr; // good practice
    cout << endl;

    // 3. Allocate in main and delete in a function
    cout << "Allocate in main and delete in a function" << endl;
    p = new int(20); // allocate memory memory and initialize to 20
    print_pointer("In main: After new", p);
    *p = 200;
    delete_memory(p); // free the memory
        // the function sets p to nullptr, but it is useless
        // as p in main is a different variable
    print_pointer("In main: After delete_memory ** WHAT IS GOING ON? **", p);
    p = nullptr; // good practice
    cout << endl;

    // in general, it is acceptable to allocate/delete 
    // memory in different functions

    // 4. Allocate in a function and return a reference
    cout << "Allocate in a function and return a reference ** BAD PRACTICE **" << endl;
    int &r = new_meory_ref();
    cout << setw(MSG_WIDTH) << "In main: r = " << r << endl;
    r = 55; // memory is lost!
    // there is no way to delete the memory now!!
    // Memory lost!
    return 0;
}