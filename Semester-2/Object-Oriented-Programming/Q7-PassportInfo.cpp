#include<iostream>
using namespace std;
class passport
{
private:
	string full_name;
	int passport_num;
	string nationality;
	string gender;
	string citizenship_num;
public:
	passport()
	{
		cout << " Enter citizenship number in the given format : " << endl;
		cout << " *****-*******-* " << endl;
		cin >> citizenship_num;

	}
	passport(string f_n, string l_n)
	{
		full_name = f_n + l_n;
		cout << " full name : " << full_name << endl;
	}
	passport(string Gender, string Nationality, int Passport_n)
	{
		gender = Gender;
		nationality = Nationality;
		passport_num = Passport_n;
		cout << " gender : " << gender << endl;
		cout << " nationality : " << nationality << endl;
		cout << " passport number : " << passport_num << endl;
	}
	void display()
	{
		cout << " citizenship number : " << citizenship_num << endl;
	}
};
void main()
{
	passport obj;
	passport obj2("NOOR", "-UL-AIN");
	passport obj3("female", "pakistan", 123456789);
	obj.display();
}
