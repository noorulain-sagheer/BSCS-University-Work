#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter a number to find whether it is prime of not : " << endl;
	cin >> n;
	int flag = 1;
	for (int k = 2;k <= n / 2;k++)
	{
		if (n % k == 0)
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		cout << " prime number " << endl;
	}
	else
	{
		cout << " composite number " << endl;
	}
  return 0;
}

}
