#include <iostream>
#include <string>
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
class IpHeader
{
private:
    string sourceIp;
    string destinIp;
public:
    static inline bool isInteger(const std::string & s)
    {
        if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

        char * p;
        strtol(s.c_str(), &p, 10);

        return (*p == 0);
    }
    static::string ipCorrect(string ip)
    {
        const char delim = '.';
        vector<string> out;
        tokenize(ip, delim, out);
        if (out.size() <= 3)
        {
            return "Incorrect parts count";;
        }
        else if (out.size() >= 5)
        {
            return "Too many parts";
        }
        for (auto &ip : out)
        {
            if (!IpHeader::isInteger(ip))
            {
                return "Only digits and dots allowed";
            }
            else if (stoi(ip) > 255 && stoi(ip) <= 999)
            {
                return "Too big a value of a part";
            }
            else if (ip.length() >= 4)
            {
                return "Too many characters in a part";
            }
            else
            {
                continue;
            }
        }
        return  "Correct IP";
    }
    bool checkIp(string ip)
    {
        if (IpHeader::ipCorrect(ip) == "Correct IP")
            return true;
        return false;
    }
    IpHeader(string source, string destin)
    {
        if (!checkIp(source), !checkIp(destin))
        {
            throw "Invalid IP Header - Source IP Address and Destination Ip Address are invalid \n";
        }
        else if (!checkIp(source))
        {
            throw "Invalid IP Header - Source IP Address is invalid \n";
        }
        else if (!checkIp(destin))
        {
            throw "Invalid IP Header - Destination Ip Address is invalid \n";
        }
        else
        {
            this->sourceIp = source;
            this->destinIp = destin;
            cout << "Valid IP Header \n";
        }
    }
};


int main()
{
    try
    {
        IpHeader header("212.122.212.11","212.112.212.12");
        IpHeader header1("212.112.212.333","212.112.212.33");
    }
    catch (const char* err)
    {
        cout<<err;
    }

    
    return 0;
}
