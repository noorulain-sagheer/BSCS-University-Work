/*Write a C++ program that asks the user to enter a string value in a variable named “Str”. The input string 
should be of size 20 characters (minimum). Next, apply following operation (in sequence) on the input 
string: 
1) Find and print the length of the string. 
2) Display string in reverse order. 
3) Concatenate “Hello World” to the string. 
4) Count number of words in updated string. 
5) Convert whole string in lowercase. 
Sample Inputs: 
My name is Ali Raza 
Sample Outputs: 
1) String length: 19 
2) azaR ilA si eman yM 
3) My name is Ali Raza Hello World 
4) 7 
5) my name is ali raza hello world */

#include <iostream>
#include <cstring>   // For strlen, strcat
#include <cctype>    // For tolower
using namespace std;
int main() 
{
    char Str[100];
    cout << "Enter a string (minimum 20 characters):\n";
    cin.getline(Str, 100); //get string with spaces
    int len = strlen(Str);
    cout << "1) String length: " << len << endl;
    cout << "2) Reversed string: ";
    for (int i = len - 1; i >= 0; i--) 
    {
        cout << Str[i];
    }
    cout << endl;
    strcat(Str, " Hello World");
    cout << "3) After concatenation: " << Str << endl;
    int words = 0;
    bool inWord = false;
    for (int i = 0; Str[i] != '\0'; i++)
      {
        if (Str[i] != ' ' && !inWord) 
        {
            inWord = true;
            words++;
        } 
        else if (Str[i] == ' ') 
        {
            inWord = false;
        }
    }
    cout << "4) Number of words: " << words << endl;
    for (int i = 0; Str[i] != '\0'; i++) 
    {
        Str[i] = tolower(Str[i]);
    }
    cout << "5) Lowercase string: " << Str << endl;
    return 0;
}
