// Program to sort 3 characters in ascending or descending order

#include <iostream>
using namespace std;

int main()
{
    char ch1, ch2, ch3;
    int choice;

    // Step 1: Input 3 characters
    cout << "Enter first character: ";
    cin >> ch1;
    cout << "Enter second character: ";
    cin >> ch2;
    cout << "Enter third character: ";
    cin >> ch3;

    // Step 2: Display menu
    cout << "\nSelect sorting option:\n";
    cout << "1. Sort in Ascending order\n";
    cout << "2. Sort in Descending order\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    // Step 3: Sorting logic (simple if-else)
    char temp;

    // Ascending order sorting using simple swapping
    if (choice == 1) 
    {
        if (ch1 > ch2) 
        {
          temp = ch1;
          ch1 = ch2;
          ch2 = temp;
        }
        if (ch2 > ch3) 
        {
          temp = ch2;
          ch2 = ch3;
          ch3 = temp;
        }
        if (ch1 > ch2) 
        {
          temp = ch1;
          ch1 = ch2;
          ch2 = temp;
        }

        cout << "Characters in Ascending order: " << ch1 << " " << ch2 << " " << ch3 << endl;
    } 
    else if (choice == 2) 
    {
        // Descending order
        if (ch1 < ch2) 
        {
          temp = ch1;
          ch1 = ch2;
          ch2 = temp;
        }
        if (ch2 < ch3) 
        {
          temp = ch2; 
          ch2 = ch3;
          ch3 = temp;
        }
        if (ch1 < ch2) 
        {
          temp = ch1;
          ch1 = ch2;
          ch2 = temp;
        }

        cout << "Characters in Descending order: " << ch1 << " " << ch2 << " " << ch3 << endl;
    } 
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
