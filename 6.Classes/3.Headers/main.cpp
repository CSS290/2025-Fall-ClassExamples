// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the basics of a class in C++ with separate implementaion and header file
//     Since Point.h is included, we can use the Point class defined there
//     and we do not need to re-include stream
#include "Point.h"

int main() {
    Point p(5, 8);
    p.print();
}
