
#include <iostream>

using namespace std;

int main()
{
	int numb;
	cout << "Enter a positive number: ";
	cin >> numb;
	if (numb >= 0)
	{
		int count = 0;
		while (numb)
		{
			count += numb & 1;
			numb >>= 1;
		}
		cout << count;
	}
	else
	{
		cout << "You entered invalid data";
	}

	return 0;
}

