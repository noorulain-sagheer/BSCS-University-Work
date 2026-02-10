/*Write a function to print the diamond of size n. n will be taken input from user and pass as an argument 
in function by reference. 
   *
  ***
 *****
*******
 *****
  ***
   *

*/
#include <iostream>
using namespace std;
void printDiamond(int &n) 
{
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n - i; j++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << endl;
    }

    for (int i = n - 1; i >= 1; i--)
      {
        for (int j = 1; j <= n - i; j++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << endl;
    }
}

int main() 
{
    int size;
    cout << "Enter diamond size: ";
    cin >> size;
    printDiamond(size); 
    return 0;
}
