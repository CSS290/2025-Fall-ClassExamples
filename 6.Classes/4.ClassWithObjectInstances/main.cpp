// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//   Illustrate the basics of a class in C++ that has an instance of another class as a member  
//   In this case, Circle has a Point as its center

#include <iostream>
using namespace std;

#include "Circle.h"


int main() {
    Circle c1; // default constructor
    c1.print();
    
    Circle c(3, 1, 1);  // radius 3, center at (1,1)
    c.print();

    // Using pointer to an object
    cout << "Using pointer to an object:" << endl;
    Circle *cPtr = &c;  // pointer to object c
    cPtr->setCenter(2, 3);
    (*cPtr).setRadius(2);
    cPtr[0].print();

    // Using reference to an object
    cout << "Using reference to an object:" << endl;
    Circle &ref(*cPtr);
    ref.print();
}
