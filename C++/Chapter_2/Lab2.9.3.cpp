
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	
	int vector[] = { 1, 7, 3, 7, 3, 7, 1 };
	bool ispalindrome = true;
	int n = sizeof(vector) / sizeof(vector[0]);
	for (int i = 0; i < n / 2; i++)
	{
		if (vector[i] == vector[n - i - 1])
			continue;
		ispalindrome = false;
	}
	if (ispalindrome)
		cout << "It's a palindrome";
	else
		cout << "It isn't a palindrome";
	cout << endl;

	
	return 0;

}

