// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Deeper dive into operator overload in a class
//     1. Examine operators as simple function calls (with awkward function names)
//     2. Examine the details of reutrning a temporary object vs a reference to *this
#include "Point.h"

int main() {
    Point p1("p1", 10, 20);

    // Operators as function calls
    p1.operator-();  // -p1 exactly the same as p1.operator-()
    p1.print("After -p1");

    p1.operator++(); // ++p1 exactly the same as p1.operator++()
    p1.print("After ++p1");
    cout << endl;

    Point p2("p2", 0, 0);
    p2.operator+=(p1); // p2 += p1 exactly the same as p2.operator+=(p1
    p2.print("After p2 += p1");
    cout << endl;

    Point p3 = p1.operator+(p2); // p1 + p2 exactly the same as p1.operator+(p2)
    p3.print("After p3(op+) = p1 + p2");
    cout << endl;

    cout << "Why returning reference to *this is important" << endl << endl;
    p1.set(0, 0);
    p1.print("Initial p1");
    ++(++p1);  // what does this do?
    p1.print("After ++(++p1)");  // what is going on?
    // Alternatively written as:
    (p1.operator++()).operator++();
    p1.print("After p1.operator++().operator++()");
    // Or more humanely
    Point& ref = p1.operator++();       // NOTICE: no constructor called!
    ref.operator++();
    p1.print("After ref.operator++()");
    cout << endl;   

    cout << "Postfix increment operator is *VERY* DIFFERENT!!" << endl;
    p1.set(0, 0);
    p1.print("Initial p1");
    p1++++;  // what does this do?
    p1.print("After p1++++");  // what is going on?
    // How about this?
    p1++++++;  // NOT cool!
    p1.print("After p1++++++");

    cout << endl;
    
    // Now do we understand ...
    int a = 5;
    cout << "What is this?: ";
    (cout.operator<<(a)).operator<<(endl);  // <<------ What is going on here?
    cout << "Compare  with: " << a << endl;

    cout.operator<<(endl);

    return 0;
}
