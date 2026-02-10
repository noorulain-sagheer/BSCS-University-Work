// Program to calculate salary and medical charges for Permanent/Daily Wages Employee

#include <iostream>
using namespace std;

int main() 
{
    int empType;
    char choice;
    int hoursWorked;
    double salary, medicalCharges;

    // Step 1: Select employee type
    cout << "Select Employee Type:\n";
    cout << "1. Permanent Employee\n";
    cout << "2. Daily Wages Employee\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> empType;

    // Step 2: Display menu
    cout << "\nTransaction Menu:\n";
    cout << "a. Calculate Salary\n";
    cout << "b. Calculate Medical Charges\n";
    cout << "Enter your choice (a/b): ";
    cin >> choice;

    if (empType == 1)
    {
        // Permanent Employee
        cout << "Enter hours worked: ";
        cin >> hoursWorked;
        salary = hoursWorked * 800;

        if (choice == 'a' || choice == 'A') 
        {
            cout << "Permanent Employee Salary: Rs. " << salary << endl;
        } 
        else if (choice == 'b' || choice == 'B') 
        {
            medicalCharges = salary * 0.05; // 5% medical
            cout << "Permanent Employee Medical Charges: Rs. " << medicalCharges << endl;
        } 
        else
        {
            cout << "Invalid choice!" << endl;
        }

    } 
    else if (empType == 2) 
    {
        // Daily Wages Employee
        cout << "Enter hours worked: ";
        cin >> hoursWorked;
        salary = hoursWorked * 400;

        if (choice == 'a' || choice == 'A') 
        {
            cout << "Daily Wages Employee Salary: Rs. " << salary << endl;
        } 
        else if (choice == 'b' || choice == 'B') 
        {
            medicalCharges = salary * 0.03; // 3% medical
            cout << "Daily Wages Employee Medical Charges: Rs. " << medicalCharges << endl;
        } 
        else
        {
            cout << "Invalid choice!" << endl;
        }
    } 
    else
    {
        cout << "Invalid Employee Type!" << endl;
    }

    return 0;
}
