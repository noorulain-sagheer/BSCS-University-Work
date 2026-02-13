#include <iostream>
using namespace std;
class FoodCorner 
{
protected:
    string name;
    double price;
public:
    FoodCorner(string n, double p) 
    {
        name = n;
        price = p;
    }
    virtual void showMenu() = 0;
    double getPrice() 
    {
        return price;
    }
};

class FastFood : public FoodCorner 
{
public:
    FastFood(string n, double p) : FoodCorner(n, p) {}
    void showMenu()
   {
        cout << "FastFood: " << name << " Price: " << price << endl;
    }
};

class ProperMeal : public FoodCorner
  {
public:
    ProperMeal(string n, double p) : FoodCorner(n, p) {}
    void showMenu()
    {
        cout << "ProperMeal: " << name << " Price: " << price << endl;
    }
};

class Beverages : public FoodCorner 
{
public:
    Beverages(string n, double p) : FoodCorner(n, p) {}
    void showMenu()
   {
        cout << "Beverage: " << name << " Price: " << price << endl;
    }
};

class Customer
 {
protected:
    string name;
public:
    Customer(string n) 
    {
        name = n;
    }
    virtual void display() = 0;
};

class Student : public Customer  
{
public:
    Student(string n) : Customer(n) {}
    void display() 
    {
        cout << "Student: " << name << endl;
    }
};
class Employee : public Customer
{
public:
    Employee(string n) : Customer(n) {}
    void display() 
    {
        cout << "Employee: " << name << endl;
    }
};
class Bill 
{
    double total;
public:
    Bill(double t) 
    {
        total = t;
    }
    void generate() 
    {
        cout << "Total Bill: " << total << endl;
    }
};

class Server 
{
public:
    void showMenu(FoodCorner* f) 
    {
        f->showMenu();
    }
    void placeOrder(Customer* c, FoodCorner* f)
   {
        c->display();
        Bill b(f->getPrice());
        b.generate();
    }
};

int main() 
{
    Student s("Ali");
    Employee e("Sara");
    FastFood f1("Burger", 500);
    ProperMeal p1("Biryani", 300);
    Beverages b1("Juice", 150);
    Server server;
    server.showMenu(&f1);
    server.showMenu(&p1);
    server.showMenu(&b1);
    server.placeOrder(&s, &f1);
    server.placeOrder(&e, &p1);
    return 0;
}
