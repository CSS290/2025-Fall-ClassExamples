// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the basics of a class in C++ with separate implementaion and header file
//     Also: note the copy constructor and contrast with assignment statement
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

// Copy constructor
Point::Point(const Point &p) : x(p.x), y(p.y) {
    cout << "Point copy constructor called" << endl;
}
    // The copy constructor is also defined by the compiler by default
    // But we define it here explicitly for illustration

Point::~Point() {
    cout << "Point destructor called for (" << x << ", " << y << ")" << endl;
}

// notice the "const" keyword!
void Point::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}
