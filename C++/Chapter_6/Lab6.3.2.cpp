
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void FillMap(map<char, int> *map);
vector<string> split(string line, char c);



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


int main()
{
	// second part
	Man* man = new Man();
	Position* start = new Position(1, 'b');
	Position* end = new Position(3, 'd');
	cout << man->canMove(*start, *end);
	King* king = new King();
	Position* startK = new Position(4, 'd');
	Position* endK = new Position(5, 'f');
	cout << king->canMove(*startK, *endK);

	return 0;
}

