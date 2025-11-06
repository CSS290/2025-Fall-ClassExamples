// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Implementation of what is a circle
//     Take note of the initialization of member objects in the constructor
//
#include <iostream>
using namespace std;

#include "Circle.h" // include the circle class definition

Circle::Circle() : radius(1.0), center() {}

Circle::Circle(float r, float x, float y) : radius(r), center(x, y) {}

// Behaviors or functions
void Circle::print() const {
    cout << "Circle(" << center.getX() << ", " << center.getY() 
         << "), r=" << radius << " Area=" << area() << endl;
}

float Circle::area() const {
    return PI * radius * radius;
}

// Setters and Getters
void Circle::setRadius(int r) {
    this->radius = r; // once again, "this->" pointer is optional
}

void Circle::setCenter(float x, float y) {
    center.setX(x);
    center.setY(y);
}

double Circle::getRadius() const {
    return radius;
}

Point Circle::getCenter() const {
    return center;
}