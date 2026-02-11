/*7.2 Practice Task 2 [Expected time = 20 mins] 
Write a C++ program called “Eliminate evens”. First, create an array named “values” having 10 
elements of integer type. Then, the program should ask the user to enter values (which may be 
negative as well as positive) in this array. After that, the program replaces each array element which 
is odd with an even value. Positive odds should be replaced by even values by adding 1 to them 
while the negative odd values must be replaced by adding -1 to them. In the end, the program shows 
the updated array.  
Please Note: Array input, output, and other accesses must be done using pointer notation only (no 
subscript [ ] notation allowed). */

#include <iostream>
using namespace std;
int main() 
{
    const int SIZE = 10;
    int values[SIZE];
    cout << "Enter 10 integer values:\n";

    for (int i = 0; i < SIZE; i++) 
    {
        cin >> *(values + i);
    }

    for (int i = 0; i < SIZE; i++)
      {
        if (*(values + i) % 2 != 0)
        {
            if (*(values + i) > 0) 
            {
                *(values + i) = *(values + i) + 1;   
            }
            else
            {
                *(values + i) = *(values + i) - 1;   
            }
        }
    }
    cout << "Updated array values:\n";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << *(values + i) << " ";
    }
    return 0;
}
