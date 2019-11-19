#include <iostream>
#include <exception>
#include <iterator>

using namespace std;

float internaldiv(float arg1, float arg2)
{
    if (arg2 == 0)
        throw "You cannot divide by zero!";
    return arg1 / arg2;
}
float div(float arg1, float arg2)
{
    float res;
    try
    {
        res = internaldiv(arg1, arg2);
    }
    catch (...)
    {
        res = -1;
    }
    return res;
}
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


int main(void)
{
    float r, a, b;
    while(cin >> a)
    {
        cin >> b;
        if(div(a,b) != -1)
            cout << div(a, b) << endl;
        else
            cout << "Are you kidding me? \n Your input is not valid. You can't divide by zero." << endl;
    }
 
    return 0;
}
