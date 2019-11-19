
#include <iostream>
#include <string>

using namespace std;

class Square
{
public:
	Square(double side);
	void set_side(double side);
	double get_side();
	double get_area();
	void print();
private:
	double side;
	double area;
};
Square::Square(double side)
{
	if (side >= 0)
	{
		this->side = side;
		this->area = side * side;
	}
	else
	{
		this->side = 0;
		this->area = 0;
	}
}
void Square::set_side(double side)
{
	if (side >= 0)
	{
		this->side = side;
		this->area = side * side;
	}
}
void Square::print()
{
	cout << "Square: side = " << this->side << " area = " << this->area << endl;
}

class AdHocSquare
{
public:
	AdHocSquare(double side);
	void set_side(double side);
	double get_area();
private:
	double side;
};
class LazySquare
{
public:
	LazySquare(double side);
	void set_side(double side);
	double get_area();
private:
	double side;
	double area;
	bool side_changed;
};
AdHocSquare::AdHocSquare(double side)
{
	if (side >= 0)
		this->side = side;
	else
		this->side = 0;
}
void AdHocSquare::set_side(double side)
{
	if (side >= 0)
	{
		this->side = side;
	}
}
double AdHocSquare::get_area()
{
	return this->side * this->side;
}
LazySquare::LazySquare(double side)
{
	if (side >= 0)
	{
		this->side = side;
		this->area = side * side;
	}
	else
	{
		this->side = 0;
		this->area = 0;
	}
}
void LazySquare::set_side(double side)
{
	if (side >= 0)
	{
		this->side = side;
		this->side_changed = true;
	}
}
double LazySquare::get_area()
{
	if (this->side_changed)
	{
		return side * side;
	}
	else
	{
		return this->area;
	}
}


int main()
{
	
	// thisd part
	// change AdHocSquare & LazySquare
		
	return 0;
}

