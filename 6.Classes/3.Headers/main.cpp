// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the basics of a class in C++ with separate implementaion and header file
//     Since Point.h is included, we can use the Point class defined there
//     and we do not need to re-include stream
// Note:
//    Also: note the copy constructor and contrast with assignment statement
//
#include "Point.h"
#include <iostream>
using namespace std;

int main() {
    Point p(5, 8);
    cout << "p:";
    p.print();
        {
            Point p2(100, 200);
            cout << "p2:";
            p2.print();

            Point p3 = p2; // Calls copy constructor
            cout << "p3:"; 
            p3.print();

            p = p3; // Calls assignment operator (default provided by compiler)
            cout << "After assignment, p:";
            p.print();
        }
    cout << "End of main()" << endl << endl;
    return 0;
}
