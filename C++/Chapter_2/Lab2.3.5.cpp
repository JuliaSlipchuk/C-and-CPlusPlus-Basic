
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{

	int n;
	cout << "Enter a positive value, greater than 1: ";
	cin >> n;
	if (n > 1 && n <= 24)
	{
		cout << '+';
		for (int i = 0; i < n; i++)
			cout << '_';
		cout << '+' << endl;
		for (int i = 0; i < n; i++) {
			cout << '|';
			for (int j = 0; j < n; j++)
				cout << ' ';
			cout << '|' << endl;
		}
		cout << '+';
		for (int i = 0; i < n; i++)
			cout << '_';
		cout << '+' << endl;
	}
	else if (n > 24)
	{
		cout << "Sorry, the side is too big";
	}
	else
	{
		cout << "You entered invalid value";
	}
	

	return 0;
}

