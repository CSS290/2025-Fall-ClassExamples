// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate pointers and references to structs 
//
#include <iostream>
using namespace std;
#include <iomanip> // Required for std::setw
#include <string>

struct IntPair {
    int a;
    int b;
    string name;
};

// Can also pass by reference
// Notice: returning a reference to a local variable is NOT valid
// because the local variable goes out of scope when the function ends
// Here we are returning the reference to demonstrate the syntax
// but in practice, we should avoid doing this
// Instead, we can return a pointer or a copy of the struct
// or pass a reference to be modified
// and avoid returning anything (void)
IntPair& PrintPairValues(IntPair &p) {
    cout << p.name << ": a=" << p.a << " b=" << p.b << " &p=" << &p << endl;
    return p; // Remove constness for demonstration purposes
}

// Can also pass by reference
// Returning a pointer to a local variable is NOT valid
// because the local variable goes out of scope when the function ends
// Here we are passing a pointer to be modified and returning the same pointer
// which is valid
// Note: when passing a pointer to a struct, we can directly access its members
// using the arrow operator (->)
IntPair* SetPairValues(IntPair *p, int x, int y) {
    p->a = x; // equivalent to (*p).a = x;
    (*p).b = y; // equivalent to p->b = y;
    return p;
}

int main() {
    IntPair ip1{10, 20, "First"};
    IntPair ip2{30, 40, "Second"};
    IntPair *p1(&ip1); // Pointer to ip1
    IntPair &r1 = ip1;

    ip1.a = ip1.b * 10; // change a through ip1
    PrintPairValues(r1);
    p1->name = "After"; // change name through p1
    IntPair &r2 = PrintPairValues(ip1);
    r2.a = 700;
    r2.name = " Next";
    PrintPairValues(r2);  // Notice: ignoring the return value
    cout << endl;

    IntPair *p2 = SetPairValues(&ip2, 100, 200); // p2 is a pointer to int
    PrintPairValues(ip2); 
    p2->name = " After";
    (*p2).a = 300; // equivalent to p2->a = 300;
    PrintPairValues(*p2); // dereference p2 to get the struct it points to

    return 0;
}