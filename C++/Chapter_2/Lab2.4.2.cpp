
#include <iostream>

using namespace std;

bool isBitPalindrome(int x) {
	int reversed = 0, aux = x;
	while (aux > 0) {
		reversed = (reversed << 1) | (aux & 1);
		aux = aux >> 1;
	}
	return (reversed == x) ? true : false;
}

int main()
{

	int numb;
	bool check;
	cout << "Enter a number: ";
	cin >> numb;
	check = isBitPalindrome(numb);
	check == true ? printf("%d is a bitwise palindrome", numb) : printf("%d is not a bitwise palindrome", numb);

	return 0;
}

