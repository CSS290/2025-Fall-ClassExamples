// Date: 9/25/2025
// Author: K. Sung
// Purpose:
// Take a look at the optional argc and argv, parameters to the main function
// Now, do we have some sense why or how the following works?
//    WinWord.exe MyDoc.docx
#include <iostream>

using namespace std;

// The char* argv[] looks super intimidating!, 
// no worries, we will look at this sometime next week
// when looking at pointers and arrays
//
// Important to note: delimiter is space!!, Try:
//   a.out wait, can-some-one-help-me? This is strange
//
// When writing code, space is also delimiter!!
// So, avoid including spaces as part of an identifier!
// 
// My_Name: is ok
// My Name: creates potential trouble!
// 
int main(int argc, char* argv[])
{
    cout << "argc=" << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "]=" << argv[i] << endl;
    }
}