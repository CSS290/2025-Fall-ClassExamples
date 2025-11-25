#include <iostream>
using namespace std;

class MyArrayClass {
    //
    friend ostream& operator<<(ostream& os, const MyArrayClass& myArray);
    //      Note: this global funciton can perform the proper printing 
    //            of MyArrayClass objects without being a friend!
    //            But, we need to print the address of "arr", so we make it a friend.
private:
    int *arr;
    int size;

    // Helper function to initialize the array  
    // Precondition: arr is nullptr
    void initializeArray() {
        if (arr == nullptr)
            arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;  // Initialize all elements to 0
        }
    }

    // Helper function to copy array from another object
    // Precondition: size and arr are properly initialize
    //          size and other.size must be the same
    void copyArray(const MyArrayClass &other) {
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
public:
    MyArrayClass() : size(10), arr(nullptr) {  // Default size is 10
        initializeArray();
    }

    MyArrayClass(int s) : size(s), arr(nullptr) {
        initializeArray();
    }

    // Copy constructor: This is performing "Deep Copy"
    //      Rules:
    //         1. Allocate new memory for the new object
    //         2. Copy the data from the source object to the new object
    MyArrayClass(const MyArrayClass &other) : size(other.size), arr(nullptr) {
        arr = new int[size];  // Allocate new memory
        copyArray(other);
    }

    // Destructor
    ~MyArrayClass() {
        if (arr != nullptr)
            delete[] arr;  // Free the dynamically allocated memory
    }
    
    int operator[](int index) const {
        return arr[index];
    }

    int& operator[](int index) {
        return arr[index];
    }

    // This is performing "Deep Comparison"
    bool operator==(const MyArrayClass& other) const {
        if (size != other.size)
            return false;
        for (int i = 0; i < size; i++) {
            if (arr[i] != other.arr[i])
                return false;
        }
        return true;
    }

    // Assignment operator rules:
    //    1. Check to make sure we are not performing a self-assignment  (a = a)
    //    2. Free any existing dynamically allocated memory
    // then similar to copy constructor:
    //    3. Allocate new memory if necessary
    //    4. Copy the data from the source object to this object
    void operator=(const MyArrayClass& other) {
        if (this != &other) {  // Self-assignment check
            if (size != other.size) {
                if (arr != nullptr)
                    delete[] arr;  // Free existing memory
                size = other.size;
                arr = new int[size];  // Allocate new memory
            }
            copyArray(other);
        }
    }

    // how would we define ">" operators?
    
    int getSize() const {
        return size;
    }  
};

// this is a global function
ostream& operator<<(ostream& os, const MyArrayClass& myArray) {
    os << "arr=" << myArray.arr << ": ";
    for (int i = 0; i < myArray.getSize(); i++) {
        os << myArray[i] << " ";
    }
    return os;
}