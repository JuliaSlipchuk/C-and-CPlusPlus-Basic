#include <iostream>

using namespace std;

int main(void)
{

    int a = 0, b = 0, c = 0;
    cout << "Enter divided: ";
    cin >> a;
    cout << "Enter divider: ";
    cin >> b;
    try
    {
        if (b == 0)
            throw "You cannot divide by zero!";
        c = a / b;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
    cout << c << endl;

    return 0;
}
