//Program to calculate factorial of a number (N <= 10)

#include <iostream>
using namespace std;
int main() 
{
    int num;
    double fact = 1;
    cout << "Enter a number (<=10): ";
    cin >> num;
    if (num < 0 || num > 10) 
    {
        cout << "Invalid input! Please enter number between 0 and 10." << endl;
    }
    else
    {
        for (int i = 1; i <= num; i++)
          {
            fact = fact * i;
          }

        cout << "Factorial of " << num << " is: " << fact << endl;
    }
    return 0;
}
