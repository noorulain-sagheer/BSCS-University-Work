/*Write a C++ program for a new ice cream vendor called PopSalon. The management of PopSalon has 
decided that they are going to sell their popcorn in 11 different flavors namely: chocolate, English toffee, 
salted caramel, caramel, jalapeno, cheese, spiced cheese, plain sated, buttered, salt and pepper, and garlic. 
Carefully design the program by observing the following rules. 
● PopSalon is charging Rs. 100 for small pack, Rs. 250 for medium sized pack, Rs. 500 for large 
sized pack and Rs. 750 large size tin pack. Hence you will need a function to determine the size of 
the pack and based on that the price. If a user enters option number other than the ones displayed, 
your program should display an invalid input message and ask the user to re-enter the option 
number. 
● PopSalon allows its customers to purchase a gift wrapper with their popcorn. If the customer wants 
to purchase the wrapper he will have to pay an additional Rs 50. This amount should be added to 
the total amount payable by the user. 
● If the customer asks for chocolate sauce, caramel sauce, or melted cheese as an additional topping 
then he will have to pay an additional amount of Rs. 50, Rs. 30 and, Rs. 60 respectively. Design a 
function that will be called if the customer chooses an additional topping. 
● The program should show a menu that asks the customer for his requirements and then displays the 
final payable amount with full details about the flavor, the size of the pack and details regarding 
any additional toppings. 
● For service quality inspection and monthly product promotions, the program should ask the user to 
enter his/her contact details including name, mobile number and email address, and select between 
the options good, neutral and bad against the quality of the service provided. 
● In the end create a class destructor that displays a thank you message to the user. Design your 
program using sound OOP practices. Carefully determine the data members, member functions, 
access specifiers, activities to be performed in the constructor. Make sure that you use good naming 
conventions in your code. A good design can earn you higher marks.*/
#include<iostream>
using namespace std;
class PopSalon
{
private:
	string flavor;
	string pack_size;
	int price;
	string gift_wrapper;
	string topping;
	double total_price;
	string name;
	string contact_num;
	string email_id;
	string quality_of_service;
public:
	PopSalon()
	{
		flavor = "";
		pack_size = "";
		gift_wrapper = "";
		topping = "";
		total_price = 0.0;
		name = "";
		contact_num = "";
		email_id = "";
		quality_of_service = "";
		cout << " WELCOME TO POPSALON " << endl;
	}
	void menu_display()
	{

		cout << " PLEASE CHOOSE A FLAVOR " << endl;
		cout << " 1.CHOCOLATE " << endl;
		cout << " 2.ENGLISH TOFFEE " << endl;
		cout << " 3.SALTED CARAMEL " << endl;
		cout << " 4.CARAMEL " << endl;
		cout << " 5.JALAPENO " << endl;
		cout << " 6.CHEESE " << endl;
		cout << " 7.SPICED CHEESE " << endl;
		cout << " 8.PLAIN SATED " << endl;
		cout << " 9.BUTTERED " << endl;
		cout << " 10.SALT PEPPER " << endl;
		cout << " 11.GARLIC " << endl;
		
	}
	void select_flavor()
	{
		int choice;
		cout << " ENTER YOUR OPTION NUMBER : " << endl;
		cin >> choice;
		do
		{

			switch (choice)
			{
			case 1:
				flavor = "CHOCOLATE";
				break;
			case 2:
				flavor = "ENGLISH TOFFEE ";
				break;
			case 3:
				flavor = "SALTED CARAMEL";
				break;
			case 4:
				flavor = "CARAMEL";
				break;
			case 5:
				flavor = "JALAPENO";
				break;
			case 6:
				flavor = "CHEESE";
				break;
			case 7:
				flavor = "SPICED CHEESE";
				break;
			case 8:
				flavor = "PLAIN SATED";
				break;
			case 9:
				flavor = "BUTTERED";
				break;
			case 10:
				flavor = "SALT PEPPER";
				break;
			case 11:
				flavor = "GARLIC";
				break;
			default:
				cout << " INVALID INPUT , PLEASE RE_ENTER YOUR CHOICE : " << endl;
				menu_display();
				cin >> choice;
				break;
			}
		}
			while (choice < 1 || choice > 11);
		
	}
		
	void PackSize_menu()
	{

		cout << " SELECT PACK SIZE : " << endl;
		cout << " 1.SMALL PACK (100) " << endl;
		cout << " 2.MEDIUM PACK (250) " << endl;
		cout << " 3.LARGE PACK (500) " << endl;
		cout << " 4.LARGE SIZE TIN PACK (750) " << endl;
	}
	void PACK_SIZE()
	{
			int select;
			cout << " ENTER OPTION NUMBER : " << endl;
			cin >> select;
			do
			{
				switch (select)
				{
				case 1:
					pack_size = "SMALL";
					price = 100;
					total_price = price;
					break;
				case 2:
					pack_size = "MEDIUM";
					price = 250;
					total_price = price;
					break;
				case 3:
					pack_size = "LARGE";
					price = 500;
					total_price = price;
					break;
				case 4:
					pack_size = "LARGE TIN PACK";
					price = 750;
					total_price = price;
					break;
				default:
					cout << " INVALID INPUT, PLEASE RE_ENTER THE CHOICE NUMBER : " << endl;
					PackSize_menu();
					cin >> select;

				}
			} while (select < 1 || select>4);
	}
	void GiftWrapper()
	{
		char ch;
		cout << " DO YOU WANT TO PURCHASE GIFT WRAPPER ?(RS.50) " << endl;
		cout << " Y/N " << endl;
		cin >> ch;
		
			if (ch == 'Y' || ch == 'y')
			{
				total_price = total_price + 50;
				gift_wrapper = "YES ADDITIONAL GIFT WRAPPER IS REQUIRED! ";

			}
			else if (ch == 'n' || ch == 'N')
			{
				total_price = total_price + 0;
				gift_wrapper = "NO ADDITIONAL GIFT WRAPPER REQUIRED! ";
			}
			else
			{
				cout << " WRONG INPUT " << endl;
				gift_wrapper = "YOU DONOT TELL WHETHER YOU WANT GIFT WRAPPER OR NOT!";
			}
		
	}
	void extra_topping()
	{
		char ch;
		int op;
		cout << " DO YOU WANT SOME EXTRA TOPPINGS ? " << endl;
		cout << " ENTER Y/N " << endl;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{   
			topping = "YES ADDITIONAL TOPPING IS REQUIRED! ";
			cout << " HERE IS THE LIST: " << endl;
			cout << " 1.CHOCOLATE SAUCE (RS.50) " << endl;
			cout << " 2.CARAMEL SAUCE (RS.30) " << endl;
			cout << " 3.MELTED CHEESE (RS.60) " << endl;
			cout << " ENTER OPTION NUMBER : " << endl;
			cin >> op;
			switch (op)
			{
			case 1:
				total_price = total_price + 50;
				break;
			case 2:
				total_price = total_price + 30;
				break;
			case 3:
				total_price = total_price + 60;
				break;
			default:
				cout << " WRONG INPUT " << endl;
				break;
			}
		}
		else if(ch=='n'||ch=='N')
		{
			topping = "NO ADDITIONAL TOPPING REQUIRED! ";
			total_price = total_price + 0;
		}
		else
		{
			cout << "WRONG INPUT " << endl;
			topping = " YOU DONOT TELL WHETHER YOU WANT TOPPING OR NOT!";
		}

	}
	void product_promotion_details()
	{
		int choice;
		cout << " ENTER YOUR NAME : " << endl;
		cin >> name;
		cout << " ENTER YOUR PHONE NUMBER : " << endl;
		cin >> contact_num;
		cout << " ENTER YOUR E_MAIL ID : " << endl;
		cin >> email_id;
		cout << " ENTER YOUR REVIEW ABOUT QUALITY OF SERVICE PROVIDED" << endl;
		cout << " 1.GOOD " << endl;
		cout << " 2.NEUTRAL " << endl;
		cout << " 3.BAD " << endl;
		cout << " ENTER OPTION NUMBER : " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			quality_of_service = " GOOD ";
			break;
		case 2:
			quality_of_service = " NEUTRAL ";
			break;
		case 3:
			quality_of_service = " BAD ";
			break;
		default:
			cout << " WRONG INPUT! " << endl;
			quality_of_service = " I DONOT WANT TO SHARE ANYTHING ABOUT IT! ";
		}

	}
	void final_menu()
	{
		cout << endl;
		cout << " ---------------------- " << endl;
		cout << " YOUR CHOICE OF POPCORN IS : " << endl;
		cout << " FLAVOR = " << flavor << endl;
		cout << " SIZE OF PACK = " << pack_size << endl;
		cout << " GIFT WRAPPER = " << gift_wrapper << endl;
		cout << " EXTRA TOPPINGS = " << topping << endl;
		cout << " TOTAL PAYABLE AMOUNT = " << total_price << endl;
		
	}
	
	~PopSalon()
	{
		cout << endl;
		cout<< " THANK YOU " << name << " FOR CHOOSING POPALON, WE HOPE YOU ENJOYED YOUR POPSALON!!" << endl;
	}

};
void main()
{
	PopSalon obj;
	obj.menu_display();
	obj.select_flavor();
	obj.PackSize_menu();
	obj.PACK_SIZE();
	obj.GiftWrapper();
	obj.extra_topping();
	obj.product_promotion_details();
	obj.final_menu();
}
