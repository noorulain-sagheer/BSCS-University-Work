#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class student_info
{
private:
	int reg[5];
	string name[5];
	int age[5];
public:
	void writing();
	void searching();
	void display();
};
	void student_info:: writing()
	{
		
		int index;
		ofstream write("student.txt", ios::app);
		cout << " ENTER INDEX NUMBER (0-4) AT WHICH YOU WANT TO PLACE DATA : " << endl;
		cin >> index;
		cout << " ENTER NAME OF STUDENT :" << endl;
		getline(cin, name[index]);
		write << name << endl;
		cout << " ENTER AGE OF STUDENT : " << endl;
		cin >> age[index];
		write << age << endl;
		cout << " ENTER REGISTRATION NUMBER OF STUDENT : " << endl;
		cin >> reg[index];
		write << reg << endl;
		write.close();
	}
	void student_info::searching()
	{
		string search;
		int i;
		fstream read("student.txt");
		cout << " ENTER NAME OR AGE OR REGISTRATION NUMBER OF STUDENT FOR SEARCHING DATA : " << endl;
		getline(read, search);

		for (int n = 0;n <= 4;n++)
		{
			if (search[n] == n)
			{
				i = n;
			}
		}
		cout << " NAME " << name[i] << endl;
		cout << " REGISTRATION MUMBER " << reg[i] << endl;
		cout << " AGE " << age[i] << endl;
		read.close();
	}
	void student_info::display()
	{
		cout << " student information " << endl;
		cout << " name " << endl;
		for (int i = 0;i < 5;i++)
		{
			cout << name[i] << endl;
		}
		cout << " age " << endl;
		for (int i = 0;i < 5;i++)
		{
			cout << age[i] << endl;

		}
		cout << " registration number " << endl;
		for (int i = 0;i < 5;i++)
		{
			cout << reg[i] << endl;
		}
	}
void main()
{
	student_info obj;
	char ch;
	cout << "------ MENU ------" << endl;
	cout << " ENTER WHAT DO YOU WANT WRITING IN FILE OR SEARCHING ? " << endl;
	cout << " FOR WRITING SELECT 1 :" << endl;
	cout << " FOR SEARCHING SELECT 2 :" << endl;
	
	cin >> ch;
    switch (ch)
	{
	case 1:
		obj.writing();
		obj.display();
		break;
	case 2:
		obj.searching();
		break;
	default:
		cout << " WRONG INPUT!!" << endl;
		break;
	}
}
