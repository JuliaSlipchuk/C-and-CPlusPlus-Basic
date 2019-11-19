
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <cctype>
#include <map>
#include <iterator>

using namespace std;

bool isAnagram(string first, string second)
{
	if (first.length() != second.length())
	{
		return false;
	}
	else
	{
		int count = first.length();
		for (int i = 0; i < first.length(); i++)
		{
			for (int j = 0; j < second.length(); j++)
			{
				if (first[i] == second[j])
				{
					first.erase(first.begin() + i);
					second.erase(second.begin() + j);
					i--; j--;
					count--;
					break;
				}
			}
		}
		if (count == 0)
			return true;
		else
			return false;
	}
}

int main()
{

	cout << "Enter the first word: ";
	string first;
	getline(cin, first);
	cout << "Enter the second word: ";
	string second;
	getline(cin, second);

	bool check = isAnagram(first, second);
	if (check)
		cout << "anagrams";
	else
		cout << "not anagrams";

	
	return 0;
}

