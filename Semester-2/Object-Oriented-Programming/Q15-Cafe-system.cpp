class cafe_service
{
protected:
	string order_id;
	double price;
public:
	cafe_service()
	{
		order_id = "ord#0";
		price = 0.0;
	}
	cafe_service(string id, double pr)
	{
		order_id = id;
		price = pr;
	}
};
class staff_service :public cafe_service
{
protected:
	double service_fee;
	int cabin_num;
	double total_charges;
public:
	staff_service(double fee, int c_n,string id,double pr)
	{
		service_fee = fee;
		cabin_num = c_n;
		order_id = id;
		price = pr;
	}
	double Total_charges()
	{
		total_charges = service_fee + price;
		return total_charges;
	}
	void display()
	{
		cout << " Order id: " << order_id << endl;
		cout << " Price: " << price << endl;
		cout << " Service fee: " << service_fee << endl;
		cout << " Cabin number: " << cabin_num << endl;
		cout << " Total charges: " << total_charges << endl;
	}
};
void main()
{
	staff_service obj(140.0, 2, "23jk", 34.7);
	obj.Total_charges();
	obj.display();
}
