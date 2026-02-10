/*Write a program that creates and then reads a matrix of 5 rows and 5 columns of type int. while reading; 
the program should not accept values greater than 100. For any entered value greater than 100, the 
program should ask for input repeatedly. After reading all numbers, the system should find the smallest 
number in the matrix and its location or index values. The program should print the smallest number 
and its location (row and column) and also print their count.*/
#include <iostream>
using namespace std;

int main() 
{
    int matrix[5][5];
    int smallest;
    int count = 0;
    int smallestRow = -1, smallestCol = -1;

    cout << "Enter 5x5 matrix (values <= 100 only):\n";
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            int value;
            do 
            {
                cin >> value;
                if (value > 100) 
                {
                    cout << "Value cannot be greater than 100. Enter again: ";
                }
            } while (value > 100);
            matrix[i][j] = value;
        }
    }
    smallest = matrix[0][0];
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            if (matrix[i][j] < smallest) 
            {
                smallest = matrix[i][j];
            }
        }
    }
    cout << "\nSmallest number: " << smallest << endl;
    cout << "Location(s) (row, column):\n";
    for (int i = 0; i < 5; i++)
      {
        for (int j = 0; j < 5; j++) 
        {
            if (matrix[i][j] == smallest) 
            {
                cout << "(" << i+1 << ", " << j+1 << ")\n";
                count++;
            }
        }
    }
    cout << "Total occurrences: " << count << endl;
    return 0;
}
