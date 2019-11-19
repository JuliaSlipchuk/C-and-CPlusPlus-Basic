
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{

	int banknotes[5] = { 50, 20, 10, 5, 1 };
	int amount;
	string result;
	cout << "Enter an amount: ";
	cin >> amount;
	if (amount > 0)
	{
		while (amount != 0)
		{
			if (amount >= 50)
			{
				amount -= 50;
				result += " 50";
			}
			else if (amount >= 20)
			{
				amount -= 20;
				result += " 20";
			}
			else if (amount >= 10)
			{
				amount -= 10;
				result += " 10";
			}
			else if (amount >= 5)
			{
				amount -= 5;
				result += " 5";
			}
			else
			{
				amount -= 1;
				result += " 1";
			}
		}
		cout << result;
	}
	else
	{
		cout << "You entered invalid data";
	}

	return 0;

}

