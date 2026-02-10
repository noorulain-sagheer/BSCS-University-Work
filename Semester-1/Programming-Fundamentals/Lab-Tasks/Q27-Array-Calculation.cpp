#include <iostream>
using namespace std;
int main() 
{
    int A[20], B[20];
    cout << "Enter 20 integers for array A:\n";
    
    for (int i = 0; i < 20; i++) 
    {
        cin >> A[i];
    }
  
    for (int i = 0; i < 20; i++) 
    {
        B[i] = 0;
    }
    for (int i = 0; i < 20; i++) 
    {
        B[i] = (A[i] - 2) * (A[i] - 2);
    }
    cout << "\nValues in array B:\n";
    for (int i = 0; i < 20; i++) 
    {
        cout << B[i] << " ";
    }
    cout << "\n\nOdd values in array B:\n";
    for (int i = 0; i < 20; i++) 
    {
        if (B[i] % 2 != 0) 
        {
            cout << B[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
