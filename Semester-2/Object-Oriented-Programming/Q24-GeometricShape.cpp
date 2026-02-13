#include <iostream>
using namespace std;
class GeometricShape 
{
public:
    virtual void show() = 0;
    virtual double computeArea() = 0;
};

class Rectangle : public GeometricShape 
{
protected:
    double length;
    double width;
public:
    void setLength(double l)
    {
        length = l;
    }
    void setWidth(double w) 
    {
        width = w;
    }
    double getLength()
    {
        return length;
    }
    double getWidth() 
    {
        return width;
    }
    double computeArea() 
    {
        return length * width;
    }
    void show() 
    {
        cout << "Rectangle" << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << computeArea() << endl;
        cout << endl;
    }
};

class Cuboid : public Rectangle 
{
    double height;
public:
    void setHeight(double h) 
    {
        height = h;
    }
    double getHeight() 
    {
        return height;
    }
    double computeArea() 
    {
        return length * width * height;
    }
    void show()
    {
        cout << "Cuboid" << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Volume: " << computeArea() << endl;
        cout << endl;
    }
};

int main()
{
    GeometricShape* g1 = new Rectangle();
    Rectangle* r = dynamic_cast<Rectangle*>(g1);
    r->setLength(5);
    r->setWidth(4);
    GeometricShape* g2 = new Cuboid();
    Cuboid* c = dynamic_cast<Cuboid*>(g2);
    c->setLength(3);
    c->setWidth(2);
    c->setHeight(6);
    g1->show();
    g2->show();
    delete g1;
    delete g2;
    return 0;
}
