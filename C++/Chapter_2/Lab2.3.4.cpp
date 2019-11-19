
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
 
	int power;
	double result = 1;
	cout << "Enter a negative power: ";
	cin >> power;
	if (power > 0)
	{
		for (int i = 1; i <= power; i++)
		{
			result *= 2;
		}
		result = 1. / result;
		cout.precision(20);
		cout << "2 in power " << power << " = " << result;
	}
	else if (power == 0)
	{
		cout << "2 in power 0 = 1";
	}
	else
	{
		cout << "You entered invalid power";
	}

	
	return 0;
}

