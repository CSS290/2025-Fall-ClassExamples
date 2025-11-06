// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the basics of a class in C++ with header file
//
#ifndef POINT_H
#define POINT_H

// Define a Point class
class Point {
    float x, y; // private by default
public:
    // Constructors
    Point();
    Point(float a, float b);

    // Member function to print the point
    void print() const;

    // Getters
    float getX() const;
    float getY() const;

    // Setters
    void set(float a, float b);
    void setX(float a);
    void setY(float b);
};

#endif
