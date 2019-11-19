
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{

	int numb;
	cout << "Enter a number: ";
	cin >> numb;
	long long curr = 0, prev, prevprev;
	if (numb == 1 || numb == 2)
	{
		cout << "1";
	}
	else if (numb >= 3)
	{
		prevprev = 1; prev = 1;
		for (int i = 2; i < numb; i++)
		{
			curr = prev + prevprev;
			prevprev = prev;
			prev = curr;
		}
		cout << curr;
	}
	else
	{
		cout << "You entered not positive number";
	}

	
	return 0;
}

