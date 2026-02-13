#include <iostream>
using namespace std;

template <class T>
T area(T radius)
{
    return 0.5 * 3.14159 * radius * radius;
}

template <class T>
T area(T length, T width) 
{
    return 3 * length * width;
}

int main()
{
    double r = 5.0;
    cout << "Half area of circle: " << area(r) << endl;
    int l = 4, w = 6;
    cout << "Triple area of rectangle: " << area(l, w) << endl;
    return 0;
}
