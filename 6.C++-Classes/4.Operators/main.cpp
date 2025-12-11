// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Examine operators overload in a class
//     Pay attention to temoprary objects created during operations
#include "Point.h"

int main() {
    Point p1("p1", 10, 20);
    
    p1.print("Initial");
    // Testing operator overload: operating on the current object with no operand
    -p1;
    p1.print("After -p1");
    ++p1;
    p1.print("After ++p1");
    cout << endl;

    {
        Point p2(p1++); // Note: This is copy construction!
                        //       compiler provided copy constructor is used here
                        //       p2.name is copied from p1.name, so, two objects with p1
                        //      this is because we did not define a copy constructor and the compiler copied everything
        p2.print("p2 assigned from p1++");
        p1.print("p1 after p1++");
    }
    cout << endl;
    p1.print("p1 is still here after p2 goes out of scope");
    cout << endl;

    // Testing single operand operator overload: operating on the current object
    Point p3("p3", 10, 20);
    p3.print("Initial p3");
    p3 += p1;
    p3.print("After p3 += p1");
    p3 -= p1;
    p3.print("After p3 -= p1");
    cout << endl;

    // Testing two operand operator overload: current object is a participant
    Point p4 = p1 + p3;  // NOTE: this is copy construction!
                         // And, the compiler provided copy constructor is used here
                         // Now: p4's name is "op"!!
    p4.print("p4(op+) = p1 + p3");

    p3 = p4 - p1;  // NOTE: this is assignment, not copy construction
                   //       compiler provided assignment operator is used here
                   //      p3's name now becomes "op-"
    p3.print("After p3(op-) = p4 - p1");
    cout << endl;

    p4 = p3 * 3; // Scalar multiplication, now p4's name becomes "*op"
    p4.print("After p4(op*) = p3 * 3");
    // p4 = 3 * p3; // This will cause a compilation error
    //     as 3 is a integer, and 3 does not have a member function operator* defined for point
    cout << endl;

    // Testing equality operator
    if (p4 == p3) {
        cout << "p4 is equal to p3" << endl;
    } else {
        cout << "p4 is not equal to p3" << endl;
    }
    cout << endl;
    
    cout << "Setting p1 = p4 - p3 * 2;" << endl;
    p1 = p4 - p3 * 2;; // p1 gets a new value, p1's name is now op-
    if (p1 == p3) {
        cout << "p1 is equal to p3" << endl;
        p1.print("p1(op-)");
    } else {
        cout << "p1 is not equal to p3" << endl;
    }
    cout << endl;

    cout << "End of main()" << endl;
    return 0;
}
