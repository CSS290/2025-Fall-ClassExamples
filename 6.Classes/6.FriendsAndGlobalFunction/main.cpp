// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     1. friend declaration example: grant access to private data members
//     2. Examples of global operators
#include "Point.h"

int main() {
    Point p1("p1", 10, 20);

    f(p1); // global function that is a friend of Point class
    cout << endl;

    p1.print("Initial p1");
    --p1;  // global prefix decrement operator
           // from this operator function call,
           // it is impossible to tell if the operator is a global function or a member function
    p1.print("After --p1");
    // p1--;  // ha ha, this is not defined!

    // Alternate way to call the global operator function
    operator--(p1);
    p1.print("After operator--(p1)");
    // Note, for member operator functions:
    //    p1.operator--();  // this would be the way to call a member function
    cout << endl;

    Point p2 = p1 - 4;  // global subtraction operator
    p2.print("p2 (Global-op-) = p1 - 4");
    // Alternate way to call the global operator function
    Point p3 = operator-(p1, 4);
    p3.print("p3 (Global-op-) = operator-(p1, 4)");
    // Note, for member operator functions:
    //    Point p4 = p1.operator-(p2);  // this would be the way to call a member function
    cout << endl;

    //
    cout << "Ostream operator<< output!!" << endl;
    cout << p1 << " " << p2 << " " << p3 << endl;
    // Alternate way to call the global operator function
    operator<<(cout, p1);
    cout << " ";
    operator<<(cout, p2);
    cout << " ";
    operator<<(cout, p3);
    cout << endl;
    // or, less humane way ...
    operator<<(operator<<(operator<<(cout, p1), p2), p3) << endl;
    cout << endl;

    
    /*  Compiler error: cannot differentiate between member function and global function
    ++p1;  // global prefix increment operator
           // from this operator function call,
           // it is impossible to tell if the operator is a global function or a member function
    p1.print("After ++p1");
    */

    return 0;
}
