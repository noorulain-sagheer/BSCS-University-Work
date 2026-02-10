/*Write a function that would calculate an item’s sale price based on the item’s purchase price plus 
the tax. The function prototype is double Sale_Price (double, double). The first 
parameter is the purchase price and the second parameter is the tax. The function will return the 
sale price of the product. its formula is: 
Tax Amount= purchase price *(Tax Rate/100) 
The formula of calculating the final price of an 
item is: Sale Price = Purchase price + Tax Amount*/
#include <iostream>
using namespace std;
double Sale_Price(double purchasePrice, double taxRate) 
{
    double taxAmount = purchasePrice * (taxRate / 100.0);
    double finalPrice = purchasePrice + taxAmount;
    return finalPrice;
}
int main() 
{
    double price, tax;
    cout << "Enter purchase price: ";
    cin >> price;
    cout << "Enter tax rate (%): ";
    cin >> tax;
    double salePrice = Sale_Price(price, tax);
    cout << "Sale Price of the item: " << salePrice << endl;
    return 0;
}
