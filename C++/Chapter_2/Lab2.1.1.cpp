
#include <iostream>
#include <string>

using namespace std;

int main(void) 
{

	int year;
	cout << "Enter a year: ";
	cin >> year;
	if (year % 4 != 0)
	{
		printf("%d is a common year", year);
	}
	else if (year % 100 != 0)
	{
		printf("%d is a leap year", year);
	}
	else if (year % 400 != 0)
	{
		printf("%d is a common year", year);
	}
	else
	{
		printf("%d is a leap year", year);
	}

	
	return 0;
}


