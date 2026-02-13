#include <iostream>
using namespace std;
class Square;
class Area;
class Circle 
{
    double radius;
public:
    Circle(double r) 
    {
        radius = r;
    }
    friend class Area;
};

class Square 
{
    double length;
public:
    Square(double l)
    {
        length = l;
    }
    friend double perimeter(Square s);
    friend class Area;
};

double perimeter(Square s)
{
    return 4 * s.length;
}

class Area 
{
public:
    double circleArea(Circle c) 
    {
        return 3.14159 * c.radius * c.radius;
    }

    double squareArea(Square s)
    {
        return s.length * s.length;
    }
};

int main()
{
    Circle c(5);
    Square s(4);
    Area a;
    cout << "Perimeter of Square: " << perimeter(s) << endl;
    cout << "Area of Circle: " << a.circleArea(c) << endl;
    cout << "Area of Square: " << a.squareArea(s) << endl;
    return 0;
}
