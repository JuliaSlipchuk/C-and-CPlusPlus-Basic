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

class ValueAndBoundaries
{
private:
    int value;
    long minLimit;
    long maxLimit;
public:
    ValueAndBoundaries(int val, long minLim, long maxLim)
    {
        this->value = val;
        this->minLimit = minLim;
        this->maxLimit = maxLim;
    }
    int get_value()
    {
        return this->value;
    }
    void add(int val);
    void subtract(int val);
};
void ValueAndBoundaries::add(int val)
{
    if (this->value + val < this->minLimit || this->value + val > maxLimit)
        throw MyException("Value could exceed limit");
    this->value += val;
}
void ValueAndBoundaries::subtract(int val)
{
    if (this->value - val < this->minLimit || this->value - val > maxLimit)
        throw MyException("Value could exceed limit");
    this->value -= val;
}

int main(void)
{
    
    ValueAndBoundaries* vB1 = new ValueAndBoundaries(10, 0, 100);
    ValueAndBoundaries* vB2 = new ValueAndBoundaries(5, 0, 50);
    try
    {
        vB1->add(90);
        cout << "Value in vB1: " << vB1->get_value() << endl;
        vB2->subtract(3);
        cout << "Value in vB2: " << vB2->get_value() << endl;
    }
    catch (MyException &e)
    {
        cout << e.get_mess() << endl;
    }

    return 0;
}
