#include <iostream>
using namespace std;
int main()
{
    char again;
    do 
    {
        int choice;
        cout << "\n===== MENU =====\n";
        cout << "1. Option 1\n";
        cout << "2. Option 2\n";
        cout << "3. Option 3\n";
        cout << "4. Option 4\n";
        cout << "5. Option 5\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
          {
            case 1:
                cout << "You selected Option 1\n";
                break;
            case 2:
                cout << "You selected Option 2\n";
                break;
            case 3:
                cout << "You selected Option 3\n";
                break;
            case 4:
                cout << "You selected Option 4\n";
                break;
            case 5:
                cout << "You selected Option 5\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
        cout << "\nDo you want to continue again (Y/N)? ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    cout << "\nProgram Terminated.\n";
    return 0;
}

