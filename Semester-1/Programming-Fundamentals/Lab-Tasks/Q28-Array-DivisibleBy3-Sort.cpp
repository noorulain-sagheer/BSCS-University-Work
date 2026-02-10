/*Write a C++ program that creates an array “A” having 5 elements (in the main function). Then, the 
program asks the user to enter values in this array. After that, the program should replace each array 
element which is divisible by 3 with new value (by adding 1 to it). In the end, the main program (“main”) 
shows the updated array elements in ascending order. 
Sample Inputs: 
Enter 5 elements in array A: 
4 5 9 8 2 
Sample Outputs: 
Sorted Array 
2 4 6 8 10*/

#include <iostream>
using namespace std;
int main() 
{
    int A[5];
    cout << "Enter 5 elements in array A:\n";
    
    for (int i = 0; i < 5; i++)
      {
        cin >> A[i];
      }
    
    for (int i = 0; i < 5; i++) 
    {
        if (A[i] % 3 == 0) 
        {
            A[i] = A[i] + 1; // Add 1 if divisible by 3
        }
    }

    for (int i = 0; i < 5 - 1; i++)
      {
        for (int j = 0; j < 5 - i - 1; j++) 
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted Array:\n";
    for (int i = 0; i < 5; i++)
      {
        cout << A[i] << " ";
      }
    cout << endl;
    return 0;
}
