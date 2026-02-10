// Perform Addition, Subtraction, Multiplication, Division and Square
#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cout << "Enter first integer: ";
    cin >> num1;

    cout << "Enter second integer: ";
    cin >> num2;

    // Addition
    cout << "Addition: " << num1 + num2 << endl;

    // Subtraction
    cout << "Subtraction: " << num1 - num2 << endl;

    // Multiplication
    cout << "Multiplication: " << num1 * num2 << endl;

    // Division (handle division by zero)
    if (num2 != 0) {
        cout << "Division: " << num1 / num2 << endl;
    } else {
        cout << "Division: Error! Division by zero." << endl;
    }

    // Square of each number
    cout << "Square of first number: " << num1 * num1 << endl;
    cout << "Square of second number: " << num2 * num2 << endl;

    return 0;
}
