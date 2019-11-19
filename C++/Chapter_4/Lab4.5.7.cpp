
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <cctype>
#include <map>
#include <iterator>

using namespace std;


string GetResult(string pattern, string sentence)
{
	string re = "";
	for (int i = 0; i < pattern.length(); i++)
	{
		if (pattern[i] == 'D')
		{
			re += "\\d";
		}
		else if (pattern[i] == 'A')
		{
			re += "([a-z]|[A-Z])";
		}
		else if (pattern[i] == '-')
		{
			re += "-";
		}
		else
		{
			re += ".";
		}
	}
	const regex reg(re);
	string result = "";
	smatch match;
	while (regex_search(sentence, match, reg))
	{
		result += match.str(0) + "\n";
		sentence = sentence.substr(match.position(0) + 1, pattern.length() - 1) + match.suffix().str();
	}
	return result;
}

int main()
{

	cout << "Enter the pattern: ";
	string pattern;
	getline(cin, pattern);
	cout << "Enter the sentence: ";
	string sentence;
	getline(cin, sentence);
	
	sentence = GetResult(pattern, sentence);
	cout << sentence << "\n";

	return 0;
}

