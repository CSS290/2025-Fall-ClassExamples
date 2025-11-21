// File: LinkedListClass GivenCode.cpp
// Created by ksung on 2025-12-01.
// 
// This file contains implementation of LinkedListClass methods
// that you cannot change for MP9. 
//
#include <iostream>
#include "LinkedListClass.h"
using namespace std;


// Constructor
LinkedListClass::LinkedListClass(const string &n)
    : name(n), head(nullptr), tail(nullptr), size(0)
{ 
    init_list(); 
}

// Copy constructor
LinkedListClass::LinkedListClass(const LinkedListClass &other) 
    : name(other.name + "_copy"), head(nullptr), tail(nullptr), size(0)
{
    init_list();
    copy_list(other);
}

// Function to initialize the list
// Precondition: head and tail are nullptr
// Postcondition: dummy head created, head and tail set, size = 0
void LinkedListClass::init_list() {
    head = new Node(0, nullptr); // dummy head
    tail = head;
    size = 0;
}

// Function clear the list
// Precondition: dummy header exists
// Postcondition: all nodes except dummy header are deleted
// DOES NOT delete the dummy head
void LinkedListClass::clear_list() {
    Node *current = head->next;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head->next = nullptr;
    tail = head;
    size = 0;
}

// Destructor
LinkedListClass::~LinkedListClass() { 
    cout << "List: " << name << " size(" << size << ") destroyed." << endl;
    clear_list(); 
    // now delete the dummy head
    delete head;
    head = tail = nullptr;
}

// Function to copy another list into this list
// Precondition: none
int LinkedListClass::list_size() const {
    return size;
}

// Global function for outputting the list
// Format: [elem1 elem2 elem3 ... ]
ostream& operator<<(ostream &os, const LinkedListClass &list) {
    os << "[";
    for (int i = 0; i < list.list_size(); i++) {
        os << list[i] << " ";
    }
    os << "]";
    return os;
}