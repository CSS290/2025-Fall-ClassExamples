// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     Illustrate the basics of pointers

#include <iostream>
using namespace std;

int main() {
    int aNum(10), bNum(20);
    int *p1(&aNum); // Pointer to aNum, can also initialze by: int *p1 = &aNum;
    int *p2 = &bNum; // Pointer to bNum, identical to int *p2(&bNum);
    int *ptr(nullptr); // Pointer initialized to null

    // 1. print aNum and its address
    cout << "aNum=" << aNum << " &aNum=" << &aNum << endl;
    cout << "bNum=" << bNum << " &bNum=" << &bNum << endl;
    cout << endl;

    // 2. print p1 and p2
    cout << "p1=" << p1 << " *p1=" << *p1 << " &p1=" << &p1 << endl;
    cout << "p2=" << p2 << " *p2=" << *p2 << " &p2=" << &p2 << endl;
    cout << endl;

    *p1 = 100; // change the value of aNum through p1
    *p2 = *p1; // change the value of bNum through p2
    cout << "After changing values through pointers:" << endl;
    cout << "aNum=" << aNum << " &aNum=" << &aNum << endl;
    cout << "bNum=" << bNum << " &bNum=" << &bNum << endl;
    cout << endl;

    ptr = p1; // make ptr point to where p1 points (aNum)
    cout << "ptr=" << ptr << endl << " p1=" << p1 << endl << " p2=" << p2 << endl;
    if (ptr == p1) {
        cout << "p1 and ptr point to the same address." << endl;
    } else {
        cout << "p1 and ptr point to different addresses." << endl;
    }
    
    if (ptr != p2) {
        cout << "p2 and ptr point to different addresses." << endl;
    } else {
        cout << "p2 and ptr point to the same address." << endl;
    }
    cout << endl;

    return 0;
}