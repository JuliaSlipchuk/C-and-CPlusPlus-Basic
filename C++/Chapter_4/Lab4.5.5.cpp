
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
string ToLowerCase(string str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

int main()
{
	
	cout << "Enter stop words: ";
	string stop_words;
	getline(cin, stop_words);
	cout << "Enter the sentence: ";
	string sentence;
	getline(cin, sentence);
	
	const char delimStopWords = ',';
	vector<string> outStopWords;
	tokenize(stop_words, delimStopWords, outStopWords);
	const char delimSentence = ' ';
	vector<string> outSentence;
	tokenize(sentence, delimSentence, outSentence);
	for (int i = 0; i < outSentence.size(); i++)
	{
		for (int j = 0; j < outStopWords.size(); j++)
		{
			if (ToLowerCase(outSentence[i]) == ToLowerCase(outStopWords[j]))
			{
				outSentence.erase(outSentence.begin() + i);
				i--;
			}
		}
	}
	sentence = "";
	for (int i = 0; i < outSentence.size(); i++)
	{
		sentence += outSentence[i] + " ";
	}
	RemoveWhiteSpace(sentence);
	std::cout << sentence << "\n";
	
	return 0;
}

