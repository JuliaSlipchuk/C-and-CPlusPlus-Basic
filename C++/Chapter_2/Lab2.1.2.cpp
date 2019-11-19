
#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
	
	float grossprice, taxrate, netprice, taxvalue;
	cout << "Enter a gross price: ";
	cin >> grossprice;
	cout << "Enter a tax rate: ";
	cin >> taxrate;

	if (taxrate >= 100)
	{
		printf("taxrate can not be greater or equals 100");
	}
	else
	{
		netprice = grossprice / (1 + taxrate / 100);
		taxvalue = taxrate * netprice / 100;

		cout << "Net price: " << netprice << endl;
		cout << "Tax value: " << taxvalue << endl;
	}

	return 0;
}


