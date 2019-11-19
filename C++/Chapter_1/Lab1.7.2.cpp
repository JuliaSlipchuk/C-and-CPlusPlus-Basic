
#include <iostream>

using namespace std;

int main()
{
	float first, second;
	float epsilon = 0.000001;

	cout << "Enter first numb : ";
	cin >> first; cout << "\n";
	cout << "Enter second numb : ";
	cin >> second; cout << "\n";

	if (abs(first / second - 1) <= epsilon)
	{
		cout << "they are equals";
	}
	else
	{
		cout << "they are NOT equals";
	}

	
	return 0;
}


