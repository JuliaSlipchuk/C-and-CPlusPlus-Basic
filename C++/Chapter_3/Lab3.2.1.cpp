
#include <iostream>

using namespace std;

int main()
{
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);
	int res = *(vector);
	for (int i = 0; i < n; i++)
	{
		if (res > *(vector + i))
			res = *(vector + i);
	}
	cout << res;


	return 0;
}

