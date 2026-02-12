#include <iostream>
using namespace std;

class Calculator 
{
public:
 
    int add(int a, int b)
    {
        return a + b;
    }
    double add(double a, double b) 
    {
        return a + b;
    }

    int subtract(int a, int b)
    {
        return a - b;
    }
    double subtract(double a, double b)
    {
        return a - b;
    }

    int multiply(int a, int b) 
    {
        return a * b;
    }
    double multiply(double a, double b) 
    {
        return a * b;
    }

    int divide(int a, int b)
    {
        if (b != 0)
            return a / b;
        else
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
    double divide(double a, double b) 
    {
        if (b != 0)
            return a / b;
        else  
        {
            cout << "Error: Division by zero!" << endl;
            return 0.0;
        }
    }
};

int main() 
 {
    Calculator calc;
    int a = 12, b = 4;
    cout << "Integer Operations:" << endl;
    cout << "Addition: " << calc.add(a, b) << endl;
    cout << "Subtraction: " << calc.subtract(a, b) << endl;
    cout << "Multiplication: " << calc.multiply(a, b) << endl;
    cout << "Division: " << calc.divide(a, b) << endl;

    double x = 12.5, y = 4.2;
    cout << "\nDouble Operations:" << endl;
    cout << "Addition: " << calc.add(x, y) << endl;
    cout << "Subtraction: " << calc.subtract(x, y) << endl;
    cout << "Multiplication: " << calc.multiply(x, y) << endl;
    cout << "Division: " << calc.divide(x, y) << endl;
    return 0;
}
