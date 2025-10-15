// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the basics of pointers and references

#include <iostream>
using namespace std;

int main() {
    int aNum(10);
    int *p1(&aNum); // Pointer to aNum, can also initialze by: int *p1 = &aNum;
    int &r = aNum; // r is a different name for aNum
    int *ptr(&r); // Pointer initialized to r or aNum

    *p1 = 100;
    // 1. print aNum, &aNum, and p1
    cout << "aNum=" << aNum << "   &aNum=" << &aNum << endl;
    cout << " *p1=" << *p1 << "      p1=" << p1 <<  endl;
    cout << "   r=" << r<< "      &r=" << &r  << endl;
    cout << "*ptr=" << *ptr << "     ptr=" << ptr << endl;

    return 0;
}