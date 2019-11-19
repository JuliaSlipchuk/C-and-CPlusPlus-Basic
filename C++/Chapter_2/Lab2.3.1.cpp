
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	int c0, count = 0;
	cout << "Enter a positive number :";
	cin >> c0;
	if (c0 > 0)
	{
		while (c0 > 1)
		{
			if (c0 % 2 == 0)
			{
				c0 /= 2;
			}
			else
			{
				c0 = 3 * c0 + 1;
			}
			printf("%d \n", c0);
			count++;
		}
		printf("steps = %d", count);
	}
	else
	{
		printf("You entered 0 or negative number");
	}

	

	return 0;
}

