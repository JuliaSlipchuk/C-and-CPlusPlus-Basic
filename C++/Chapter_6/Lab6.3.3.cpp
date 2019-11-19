
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> split(string line, char c);


class IPAddress
{
protected:
	string ipAddrr;
public:
	IPAddress(string ip)
	{
		this->ipAddrr = ip;
	}
	virtual void print();
};
void IPAddress::print()
{
	cout << this->ipAddrr;
}
class IPAddressChecked : public IPAddress
{
private:
	bool isCorrect;
public:
	IPAddressChecked(string ip) : IPAddress(ip) 
	{ }
	void print() override
	{
		IPAddress::print();
		vector<string> out = split(ipAddrr, '.');
		if (out.size() != 4)
		{
			this->isCorrect = false;
		}
		else
		{
			for (int i = 0; i < out.size(); i++)
			{
				if (atoi(out[i].c_str()) < 0 || atoi(out[i].c_str()) > 255)
				{
					this->isCorrect = false;
					break;
				}
				this->isCorrect = true;
			}
		}
		if (this->isCorrect)
			cout << " - Correct";
		else
			cout << " - Not correct";
	}
};
vector<string> split(string line, char c)
{
	vector<string> result;
	string tmpstr = "";
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] != c)
			tmpstr += line[i];
		else
		{
			result.push_back(tmpstr);
			tmpstr = "";
		}
	}

	if (line[line.length() - 1] != ' ')
		result.push_back(tmpstr);

	return result;
}

int main()
{

	// third part
	string firstIP, secondIP, thirdIP;
	cout << "Enter the first ip-address: ";
	cin >> firstIP;
	IPAddress* first = new IPAddress(firstIP);
	first->print();
	cout << "\n Enter the second ip-address: ";
	cin >> secondIP;
	IPAddressChecked* second = new IPAddressChecked(secondIP);
	second->print();
	cout << "\n Enter the third ip-address: ";
	cin >>thirdIP;
	IPAddressChecked* third = new IPAddressChecked(thirdIP);
	third->print();

	return 0;
}

