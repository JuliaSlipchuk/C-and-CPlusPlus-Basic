
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


int main()
{
	for (int yr = 1995; yr < 2017; yr++)
		cout << yr << " -> " << isLeap(yr) << endl;

	return 0;

}
    
