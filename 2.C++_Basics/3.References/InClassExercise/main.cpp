#include <iostream>
using namespace std;


void problem1() {
    int a = 4;
    int &r = a;   // or int& r(a);
    int b = a;
    int c = r;

    cout << " a=" << a
         << " b=" << b
         << " c=" << c
         << " r=" << r << endl;
}

// Problem 2:

void f (int a) {
      a += 10;
}

void g (int &a) {
    a += 11;
}

int main() {

    cout << "Problem 1:" << endl;
    problem1();
    cout << endl << endl;

    cout << "Problem 2:" << endl;
    // Here is Problem 2:
     int x = 4;
     int &r(x);
     cout << "Now calling with the int x:" << endl;
     f(x);
     cout << "    After calling f(x), x =" << x << " r=" << r << endl;
     g(x);
     cout << "    After calling g(x), x =" << x << " r=" << r << endl;

     cout << "Now calling with the reference r:" << endl;
     f(r);
     cout << "    After calling f(r), x =" << x << " r=" << r << endl;
     g(r);
     cout << "    After calling g(r), x =" << x << " r=" << r << endl;

     return 0;
}