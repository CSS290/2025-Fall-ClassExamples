// First simple demo
// Date: 9/25/2025
// Author: K. Sung
// Purpose: Compare with Java HelloWorld
//       Show basic input/output

#include <iostream>
using namespace std;
    // these two statements is equivalent to: 
    //      import java.lang.System;
    //      import java.util.Scanner;
    // using is allows shorthand, we will discuss this later

int main() {
    int a;
    cout << "Hello World\n";

    cout << "Please enter an integer: ";
    cin >> a;   // read an integer from keyboard and store it in a
    cout << "You entered: " << a << endl;       
	
	return 0;
}


// Compare with Java
/*

public class HelloWorld {
    public static void main(String[] args) {
        int a;
        System.out.println("Hello World!");

        System.out.print("Please enter an integer: ");
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();  // read an integer from keyboard and store it in a
        System.out.println("You entered: " + a);
    }
}


1. No class definition
2. args argument is missing from main() [more about this later]
3. main is defined as "int" instead of "void"
4. The  wired symbols: << and >>
5. instead of "System.out", we have "cout"
6. instead of "System.in", we have "cin"

Algorithmically, they are the same!!


*/