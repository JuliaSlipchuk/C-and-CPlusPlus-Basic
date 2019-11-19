#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Stack
{
public:
    stack<int> stck;
};
ostream& operator << (std::ostream &os, Stack &stck)
{
    if (stck.stck.size() == 0)
        throw "Exception: the stack is empty";
    os << stck.stck.top() << "\n";
    stck.stck.pop();
    return  os;
}
istream& operator >> (std::istream& is, Stack& stck)
{
    int newVal;
    is >> newVal;
    stck.stck.push(newVal);
    return is;
}

int main()
{

    Stack stck;
    int count, out;
    cout << "Enter count of elements in stack: ";
    cin >> count;
    try
    {
        if (count <= 0)
            throw "The count of values cannot be equal or less than 0";
        for (int i = 0; i < count; i++)
        {
            cin >> stck;
        }
        cout << "Enter count of values, which you want to see: ";
        cin >> out;
        if (out <= 0)
            throw "The count of values cannot be equal or less than 0";
        for (int i = 0; i < out; i++)
        {
            cout << stck;
        }
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

    return 0;
}
