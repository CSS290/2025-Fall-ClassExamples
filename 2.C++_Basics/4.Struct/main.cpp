// Useless example to show what is a struct
//
// NOTE: there is no "new" keyword invovled in the following code?!
//       where is the memory coming from: the boxes, or storage for the values of the variables. where are they from?
//
#include <iostream>
using namespace std;

struct MyStruct {
    int a;
    int b;
};

class MyClass {
    public:
        int a;
        int b;
};

void PrintStruct(MyStruct s) {  // This is passing by value!
    cout << "From Function MyStruct: a=" << s.a << " b=" << s.b << endl;
}

void PrintClass(MyClass c) {
    cout << "From Function MyClass: a=" << c.a << " b=" << c.b << endl;
}

int main()
{
	MyStruct aStruct;   // You have NEVER seen this in Java! no new-statement
    MyClass aClass;     // STRANGE, here a class, again ... no new-statement

    // Point here is, 
    //        a sturct is a class 
    //        with no functions and all public instance variables

    aStruct.a = 3;
    aStruct.b = 4;

    aClass.a = 5;
    aClass.b = 6;

    cout << "Struct: a=" << aStruct.a << " b=" << aStruct.b << endl;
    cout << "Class:  a=" << aClass.a << " b=" << aClass.b << endl;
    cout << endl;
    cout << "Now passing to functions" << endl;
    PrintStruct(aStruct);
    PrintClass(aClass);
}