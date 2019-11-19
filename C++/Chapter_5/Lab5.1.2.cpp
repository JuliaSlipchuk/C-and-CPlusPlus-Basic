
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

int main()
{

	Square s(4);
	print(&s);
	s.set_side(2.0);
	print(&s);
	s.set_side(-33.0);
	print(&s);

	return 0;
}

