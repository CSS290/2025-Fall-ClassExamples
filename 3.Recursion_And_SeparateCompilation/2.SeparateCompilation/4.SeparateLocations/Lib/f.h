// Date: 10/4/2025
// Author: K. Sung
// Purpose:
// This is the header file that contains the prototype of func().
// This header file is included in both main.cpp and f.cpp
// so that both files know about the prototype of func().
//
// We included iostream and using namespace std here so that
// in both main.cpp and f.cpp we can use cout without having to prefix it with std::
//
// Note that we use include guards to prevent multiple inclusion of this header file.
// Pragma once is a non-standard but widely supported way to do this.

#pragma once  // Include guard: prevents multiple inclusion of this header file

#include <iostream>
using namespace std;

// this is the prototype of func()
float func(int);  