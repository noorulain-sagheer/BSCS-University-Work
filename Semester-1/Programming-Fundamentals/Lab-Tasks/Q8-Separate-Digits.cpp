// Program to separate digits of a four-digit number

#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter a four-digit number: ";
    cin >> number;

    // Check if number is 4-digit
    if (number < 1000 || number > 9999) {
        cout << "Error! Please enter a four-digit number." << endl;
        return 1;
    }

    // Extract each digit
    int digit1 = number / 1000;          // Thousands place
    int digit2 = (number / 100) % 10;    // Hundreds place
    int digit3 = (number / 10) % 10;     // Tens place
    int digit4 = number % 10;             // Ones place

    // Display digits line by line
    cout << digit1 << endl;
    cout << digit2 << endl;
    cout << digit3 << endl;
    cout << digit4 << endl;

    return 0;
}
