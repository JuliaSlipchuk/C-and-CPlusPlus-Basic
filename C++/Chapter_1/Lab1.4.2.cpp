
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float pi = 3.14159265359;
	float x, y;
	cout << "Enter value for x: ";
	cin >> x;
	y = (pow(x, 2) / (pow(pi, 2) * (pow(x, 2) + 0.5))) * (1 + (pow(x, 2) / (pow(pi, 2) * (pow(x, 2) - 0.5) * (pow(x, 2) - 0.5))));
	cout << "y = " << y;

	
	return 0;
}

