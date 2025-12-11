// File CopyObject/main.cpp
// Date: 2025-11-25
// Author: ksung
// Description: 
//      Demonstrates what happens when copying objects in C++ without proper copy constructors and assignment operators.
//
#include <iostream>
#include <cstring>
using namespace std;

class MyClass {
    friend ostream& operator<<(ostream& os, const MyClass& obj);
private:
    string name;
    int*  arr;
    int   size;
public:
    MyClass(string n, int s) : name(n), size(s) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = i;
        }
        cout << "Constructor called for " << name << endl;
    }

    ~MyClass() {
        cout << "Destructor called for " << name << endl;
        delete[] arr;
    }

    // Accessors
    string getName() const { return name; } 
    int getSize() const { return size; }

    // Setter
    void setName(const string& n) { name = n; }

    // Subscript operators
    // Const: this is accessor
    int operator[] (int index) const {
        return arr[index];
    }

    // No const and reference: this is setter
    int& operator[] (int index) {
        return arr[index];
    }
};  

// Overloading the global output operator for MyClass
ostream& operator<<(ostream& os, const MyClass& obj) {
    os << obj.getName() << " size(" << obj.size << ") arr=" << obj.arr << ": [";
    for (int i = 0; i < obj.size; i++) {
        os << obj[i] << " ";
    }
    os << "]";
    return os;
}

int main() {
    MyClass obj1("Object1", 5);
    MyClass obj2 = obj1;  // Default copy constructor (shallow copy)
    cout << endl;

    cout << "After copy construction: " << endl;
    cout << "obj1: " << obj1 << endl;
    cout << "obj2: " << obj2 << endl;
    cout << endl;

    // Modifying obj2's array
    obj2[0] = 100;
    cout << "After modifying obj2:" << endl;
    cout << "obj1: " << obj1 << endl;  // Affected due to shallow copy
    cout << "obj2: " << obj2 << endl;
    cout << endl;

    MyClass obj3("Object3", 3);
    obj3 = obj1;  // Default assignment operator (shallow copy)
    cout << "After assignment, obj3: " << obj3 << endl;

    // Exiting will crash! Why?
    // Run valgrind to see 
    //      obj2 => attempt to delete already deleted memory
    //      obj3 => memory lost
    // 
    return 0;
}