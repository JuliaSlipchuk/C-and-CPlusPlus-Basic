
#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
#include <vector>

using namespace std;

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(std::string input) = 0;
};
class DummyValidator : public StringValidator 
{
public:
	bool isValid(std::string input) override;
};
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
bool DummyValidator::isValid(std::string password)
{
	return true;
}
class ExactValidator : public StringValidator
{
private:
	string password;
public:
	ExactValidator(string password)
	{
		this->password = password;
	}
	bool isValid(std::string input) override;
};
bool ExactValidator::isValid(std::string password)
{
	if (this->password == password)
		return true;
	else
		return false;
}
class MinLengthValidator : public StringValidator
{
private:
	int minLenght;
public:
public:
	MinLengthValidator(int minLenght);
	bool isValid(std::string input) override;
};
MinLengthValidator::MinLengthValidator(int minLen)
{
	if (minLen >= 1)
		this->minLenght = minLen;
	else
		this->minLenght = 5;
}
bool MinLengthValidator::isValid(std::string password)
{
	if (password.length() > this->minLenght)
		return true;
	else
		return false;
}
class MaxLengthValidator : public StringValidator
{
private:
	int maxLenght;
public:
public:
	MaxLengthValidator(int maxLenght);
	bool isValid(std::string input) override;
};
MaxLengthValidator::MaxLengthValidator(int maxLen)
{
	if (maxLen >= 1)
		this->maxLenght = maxLen;
	else
		this->maxLenght = 5;
}
bool MaxLengthValidator::isValid(std::string password)
{
	if (password.length() < this->maxLenght)
		return true;
	else
		return false;
}
class PatternValidator : public StringValidator
{
private:
	string pattern;
public:
	PatternValidator(string patt);
	bool isValid(std::string input) override;
};
PatternValidator::PatternValidator(string patt)
{
	this->pattern = patt;
	for (int i = 0; i < patt.length(); i++)
	{
		if (patt[i] == ' ')
		{
			this->pattern = "A";
			break;
		}
	}
}
bool PatternValidator::isValid(std::string password)
{
	string pattReg = "";
	transform(password.begin(), password.end(), password.begin(), ::tolower);
	for (int i = 0; i < this->pattern.length(); i++)
	{
		if (this->pattern[i] == 'A')
		{
			pattReg += "([a-z])";
		}
		else if (this->pattern[i] == 'D')
		{
			pattReg += "\d";
		}
		else if (this->pattern[i] == '?')
		{
			pattReg += ".";
		}
		else
		{
			pattReg += this->pattern[i];
		}
	}
	regex reg(pattReg);
	if (regex_match(password, reg))
		return true;
	else
		return false;
}
void printValid(StringValidator *validator, string input)
{
	cout << "The string '" << input << "' is "
		<< (validator->isValid(input) ? "valid \n" : "invalid \n");
}

int main()
{
	// first part
	DummyValidator* dummy = new DummyValidator();
	printValid(dummy, "hello");
	cout << endl;
	ExactValidator exact("secret");
	printValid(&exact, "hello");
	printValid(&exact, "secret");

	// second part
	int n;
	cin >> n;
	cout << "MinLengthValidator" << endl;
	MinLengthValidator min(6);
	printValid(&min, "hello");
	printValid(&min, "welcome");
	cout << endl;
	cout << "MaxLengthValidator" << endl;
	MaxLengthValidator max(6);
	printValid(&max, "hello");
	printValid(&max, "welcome");
	cout << endl;
	cout << "PatternValidator" << endl;
	PatternValidator digit("D");
	printValid(&digit, "there are 2 types of sentences in the world");
	printValid(&digit, "valid and invalid ones");
	cout << endl;

	return 0;
}

