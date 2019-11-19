

#include <iostream>

using namespace std;

int main()
{
	
	int matrix[10][10] = { };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			*(*(matrix + i) + j) = (i + 1) * (j + 1);
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}

	return 0;
}

