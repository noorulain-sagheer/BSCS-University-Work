#include<iostream>
using namespace std;

class sector
{
private:
	int sect_id;
	string sect_name;
public:
	sector(int id, string name)
	{
		sect_id = id;
		sect_name = name;
	}
	void display() const
	{
		cout << " Sector id: " << sect_id << endl;
		cout << " Sector name: " << sect_name << endl;
	}
};

class laboratory
{
public:
	int lab_id;
	string access_level;
	int exp_no;

	laboratory() {}
	laboratory(int id, string level, int exp)
	{
		lab_id = id;
		access_level = level;
		exp_no = exp;
	}
	void display_lab() const
	{
		cout << " Laboratory details: " << endl;
		cout << " lab id: " << lab_id << endl;
		cout << " Access level: " << access_level << endl;
		cout << " experiment number: " << exp_no << endl;
	}
};

class department
{
public:
	string dep_name;
	string location;
	sector* sect;

	department(const string& name, const string& loc, sector* s)
	{
		dep_name = name;
		location = loc;
		sect = s;
	}
	void display() const
	{
		cout << " Department information: " << dep_name << endl;
		cout << " location: " << location << endl;
		if (sect != nullptr)
		{
			sect->display();
		}
	}
};

class person
{
protected:
	string name;
	int age;

public:
	person() {}
	person(const string& n, int a)
	{
		name = n;
		age = a;
	}
	void display() const
	{
		cout << " Name of a person: " << name << endl;
		cout << " Age of a person: " << age << endl;
	}
};

class scientist : public person
{
public:
	string sci_name;
	department* dept;
	string designation;

	scientist(const string& n, int a, const string& s, department* d, string desig)
		: person(n, a), sci_name(s), dept(d), designation(desig)
	{}

	void display_det() const
	{
		person::display();
		cout << " scientist name: " << sci_name << endl;
		cout << " designation: " << designation << endl;
		if (dept != nullptr)
		{
			dept->display();
		}
	}
};

class engineer : public person
{
public:
	laboratory lab; // engineer owns a laboratory (composition)

	engineer(const string& n, int a, const laboratory& l)
		: person(n, a), lab(l)
	{}

	void display() const
	{
		person::display();
		cout << "Engineer's Laboratory ID: " << lab.lab_id << endl;
		cout << "Access Level : " << lab.access_level << endl;
	}
};

int main()
{
	// Create a Sector
	sector* sect = new sector(1, "Research");

	// Create a Department
	department* dep = new department("Science", "Building A", sect);

	// Create a Scientist
	scientist sci("john", 35, "Dr. Doe", dep, "Research Scientist");

	// Create an Engineer
	laboratory lab(101, "dont know", 5); // Laboratory for an Engineer
	engineer eng("Alice Smith", 28, lab);

	// Display details
	sci.display_det();
	cout << endl;
	eng.display();

	// Cleanup (delete dynamically allocated objects)
	delete dep;
	delete sect;

	return 0;
}
