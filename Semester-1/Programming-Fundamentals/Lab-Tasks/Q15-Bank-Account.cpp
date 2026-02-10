// Program to simulate a bank account (Current / Savings)

#include <iostream>
using namespace std;

int main() 
{
    int accountType;
    double balance;
    char transaction;
    double amount;

    // Step 1: Select account type
    cout << "Select Account Type:\n";
    cout << "1. Current Account\n";
    cout << "2. Savings Account\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> accountType;

    if (accountType == 1)
    {
        // Current Account
        balance = 2000;
        cout << "Current Account opened with initial balance: Rs. " << balance << endl;
    } 
    else if (accountType == 2) 
    {
        // Savings Account
        balance = 5000;
        cout << "Savings Account opened with initial balance: Rs. " << balance << endl;
    } 
    else
    {
        cout << "Invalid account type!" << endl;
        return 1;
    }

    // Step 2: Transaction Menu
    cout << "\nTransaction Menu:\n";
    cout << "a. Deposit money\n";
    cout << "b. Withdraw money\n";
    cout << "Enter your choice (a/b): ";
    cin >> transaction;

    if (transaction == 'a' || transaction == 'A') 
    {
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount <= 0) 
        {
            cout << "Invalid deposit amount!" << endl;
        } else
        {
            balance += amount;
            cout << "Deposit successful. New balance: Rs. " << balance << endl;
        }
    } 
    else if (transaction == 'b' || transaction == 'B')
    {
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        // Determine max withdrawal limit
        double maxWithdraw = (accountType == 1) ? 10000 : 25000;
        double minBalance = 500;

        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount!" << endl;
        } 
        else if (amount > maxWithdraw)
        {
            cout << "Cannot withdraw more than the maximum limit for this account!" << endl;
        } 
        else if (amount > (balance - minBalance)) 
        {
            cout << "Insufficient balance! Minimum Rs. " << minBalance << " must remain." << endl;
        } 
        else
        {
            balance -= amount;
            cout << "Withdrawal successful. New balance: Rs. " << balance << endl;
        }
    } 
    else
    {
        cout << "Invalid transaction choice!" << endl;
    }

    return 0;
}
