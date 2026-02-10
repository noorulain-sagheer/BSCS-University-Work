#include <iostream>
using namespace std;
int main()
{
    char arr[5];
    char delChar;
    cout << "Please enter 5 alphabets:\n";
    
    for (int i = 0; i < 5; i++)
      {
        cin >> arr[i];
      }
    cout << "Alphabet to be deleted: ";
    cin >> delChar;
    cout << "After Deletion Array:\n";
    for (int i = 0; i < 5; i++) 
    {
        if (arr[i] != delChar) 
        {
            cout << arr[i];
        }
    }
    cout << endl;
    return 0;
}
