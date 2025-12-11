// Date: 9/25/2025
// Author: K. Sung
// Purpose:
// Useless example to show how references work with struct
// Note: the potential cost of passing struct (or class) by value
//
#include <iostream>
using namespace std;

struct MyStruct {
    int a;
    int b;
};

void PrintStruct(string msg, MyStruct s) {  // passing by value!
    cout << msg << ": MyStruct: a=" << s.a << " b=" << s.b << endl;
}

// Pass by value function
void PassByValue(MyStruct s) {
    s.a += 10;
    s.b += 20;
    PrintStruct("Inside PassByValue", s);
}

// Pass by reference function
void PassByReference(MyStruct &s) {
    s.a += 10;
    s.b += 20;
    PrintStruct("Inside PassByReference", s);
}

int main()
{
	MyStruct aStruct;   // You have NEVER seen this in Java! no new-statement

    aStruct.a = 3;
    aStruct.b = 4;

    PrintStruct("Before function call", aStruct);
    cout << endl;

    PassByValue(aStruct);
    PrintStruct("After pass by value call", aStruct);

    cout << endl;
    PassByReference(aStruct);
    PrintStruct("After pass by reference call", aStruct);

    // can I use reference here?
    cout << endl;
    MyStruct &r = aStruct;  // or MyStruct &r(aStruct);
    // MyStruct &r; // illegal!
    PrintStruct("Before modifying r (values from r)", r);
    PrintStruct("Before modifying r (values from aStruct)", aStruct);
    r.a += 100;
    r.b += 200;
    PrintStruct("After modifying r (values from r)", r);
    PrintStruct("After modifying r (values from aStruct)", aStruct);
}