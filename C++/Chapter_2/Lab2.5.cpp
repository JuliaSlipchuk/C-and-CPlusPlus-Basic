
#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int operation;
	float numb1, numb2;
	cout << "Choose the operation (0 - exit, 1 - addition, 2 - subtraction, 3 -multiplication, 4 - division)";
	cin >> operation;

	while (operation != 0)
	{
		if (operation < 0 || operation >= 5)
		{
			printf("You entered incorrect operation");
			continue;

		}

		cout << "Enter the first number: ";
		cin >> numb1;
		cout << "Enter the second number: ";
		cin >> numb2;

		switch (operation)
		{
			case 1 :
				printf("%f + %f = %f", numb1, numb2, numb1 + numb2);
				break;
			case 2:
				printf("%f - %f = %f", numb1, numb2, numb1 - numb2);
				break;
			case 3:
				printf("%f * %f = %f", numb1, numb2, numb1 * numb2);
				break;
			case 4:
				printf("%f / %f = %f", numb1, numb2, numb1 / numb2);
				break;
			default:
				printf("You entered invalid operation");
		}

		cout << "Choose the operation (0 - exit, 1 - addition, 2 - subtraction, 3 -multiplication, 4 - division)";
		cin >> operation;
	}

	return 0;
}
