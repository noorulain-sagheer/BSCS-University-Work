#include <iostream>
using namespace std;
class Sector 
{
    int sectID;
    string sectName;
public:
    Sector(int id, string name) 
    {
        sectID = id;
        sectName = name;
    }
    void display() 
    {
        cout << "Sector ID: " << sectID << endl;
        cout << "Sector Name: " << sectName << endl;
    }
};

class Department 
{
public:
    string DepartmentName;
    string location;
    Sector* sect;
    Department(string name, string loc, Sector* s) 
    {
        DepartmentName = name;
        location = loc;
        sect = s;
    }

    void display() 
    {
        cout << "Department Name: " << DepartmentName << endl;
        cout << "Location: " << location << endl;
        sect->display();
    }
};

class Laboratory 
{
    int labID;
    int access_level;
    int sectID;
    int experimentNo;
public:
    Laboratory(int id, int expNo, string designation) 
{
        labID = id;
        experimentNo = expNo;

        if (designation == "Junior") access_level = 3;
        else if (designation == "Senior") access_level = 7;
        else access_level = 10;

        sectID = 0;
    }

    void display()
{
        cout << "Lab ID: " << labID << endl;
        cout << "Experiment No: " << experimentNo << endl;
        cout << "Access Level: " << access_level << endl;
    }
};

class Person 
{
protected:
    string name;
    int age;
public:
    Person(string n, int a)
   {
        name = n;
        age = a;
    }
    void display() 
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Scientist : public Person 
 {
    string sciName;
    string designation;
    Department dept;
public:
    Scientist(string n, int a, string sName, string desig, Department d) : Person(n, a), dept(d)
    {
        sciName = sName;
        designation = desig;
    }

    void display() 
   {
        Person::display();
        cout << "Scientist Name: " << sciName << endl;
        cout << "Designation: " << designation << endl;
        dept.display();
    }
};

class Engineer : public Person 
{
    Laboratory lab;
public:
    Engineer(string n, int a, Laboratory l) : Person(n, a), lab(l) {}

    void display()
    {
        Person::display();
        lab.display();
    }
};

int main()
{
    Sector s1(1, "Research Sector");
    Department d1("Physics Dept", "Block A", &s1);
    Scientist sc("Ali", 40, "Dr. Ali", "Senior", d1);
    Laboratory lab1(101, 5, "Senior");
    Engineer eng("Ahmed", 35, lab1);
    cout << "Scientist Details" << endl;
    sc.display();
    cout << endl << "Engineer Details" << endl;
    eng.display();
    return 0;
}
