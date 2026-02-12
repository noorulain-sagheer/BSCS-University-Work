#include<iostream>
using namespace std;

class entertainment
{
private:
	string Title;
	string Air_Date;
	string* Genre;
	string Type;
	string Country;
	string* Actors;
	string Ratings;
	int size1, size2;
public:
	entertainment(int s1, int s2)
	{
		size1 = s1;
		size2 = s2;
		Genre = new string[size1];
		Actors = new string[size2];
	}
	entertainment(const entertainment& other)
	{
		size1 = other.size1;
		Genre = new string(*(other.Genre));
		Country = other.Country;
		Ratings = other.Ratings;
	}
	void set_data(string t, string a_d, string type, string c, string r)
	{
		Title = t;
		Air_Date = a_d;
		Type = type;
		Country = c;
		Ratings = r;

	}
	void set_genre(int index, string g)
	{
		if (index >= 0 && index < size1)
		{
			Genre[index] = g;
		}
	}
	void set_actors(int index, string a)
	{
		if (index >= 0 && index < size2)
		{
			Actors[index] = a;
		}
	}
	void display()
	{
		cout << " INFORMATION ABOUT THE DARAMA " << endl;
		cout << " ------------------------------- " << endl;

		cout << " Title : " << Title << endl;
		cout << " Air date : " << Air_Date << endl;
		cout << " Release Country : " << Country << endl;

		cout << " Type : " << Type << endl;
		cout << " Ratings : " << Ratings << endl;
		cout << " Genre of darama : " << endl;
		for (int i = 0;i < size1;i++)
		{
			cout << Genre[i] <<"     "<< endl;
		}
		cout << " Actors of the darama : " << endl;
		for (int i = 0;i < size2;i++)
		{
			cout << Actors[i] <<"    "<<endl;
		}
	}
	~entertainment()
	{
		delete[] Genre;
		delete[] Actors;
	}

};
void main()
{

	entertainment obj1(3, 3);
	obj1.set_data(" Entertainment ", " 10-oct-2022 ", " darama ", " pakistan ", " good ");
	obj1.set_genre(0, " tragedy ");
	obj1.set_genre(1, " mystery ");
	obj1.set_genre(2, " melodarama ");
	obj1.set_actors(0, " ahsan khan ");
	obj1.set_actors(1, " saba kamar ");
	obj1.set_actors(2, " ayesha malik ");
	obj1.display();
	entertainment obj2(obj1);
	cout << endl;
	cout << " -------------------------------------------" << endl;
	cout << endl;
	cout<<" output display when using the copy constructor : " << endl;
	obj2.display();

}
