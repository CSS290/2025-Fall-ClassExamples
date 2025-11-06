// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the use of constructors in C++
//
#include <iostream>
using namespace std;

// Define a Point class
class Point {
    int x, y; // private by default
public:
    // Constructor
    //    Note: function name is same as class name
    //          No return type
    //          Can be overloaded (many versions with different parameters)
    //          The MAIN PURPOSE is to initialize member variables upon object creation
    //
    //    The list after ":" is referred to as: member initializer list
    Point() : x(0), y(0)    // this is the default constructor, 
        {}                  // if not defined by user, compiler will provide one
    // WARNING: compiler provided default constructor does not initialize members

    // Another constructor with parameters
    Point(int a, int b) : x(a), y(b) 
        {}

    // notice the "const" keyword!
    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p0;  // calls default constructor
    p0.print();

    Point p1(10, 20);
    p1.print();
}
