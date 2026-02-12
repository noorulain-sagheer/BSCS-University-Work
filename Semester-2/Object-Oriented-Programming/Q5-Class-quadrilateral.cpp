#include <iostream>
#include <cmath>
using namespace std;
class Quadrilateral 
{
private:
    double side1, side2, side3, side4;
    double angle1, angle2;   
public:
    void setSides(double s1, double s2, double s3, double s4) 
    {
        side1 = s1;
        side2 = s2;
        side3 = s3;
        side4 = s4;
    }
    void setAngles(double a1, double a2) 
    {
        angle1 = a1;
        angle2 = a2;
    }

    // Getter methods
    double getSide1() const 
    { return side1; }
    double getSide2() const
    { return side2; }
    double getSide3() const 
    { return side3; }
    double getSide4() const 
    { return side4; }
    double getAngle1() const 
    { return angle1; }
    double getAngle2() const 
    { return angle2; }

    double computePerimeter() const 
    {
        return side1 + side2 + side3 + side4;
    }
    double computeArea() const 
    {
        double rad = angle1 * 3.14159265 / 180.0; 
        return 0.5 * side1 * side3 * sin(rad);
    }

    void displayDetails() const 
   {
        cout << "\n--- Quadrilateral Details ---\n";
        cout << "Side 1: " << side1 << endl;
        cout << "Side 2: " << side2 << endl;
        cout << "Side 3: " << side3 << endl;
        cout << "Side 4: " << side4 << endl;
        cout << "Opposite Angle 1: " << angle1 << " degrees" << endl;
        cout << "Opposite Angle 2: " << angle2 << " degrees" << endl;
        cout << "Perimeter: " << computePerimeter() << endl;
        cout << "Area: " << computeArea() << endl;
    }
};

int main() 
{
    Quadrilateral q1;
    double s1, s2, s3, s4;
    double a1, a2;
    cout << "Enter four sides of quadrilateral:\n";
    cin >> s1 >> s2 >> s3 >> s4;
    cout << "Enter two opposite angles (in degrees):\n";
    cin >> a1 >> a2;
    q1.setSides(s1, s2, s3, s4);
    q1.setAngles(a1, a2);
    q1.displayDetails();
    return 0;
}
