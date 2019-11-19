

#include <iostream>
#include <cmath>

using namespace std;

long long SumRange(int N)
{
	long long sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += i;
	}
	return sum;
}

int main()
{
	int N;
	cout << "Enter a number (N): ";
	cin >> N;
	long long result = SumRange(N);
	cout << "result = " << result;
	
	return 0;
}

