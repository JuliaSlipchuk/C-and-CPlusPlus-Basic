#include <iostream>
#include <string>
#include <fstream>
#include <cerrno>
#include <vector>

using namespace std;


void tokenize(string const &str, const char delim, vector<string> &out)
{
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}
inline bool isInteger(const std::string & s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char * p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}
class IP
{
private:
    int* ip;
    int range;
public:
    IP(string ip, int range)
    {
        bool check = false;
        int numb = range;
        if (numb > 0)
        {
            while(numb%2 == 0)
                numb /= 2;
            if (numb == 1 && (range >= 1 || range <= 256))
            {
                check = true;
            }
        }
        if (check)
        {
            vector<string> out;
            tokenize(ip, '.', out);
            if (out.size() != 4)
                throw "Exception - incorrect parts count";
            this->ip = new int[4];
            for (int i = 0; i < out.size(); i++)
            {
                if (atoi(out[i].c_str()) < 0 || atoi(out[i].c_str()) > 255)
                    throw "Exception - invalid ip number";
                this->ip[i] = atoi(out[i].c_str());
            }
            this->range = range;
        }
        else
        {
            throw "Exception - invalid range";
        }
    }
    void ChangeIp()
    {
        for (int i = 3; i >= 0; i--)
        {
            if (ip[i] + 1 <= 255)
            {
                ip[i]++;
                return;
            }
            else
            {
                ip[i] = 0;
                if (i == 0)
                    throw  "Exception - too large range for this ip";
            }
        }
    }
    void print()
    {
        while(range > 0)
        {
            this->ChangeIp();
            string res = "";
            for (int i = 0; i < 4; i++)
            {
                if (i == 3)
                    cout << ip[i] << endl;
                else
                    cout << ip[i] << ".";
            }
            range--;
        }
    }
};

int main()
{
    
    try
    {
        IP* ip1 = new IP("212.111.212.128", 2);
        ip1->print();
        cout << "\n";
        IP* ip2 = new IP("212.112.212.128", 4);
        ip2->print();
        cout << "\n";
        IP* ip3 = new IP("212.113.212.128", 6);
        ip3->print();
        cout << "\n";
        IP* ip4 = new IP("212.114.212.328", 4);
        ip4->print();
        cout << "\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

    return 0;
}
