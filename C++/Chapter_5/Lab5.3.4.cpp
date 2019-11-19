
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

class Gym
{
private:
	int id;
	string name;
	int countMonths;
public:
	void set_id(int id);
	void set_name(string name);
	void set_countMonth(int count);
	int get_id();
	string get_name();
	int get_countMonth();
	static Gym* create(int id, string name, vector<Gym*> &vector);
	static void deleteG(int id, vector<Gym*> &vector);
	static void extend(int id, int n, vector<Gym*> &vector);
	static void cancel(int id, vector<Gym*> &vector);
};
void Gym::set_id(int id)
{
	this->id = id;
}
void Gym::set_name(string name)
{
	this->name = name;
}
void Gym::set_countMonth(int count)
{
	this->countMonths = count;
}
int Gym::get_id()
{
	return this->id;
}
string Gym::get_name()
{
	return this->name;
}
int Gym::get_countMonth()
{
	return this->countMonths;
}
Gym* Gym::create(int id, string name, vector<Gym*> &vector)
{
	Gym* gym = new Gym();
	gym->id = id; gym->name = name;
	vector.push_back(gym);
	return gym;
}
int select(vector<Gym*> &vector, int id)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i]->get_id() == id)
			return i;
	}
	return -1;
}
void Gym::deleteG(int id, vector<Gym*> &vector)
{
	int index = select(vector, id);
	if (index != -1)
	{
		delete vector[index];
		vector.erase(vector.begin() + index);
	}
	else
		cout << "Cannot perform this operation";
}
void Gym::extend(int id, int n, vector<Gym*> &vector)
{
	int index = select(vector, id);
	if (index != -1 && n >= 0 && n <= 100)
	{
		int currCount = vector[index]->countMonths + n;
		if (currCount <= 100)
			vector[index]->countMonths += n;
		else
			cout << "Cannot perform this operation";
	}
	else
		cout << "Cannot perform this operation";
}
void Gym::cancel(int id, vector<Gym*> &vector)
{
	int index = select(vector, id);
	if (index != -1)
	{
		vector[index]->countMonths = 0;
	}
	else
		cout << "Cannot perform this operation";
}

int main()
{
	vector<Gym*> gyms;
	string command;
	int id;
	char name[100];
	int monthCount;
	while (true)
	{
		cout << "Enter command: ";
		cin >> command;
		if (command == "quit")
			break;
		cout << "Enter the id: ";
		cin >> id;
		if (command == "create")
		{
			cout << "Enter the name: ";
			cin.ignore();
			cin.getline(name, sizeof(name));
			Gym* gym = Gym::create(id, string(name), gyms);
		}
		else if (command == "extend")
		{
			cout << "Enter a count of months: ";
			cin >> monthCount;
			Gym::extend(id, monthCount, gyms);
		}
		else if (command == "cancel")
		{
			Gym::cancel(id, gyms);
		}
		else if (command == "delete")
		{
			Gym::deleteG(id, gyms);
		}
		else
		{
			cout << "Command is undefined";
		}
		int index = select(gyms, id);
		if (index != -1)
			cout << "Member " << id << " : " << name << ", subscription valid for " << gyms[index]->get_countMonth() << " months \n";
	}

	return 0;
}

