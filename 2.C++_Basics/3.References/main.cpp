
// Date: 9/25/2025
// Author: K. Sung
// Purpose:
// To illustrate C++ (or c) references
// Page 260 of C++ text
//
#include <iostream>
using namespace std;

void IncByOne(int x) {
    x++;
}

void IncByOneRef(int &x) {
    x++;
}

void printAllNums(string msg, int a, int b, int r, int s) {
    cout << msg << ": a=" << a << " b=" << b << " r(same as a)=" << r << " s(same as a)=" << s << endl;
}

int main() {
	int a; 		// this we know 
	int &r(a), b;	// What is this? 
			// Notice b is an int, NOT INITIALIZED!
			// r once initialized, the reference CANNOT be changed!
    int &s = r; 
            // This is another way of initializing a reference
            // Since r is another name for a, s is also another name for a
	// int &m; 	// this is illegal!

	a = 3;

	cout << "a=" << a << " b=" << b << " r(same as a)=" << r << " s(same as a)=" << s << endl;
	b = 10;	
    r = b; // sets "a" to 10!
	cout << "a=" << a << " b=" << b << " r(same as a)=" << r << " s(same as a)=" << s << endl;
    s -= 5;
    cout << "a=" << a << " b=" << b << " r(same as a)=" << r << " s(same as a)=" << s << endl;

    // now start using the print function
    // testing passing by value and reference for a
    //         Note: since r and s are references to a, they too changed
    printAllNums("Before IncByOne", a, b, r, s);
    IncByOne(a);
    printAllNums("After IncByOne for a", a, b, r, s);
    IncByOneRef(a);
    printAllNums("After IncByOneRef for a", a, b, r, s);

    cout << endl;
    // testing passing by value and reference for b
    //         in this case, b has no references defined, so only b changed
    IncByOne(b);
    printAllNums("After IncByOne for b", a, b, r, s);
    IncByOneRef(b);
    printAllNums("After IncByOneRef for b", a, b, r, s);
}