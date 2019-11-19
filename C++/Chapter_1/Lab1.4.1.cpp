
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	
	float numb = 5;
	float result = numb + 5;
	std::cout << "result: " << result << " expected result: 10 \n";
	result = numb * 10 + 5 * 5;
	std::cout << "result: " << result << " expected result: 75 \n";
	result = numb - 10 / 2;
	std::cout << "result: " << result << " expected result: 0 \n";
	result = (int)numb % 2 * 2 + 1;
	std::cout << "result: " << result << " expected result: 3 \n";

	return 0;
}
