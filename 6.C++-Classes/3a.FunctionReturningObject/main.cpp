// File: main.cpp
// Kelvin Sung
// Date: 11/25/2025
// Description: Demonstrates functions returning an instance to an object and reference in C++.
//       Illustrates object creation, copying, destruction, and chaining calls.

#include <iostream>
using namespace std;

class MyClass {
    string name; // for debugging
    int data;

public:
    MyClass(string n, int val) : name(n), data(val) {
        cout << "Construct (Default): " << name << " " << data << endl;
    }

    MyClass(const MyClass &other) : name(other.name + "_copy"), data(other.data) {
        cout << "Construct (Copy): " << name << " " << data << endl;
    }
    
    ~MyClass() {
        cout << "~Destroy: " << name << " " << data << endl;
    }

    // Function that returns a new instance of an object
    MyClass ReturnObj() {
        return MyClass("FromReturn", data + 1);
    }

    // Function that returns a reference to the current object
    MyClass& ReturnRef() {
        data += 1;
        return *this;
    }

    void print(string msg) const {
        cout << msg << ": " << name << ": " << data << endl;
    }   
};


int main() {
    MyClass obj1("Object1", 0);
    cout << endl;

    {
        cout << "================> Calling ReturnObj()" << endl;
        MyClass obj2 = obj1.ReturnObj(); // A new object is created and then destroyed
            // Copy constructor may be called here depending on optimization
    }
    obj1.print("After ReturnObj() from obj2 scope");

    cout << endl;
    cout << "================> Calling ReturnObj() many times!" << endl;
    (obj1.ReturnObj()).ReturnObj(); // What am I doing? "chaining" calls
    ((obj1.ReturnObj()).ReturnObj()).ReturnObj(); // What am I doing? "chaining" calls
    obj1.print("After ReturnObj()");
    cout << endl;

    cout << "================> Calling ReturnRef()" << endl;
    MyClass& refObj = obj1.ReturnRef();
    (refObj.ReturnRef()).ReturnRef(); // chaining on reference
    refObj.ReturnRef().ReturnRef().ReturnRef(); // chaining on reference
    obj1.print("After ReturnRef()");

    cout << endl;
    cout << "================> End of main()" << endl;
    return 0;
}