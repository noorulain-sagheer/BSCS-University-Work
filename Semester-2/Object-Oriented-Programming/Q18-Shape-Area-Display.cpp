#include <iostream>
#include <string>
using namespace std;
class Shape 
{
protected:
    string ShapeName;
    int area;

public:
    Shape() 
   {
        ShapeName = "";
        area = 0;
    }

    Shape(string name, int a) 
   {
        ShapeName = name;
        area = a;
    }

    void displayarea()
   {
        cout << "Shape: " << ShapeName << ", Area: " << area << endl;
    }
};


class Circle : public Shape 
{
public:
    Circle(string name, int r)
   {
        ShapeName = name;
        area = 3.14159 * r * r; 
    }
};

class Polygon : public Shape
{
public:
    Polygon(string name, int b, int h) 
   {
        ShapeName = name;
        area = (b * h)/2;
    }
};

int main() 
{
    Circle c("Circle", 5);      
    Polygon p("Polygon", 6, 4); 
    Shape s; 
    cout << "Displaying areas using Shape object:" << endl;
    s.displayarea(); 
    c.displayarea();
    p.displayarea();
    return 0;
}
