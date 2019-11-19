
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;

class Point2D 
{
public:
	Point2D(double x, double y);
	string toString();
	double distanceTo(Point2D that);
	double get_x();
	double get_y();
private:
	double x;
	double y;
};
Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}
string Point2D::toString()
{
	return to_string(this->x) + " " + to_string(this->y);
}
double Point2D::get_x()
{
	return this->x;
}
double Point2D::get_y()
{
	return this->y;
}
double Point2D::distanceTo(Point2D that)
{
	double result;
	result = sqrt((that.x - this->x) * (that.x - this->x) + (that.y - this->y) * (that.y - this->y));
	return result;
}
class Line2D {
public:
	Line2D(double slope, double y_intercept);
	Line2D(Point2D pointA, Point2D pointB);
	string toString();
	bool contains(Point2D point);
private:
	double slope;
	double y_intercept;
};
string Line2D::toString()
{
	if (this->y_intercept > 0)
		return "y = " + to_string(round(this->slope)) + "x + " + to_string(round(this->y_intercept));
	else
		return "y = " + to_string(round(this->slope)) + "x - " + to_string(abs(round(this->y_intercept)));
}
Line2D::Line2D(Point2D pointA, Point2D pointB)
{
	double slope = (pointB.get_y() - pointA.get_y()) / (pointB.get_x() - pointA.get_x());
	double y_intercept = (-pointA.get_x() * (pointB.get_y() - pointA.get_y())) / (pointB.get_x() - pointA.get_x()) + pointA.get_y();
	this->slope = slope;
	this->y_intercept = y_intercept;
}
Line2D::Line2D(double slope, double y_intercept)
{
	this->slope = slope;
	this->y_intercept = y_intercept;
}
bool Line2D::contains(Point2D point)
{
	double res = this->slope * point.get_x() + this->y_intercept;
	if (point.get_y() == res)
		return true;
	else
		return false;
}
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
char* deleteComma(char str[100])
{
	string *strStr = new string();
	for (int i = 0; i < strlen(str) + 1; i++)
	{
		if (str[i] != ',')
			strStr->push_back(str[i]);
	}
	char* result = const_cast<char*>(strStr->c_str());
	return result;
}
int main()
{
	// eight part
	double x1, x2, y1, y2;
	char* firstPoint = new char[100];
	char* secondPoint = new char[100];
	cout << "Enterthe first point: ";
	cin.getline(firstPoint, 100);
	firstPoint = deleteComma(firstPoint);
	cout << "Enter the second point: ";
	cin.getline(secondPoint, 100);
	secondPoint = deleteComma(secondPoint);
	vector<string> first = split(firstPoint, ' ');
    vector<string> second = split(secondPoint, ' ');
	Point2D point1(atof(first[0].c_str()), atof(first[1].c_str()));
	Point2D point2(atof(second[0].c_str()), atof(second[1].c_str()));
	double distance = point1.distanceTo(point2);
	cout << distance;

	// nine part
	double x1, x2, y1, y2;
	char* firstPoint = new char[100];
	char* secondPoint = new char[100];
	cout << "Enterthe first point: ";
	cin.getline(firstPoint, 100);
	firstPoint = deleteComma(firstPoint);
	cout << "Enter the second point: ";
	cin.getline(secondPoint, 100);
	secondPoint = deleteComma(secondPoint);
	vector<string> first = split(firstPoint, ' ');
	vector<string> second = split(secondPoint, ' ');
	Point2D point1(atof(first[0].c_str()), atof(first[1].c_str()));
	Point2D point2(atof(second[0].c_str()), atof(second[1].c_str()));
	Line2D line(point1, point2);
	cout << line.toString();

	// ten part
	double x1, x2, y1, y2;
	char* firstPoint = new char[100];
	char* secondPoint = new char[100];
	cout << "Enter the first point (for line): ";
	cin.getline(firstPoint, 100);
	firstPoint = deleteComma(firstPoint);
	cout << "Enter the second point (for line): ";
	cin.getline(secondPoint, 100);
	secondPoint = deleteComma(secondPoint);
	vector<string> first = split(firstPoint, ' ');
	vector<string> second = split(secondPoint, ' ');
	Point2D point1(atof(first[0].c_str()), atof(first[1].c_str()));
	Point2D point2(atof(second[0].c_str()), atof(second[1].c_str()));
	Line2D line(point1, point2);
	double x3, y3;
	char* thirdPoint = new char[100];
	cout << "Enter the third point: ";
	cin.getline(thirdPoint, 100);
	thirdPoint = deleteComma(thirdPoint);
	vector<string> third = split(thirdPoint, ' ');
	Point2D point3(atof(third[0].c_str()), atof(third[1].c_str()));
	if (line.contains(point3))
		cout << "collinear";
	else
		cout << "not collinear";

	return 0;
}
