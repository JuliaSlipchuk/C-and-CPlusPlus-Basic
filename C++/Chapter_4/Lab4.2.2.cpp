
#include <iostream>
#include <cmath>

using namespace std;


bool is_close(double a, double b, double tolerance) 
{
	double diff = a - b;
	if (fabs(diff) > tolerance)
		return false;
	else
		return true;
}
int main()
{
	
	if (0.3 == 3 * 0.1) 
	{
		cout << "The numbers are equal";
	}
	else 
	{
		cout << "The numbers are not equal";
	}
	cout << endl;
	if (is_close(0.3, 3 * 0.1, 0.00000001)) 
	{
		cout << "The numbers are close enough";
	}
	else 
	{
		cout << "The numbers are not close enough";
	}
	cout << endl;
	// this should work regardless of the argument order
	if (is_close(3 * 0.1, 0.3, 0.00000001)) 
	{
		cout << "The numbers are still close enough";
	}
	else {
		cout << "The numbers are not close enough";
	}
	cout << endl;
	if (is_close(3 * 0.1, 0.31, 0.00000001)) {
		cout << "The numbers are still close enough";
	}
	else 
	{
		cout << "The numbers are not close enough";
	}
	cout << endl;

	return 0;
}

