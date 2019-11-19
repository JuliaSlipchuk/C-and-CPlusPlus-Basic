
#include <iostream>
#include <ctime>

using namespace std;

bool isLeap(int year)
{
	if (year % 4 != 0)
	{
		return false;
	}
	else if (year % 100 != 0)
	{
		return true;
	}
	else if (year % 400 != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int monthLength(int year, int month) 
{
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			return 29;
		else
			return 28;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
		return 31;
	else
		return 30;
}
struct Date 
{
	int year;
	int month;
	int day;
};
int dayOfYear(Date date) 
{
	int daysNumb = 0;
	for (int i = 1; i < date.month; i++)
	{
		daysNumb += monthLength(date.year, i);
	}
	return daysNumb + date.day;
}

int main()
{
	
	Date d;
	cout << "Enter year month day: ";
	cin >> d.year >> d.month >> d.day;
	cout << dayOfYear(d) << endl;

	return 0;

}
    
