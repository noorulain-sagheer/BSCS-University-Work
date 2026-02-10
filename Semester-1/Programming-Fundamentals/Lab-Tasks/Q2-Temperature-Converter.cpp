//Q2.Take temperature in Fahrenheit as input from user and display in Celsius C=(F-32)*5/9
#include <iostream>
using namespace std;

int main() 
{
    float fahrenheit, celsius;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;

    celsius = (fahrenheit - 32) * 5 / 9;

    cout << "Temperature in Celsius is: " << celsius << endl;

    return 0;
}
