#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum State
{
    Start,
    Intermediate1,
    Intermediate2,
    Intermediate3,
    Intermediate4,
    End
};

class FSM
{
public:
    State st;
    vector<State> visited;
    FSM()
    {
        st=Start;
        visited.push_back(st);
    }
    void printVisisted()
    {
        string way="";
        sort(visited.begin(),visited.end());
        for (int i = 0; i < visited.size(); i++) {
            switch (visited[i]){
                case Start: way+="1(Start) ";
                    break;
                case Intermediate1: way+="2 ";
                    break;
                case Intermediate2: way+="3 ";
                    break;
                case Intermediate3: way+="4 ";
                    break;
                case Intermediate4: way+="5 ";
                    break;
                case End: way+="6(Stop)";
                    break;
            }
        }
        cout<<way<<endl;
    }
    friend istream &operator >>(istream &is, FSM &fsm)
    {
        int val;
        is>>val;
        fsm.visited.push_back(static_cast<State>(--val));
        fsm.st= static_cast<State>(val);
        return  is;
    }
};


int main()
{

    FSM fs;
    cin>>fs;
    cin>>fs;
    cin>>fs;
    fs.printVisisted();

    return 0;
}
