
#include <iostream>
#include <ctime>

using namespace std;


int main()
{
	
	time_t t = time(NULL);
	tm tl = *localtime(&t);
	cout << tl.tm_year + 1900 << "-" << tl.tm_mon + 1 << "-" << tl.tm_mday << endl;


	return 0;

}
    
