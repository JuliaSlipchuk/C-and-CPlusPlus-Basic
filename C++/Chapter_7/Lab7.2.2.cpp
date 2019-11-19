#include <iostream>
#include <exception>
#include <iterator>

using namespace std;


class MyException : public std::exception
{
private:
    char* mess;
public:
    char* get_mess()
    {
        return this->mess;
    }
    MyException(char* mess)
    {
        this->mess = mess;
    }
};
float square_area(float side)
{
    if (side > 0)
        return  side*side;
    throw MyException("Your input is not valid. The area can't be negative.");
}
float rectangle_area(float a, float b)
{
    if (a > 0 && b > 0)
        return a*b;
    throw MyException("Your input is not valid. The area can't be negative.");
}

int main(void)
{

    float a, b, r;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    try
    {
        float rsquare = square_area(a);
        float rrectangle = rectangle_area(a,b);
        cout << rsquare << endl << rrectangle << endl;
    }
    catch (MyException &e)
    {
        cout << e.get_mess() << endl;
    }

    return 0;
}
