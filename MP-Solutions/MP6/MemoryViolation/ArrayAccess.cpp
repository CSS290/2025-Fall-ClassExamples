// ArrayAccess.cpp
// This file contains functions that demonstrate array out of bound access without crashing!

#include <iostream>
#include <stdexcept>

using namespace std;

const int ARRAY_SIZE = 10;

int arrayAccess(int* arr, int index) {
    return arr[index];
}

int& setArrayValue(int* arr, int index) {
    return arr[index];
}

int main() {
    int myArray[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Index = 5: " << arrayAccess(myArray, 5) << endl;   // Valid access
    cout << "Index = 10: " << arrayAccess(myArray, 10) << endl; // Out of bounds access

    setArrayValue(myArray, 10) = 42; // Out of bounds access
    cout << "After setting index 10 to 42: " << arrayAccess(myArray, 10) << endl; // Out of bounds access

    setArrayValue(myArray, -1) = 99; // Out of bounds access
    cout << "After setting index -1 to 99: " << arrayAccess(myArray, -1) << endl; // Out of bounds access

    return 0;
}
