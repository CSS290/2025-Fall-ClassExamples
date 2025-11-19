// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the use of constructors and the existence of destructors in C++
// Note:
//     1. Scope, that destructors are called automatically when objects go out of scope (the inner {})
//     2. Constructors: default and parameterized
//     3. Copy constructor: default by the compiler
//     4. Assignment operator: default by the compiler
//     5. Difference between copy constructor and assignment operator
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
    Point() : x(0)    // this is the default constructor, 
        {
            y = 0; // initialization can also be done here
                   // This is the OLD style, not recommended
            cout << "Point default constructor called" << endl;
        }                  // if not defined by user, compiler will provide one
    // WARNING: compiler provided default constructor does not initialize members

    // Another constructor with parameters
    Point(int a, int b) : x(a), y(b) {
        cout << "Point constructor called for (" << x << ", " << y << ")" << endl;
    }

    ~Point() { // Destructor
        // Destructor name is class name preceded by "~"
        // No return type, no parameters
        // Called automatically when object goes out of scope
        // ONLY USE: to release resources (memory) if needed
        cout << "Point destructor called for (" << x << ", " << y << ")" << endl;
    }
    
    // notice the "const" keyword!
    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// **RULE**: we should know, no need to memorize, but, need to know
//    If a user-defined constructor is provided, the compiler does NOT generate a default constructor.
// Try:
//    1. Comment out the empty (or defult) constructor above
//       try compile and see what happens when Point p0; is declared in main()
//    2. Comment out both constructors, try compile and see what happens when Point p1(10,20); is declared in main()
//    3. Change the p2 and p3 construction to without parameters, try compile and see what happens
// 
// **RULE**: Destructor is ALWAYS provided by the compiler if not defined by user
//           However, if user-defined destructor is provided, the compiler does not generate one, not even the default one
//

int main() {
    Point p0;  // calls default constructor
    cout << "p0:";
    p0.print();

    Point p1(10, 20);
    cout << "p1:";
    p1.print();

    {
        Point p2(100, 200);
        cout << "p2:";
        p2.print();

        Point p3(p2);  // creates a copy from p2 by calling copy constructor
                //       we did not define a copy constructor above, so compiler provides one
                // **** NOTE  ***: this is different from assignment statement
                //             Point p3 = p2; also calls copy constructor
                //             p3 = p2; calls assignment operator (default provided by compiler)
        cout << "p3:";
        p3.print();
    } // p2 goes out of scope here, destructor called automatically
    cout << "After inner block" << endl << endl;

    return 0;
    // P0 and P1 go out of scope here, destructors called automatically
}
