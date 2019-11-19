
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



void RemoveWhiteSpace(string & sentence)
{
	for (int i = sentence.size() - 1; i > 0; i--)
	{
		if (sentence[i] == ' ' && sentence[i] == sentence[i - 1])
		{
			sentence.erase(sentence.begin() + i);
		}
	}
}

int main()
{
	
	string sentence;
	cout << "Enter a sentence: ";
	getline(cin, sentence);
	RemoveWhiteSpace(sentence);
	cout << sentence << endl;
	
	return 0;
}

