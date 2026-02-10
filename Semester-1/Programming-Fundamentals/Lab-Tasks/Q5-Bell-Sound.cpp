//Write a program in C++ using escape sequence which would produce the sound of a bell when user enters the character. 
#include <iostream>
using namespace std;

int main()
{
    char ch;

    cout << "Enter any character to hear the bell sound: ";
    cin >> ch;

    // Generate bell sound
    cout << "\a";

    cout << "You entered: " << ch << endl;

    return 0;
}
