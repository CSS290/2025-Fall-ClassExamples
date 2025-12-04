// File: main.cpp
// Created by ksung Fall 2025.
// 
// Test driver for LinkedListClass. 
// 
#include <iostream>
#include <iomanip>
#include "LinkedListClass.h"
using namespace std;

// for formatted output
const int WIDTH = 25;

// Function to print the list with a message
// Format: msg [elem1 elem2 elem3 ... ]
void print_list(const LinkedListClass &list, const string &msg) {
    cout << left << setw(WIDTH) << msg << list << endl;
}

// Function to compare two lists and print whether they are equal
void compare_lists(const LinkedListClass &list1, const LinkedListClass &list2, const string &msg) {
    cout << left << setw(WIDTH) << msg;
    if (list1 == list2) {
        cout << "EQUAL" << endl;
    } else {
        cout << "NOT EQUAL" << endl;
    }
}

int main() {
    LinkedListClass list1("list1");

    // testing the += operator
    for (int i = 1; i <= 10; i++) {
        list1 += i; // inserting values 1 to 10
    }
    print_list(list1, "list1 +=: ");

    // testing copy constructor
    LinkedListClass list2(list1);
    print_list(list2, "list2 copied: ");

    // testing the -= operator
    list1 -= 1; // Try removing first element
    list1 -= 3; // removing something from the middle 
    list1 -= 10; // Removing the very last
    print_list(list1, "list1 -=: ");
    cout << endl;

    // testing the == operator
    compare_lists(list1, list2, "List1, List2: ");

    // testing operator chaining
    ((list2 -= 1)-= 3)-= 10;
    print_list(list2, "list2 -= chain: ");
    compare_lists(list1, list2, "List1, List2: ");
    cout << endl;

    // testing assignment operator
    LinkedListClass list3("list3");
    print_list(list3, "list3 empty: ");
    list1 = list3; // assignment
    print_list(list1, "list1 after assignment: ");
    compare_lists(list1, list3, "List1, List3: ");
    cout << endl;

    list1 = list2 + 100; // testing + and assignment operators
    print_list(list1, "list1 = list2 + 100: ");

    list3 += list2; // testing += with another list
    print_list(list3, "list3 += list2: ");
    print_list(list2, "list2 remains: ");

    list3 += list2; // testing += with empty list
    print_list(list3, "list3 += empty: ");
    print_list(list2, "list2 remains: ");
    cout << endl;

    list2 = list1 + list3; // testing + opeator with another list
    print_list(list1, "list1 remains: ");
    print_list(list3, "list3 remains: ");
    print_list(list2, "list2 = list1 + list3: ");

    // Last set of test
    list1 -= 1000; // removing from list1 that is not there
    list1 -= 100; // removing from the end
    list1 -= 9;  // removing from the front
    list1 += 500; // adding to the front
    list1 = list1 + 600; // adding to the end
    print_list(list1, "list1 final ops: ");

    cout << endl;
    return 0;
}