// File: main (Shallow vs Deep Copy example)
// Date: 11/25/2025
// Author: K. Sung
// Purpose:
//     Illustrate shallow vs deep copy concepts
#include <iostream>
using namespace std;    

void PrintArray(string msg, int *arr, int size) {
    cout << msg << ": ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Simple example
    int a = 10;
    int b = a; // copy by value
    cout << "a: " << a << ", b: " << b << endl;
    b = 20; // modify b
    cout << "After modifying b:" << endl;
    cout << "a: " << a << ", b: " << b << endl; // a is unchanged
    cout << endl;

    // Pointer example: shallow copy
    cout << "Shallow Copy Example with simple pointers:" << endl;
    int *p1 = new int(30); // allocate an int on the heap
    int *p2 = p1; // shallow copy: copy the pointer value
    cout << "p1: " << *p1 << ", p2: " << *p2 << endl;
    *p2 = 40; // modify the value pointed by p2
    cout << "After modifying *p2:" << endl;
    cout << "p1: " << *p1 << ", p2: " << *p2 << endl; // p1 is also changed
    delete p1; // free the allocated memory
    cout << endl;

    // Pointer example: deep copy
    cout << "Deep Copy Example with simple pointers:" << endl;
    int *q1 = new int(50); // allocate an int on the heap
    int *q2 = new int(*q1); // deep copy: allocate new memory and copy the value
    cout << "q1: " << *q1 << ", q2: " << *q2 << endl;
    *q2 = 60; // modify the value pointed by q2
    cout << "After modifying *q2:" << endl;
    cout << "q1: " << *q1 << ", q2: " << *q2 << endl; // q1 is unchanged
    delete q1; // free the allocated memory
    delete q2; // free the allocated memory
    cout << endl;

    // Array example: shallow and deep copy
    cout << "Shallow and Deep Copy Example with an array:" << endl;
    const int size = 3;
    int *arr1 = new int[size]{1, 2, 3}; // allocate an array on the heap
    int *arr2 = arr1; // shallow copy: copy the pointer value
    int *arr3 = new int[size]; // deep copy: allocate new memory
    for (int i = 0; i < size; ++i) {
        arr3[i] = arr1[i]; // copy the values
    }
    PrintArray("arr1", arr1, size);
    PrintArray("arr2", arr2, size);
    PrintArray("arr3", arr3, size);
    cout << endl;
    
    cout << "After modifying arr2 and arr3:" << endl;
    arr2[1] = 5; // modify arr2
    arr3[2] = 5; // modify arr3
    PrintArray("arr1", arr1, size);
    PrintArray("arr2", arr2, size);
    PrintArray("arr3", arr3, size);

    // Clean up
    delete[] arr1; // free the allocated memory
        // note: CANNOT 
        //    delete[] arr2; 
        // because it points to the same memory as arr1
    delete[] arr3; // free the allocated memory

    return 0;
}
