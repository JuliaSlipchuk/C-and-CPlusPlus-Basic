
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

string GetTemplate(string values, string templateStr)
{
	map <string, string> myMap;
	const char delim = ',';
	vector<string> out;
	tokenize(values, delim, out);
	for (int i = 0; i < out.size(); i++)
	{
		int equalPos = out[i].find('=');
		myMap.insert(pair<string, string>(out[i].substr(0, equalPos), out[i].substr(equalPos + 1)));
	}
	string subRes = "";
	bool open = false;
	bool check = false;
	size_t pos = 0;
	for (int i = 0; i < templateStr.length(); i++)
	{
		if (templateStr[i] == '[')
		{
			open = true;
			pos = templateStr.find('[', i - 1);
		}
		else if (templateStr[i] == ']')
		{
			open = false;
			subRes = "";
		}
;		if (open && templateStr[i] != '[')
		{
			subRes += templateStr[i];
		}
		if (myMap.find(subRes) != myMap.end())
		{
			int diff = subRes.length() + 2 - myMap[subRes].length();
			i -= diff; i += 2;
			templateStr.replace(pos, subRes.length() + 2, myMap[subRes]);
			subRes = "";
			open = false;
		}
	}
	return templateStr;
}
int main()
{

	cout << "Enter values: ";
	string values;
	getline(std::cin, values);
	cout << "Enter templates: ";
	string templateStr;
	getline(std::cin, templateStr);
	templateStr = GetTemplate(values, templateStr);
	std::cout << templateStr << "\n";

	return 0;
}

