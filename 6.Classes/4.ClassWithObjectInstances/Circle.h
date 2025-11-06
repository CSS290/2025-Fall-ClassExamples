// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Define what is a circle
//
#ifndef CIRCLE_H
#define CIRCLE_H


#include "Point.h" // include the Point class definition

const float PI = 3.14159;

class Circle {
    float radius;
    Point center;
public:
    Circle();
    Circle(float, float x, float y);
    
    // functions
    void print() const;
    float area() const;

    // setter and getters
    void setRadius(int r);
    void setCenter(float x, float y);

    double getRadius() const;  
    Point getCenter() const;
};

#endif // CIRCLE_H