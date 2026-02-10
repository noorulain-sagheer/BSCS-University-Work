/*Write a program that implements isVowel that returns the value true if a given character is a vowel 
and otherwise returns false. Mention proper function declaration/prototype, and function call from
the main body.*/
#include <iostream>
using namespace std;
bool isVowel(char ch);
int main()
{
    char c;
    cout << "Enter a character: ";
    cin >> c;
    if (isVowel(c))
        cout << c << " is a vowel" << endl;
    else
        cout << c << " is not a vowel" << endl;
    return 0;
}
bool isVowel(char ch)
{
    ch = tolower(ch); 
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
