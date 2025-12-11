// Date: 10/14/2025
// Author: K. Sung
// Purpose: Demonstrate the use of 2D arrays in C++
//
#include <iostream>
using namespace std;
#include <iomanip> // Required for std::setw
#include <string>


int main(int argc, const char* argv[])
{
    // Case of 2D arrays with different second dimension sizes
    cout << "2D arrays with different second dimension sizes" << endl;
    float *a[3];  // This is an array of 3 float pointers
    a[0] = new float[2] {0.0, 0.1};
    a[1] = new float[3] {1.0, 1.1, 1.2};
    a[2] = new float[1] {2.0};

    cerr << "a[0]: " << a[0][0] << " " << *(a[0]+1) << "\n";
    cerr << "a[1]: " << a[1][0] << " " << *(a[1]+1) << " " << *(*(a+1)+2) << "\n";
    cerr << "a[2]: " << *(a[2]) << "\n";

    // the fact that you can do something does not mean it is cool, or you should
    //         *(*(a+1)+2) is simply evil. 
    cout << "a[1][2]: " << a[1][2] << " or " << *(*(a+1)+2) << "\n";
    // besides a[i][j], there is no reason to use any other syntax!
    cout << endl;

    delete [] a[0];  // This is how we free each row
    delete [] a[1];
    delete [] a[2];

    cout << "2D arrays using pointer to a pointer" << endl;
    // 2D array is simply an pointer to a pointer
    int **b; // This is a pointer to a pointer
    b = new int*[3]; // allocate 3 int pointers
    b[0] = new int[2] {10, 20};
    b[1] = new int[3] {30, 40, 50};
    b[2] = new int[1] {60}; 
    cout << "b[0]: " << b[0][0] << " " << b[0][1] << "\n";
    cout << "b[1]: " << b[1][0] << " "
            << b[1][1] << " " << b[1][2] << "\n";
    cout << "b[2]: " << b[2][0] << "\n";
    cout << endl;

    delete [] b[0];
    delete [] b[1];
    delete [] b[2];
    delete [] b; // free the array of pointers


    // Case of straightforward 2D arrays with same second dimension sizes
    float t[3][3] {     // This is a 2D array of 3 rows and 3 columns with proper initialization
        {0.0, 0.1, 0.2},
        {1.0, 1.1, 1.2},
        {2.0, 2.1, 2.2}
    };  
    cout << "Simple case of 2D arrays" << endl;
    cout << "t[0]: " << t[0][0] << " " << t[0][1] << " " << t[0][2] << endl;
    cout << "t[1]: " << t[1][0] << " " << t[1][1] << " " << t[1][2] << endl;
    cout << "t[2]: " << t[2][0] << " " << t[2][1] << " " << t[2][2] << endl;
    cout << endl;
    // Array not allocated so no free needed

    cout << "Simple case of 2D arrays with unspecified first dimension:" << endl;
    float f[][2] {   // This is OK allowed
        {0.0, 0.1},
        {1.0, 1.1},
        {2.0, 2.1},
        {3.0, 3.1}  // First index is the number of rows, can be omitted
    };
    cout << "f[0]: " << f[0][0] << " " << f[0][1] << endl;
    cout << "f[1]: " << f[1][0] << " " << f[1][1] << endl;
    cout << "f[2]: " << f[2][0] << " " << f[2][1] << endl;
    cout << "f[3]: " << f[3][0] << " " << f[3][1] << endl;
    cout << endl;
        // Again, array not allocated so no free needed

    // Declared 2d array must have same 2nd dimension size
    // float c[][];   // This is NOT allowed
    // float d[][3];  // This is allowed
    // float e[3][3]; // This is allowed
    return 0;
}