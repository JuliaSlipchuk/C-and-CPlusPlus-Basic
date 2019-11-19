
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <cctype>
#include <map>
#include <iterator>

using namespace std;


int main()
{

	cout << "Enter 'from': ";
	string from;
	getline(cin, from);
	cout << "Enter 'to': ";
	string to;
	getline(cin, to);
	cout << "Enter the sentence: ";
	string sentence;
	getline(cin, sentence);
	
	size_t pos = sentence.find(from);
	sentence.replace(pos, from.length(), to);


	cout << sentence << "\n";

	

	return 0;
}

