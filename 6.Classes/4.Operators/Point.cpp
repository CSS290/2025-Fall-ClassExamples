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
Point::Point() : name("NoName"), x(0), y(0) {
    cout << name << ": constructor" << endl;
}

// Another constructor with parameters
Point::Point(string n, int a, int b) : name(n), x(a), y(b) {
    cout << name << ": constructor called for (" << x << ", " << y << ")" << endl;
}

Point::~Point() {
    cout << name << ": destructor called for (" << x << ", " << y << ")" << endl;
}

// notice the "const" keyword!
void Point::print(string msg) const {
    cout << name << ": " << msg << ": (" << x << ", " << y << ")" << endl;
}

// --------------------------------------------------------------
// Operator overload: operating on the current object with no operand

// Unary minus operator
Point& Point::operator-() {
    x = -x;
    y = -y;
    return *this;
}
// Prefix increment operator
Point& Point::operator++() {
    ++x;
    ++y;
    return *this;
}
// Postfix increment operator
//   the int parameter is a dummy parameter to distinguish it from the prefix version
//   NOTE: the postfix version returns by value, not by reference
Point Point::operator++(int) {
    Point temp = *this; // make a copy
    ++x;
    ++y;
    return temp;
} 


// --------------------------------------------------------------
// Single operand operator overload: operating on the current object

// Compound assignment operators
Point& Point::operator+=(const Point &p) {  
    x += p.x;
    y += p.y;
    return *this;
}   
Point& Point::operator-=(const Point &p) {  
    x -= p.x;
    y -= p.y;
    return *this;
}


// --------------------------------------------------------------
// Two operand operator overload: object is const, just a participant


// Addition operator
Point Point::operator+(const Point &p) const {
    return Point("op+", x + p.x, y + p.y);
}

// Subtraction operator
Point Point::operator-(const Point &p) const {
    return Point("op-", x - p.x, y - p.y);
}

// Scalar multiplication operator
Point Point::operator*(int scaler) const {
    return Point("op*", x * scaler, y * scaler);
}

// Equality operator
bool Point::operator==(const Point &p) const {
    return (x == p.x) && (y == p.y);
}