// Find odd numbers divisible by 5

#include <iostream>
using namespace std;

int main() 
{
    int num;
    bool found = false;

    cout << "Enter 10 integers:" << endl;

    for (int i = 1; i <= 10; i++)
      {
        cin >> num;
        if (num % 2 != 0 && num % 5 == 0)
        {
            cout << num << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;
    return 0;
}
