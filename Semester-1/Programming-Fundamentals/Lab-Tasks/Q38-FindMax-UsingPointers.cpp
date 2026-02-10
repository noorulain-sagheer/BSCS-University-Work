/*Write a C++ program that creates and integer array having 30 elements. Get input in this array (in main 
function). After that, pass that array to a function called “Find_Max_Divisors” using reference pointer. 
The function “Find_Max_Divisors” should find (and return) in the array that number which has highest 
number of divisors. In the end, the main function displays that number having highest number of 
divisors.*/
#include <iostream>
using namespace std;

int Find_Max_Divisors(int *arr, int size) 
{
    int maxDiv = 0;       
    int numberWithMax = *arr; 
    for (int i = 0; i < size; i++) 
    {
        int count = 0;
        for (int j = 1; j <= *(arr + i); j++)
          { 
            if (*(arr + i) % j == 0) {
                count++;
            }
        }
        if (count > maxDiv) 
        {
            maxDiv = count;
            numberWithMax = *(arr + i);
        }
    }
    return numberWithMax;
}
int main() 
{
    const int SIZE = 30;
    int arr[SIZE];
    cout << "Enter 30 integers in the array:\n";
    for (int i = 0; i < SIZE; i++)
      {
        cin >> *(arr + i);
      }
    int result = Find_Max_Divisors(arr, SIZE);
    cout << "Number having highest number of divisors: " << result << endl;
    return 0;
}
