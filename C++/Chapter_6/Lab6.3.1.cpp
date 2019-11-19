
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

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



int main()
{
	// first part
	Drawing* drawLine = new LineDraw();
	drawLine->Draw();
	Drawing* starLine = new StarDraw();
	starLine->Draw();
	Drawing* plusLine = new PlusDraw();
	plusLine->Draw();

	
	return 0;
}

