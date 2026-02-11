/*Write a program to calculate the weekly gross earnings for an employee. If the employee works more than 
40 hours during the week, the overtime pay rate for the extra hours is 130 percent of the base pay rate. Take 
“hours worked” and “hour rate” as input from the user.*/
#include <iostream>
using namespace std;
int main() 
{
    double hoursWorked, hourlyRate;
    double grossPay;
    cout << "Enter hours worked in a week: ";
    cin >> hoursWorked;
    cout << "Enter hourly pay rate: ";
    cin >> hourlyRate;
    if (hoursWorked <= 40) 
    {
        grossPay = hoursWorked * hourlyRate;
    }
    else 
    {
        double overtimeHours = hoursWorked - 40;
        double overtimeRate = hourlyRate * 1.3; 
        grossPay = (40 * hourlyRate) + (overtimeHours * overtimeRate);
    }
    cout << "Weekly Gross Earnings: " << grossPay << endl;
    return 0;
}
