
//Q1. Write a program that takes radius of circle from user and calculate the area of circle using the following formula. Area = πr2.

#include <iostream>
using namespace std;

int main() {
    float radius, area;

    cout << "Enter radius of circle: ";
    cin >> radius;

    area = 3.1416 * radius * radius;

    cout << "Area of circle is: " << area << endl;

    return 0;
}
