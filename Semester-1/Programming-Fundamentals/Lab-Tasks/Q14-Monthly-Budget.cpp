// Program to calculate monthly budget charges based on salary

#include <iostream>
using namespace std;

int main()
{
    double salary;
    int choice;
    double charges;

    cout << "Enter your monthly salary: ";
    cin >> salary;

    cout << "\nSelect the option to calculate charges:\n";
    cout << "1. Gas bill (10% of salary)\n";
    cout << "2. Electricity bill (5% of salary)\n";
    cout << "3. Fueling charges (10% of salary)\n";
    cout << "4. House rent charges (15% of salary)\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch (choice)
      {
        case 1:
            charges = salary * 0.10;
            cout << "Gas bill charges: Rs. " << charges << endl;
            break;
        case 2:
            charges = salary * 0.05;
            cout << "Electricity bill charges: Rs. " << charges << endl;
            break;
        case 3:
            charges = salary * 0.10;
            cout << "Fueling charges: Rs. " << charges << endl;
            break;
        case 4:
            charges = salary * 0.15;
            cout << "House rent charges: Rs. " << charges << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
