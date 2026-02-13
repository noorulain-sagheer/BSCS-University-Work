#include <iostream>
using namespace std;
class Calculation;
class Data 
{
    float a, b;
public:
    Data(float x, float y) 
   {    
        a = x;
        b = y;
    }
    friend class Calculation;
    friend void display(Data d);
};

void display(Data d) 
{
    cout << "a = " << d.a << endl;
    cout << "b = " << d.b << endl;
}

class Calculation 
{
public:
    float squareOfSum(Data d) 
    {
        return d.a*d.a + d.b*d.b + 2*d.a*d.b;
    }

    float squareOfDifference(Data d) 
    {
        return d.a*d.a + d.b*d.b - 2*d.a*d.b;
    }
};

int main() 
{
    float x, y;
    cout << "Enter values of a and b: ";
    cin >> x >> y;
    Data d(x, y);
    Calculation c;
    display(d);
    cout << "Square of Sum: " << c.squareOfSum(d) << endl;
    cout << "Square of Difference: " << c.squareOfDifference(d) << endl;
    return 0;
}
