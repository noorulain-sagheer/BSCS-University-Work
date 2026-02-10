//Make a program which will read an integer variable count from user and then write each of the following statements in cout and note the output. 
 
//1. ++count,  
//2. -- count,  
//3. count ++,  
//4. count - - 

//CODE:
#include <iostream>
using namespace std;

int main() {
    int count;

    cout << "Enter an integer value for count: ";
    cin >> count;

    cout << "Initial value of count: " << count << endl;

    // Pre-increment
    cout << "1. ++count = " << ++count << endl;

    // Pre-decrement
    cout << "2. --count = " << --count << endl;

    // Post-increment
    cout << "3. count++ = " << count++ << endl;

    // Show value after post-increment
    cout << "   Value of count now: " << count << endl;

    // Post-decrement
    cout << "4. count-- = " << count-- << endl;

    // Show value after post-decrement
    cout << "   Value of count now: " << count << endl;

    return 0;
}
