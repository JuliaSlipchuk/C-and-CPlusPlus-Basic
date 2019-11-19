
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Enter count: ";
	int c;
	cin >> c;

	int ** g = new int*[c];
	for (int i = 0; i < c; i++)
	{
		int n;
		cout << "Enter the number of marks: ";
		cin >> n;
		g[i] = new int[n+1];
		g[i][0] = n;
		for (int j = 1; j <= n; j++)
		{
			cin >> g[i][j];
		}
	}

	for (int i = 0; i < c; i++)
	{
		float finalGrad = 0;
		string grades;
		for (int j = 1; j <= g[i][0]; j++)
		{
			finalGrad += g[i][j];
			grades += to_string(g[i][j]) + " ";
		}
		finalGrad = finalGrad / g[i][0];

		printf("Course %d: final %f, grades: %s \n", i + 1, finalGrad, grades.c_str());
	}

	return 0;
}
