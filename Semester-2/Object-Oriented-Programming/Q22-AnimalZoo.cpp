#include <iostream>
using namespace std;
class Animal
{
protected:
    string Name;
    string Zoo;
public:
    Animal(string n, string z) 
   {
        Name = n;
        Zoo = z;
    }
    virtual void show() = 0;
};
class Birds : public Animal 
{
    bool flying;
public:
    Birds(string n, string z, bool f) : Animal(n, z) 
    {
        flying = f;
    }
    void show() 
    {
        cout << "Name: " << Name << endl;
        cout << "Zoo: " << Zoo << endl;
        cout << "Flying: " << (flying ? "Yes" : "No") << endl;
        cout << endl;
    }
};

class Reptiles : public Animal 
{
    float Length;
public:
    Reptiles(string n, string z, float l) : Animal(n, z) 
    {
        Length = l;
    }
    void show()
    {
        cout << "Name: " << Name << endl;
        cout << "Zoo: " << Zoo << endl;
        cout << "Length: " << Length << endl;
        cout << endl;
    }
};
int main()
{
    Animal* a1 = new Birds("Parrot", "Lahore Zoo", true);
    Animal* a2 = new Reptiles("Snake", "Karachi Zoo", 5.5);
    a1->show();
    a2->show();
    delete a1;
    delete a2;
    return 0;
}
