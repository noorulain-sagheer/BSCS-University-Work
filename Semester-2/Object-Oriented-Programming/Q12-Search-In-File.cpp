//SEARCHING IN FILES
CODE:
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream write("lab7.txt",ios::app);
	write << " Noor ul ain ";
	write << " maleeha ";
	write << " maryam ";
	write << " laiba ";
	write.close();
	ifstream read("lab7.txt");
	if (!read.is_open())
	{
		cout << " file not opened! " << endl;
		return 1;
	}
	string line;
	bool found = false;
	string search_name;
	cout << " enter name you want to search " << endl;
	cin >> search_name;
	while (getline(read, line))
	{
		if (line == search_name)
		{
			found = true;
			break;
		}
	}
	
	read.close();
	if (found)
	{
		cout << " found " << search_name << endl;

	}
	else
	{
		cout << " not found " << search_name << endl;
	}
	return 0;
 }
