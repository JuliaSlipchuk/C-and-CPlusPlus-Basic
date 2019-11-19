
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{

	int numb;
	cout << "Enter an odd number greater than 2: ";
	cin >> numb;
	if (numb < 3 || numb % 2 == 0)
	{
		cout << "You entered invalid data";
	}
	else
	{
		int diff = 4;
		long prev = 1, curr = 5;
		for (int i = 5; i <= numb; i+=2)
		{
			prev = curr;
			diff += 8;
			curr = prev + diff;
		}
		cout << curr;
	}

	return 0;
}

