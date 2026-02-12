#include<iostream>
using namespace std;
class company
{
protected:
	string c_name;
	int c_id;
public:
	company()
	{
		c_name = "";
		c_id = 0;
	}
	company(string name, int id)
	{
		c_name = name;
		c_id = id;
	}
	void set_name(string name)
	{
		c_name = name;
	}
	void set_id(int id)
	{
		c_id = id;
	}
	string get_name()
	{
		return c_name;
	}
	int get_id()
	{
		return c_id;
	}
	void display()
	{
		cout << " Call to base class " << endl;
		cout << " Company name " << c_name << endl;
		cout << " Id " << c_id << endl;
	}
};
class mobile_phone :public company
{
protected:
	string m_name;
	int m_id;
	int m_price;
public:
	void set_Mname(string name)
	{
		m_name = name;
	}
	void set_Mid(int id)
	{
		m_id = id;
	}
	void set_Mprice(int pr)
	{
		m_price = pr;
	}
	string get_Mname()
	{
		return m_name;
	}
	int get_Mid()
	{
		return m_id;
	}
	int get_Mprice()
	{
		return m_price;
	}
	void show()
	{
		cout << " Call to derived class " << endl;
		cout << " Mobile name: " << m_name << endl;
		cout << " Mobile id: " << m_id << endl;
		cout << " Mobile price: " << m_price << endl;
		cout << " Company name: " << c_name << endl;
		cout << " Company id: " << c_id << endl;
	}

};
class laptop :public company
{
protected:
	string l_name;
public:
	void set_Lname(string name)
	{
		l_name = name;
	}
	string get_Lname()
	{
		return l_name;
	}
	void show()
	{
		cout << " Call to derived class " << endl;
		cout << " Laptop name: " << l_name << endl;
		cout << " Company name: " << c_name << endl;
		cout << " Company id: " << c_id << endl;
	}
};
void main()
{
	mobile_phone obj1;
	obj1.set_id(3344);
	obj1.set_name("movers");
	obj1.set_Mname("samsung");
	obj1.set_Mid(1789);
	obj1.set_Mprice(20000);
	obj1.show();
	laptop obj2;
	obj2.set_id(5678);
	obj2.set_name("mossam");
	obj2.set_Lname("HP");
	obj2.show();
}
