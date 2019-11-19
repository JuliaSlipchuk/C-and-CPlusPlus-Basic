
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <cctype>
#include <map>
#include <iterator>

using namespace std;


char ToUpperCase(char ch)
{
	ch = toupper(ch);
	return ch;
}
string ChangeSentence(string sentence)
{
	string result;
	bool star = false; 
	bool underLine = false;
	for (int i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] == '*' && !star)
			star = true;
		else if (sentence[i] == '*' && star)
			star = false;
		if (sentence[i] == '_' && !underLine)
			underLine = true;
		else if (sentence[i] == '_' && underLine)
			underLine = false;
		if (star && underLine)
		{
			result.push_back(ToUpperCase(sentence[i]));
			result.push_back(' ');
		}
		else if (star)
		{
			result.push_back(ToUpperCase(sentence[i]));
		}
		else if (underLine)
		{
			result.push_back(sentence[i]);
			result.push_back(' ');
		}
		if (!star && !underLine)
		{
			result.push_back(sentence[i]);
		}
	}
	for (int i = 0; i < result.length(); i++)
	{
		if (result[i] == '*' || result[i] == '_')
			result.erase(i, 1);
	}
	return result;
}

int main()
{
	
	cout << "Enter the sentence: ";
	string sentence;
	getline(cin, sentence);
	sentence = ChangeSentence(sentence);
	cout << sentence << "\n";
	

	return 0;
}

