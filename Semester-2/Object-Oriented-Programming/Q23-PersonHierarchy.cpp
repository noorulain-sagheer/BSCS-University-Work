#include <iostream>
using namespace std;
class Person 
{
protected:
    string personName;
    int age;
public:
    Person(string n, int a) 
    {
        personName = n;
        age = a;
    }
    virtual void print() = 0;
};
class Student : public Person 
{
protected:
    int Std_id;
    float Cgpa;
public:
    Student(string n, int a, int id, float c) : Person(n, a) 
    {
        Std_id = id;
        Cgpa = c;
    }
    void print()
    {
        cout << "Name: " << personName << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << Std_id << endl;
        cout << "CGPA: " << Cgpa << endl;
        cout << endl;
    }
};

class Regular : public Student 
{
    string SchoolName;
    float Fee;
public:
    Regular(string n, int a, int id, float c, string s, float f) : Student(n, a, id, c) 
   {
        SchoolName = s;
        Fee = f;
    }
    void print()
{
        cout << "Name: " << personName << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << Std_id << endl;
        cout << "CGPA: " << Cgpa << endl;
        cout << "School Name: " << SchoolName << endl;
        cout << "Fee: " << Fee << endl;
        cout << endl;
    }
};

class Private : public Student
{
    string Address;
    float Fee;
public:
    Private(string n, int a, int id, float c, string ad, float f) : Student(n, a, id, c) 
    {
        Address = ad;
        Fee = f;
    }
    void print() 
   {
        cout << "Name: " << personName << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << Std_id << endl;
        cout << "CGPA: " << Cgpa << endl;
        cout << "Address: " << Address << endl;
        cout << "Fee: " << Fee << endl;
        cout << endl;
    }
};

int main()
{
    Person* p1 = new Regular("Ali", 20, 101, 3.5, "City School", 50000);
    Person* p2 = new Private("Sara", 22, 102, 3.8, "Lahore", 40000);
    p1->print();
    p2->print();
    delete p1;
    delete p2;
    return 0;
}
