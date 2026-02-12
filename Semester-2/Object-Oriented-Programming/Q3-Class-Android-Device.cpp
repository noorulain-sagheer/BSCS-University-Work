/*Create a class Android_Device. The data members of the class are IMEIno (int), Type (String), Make 
(String), Modelno (int), Memory(float), Operating_System(String). Then Implement member functions to: 
1. Set the values of all data members. 
2. Display the values of all data members */
#include <iostream>
using namespace std;

class Android_Device
{
private:
    int IMEIno;
    string Type;
    string Make;
    int Modelno;
    float Memory;
    string Operating_System;

public:
    void setValues()
{
        cout << "Enter IMEI Number: ";
        cin >> IMEIno;

        cin.ignore();  // Clear buffer

        cout << "Enter Device Type: ";
        getline(cin, Type);

        cout << "Enter Make (Company): ";
        getline(cin, Make);

        cout << "Enter Model Number: ";
        cin >> Modelno;

        cout << "Enter Memory (GB): ";
        cin >> Memory;

        cin.ignore();

        cout << "Enter Operating System: ";
        getline(cin, Operating_System);
}
    void displayValues() 
{
        cout << "\n--- Android Device Details ---\n";
        cout << "IMEI Number: " << IMEIno << endl;
        cout << "Type: " << Type << endl;
        cout << "Make: " << Make << endl;
        cout << "Model Number: " << Modelno << endl;
        cout << "Memory: " << Memory << " GB" << endl;
        cout << "Operating System: " << Operating_System << endl;
    }
};

int main() 
{
    Android_Device device; 
    device.setValues();      
    device.displayValues();  
    return 0;
}
