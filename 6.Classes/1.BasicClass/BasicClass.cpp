// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the basics of a class in C++
//
#include <iostream>
using namespace std;

// Define a simple class named Point
class Point {
public:
    int x;  // member variable
    int y;  // These are referred to as: instance variables

    // member function to print the point
    // These are referred to as: instance methods (or functions)
    void print() {
        cout << "(" << this->x << ", " << y << ")" << endl;
            // this-> is optional here for y, but shown for clarity
    }
};

int main() {
    Point p;
    p.x = 2;
    p.y = 3;
    p.print();

    // for working with pointer
    Point* ptr = &p;
    ptr->x = 5;
    (*ptr).y = 7; // alternative way to access member via pointer
    ptr->print();
}
