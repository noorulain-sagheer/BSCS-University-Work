/*Write the definition of a void function that takes as input two decimal numbers. If the first number is 
nonzero, it outputs the second number divided by the first number; otherwise, it outputs a message 
indicating that the second number cannot be divided by the first number because the first number is 0.*/
#include <iostream>
using namespace std;
void divideNumbers(double num1, double num2) 
{
    if (num1 != 0)
    {
        cout << "Result: " << num2 / num1 << endl;
    }
    else 
    {
        cout << "Cannot divide by zero!" << endl;
    }
}
int main() 
{
    double a, b;
    cout << "Enter two decimal numbers:\n";
    cin >> a >> b;
    divideNumbers(a, b);
    return 0;
}
