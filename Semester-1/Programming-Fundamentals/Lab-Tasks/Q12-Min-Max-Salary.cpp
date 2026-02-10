// Question 15
// Program to find maximum and minimum salary among 10 employees

#include <iostream>
using namespace std;

int main() 
{
    const int SIZE = 10;
    double salaries[SIZE];

    // Input salaries
    cout << "Enter salaries of 10 employees:" << endl;
    for (int i = 0; i < SIZE; i++) 
    {
        cout << "Salary of employee " << (i + 1) << ": ";
        cin >> salaries[i];
    }

    // Initialize max and min
    double maxSalary = salaries[0];
    double minSalary = salaries[0];

    // Find max and min
    for (int i = 1; i < SIZE; i++)
      {
        if (salaries[i] > maxSalary)
            maxSalary = salaries[i];
        if (salaries[i] < minSalary)
            minSalary = salaries[i];
    }

    // Display results
    cout << "\nMaximum Salary: Rs. " << maxSalary << endl;
    cout << "Minimum Salary: Rs. " << minSalary << endl;

    return 0;
}
