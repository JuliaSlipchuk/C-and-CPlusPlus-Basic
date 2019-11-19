
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <cctype>
#include <map>
#include <iterator>

using namespace std;

void tokenize(string const &str, const char delim, vector<string> &out)
{
	size_t start;
	size_t end = 0;
	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}
inline bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}
string ipCorrect(string ip)
{
	const char delim = '.';
	vector<string> out;
	tokenize(ip, delim, out);
	if (out.size() <= 3)
	{
		return "Incorrect parts count";;
	}
	else if (out.size() >= 5)
	{
		return "Too many parts";
	}
	for (auto &ip : out)
	{
		if (!isInteger(ip))
		{
			return "Only digits and dots allowed";
		}
		else if (stoi(ip) > 255 && stoi(ip) <= 999)
		{
			return "Too big a value of a part";
		}
		else if (ip.length() >= 4)
		{
			return "Too many characters in a part";
		}
		else
		{
			return "Correct IP";
		}
	}
}

int main()
{
	
	string ip;
	cout << "Enter an IP-address: ";
	getline(cin, ip);
	string isCorrect = ipCorrect(ip);
	cout << isCorrect.c_str();


	return 0;
}

