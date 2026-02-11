#include <iostream>
#include <cstring>
using namespace std;
// Structure
struct Book 
{
    int id;
    char title[50];
    char author[50];
    double price;
};
int main() 
{
    const int SIZE = 10;
    Book books[SIZE];
    cout << "Enter details for 10 books:\n";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << "\nBook " << i + 1 << endl;
        cout << "Enter Book ID: ";
        cin >> books[i].id;
        cin.ignore();
        cout << "Enter Book Title: ";
        cin.getline(books[i].title, 50);
        cout << "Enter Author Name: ";
        cin.getline(books[i].author, 50);
        cout << "Enter Price: ";
        cin >> books[i].price;
    }
    
    cout << "\nBooks having same authors:\n";
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = i + 1; j < SIZE; j++) 
        {
            if (strcmp(books[i].author, books[j].author) == 0) 
            {
                cout << books[i].title << endl;
                cout << books[j].title << endl;
            }
        }
    }
    return 0;
}
