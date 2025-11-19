// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the basics of operator overloading in C++.
//
#ifndef POINT_H
#define POINT_H

#include <iostream>   // for the "string" in the print function
using namespace std;

// Define a Point class
class Point {
    string name; // this is for clarity in debugging output
    int x, y; // private by default
public:
    Point();              // Default constructor declaration
    Point(string n, int a, int b); // Constructor declaration
    ~Point();             // Destructor declaration
    void print(string msg) const;

    // Operator overload: operating on the current object with no operand
    Point& operator-();  // Unary minus operator
    Point& operator++();      // Prefix increment operator
    Point operator++(int);    // Postfix increment operator
    
    // Single operand operator overload: 
    //    operating on the current object
    Point& operator+=(const Point &p); // Compound assignment operator
    Point& operator-=(const Point &p); // Compound assignment operator
    // 
    //  this is defined by the compiler by default
    //  Point& operator=(const Point &p);  // Assignment operator
    
    // Two operand operator overload: 
    //    notice the const qualifier at the end
    //    because we are not modifying the current object
    //    current object is a participant in the operation
    Point operator+(const Point &p) const;
    Point operator-(const Point &p) const;
    Point operator*(int scaler) const;
    bool operator==(const Point &p) const;
};

#endif
