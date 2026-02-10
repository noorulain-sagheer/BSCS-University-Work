// Question 14
// Program to determine grade based on marks

#include <iostream>
using namespace std;

int main()
{
    int marks;

    cout << "Enter your marks: ";
    cin >> marks;

    if (marks > 100 || marks < 0)
    {
        cout << "Invalid marks! Please enter a value between 0 and 100." << endl;
        return 1;
    }

    if (marks > 90)
    {
        cout << "Grade: A" << endl;
    } 
    else if (marks >= 86 && marks <= 90) 
    {
        cout << "Grade: A-" << endl;
    } 
    else if (marks >= 81 && marks < 86) 
    {
        cout << "Grade: B+" << endl;
    } 
    else if (marks >= 77 && marks < 81)
    {
        cout << "Grade: B" << endl;
    } 
    else if (marks >= 72 && marks < 77) 
    {
        cout << "Grade: B-" << endl;
    } 
    else if (marks >= 68 && marks < 72) 
    {
        cout << "Grade: C+" << endl;
    } 
    else if (marks >= 63 && marks < 68) 
    {
        cout << "Grade: C" << endl;
    } 
    else if (marks >= 58 && marks < 63)
    {
        cout << "Grade: C-" << endl;
    } 
    else if (marks >= 54 && marks < 58)
    {
        cout << "Grade: D+" << endl;
    } 
    else if (marks >= 50 && marks < 54)
    {
        cout << "Grade: D" << endl;
    } 
    else
    {
        cout << "Grade: F" << endl;
    }

    return 0;
}
