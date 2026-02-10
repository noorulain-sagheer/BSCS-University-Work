// Program to count Even, Odd and numbers divisible by 7

#include <iostream>
using namespace std;

int main() 
{
    int num;
    int evenCount = 0, oddCount = 0, div7Count = 0;
    cout << "Enter 10 integers:\n";
    for (int i = 1; i <= 10; i++)
      {
        cin >> num;
        if (num % 2 == 0)
            evenCount++;
        else
            oddCount++;
        if (num % 7 == 0)
            div7Count++;
    }
    cout << "\nTotal Even Numbers: " << evenCount << endl;
    cout << "Total Odd Numbers: " << oddCount << endl;
    cout << "Numbers Divisible by 7: " << div7Count << endl;
    return 0;
}
