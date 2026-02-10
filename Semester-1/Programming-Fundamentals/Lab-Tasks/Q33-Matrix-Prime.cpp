/*Write a C++ program that displays the row numbers of a matrix containing at least two even numbers. 
First, the program should create a 2D array (5 rows, 5 columns). Then, ask the user to input values in the 
matrix or 2D array. After that, program should display row number (or index) which have less than 2 
prime numbers. If no row (of the matrix) contains at least two prime numbers then the program should 
display the message “No row found containing two prime numbers”. 
Sample Input: 
Please enter data for matrix of 5 x 5: 
2 6 18 49 8 
33 15 11 17 13 
8 21 47 37 28 
12 12 12 12 12 
2 
3 4 5 6 
Sample Output: Row number 1, 4  contains prime numbers less than 2.*/

#include <iostream>
using namespace std;
bool isPrime(int num) 
{
    if (num < 2) 
      return false;
    for (int i = 2; i*i <= num; i++) 
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() 
{
    int matrix[5][5];
    cout << "Please enter data for matrix of 5x5:\n";
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            cin >> matrix[i][j];
        }
    }

    bool found = false; 
    cout << "\nRows containing less than 2 prime numbers:\n";
    for (int i = 0; i < 5; i++) 
    {
        int primeCount = 0;
        for (int j = 0; j < 5; j++) 
        {
            if (isPrime(matrix[i][j]))
                primeCount++;
        }
        if (primeCount < 2) 
        {
            cout << "Row " << i+1 << endl; 
            found = true;
        }
    }
    if (!found) 
    {
        cout << "No row found containing two prime numbers" << endl;
    }
    return 0;
}
