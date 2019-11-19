
#include <iostream>
#include <ctime>

using namespace std;


bool isPrime(int num) 
{
	if (num <= 1)
		return false;
	for (int i = 2; i < num; i++)
		if (num % i == 0)
			return false;

	return true;
}
int main()
{
	
	for (int i = 0; i <= 21; i++)
		if (isPrime(i))
			cout << i << " ";
	cout << endl;

	return 0;

}
    
