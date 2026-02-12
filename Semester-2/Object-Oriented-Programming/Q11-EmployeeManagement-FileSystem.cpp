#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    string name;
    int age;
    double salary;

public:
    // Setters
    void setName(const string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    void setSalary(double newSalary) {
        salary = newSalary;
    }

    // Getters
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getSalary() const {
        return salary;
    }
};

// Function to write employee information to a file
void writeEmployeeInfo(const Employee& employee) {
    ofstream outFile("employee.txt", ios::app);

    if (!outFile.is_open()) {
        cerr << "Error opening the file for writing." << endl;
        return;
    }

    // Write the employee information to the file
    outFile << employee.getName() << "," << employee.getAge() << "," << employee.getSalary() << endl;

    outFile.close();
}

// Function to read employee information from a file
void readEmployeeInfo() {
    ifstream inFile("employee.txt");

    if (!inFile.is_open()) {
        cerr << "Error opening the file for reading." << endl;
        return;
    }

    vector<Employee> employees;
    Employee employee;

    string line;
    while (getline(inFile, line)) {
        // Assuming the data in the file is stored as "name,age,salary"
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);

        employee.setName(line.substr(0, pos1));
        employee.setAge(stoi(line.substr(pos1 + 1, pos2 - pos1 - 1)));
        employee.setSalary(stod(line.substr(pos2 + 1)));

        employees.push_back(employee);
    }

    // Display the read employee information
    cout << "Employee Information:" << endl;
    for (const auto& emp : employees) {
        cout << "Name: " << emp.getName() << ", Age: " << emp.getAge() << ", Salary: " << emp.getSalary() << endl;
    }

    inFile.close();
}

// Function to search for an employee in the file
void searchEmployee(const string& searchKey) {
    ifstream inFile("employee.txt");

    if (!inFile.is_open()) {
        cerr << "Error opening the file for reading." << endl;
        return;
    }

    Employee employee;

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        // Assuming the data in the file is stored as "name,age,salary"
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);

        employee.setName(line.substr(0, pos1));
        employee.setAge(stoi(line.substr(pos1 + 1, pos2 - pos1 - 1)));
        employee.setSalary(stod(line.substr(pos2 + 1)));

        if (employee.getName() == searchKey) {
            found = true;
            cout << "Employee found: Name: " << employee.getName() << ", Age: " << employee.getAge() << ", Salary: " << employee.getSalary() << endl;
            break;  // Assuming names are unique, no need to continue searching
        }
    }

    if (!found) {
        cout << "Employee not found." << endl;
    }

    inFile.close();
}

// Function to count the number of employees with salary more than 50,000
int countHighSalaryEmployees() {
    ifstream inFile("employee.txt");

    if (!inFile.is_open()) {
        cerr << "Error opening the file for reading." << endl;
        return -1;
    }

    int count = 0;
    Employee employee;

    string line;
    while (getline(inFile, line)) {
        // Assuming the data in the file is stored as "name,age,salary"
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);

        employee.setName(line.substr(0, pos1));
        employee.setAge(stoi(line.substr(pos1 + 1, pos2 - pos1 - 1)));
        employee.setSalary(stod(line.substr(pos2 + 1)));

        if (employee.getSalary() > 50000) {
            count++;
        }
    }

    inFile.close();
    return count;
}

int main() {
    int choice;

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Add employee information" << endl;
        cout << "2. Read employee information" << endl;
        cout << "3. Search for an employee" << endl;
        cout << "4. Count employees with salary > 50,000" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Employee newEmployee;

            cin.ignore(); // Clear the input buffer
            cout << "Enter employee name: ";
            getline(cin, newEmployee.setName);

            cout << "Enter employee age: ";
            cin >> newEmployee.setAge;

            cout << "Enter employee salary: ";
            cin >> newEmployee.setSalary;

            writeEmployeeInfo(newEmployee);
            break;
        }
        case 2:
            readEmployeeInfo();
            break;
        case 3: {
            cin.ignore(); // Clear the input buffer
            string searchName;
            cout << "Enter the name to search: ";
            getline(cin, searchName);
            searchEmployee(searchName);
            break;
        }
        case 4: {
            int count = countHighSalaryEmployees();
            if (count != -1) {
                cout << "Number of employees with salary > 50,000: " << count << endl;
            }
            break;
        }
        case 5:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5);

    return 0;
}
