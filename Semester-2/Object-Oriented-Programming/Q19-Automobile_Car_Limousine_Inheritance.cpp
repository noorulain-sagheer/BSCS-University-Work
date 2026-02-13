#include<iostream>
using namespace std;
class automobile
{
protected:
	int current_speed;
public:
	void set_current_speed(int speed)
	{
		current_speed = speed;
	}
	int get_curent_speed()
	{
		return current_speed;
	}
};
class car :public automobile
{
protected:
	string color;
	car(string c, int s)
	{
		color = c;
		current_speed = s;
	}
	void set_color(string c)
	{
		color = c;
	}
	string get_color()
	{
		return color;
	}

};
class limousine :public car
{
public:
	void set_current_speed(int s)
	{
		current_speed = s;
	}
	void set_color(string c)
	{
		color = c;
	}
	int get_current_speed()
	{
		return current_speed;
	}
	string get_color()
	{
		return color;
	}
};
