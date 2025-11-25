// File: main.cc in 9.DeepCopy+Destructors
// Date: 2025-11-25
// Author: ksung
// Description:
//      Demonstrate the   RULE OF THREE  in C++ with deep copy and destructors
//      If there is are dynamically allocated memory in a class,
//      you (almsot always) need to define the following three functions:
// 
//         a. Copy constructor:     when creating self from an existing object
//         b. Assignment operator=  when assigning one existing object to another
//         c. Destructor            when destroying the object
//
#include <iostream>
#include "MyArrayClass.h"
using namespace std;

// A helper function to compare two MyArrayClass objects and print the result
void CompareArrays(string msg, const MyArrayClass &a, const MyArrayClass &b) {
    if (a == b) {
        cout << msg << ": The two arrays are equal." << endl;
    } else {
        cout << msg << ": The two arrays are NOT equal." << endl;
    }
}

int main() {
    // Calling simple construction
    MyArrayClass arr1, arr2(5);

    // testing subscript operator[]()
    for (int i = 0; i < arr1.getSize(); i++) {
        arr1[i] = i + 1;  // Assign values 1 to 10
    }
    
    // Testing ostream operator<<()
    cout << "arr1: " << arr1 << endl;
    cout << "arr2: " << arr2 << endl;

    // Testing comparison operator==()
    CompareArrays("arr1 and arr2", arr1, arr2);
    
    // Testing assignment operator=
    arr2 = arr1;
    cout << "After assignment, arr2: " << arr2 << endl;
    CompareArrays("After assignment (1 and 2) :", arr1, arr2);

    // Copy construction
    MyArrayClass arr3(arr1);
    cout << "After copy construction, arr3: " << arr3 << endl;
    CompareArrays("After copy construction: (1 and 3)", arr1, arr3);

    return 0;
}