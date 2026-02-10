/*Write a C++ program that creates a 2D array having 4 rows and 4 columns. Then, ask the user to input 
values for the 2D array or matrix. After that, the program should calculate transpose of a matrix. 
Transpose is basically calculated by changing rows of matrix into columns and columns into rows. After 
calculating, display the final matrix.*/
#include <iostream>
using namespace std;
int main() 
{
    int matrix[4][4], transpose[4][4];
    cout << "Enter values for 4x4 matrix:\n";
    for (int i = 0; i < 4; i++) 
    {       
        for (int j = 0; j < 4; j++)
          {   
            cin >> matrix[i][j];
          }
    }
    for (int i = 0; i < 4; i++)
      {
        for (int j = 0; j < 4; j++) 
        {
            transpose[j][i] = matrix[i][j];
        }
      }
    cout << "\nTranspose of the matrix:\n";
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            cout << transpose[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
