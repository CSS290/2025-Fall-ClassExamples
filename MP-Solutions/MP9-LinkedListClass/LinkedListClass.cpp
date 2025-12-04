// File: LinkedListClass.cpp
// Created by ksung on 2025-12-01.
//
// This file contains implementation of LinkedListClass methods
#include <iostream>
#include "LinkedListClass.h"
using namespace std;

// --- Private methods 

// Function to insert a new node with value val at the end of the list
// Precondition: list is properly initialized with a dummy head
// Postcondition: new node added at the end, tail updated, size incremented
LinkedListClass::Node* LinkedListClass::append(int val) {
    Node *newNode = new Node(val, nullptr);
    tail->next = newNode;
    tail = newNode;
    size++;
    return newNode;
}

// Function to insert a new node with value val at the front of the list
// Precondition: list is properly initialized with a dummy head
// Postcondition: new node added at the front, head updated, size incremented
LinkedListClass::Node* LinkedListClass::insert(int val) {
    Node *newNode = new Node(val, nullptr);
    newNode->next = head->next;
    head->next = newNode;
    size++;
    return newNode;
}

// Function to get the node at a specific index (0-based)
// Precondition: index is non-negative
// Postcondition: returns pointer to the node at index, or nullptr if index >= size
LinkedListClass::Node* LinkedListClass::get_node_at(int index) const {
    Node *current = head->next; // skip dummy head
    if (index < size) {
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    } else {
        current = nullptr;
    }
    return current;
}

// Function to remove the first node with value val
// Precondition: list is properly initialized with a dummy head
// Postcondition: first node with value val is removed from the list, size decremented
//                returns pointer to the removed node, or nullptr if not found
LinkedListClass::Node* LinkedListClass::remove_node(int val) {
    Node *current = head;
    Node *toRemove = nullptr;
    while ((current->next != nullptr) && (toRemove == nullptr)) {
        if (current->next->data == val) {
            toRemove = current->next;
            current->next = toRemove->next;
            toRemove->next = nullptr;
            size--;
            // if this is the last node, must update the tail pointer
            if (toRemove == tail) {
                tail = current;
            }
        } else {
            current = current->next;
        }
    }
    
    return toRemove;
}

// Function to delete the first node with value val
// Precondition: list is properly initialized with a dummy head
// Postcondition: first node with value val is deleted from the list, size decremented
//               no-op if not found
void LinkedListClass::delete_node(int val) {
    Node *toDelete = remove_node(val);
    if (toDelete != nullptr) {
        delete toDelete;
    }
}

// Function to copy another list into this list
// Precondition: list is empty with only dummy header
//               other list is properly initialized with a dummy head
// Postcondition: this list contains a deep copy of other list's elements
void LinkedListClass::copy_list(const LinkedListClass &other) {
    Node *current = other.head->next;
    while (current != nullptr) {
        this->append(current->data);
        current = current->next;
    }
}

// --- Public methods

// Assignment operator
// Precondition: other is properly initialized with a dummy header
// Postcondition: this list is first emptied then a deep copy of other list
// Returns reference to this list
LinkedListClass& LinkedListClass::operator=(const LinkedListClass &other) {
    if (this != &other) {
        clear_list();
        copy_list(other);
    }
    return *this;
}

// Equality operator
// Precondition: other is properly initialized with a dummy header
// Postcondition: returns true if both lists have the same elements in the same order
// Returns the result of the comparison
bool LinkedListClass::operator==(const LinkedListClass &other) const {
    if (this->size != other.size) {
        return false;
    }
    Node *current1 = this->head->next; // skip dummy head
    Node *current2 = other.head->next; // skip dummy head
    while (current1 != nullptr) {
        if ((current2 == nullptr) || (current1->data != current2->data) ) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}

// Insert operator for integer
// Precondition: list is properly initialized with a dummy head
// Postcondition: integer val is inserted at the front of the list
// Returns reference to this list
LinkedListClass& LinkedListClass::operator+=(int val) {
    insert(val);
    return *this;
}

// Remove operator for integer
// Precondition: list is properly initialized with a dummy head
// Postcondition: first occurrence of integer val is removed from the list
//                no-op if val not found
// Returns reference to this list
LinkedListClass& LinkedListClass::operator-=(int val) {
    delete_node(val);
    return *this;
}

// Insert operator for another list
// Precondition: both lists are properly initialized with dummy heads  
// Postcondition: other list is concatenated to this list
//                other list becomes empty
// Returns reference to this list
LinkedListClass& LinkedListClass::operator+=(LinkedListClass &other) {
    tail->next = other.head->next; // skip dummy head
    tail = other.tail;
    size += other.size;

    other.head->next = nullptr; // other list is now empty
    other.tail = other.head;
    other.size = 0;
    
    return *this;
}

// Addition operator for integer
// Precondition: list is properly initialized with a dummy head
// Postcondition: a new list is created that is a copy of this list
//                with integer val appended at the end
// Returns the new list
LinkedListClass LinkedListClass::operator+(int val) {
    LinkedListClass newList = LinkedListClass(*this);
    newList.append(val);
    return newList;
}

// Addition operator for another list
// Precondition: both lists are properly initialized with dummy heads
// Postcondition: a new list is created that is the concatenation of
//                this list and other list
// Returns the new list
LinkedListClass LinkedListClass::operator+(const LinkedListClass &other) {
    LinkedListClass newList = LinkedListClass(*this);
    Node *current = other.head->next; // skip dummy head
    while (current != nullptr) {
        newList.append(current->data);
        current = current->next;
    }
    return newList;
}

// Indexing operator
// Precondition: list is properly initialized with a dummy head
// Postcondition: returns the integer at the given index (0-based)
//                returns -1 if index is out of bounds
int LinkedListClass::operator[](int index) const {
    Node *node = get_node_at(index);
    if (node != nullptr) {
        return node->data;
    } else {
        return -1;
    }
}