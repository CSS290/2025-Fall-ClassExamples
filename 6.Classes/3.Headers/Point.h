// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the basics of a class in C++ with header file
//
#ifndef POINT_H
#define POINT_H

// Define a Point class
class Point {
    int x, y; // private by default
public:
    Point();              // Default constructor declaration
    Point(int a, int b); // Constructor declaration
    void print() const;
};

#endif
