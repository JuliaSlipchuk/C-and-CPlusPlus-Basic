#include <iostream>
#include <string>
#include <vector>

using namespace std;


class NotInRange : public exception
{
private:
    int numbTower1;
    int numbTower2;
    string mess;
public:
    string get_err()
    {
        if (this->numbTower2 == 1 || this->numbTower2 == 2 || this->numbTower2 == 3)
            return this->mess + " " + to_string(numbTower1) + " " + to_string(numbTower2);
        else
            return this->mess + " " + to_string(numbTower1);
    }
    NotInRange(string mess, int nT1)
    {
        this->mess = mess;
        this->numbTower1 = nT1;
    }
    NotInRange(string mess, int nT1, int nT2)
    {
        this->mess = mess;
        this->numbTower1 = nT1;
        this->numbTower2 = nT2;
    }
};
class DiskIncorrectSize : public exception
{
private:
    int diskIncorrSize;
    int currDiskSize;
    string mess;
public:
    string get_err()
    {
        return this->mess + " from: " +  to_string(diskIncorrSize) + " to: " + to_string(currDiskSize);
    }
    DiskIncorrectSize(string mess, int dIS, int cDS)
    {
        this->mess = mess;
        this->diskIncorrSize = dIS;
        this->currDiskSize = cDS;
    }
};
class NoDiskInSourceTower : public exception
{
private:
    string mess;
    int towerNumb;
public:
    string get_err()
    {
        return this->mess + " " + to_string(towerNumb);
    }
    NoDiskInSourceTower(string mess, int tN)
    {
        this->mess = mess;
        this->towerNumb = tN;
    }
};
class TowerOfHanoi
{
private:
    int numb;
    vector<int> disks;
public:
    TowerOfHanoi(int numb)
    {
        this->numb = numb;
    }
    TowerOfHanoi(vector<int> disks, int numb)
    {
        this->numb = numb;
        this->disks = disks;
    }
    static void Move(TowerOfHanoi &first, TowerOfHanoi &second)
    {
        if (first.disks.size() == 0)
            throw NoDiskInSourceTower("No disks in source tower", first.numb);
        else if (second.disks.size() != 0)
        {
            if (first.disks[first.disks.size() - 1] > second.disks[second.disks.size() - 1])
                throw DiskIncorrectSize("Disk incorrect size", first.disks[first.disks.size() - 1], second.disks[second.disks.size() - 1]);
        }
        else
        {
            second.disks.push_back(first.disks[first.disks.size() - 1]);
            first.disks.pop_back();
        }
    }
};

int main()
{
   
    vector<int> forTower1 = {3, 2, 1};
    TowerOfHanoi tower1(forTower1, 1);
    TowerOfHanoi tower2(2);
    TowerOfHanoi tower3(3);
    TowerOfHanoi* towers[3] = {&tower1, &tower2, &tower3};

    int counter = 0;
    string input;
    try
    {
        while (true || counter < 7)
        {
            cout << "Enter: ";
            cin >> input;
            if (input == "-1" && counter < 7)
                continue;
            else if (input == "-1" && counter >= 7)
                break;
            int out[2]={input[0] - '0',input[1] - '0'};
            //out.push_back(input[0] - '0'); out.push_back(input[1] - '0');
            if ((out[0] < 1 || out[0] > 3) && (out[1] < 1 || out[1] > 3))
                throw NotInRange("Not in range of the towers", out[0], out[1]);
            else if (out[0] < 1 || out[0] > 3)
                throw NotInRange("Not in range of the towers", out[0]);
            else if (out[1] < 1 || out[1] > 3)
                throw NotInRange("Not in range of the towers", out[1]);
            else
            {
                TowerOfHanoi::Move(*towers[out[0] - 1], *towers[out[1] - 1]);
                counter++;
            }
        }
    }
    catch (NotInRange &e)
    {
        cout << e.get_err();
    }
    catch (DiskIncorrectSize &e)
    {
        cout << e.get_err();
    }
    catch (NoDiskInSourceTower &e)
    {
        cout << e.get_err();
    }

    return 0;
}
