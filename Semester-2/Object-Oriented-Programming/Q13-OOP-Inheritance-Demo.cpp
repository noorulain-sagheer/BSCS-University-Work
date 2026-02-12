#include<iostream>
using namespace std;
class Car
{
protected:
	string car_name;
	int speed;
public:
	Car()
	{
		car_name = "";
		speed = 0;
	}
	Car(string name, int s)
	{
		car_name = name;
		speed = s;
	}
	void set_name(string name)
	{
		car_name = name;
	}
	void set_speed(int s)
	{
		speed = s;
	}
	string get_name()
	{
		return car_name;
	}
	int get_speed()
	{
		return speed;
	}
	void display()
	{
		cout << " Call to base class : " << endl;
		cout << " Car name: " << car_name << endl;
		cout << " Car speed: " << speed << endl;
	}
};
class convertible :public Car
{
protected:
	bool top;
public:
	convertible()
	{
		top = false;
	}
	convertible(string name, int s, bool t)
	{
		car_name = name;
		speed = s;
		top = t;
	}
	void set_top(bool t)
	{
		top = t;
	}
	void show()
	{
		cout << " Call to derived class : " << endl;
		cout << endl;
		cout << " Car name: " << car_name << endl;
		cout << " Speed: " << speed << endl;
		cout << " Top: " << top << endl;
	}
};
int main()
{
	Car c1;
	c1.display();
	c1.set_name("honda");
	c1.set_speed(140);
	c1.display();
	cout << " Car name  :" << c1.get_name() << endl;
	cout << " Car speed :" << c1.get_speed() << endl;
	Car c2("suzuki", 123);
	c2.display();
	c2.set_name("civic");
	c2.set_speed(240);
	c2.display();
	convertible o1;
	o1.show();
	convertible o2("Toyota", 120, true);
	o2.show();
	o2.set_top(false);
	o2.show();

}
