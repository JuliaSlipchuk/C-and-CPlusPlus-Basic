
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main(void) 
{
	int maxball;
	int ballsno;
	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;
	srand(time(NULL));
	if (maxball < ballsno)
	{
		int temp = ballsno;
		ballsno = maxball;
		maxball = temp;
	}
	int* vector = new int[ballsno];
	bool check;
	for (int i = 0; i < ballsno; i++)
	{
		check = false;
		int rnd = rand() % 100 - 1;
		for (int j = 0; j < i; j++)
		{
			if (rnd == vector[j])
				check = true;
		}
		if (check || rnd > maxball)
		{
			i--;
			continue;
		}
		vector[i] = rnd;
	}
	string mass;
	for (int i = 0; i < ballsno; i++)
	{
		mass += to_string(vector[i]) + " ";
	}
	printf("%s", mass.c_str());

	return 0;
}
