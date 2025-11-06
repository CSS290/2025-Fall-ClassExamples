// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the basics of a class in C++ with separate implementaion and header file
//
#include "Point.h"
#include <iostream>
using namespace std;

// Define member functions of Point class
// Notice the strange "Point::" before each function name
// This indicates that these functions are members of the Point class
Point::Point() : x(0), y(0) {}

// Another constructor with parameters
Point::Point(int a, int b) : x(a), y(b) {}

// notice the "const" keyword!
void Point::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}
