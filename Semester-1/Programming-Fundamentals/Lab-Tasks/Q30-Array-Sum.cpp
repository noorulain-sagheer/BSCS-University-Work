/*Write a C++ program which calculates sum of each column and row separately. For this, first create a 2D 
array (3 rows, 5 columns) and then ask the user to input values in the array. After that, first calculate 
sum of each row separately and display that sum. Then, calculate sum of each column separately and 
display that sum on the screen. To achieve such output, you need to follow the following instructions.*/

#include <iostream>
using namespace std;
int main() 
{
    int arr[3][5]; 
    cout << "Enter values for 3x5 array:\n";
    for (int i = 0; i < 3; i++) 
    {       
        for (int j = 0; j < 5; j++)
        {   
            cin >> arr[i][j];
        }
    }
    cout << "\nSum of each row:\n";
    for (int i = 0; i < 3; i++)
      {
        int rowSum = 0;
        for (int j = 0; j < 5; j++) 
        {
            rowSum += arr[i][j];
        }
        cout << "Row " << i+1 << " sum: " << rowSum << endl;
    }
    cout << "\nSum of each column:\n";
    for (int j = 0; j < 5; j++) 
    {
        int colSum = 0;
        for (int i = 0; i < 3; i++) 
        {
            colSum += arr[i][j];
        }
        cout << "Column " << j+1 << " sum: " << colSum << endl;
    }
    return 0;
}
