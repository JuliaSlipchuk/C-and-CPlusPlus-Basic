
#include <iostream>

using namespace std;

void increment(int &val, int increm = 1)
{
	val += increm;
}
int main(void) 
{
	int var = 0;
	for (int i = 0; i < 10; i++)
		if (i % 2)
			increment(var);
		else
			increment(var, i);
	cout << var << endl;
	return 0;
}

