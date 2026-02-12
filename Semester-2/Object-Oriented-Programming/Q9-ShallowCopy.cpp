#include<iostream>
using namespace std;
class polygon
{
private:
	int length;
	int* width;
public:
	polygon(int w, int l)
	{
		width = new int(w);
		length = l;
	}
	polygon(const polygon& other)
	{
		width = other.width;

	}
	void set_data(int w, int l)
	{
		*width = w;
		length = l;
	}
	void set_width(int w)
	{
		*width = w;
	}
	void display()
	{
		cout << " length of a polygon : " << length << endl;
		cout << " width of a polygon : " << *width << endl;
	}

};
void main()
{
	polygon one(4, 5);
	cout << endl;
	cout << " first call to original object : " << endl;
	cout << endl;
	one.display();  // original object
	polygon two(one);
	cout << endl;
	cout << " first call to copied object : " << endl;
	cout << endl;
	two.display();  // copy object
	two.set_width(7);
	cout << endl;
	cout << " after modification of width from copied object : " << endl;
	cout << endl;
	two.display();
	cout << endl;
	cout << " and the data of original object : " << endl;
	cout << endl;
	one.display();

}
