/*Write a C++ program that creates an array “A” having 5 elements (in the main function). Then, the 
program asks the user to enter values in this array. After that, the program should ask question from 
user are you wanted to sort ascending or descending order kindly enter your choice that’s you want to 
search in the array, also compute the sum of array for the ascending order and difference of array for 
the descending order.  
Sample Inputs: 
Enter 5 elements in array A:  
4 5 9 8 2 
Press 1 for ascending and 2 for descending order 
1 
 
Sample Outputs: 
Ascending order array  
2 4 5 8 9*/

#include <iostream>
using namespace std;
int main()
{
    int A[5];
    int choice;
    cout << "Enter 5 elements in array A:\n";
    for (int i = 0; i < 5; i++) 
    {
        cin >> A[i];
    }
    cout << "Press 1 for ascending and 2 for descending order: ";
    cin >> choice;

    for (int i = 0; i < 5 - 1; i++) 
    {
        for (int j = 0; j < 5 - i - 1; j++) 
        {
            if ((choice == 1 && A[j] > A[j + 1]) || (choice == 2 && A[j] < A[j + 1])) 
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    if (choice == 1) 
    {
        cout << "\nAscending order array:\n";
        int sum = 0;
        for (int i = 0; i < 5; i++)
          {
            cout << A[i] << " ";
            sum += A[i]; 
        }
        cout << "\nSum of array: " << sum << endl;
    } 
    else if (choice == 2)
    {
        cout << "\nDescending order array:\n";
        int diff = A[0]; // start with first element
        for (int i = 0; i < 5; i++)
          {
            cout << A[i] << " ";
            if (i > 0) diff -= A[i]; // compute difference for descending
        }
        cout << "\nDifference of array: " << diff << endl;
    } 
    else
    {
        cout << "Invalid choice!" << endl;
    }
    return 0;
}
