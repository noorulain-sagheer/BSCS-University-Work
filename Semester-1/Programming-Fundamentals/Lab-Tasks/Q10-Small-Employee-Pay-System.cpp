// Question 13
// Program to compute pay for retired and employed employees

#include <iostream>
using namespace std;

int main() 
{
    int choice;
    
    cout << "Employee Type Menu: \n";
    cout << "1. Retired Employee\n";
    cout << "2. Employed Employee\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1)
    {
        // Retired Employee
        int age;
        int pension;

        cout << "Enter age of retired employee: ";
        cin >> age;

        if (age >= 60 && age <= 70) 
        {
            pension = 30000;
        } else if (age > 70)
        {
            pension = 40000;
        } else 
        {
            pension = 0;
            cout << "Employee not eligible for pension.\n";
        }

        if (pension > 0)
            cout << "Retired Employee Pension: Rs. " << pension << endl;

    }
    else if (choice == 2) 
    {
        // Employed Employee
        int workedHours;
        int dailyPay = 1000;
        int grossPay;

        cout << "Enter total worked hours for the day: ";
        cin >> workedHours;

        if (workedHours <= 8)
        {
            grossPay = dailyPay; // fixed 8 hours pay
        } else 
        {
            int extraHours = workedHours - 8;
            if (extraHours > 3) extraHours = 3; // max 3 hours extra
            grossPay = dailyPay + extraHours * 300;
        }

        cout << "Employed Employee Gross Pay: Rs. " << grossPay << endl;

    }
    else 
    {
        cout << "Invalid choice! Please select 1 or 2." << endl;
    }

    return 0;
}
