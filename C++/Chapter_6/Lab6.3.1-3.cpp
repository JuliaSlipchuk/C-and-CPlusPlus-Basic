
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void FillMap(map<char, int> *map);
vector<string> split(string line, char c);

class Drawing
{
public:
	virtual void Draw()
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				cout << " ";
			}
			else if (i == 1)
			{
				cout << "/";
			}
			else if (i == 2)
			{
				cout << "\\";
			}
			else
			{
				cout << " " << endl;
			}

		}
	};
};
class LineDraw : public Drawing
{
	void Draw() override
	{
		Drawing::Draw();
		for (int i = 4; i < 8; i++)
		{
			if (i == 4 || i == 5)
			{
				cout << "/";
			}
			else if (i == 6)
			{
				cout << "\\";
			}
			else
			{
				cout << "\\" << endl;
			}
		}
	}
};
class StarDraw : public Drawing
{
	void Draw() override
	{
		Drawing::Draw();
		for (int i = 4; i < 8; i++)
		{
			if (i == 4)
			{
				cout << "/";
			}
			else if (i == 5 || i == 6)
			{
				cout << "*";
			}
			else
			{
				cout << "\\" << endl;
			}
		}
	}
};
class PlusDraw : public Drawing
{
	void Draw() override
	{
		Drawing::Draw();
		for (int i = 4; i < 8; i++)
		{
			if (i == 4)
			{
				cout << "/";
			}
			else if (i == 5 || i == 6)
			{
				cout << "+";
			}
			else
			{
				cout << "\\" << endl;
			}
		}
	}
};

struct Position
{
public:
	int numb;
	char lett;
	Position(int numb, char lett);
};
Position::Position(int numb, char lett)
{
	if (numb >= 1 && numb <= 8)
		this->numb = numb;
	else
		this->numb = 1;
	if (lett >= 'a' && lett <= 'h')
		this->lett = lett;
	else
		this->lett = 'a';
}
class Piece
{
public:
	virtual bool canMove(Position start, Position end) = 0;
};
class Man : public Piece
{
private:
	map<char, int> manMap;
public:
	Man()
	{
		FillMap(&manMap);
	}
	bool canMove(Position start, Position end) override
	{
		if (start.lett == 'a')
		{
			if (end.lett == 'b' && (start.numb == end.numb + 1))
				return true;
			return false;
		}
		else if (start.lett == 'h')
		{
			if (end.lett == 'g' && (start.numb == end.numb + 1))
				return true;
			return false;
		}
		else
		{
			if ((manMap[start.lett] == manMap[end.lett] + 1 || manMap[start.lett] == manMap[end.lett] -1) && end.numb == start.numb + 1)
			{
				return true;
			}
			return false;
		}
	}
};
void FillMap(map<char, int> *map)
{
	int index = 1;
	for (char c = 'a'; c <= 'h'; c++)
	{
		map->insert(pair<char, int>(c, index));
		index++;
	}
}
class King : public Piece
{
private:
	map<char, int> kingMap;
public:
	King()
	{
		FillMap(&kingMap);
	}
	bool canMove(Position start, Position end) override
	{
		if (start.lett == 'a')
		{
			for (int i = 1; i < 9 - start.numb; i++)
			{
				if (kingMap[start.lett] == (kingMap[end.lett] + i) && start.numb == end.numb + i)
					return true;
			}
			return false;
		}
		else if (start.lett == 'h')
		{
			for (int i = 1; i < 9 - start.numb; i++)
			{
				if (kingMap[start.lett] == (kingMap[end.lett] - i) && start.numb == end.numb - i)
					return true;
			}
			return false;
		}
		else
		{
			for (int i = 1; i < 8; i++)
			{
				if ((kingMap[start.lett] == (kingMap[end.lett] + i) || kingMap[start.lett] == (kingMap[end.lett] - i) && (start.numb == (end.numb + i) || start.numb == (end.numb - i))))
				{
					return true;
				}
			}
			return false;
		}
	}
};

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
	// first part
	Drawing* drawLine = new LineDraw();
	drawLine->Draw();
	Drawing* starLine = new StarDraw();
	starLine->Draw();
	Drawing* plusLine = new PlusDraw();
	plusLine->Draw();

	// second part
	Man* man = new Man();
	Position* start = new Position(1, 'b');
	Position* end = new Position(3, 'd');
	cout << man->canMove(*start, *end);
	King* king = new King();
	Position* startK = new Position(4, 'd');
	Position* endK = new Position(5, 'f');
	cout << king->canMove(*startK, *endK);

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
