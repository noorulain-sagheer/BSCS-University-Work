#include <iostream>
#include <cmath>
using namespace std;
class Calculator 
{
public:
    static double sum(double a, double b) 
    {
        return a + b;
    }

    static double multiply(double a, double b)
    {
        return a * b;
    }

    static double divide(double a, double b)
    {
        if(b == 0) 
        {
            cout << "Cannot divide by zero!" << endl;
            return 0;
        }
        return a / b;
    }

    static int modulus(int a, int b)
    {
        if(b == 0)
        {
            cout << "Cannot divide by zero!" << endl;
            return 0;
        }
        return a % b;
    }

    static double sinFunc(double angle)
   {
        return sin(angle);
    }

    static double cosFunc(double angle)
    {
        return cos(angle);
    }

    static double tanFunc(double angle) 
    {
        return tan(angle);
    }
};

int main() 
{
    cout << "Sum: " << Calculator::sum(5, 3) << endl;
    cout << "Multiply: " << Calculator::multiply(4, 6) << endl;
    cout << "Divide: " << Calculator::divide(10, 2) << endl;
    cout << "Modulus: " << Calculator::modulus(10, 3) << endl;
    cout << "Sin(30): " << Calculator::sinFunc(30 * 3.14159 / 180) << endl;
    cout << "Cos(60): " << Calculator::cosFunc(60 * 3.14159 / 180) << endl;
    cout << "Tan(45): " << Calculator::tanFunc(45 * 3.14159 / 180) << endl;

    return 0;
}
