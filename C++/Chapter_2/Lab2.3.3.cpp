
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
 
	int power;
	unsigned long long result = 2;
	cout << "Enter a power: ";
	cin >> power;
	if (power > 1)
	{
		for (int i = 2; i <= power; i++)
		{
			result *= 2;
		}
		cout << "2 in power" << power << " = " << result;
	}
	else
	{
		cout << "You entered invalid power";
	}
	

	return 0;
}

