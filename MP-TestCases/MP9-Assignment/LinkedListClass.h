// File: LinkedListClass.h
// Created by ksung on 2025-12-01.
//
// Header file for LinkedListClass
//
// Implements a singly linked list of integers with a dummy head node
// The class supports list manipulation through operators where 
// user can add/remove elements, compare lists, and print lists 
// without exposing internal structure
// 
// Defined operators:
// 
//   == to compare two lists for equality
//   = to assign one list to another, receiver cleared first, deep copy
//
//   [] to access element at given index (0-based)
// 
//   += an integer: to insert an integer to the front of the list
//   += a list: to concatenate another list to this list (other list becomes empty)
//
//   + an integer: create a new list with integer appended at the end
//   + a list: create a new list that is the concatenation of two lists
// 
//   -= to remove an integer (first occurrence), no-op if not found


#pragma once
#include <iostream> // for ostream
using namespace std;

class LinkedListClass {

private:
    // Linked list is implemented using a singly linked list with a dummy head node
    struct Node {
        int data;
        Node *next;
        Node(int val, Node *nxt) : data(val), next(nxt) {}
    };

    string name;  // for debugging purposes
    Node *head;   // dummy head
    Node *tail;   // pointer to the last node
    int size;     // number of elements in the list

    void init_list();
    void clear_list();

    Node* insert(int val);  // Insert at the front

    void copy_list(const LinkedListClass &other); // deep copy from other list

public: 
    // Constructors and Destructor
    LinkedListClass(const string&); 
    LinkedListClass(const LinkedListClass &other);
    ~LinkedListClass();

    // Operators
    bool operator==(const LinkedListClass &other) const;
    LinkedListClass& operator=(const LinkedListClass &other);

    int operator[](int index) const;  // indexing operator
    
    LinkedListClass& operator+=(int val);
    LinkedListClass& operator+=(LinkedListClass &other);

    LinkedListClass operator+(int val);
    LinkedListClass operator+(const LinkedListClass &other);

    LinkedListClass& operator-=(int val) ;

    int list_size() const;
};

// Global function for outputting the list
// Format: [elem1 elem2 elem3 ... ]
extern ostream& operator<<(ostream &out, const LinkedListClass &list);