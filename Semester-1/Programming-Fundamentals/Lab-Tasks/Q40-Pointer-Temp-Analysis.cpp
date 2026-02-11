/*Write a C++ program that creates an integer array of a month and get the size of this array from the user. 
The program should take input values (temperatures for all days of the month) from the user. The 
program should display lowest temperature, highest temperature, and average temperature for the 
month.*/

#include <iostream>
using namespace std;
int main() 
{
    int size;
    cout << "Enter number of days in the month: ";
    cin >> size;
    //dynamic allocation 
    int *temps = new int[size];
    cout << "Enter temperature for each day:\n";
    for (int i = 0; i < size; i++)
      {
        cin >> *(temps + i);
      }
    
    int highest = *temps;
    int lowest = *temps;
    int sum = 0;
    for (int i = 0; i < size; i++) 
    {
        if (*(temps + i) > highest)
            highest = *(temps + i);
        if (*(temps + i) < lowest)
            lowest = *(temps + i);
        sum += *(temps + i);
    }
    double average = (double)sum / size;
    cout << "Highest Temperature: " << highest << endl;
    cout << "Lowest Temperature: " << lowest << endl;
    cout << "Average Temperature: " << average << endl;
    // Free memory
    delete[] temps;
    return 0;
}
