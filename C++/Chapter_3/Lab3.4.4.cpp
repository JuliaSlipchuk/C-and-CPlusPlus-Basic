
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
int countLeapYears(Date d)
{
	int years = d.year;
	if (d.month <= 2)
		years--;
	return years / 4 - years / 100 + years / 400;
}

int daysBetween(Date d1, Date d2) 
{
	if (d1.year > d2.year || (d1.year == d2.year && d1.month > d2.month) || (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day))
	{
		return -1;
	}
	else
	{
		long int n1 = d1.year * 365 + d1.day;
		for (int i = 0; i < d1.month - 1; i++)
			n1 += monthLength(d1.year, i);
		n1 += countLeapYears(d1);
		long int n2 = d2.year * 365 + d2.day;
		for (int i = 0; i < d2.month - 1; i++)
			n2 += monthLength(d2.year, i);
		n2 += countLeapYears(d2);
		return (n2 - n1);
	}
}

int main()
{
	
	Date since, till;
	cout << "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;
	cout << "Enter second date (y m d): ";
	cin >> till.year >> till.month >> till.day;
	cout << daysBetween(since, till) << endl;

	

	return 0;

}
    
