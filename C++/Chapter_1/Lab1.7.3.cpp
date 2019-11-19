#include <iostream>

using namespace std;

int main()
{

	int ipPart1, ipPart2, ipPart3, ipPart4;
	cout << "Enter first part of ip : ";
	cin >> ipPart1; cout << "\n";
	cout << "Enter second part of ip : ";
	cin >> ipPart2; cout << "\n";
	cout << "Enter third part of ip : ";
	cin >> ipPart3; cout << "\n";
	cout << "Enter fourth part of ip : ";
	cin >> ipPart4; cout << "\n";

	if (ipPart1 <= 255 && ipPart2 <= 255 && ipPart3 <= 255 && ipPart4 <= 255)
	{
		cout << "Ip-address : " << ipPart1 << "." << ipPart2 << "." << ipPart3 << "." << ipPart4;
	}
	else
	{
		cout << "Ones or more between your numbers in greater than 255";
	}

	return 0;
}


