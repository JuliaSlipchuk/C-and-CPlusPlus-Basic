
#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
	
	int year, month, day;
	cout << "Enter a year: ";
	cin >> year;
	cout << "\n Enter a month: ";
	cin >> month;
	cout << "\n Enter a day: ";
	cin >> day; cout << "\n";

	if (year >= 1900 && year <= 2019 && month >= 1 && month <= 12 && day >= 1)
	{
		month -= 2;
		if (month <= 0)
		{
			month += 12;
			year -= 1;
		}
		month = month * 83 / 32;
		month += day;
		month += year;
		month += year / 4;
		month -= year / 100;
		month += year / 400;
		int dayNumb = month % 7;
		cout << dayNumb;
	}
	else
	{
		cout << "You entered invalid data";
	}

	
	return 0;
}


