// File: LinkedListClass.cpp
// Created by ksung on 2025-12-01.
//
// Your MP9 assignment is to complete the implementaiton of the LinkedListClass methods
// in this file according to the specifications in LinkedListClass.h
// You may add helper private methods if needed.
//
#include <iostream>
#include "LinkedListClass.h"
using namespace std;


// --- Private methods

// Function to copy another list into this list
// Precondition: list is empty with only dummy header
//               other list is properly initialized with a dummy head
// Postcondition: this list contains a deep copy of other list's elements
void LinkedListClass::copy_list(const LinkedListClass &other) {
    // This function you must implement in order to have a properly functioning 
    // copy constructor and assignment operator
}

// This is to show you that, since Node is a private struct, you need to
// qualify it with LinkedListClass:: when implementing outside the class
// You can choose to implement this function, or, simply ignore it
LinkedListClass::Node* LinkedListClass::insert(int val) {
    return nullptr;
}

// --- Public methods

// Assignment operator
// Precondition: other is properly initialized with a dummy header
// Postcondition: this list is first emptied then a deep copy of other list
// Returns reference to this list
LinkedListClass& LinkedListClass::operator=(const LinkedListClass &other) {
    return *this;
}

// Equality operator
// Precondition: other is properly initialized with a dummy header
// Postcondition: returns true if both lists have the same elements in the same order
// Returns the result of the comparison
bool LinkedListClass::operator==(const LinkedListClass &other) const {
    return false;
}

// Insert operator for integer
// Precondition: list is properly initialized with a dummy head
// Postcondition: integer val is inserted at the front of the list
// Returns reference to this list
LinkedListClass& LinkedListClass::operator+=(int val) {
    return *this;
}

// Remove operator for integer
// Precondition: list is properly initialized with a dummy head
// Postcondition: first occurrence of integer val is removed from the list
//                no-op if val not found
// Returns reference to this list
LinkedListClass& LinkedListClass::operator-=(int val) {
    return *this;
}

// Insert operator for another list
// Precondition: both lists are properly initialized with dummy heads  
// Postcondition: other list is concatenated to this list
//                other list becomes empty
// Returns reference to this list
LinkedListClass& LinkedListClass::operator+=(LinkedListClass &other) {   
    return *this;
}

// Addition operator for integer
// Precondition: list is properly initialized with a dummy head
// Postcondition: a new list is created that is a copy of this list
//                with integer val appended at the end
// Returns the new list
LinkedListClass LinkedListClass::operator+(int val) {
    LinkedListClass newList = LinkedListClass(*this);
    return newList;
}

// Addition operator for another list
// Precondition: both lists are properly initialized with dummy heads
// Postcondition: a new list is created that is the concatenation of
//                this list and other list
// Returns the new list
LinkedListClass LinkedListClass::operator+(const LinkedListClass &other) {
    LinkedListClass newList = LinkedListClass(*this);
    return newList;
}

// Indexing operator
// Precondition: list is properly initialized with a dummy head
// Postcondition: returns the integer at the given index (0-based)
//                returns -1 if index is out of bounds
int LinkedListClass::operator[](int index) const {
    return -1; 
}