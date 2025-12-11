
// Date: 10/4/2025
// Author: K. Sung
// Purpose:
// This shows that the func() function can be defined in a separate file,

#include "f.h"  // Include the header file that contains the prototype of func

// The definition of func
float func(int x) {
    // A dummy function
    return (x + 1.0) / 0.3;
}
