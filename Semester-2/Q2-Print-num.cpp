/*Print the integers from 1 to a limit in which the limit is given by the user.*/
#include <iostream>
using namespace std;
int main() 
{
    int limit;
    cout << "Enter the limit: ";
    cin >> limit;
    for (int i = 1; i <= limit; i++) 
    {
        cout << i << " ";
    }
    return 0;
}
