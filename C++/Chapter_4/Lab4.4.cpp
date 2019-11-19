
#include <iostream>
#include <map>
#include <string>

using namespace std;

int Count(string str, char ch)
{
	int res = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ch)
			res++;
	}
	return res;
}
int main()
{
	string input;
	cout << "Enter string: ";
	getline(cin, input);
	map <char, int> myMap;
	char ch;
	for (int i = 0, ch = 'a'; i < 26; ++i, ++ch)
	{
		myMap.insert(pair<char, int>(ch, Count(input, ch)));
	}
	for (int i = 0, ch = 'a'; i < 26; ++i, ++ch)
	{
		printf("%c -> %d \n", ch, myMap[ch]);
	}
}
