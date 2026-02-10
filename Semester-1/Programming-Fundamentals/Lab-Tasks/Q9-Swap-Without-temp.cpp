// Question 12
// Program to swap two variables without using a third variable

#include <iostream>
using namespace std;

int main() 
{
    int a, b;

    cout << "Enter first number (a): ";
    cin >> a;

    cout << "Enter second number (b): ";
    cin >> b;

    cout << "Before swapping: a = " << a << ", b = " << b << endl;

    // Swap without third variable
    a = a + b;  // Step 1
    b = a - b;  // Step 2
    a = a - b;  // Step 3

    cout << "After swapping: a = " << a << ", b = " << b << endl;

    return 0;
}
