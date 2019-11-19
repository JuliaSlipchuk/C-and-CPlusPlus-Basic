
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <cctype>
#include <map>
#include <iterator>

using namespace std;

bool has_any_digits(string s)
{
	return std::any_of(s.begin(), s.end(), ::isdigit);
}
bool has_any_special_character(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < 48 || (str[i] > 57 && str[i] < 65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122 && str[i] < 127))
			return true;
	}
	return false;
}
string ValidationPass(string password)
{
	if (password.length() != 8)
		return "The password must have 8 characters long";
	else if (!has_any_digits(password))
		return "The password must have at least one digit";
	else if (!any_of(password.begin(), password.end(), isupper))
		return "The password must have at least one upper-case letter";
	else if (!any_of(password.begin(), password.end(), islower))
		return "The password must have at least one lower-case letter";
	else if (!has_any_special_character(password))
		return "The password must have at least one special character";
	else
		return "The password has been validated";
}

int main()
{

	cout << "Enter the password: ";
	string password;
	getline(cin, password);
	string validationRes = ValidationPass(password);
	cout << validationRes;

	return 0;
}

