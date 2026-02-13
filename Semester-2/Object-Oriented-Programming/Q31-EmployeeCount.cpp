#include <iostream>
using namespace std;
class Employee 
{
    string name;
    int emp_id;
    double salary;
public:
    static int count;
    Employee() 
    {
        count++;
    }
    void setName(string n) 
    {
        name = n;
    }
    void setEmpID(int id) 
    {
        emp_id = id;
    }

    void setSalary(double s)
    {
        salary = s;
    }

    string getName()
    {
        return name;
    }

    int getEmpID()
    {
        return emp_id;
    }
    double getSalary() 
    {
        return salary;
    }
    void display() 
    {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << emp_id << endl;
        cout << "Salary: " << salary << endl;
    }
};

int Employee::count = 0;

int main() 
{
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    Employee e[n];
    for(int i = 0; i < n; i++)
       {
        string name;
        int id;
        double salary;
        cout << "Enter details for employee " << i+1 << ":" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Salary: ";
        cin >> salary;

        e[i].setName(name);
        e[i].setEmpID(id);
        e[i].setSalary(salary);
    }

    for(int i = 0; i < n; i++)
    {
        cout << "\nEmployee " << i+1 << " details:" << endl;
        e[i].display();
    }
    cout << "\nTotal number of Employee objects created: " << Employee::count << endl;
    return 0;
}
