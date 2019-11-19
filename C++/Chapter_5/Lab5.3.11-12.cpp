
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <string>

using namespace std;

class FarmAnimal 
{
public:
	FarmAnimal(double water_consumption);
	FarmAnimal(int weight);
	void setWaterConsumption(double waterConsumption);
	double getWaterConsumption();
	void set_weight(int weight);
	int get_weight();
private:
	double water_consumption;
	int weight;
};
void FarmAnimal::set_weight(int weight)
{
	if (weight >= 5)
		this->weight = weight;
	else
		this->weight = 10;
}
int FarmAnimal::get_weight()
{
	return this->weight;
}
FarmAnimal::FarmAnimal(double water_consumption) 
{
	this->water_consumption = water_consumption;
}
FarmAnimal::FarmAnimal(int weight)
{
	this->set_weight(weight);
}
void FarmAnimal::setWaterConsumption(double waterConsumption)
{
	if (waterConsumption >= 1)
		this->water_consumption = waterConsumption;
	else
		this->water_consumption = 1;
}
double FarmAnimal::getWaterConsumption() 
{
	return water_consumption;
}
class DummyAnimal : public FarmAnimal 
{
public:
	DummyAnimal();
};
DummyAnimal::DummyAnimal() : FarmAnimal(10.0)
{
}
class DoublingAnimal : public FarmAnimal
{
public:
	DoublingAnimal(double given_water_consumption);
};
DoublingAnimal::DoublingAnimal(double given_water_consumption)
	: FarmAnimal(2 * given_water_consumption) 
{
}
void printConsumption(FarmAnimal animal)
{
	cout << "This animal consumes " << animal.getWaterConsumption()
		<< " liters of water" << endl;
}class ConsumptionAccumulator
{
public:
	ConsumptionAccumulator();
	double getTotalConsumption();
	void addConsumption(FarmAnimal animal);
private:
	double total_consumption;
};
ConsumptionAccumulator::ConsumptionAccumulator() :
	total_consumption(0)
{
}
double ConsumptionAccumulator::getTotalConsumption()
{
	return total_consumption;
}
void ConsumptionAccumulator::addConsumption(FarmAnimal animal)
{
	total_consumption += animal.getWaterConsumption();
}
class Sheep : public FarmAnimal
{
public:
	Sheep(int weight);
};
Sheep::Sheep(int weight) : FarmAnimal(weight)
{
	this->setWaterConsumption((this->get_weight() * 1.1) / 10);
}
class Horse : public FarmAnimal
{
public:
	Horse(int weight);
};
Horse::Horse(int weight) : FarmAnimal(weight)
{
	this->setWaterConsumption((this->get_weight() * 6.8) / 100);
}
class Cow : public FarmAnimal
{
public:
	Cow(int weight);
};
Cow::Cow(int weight) : FarmAnimal(weight)
{
	this->setWaterConsumption((this->get_weight() * 8.6) / 100);
}
vector<string> split(string line, char c)
{
	vector<string> result;
	string tmpstr = "";
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] != c)
			tmpstr += line[i];
		else
		{
			result.push_back(tmpstr);
			tmpstr = "";
		}
	}
	if (line[line.length() - 1] != ' ')
		result.push_back(tmpstr);
	return result;
}
int main()
{
	// eleven part
	FarmAnimal animalA(5);
	DummyAnimal animalB;
	DoublingAnimal animalC(21);
	cout << "animalA consumes " << animalA.getWaterConsumption()
		<< " liters of water." << endl;
	cout << "What about the others?" << endl;
	printConsumption(animalB);
	printConsumption(animalC);

	// twelve part
	ConsumptionAccumulator accumulator;
	char* input = new char[100];
	while (true)
	{
		cout << "Enter the animal and it weight: ";
		cin.getline(input, 100);
		if (*input == '\0')
		{
			break;
		}
		vector<string> out = split(string(input), ' ');
		if (out[0] == "sheep")
		{
			Sheep sheep(atoi(out[1].c_str()));
			accumulator.addConsumption(sheep.getWaterConsumption());
		}
		else if (out[0] == "horse")
		{
			Horse horse(atoi(out[1].c_str()));
			accumulator.addConsumption(horse.getWaterConsumption());
		}
		else if (out[0] == "cow")
		{
			Cow cow(atoi(out[1].c_str()));
			accumulator.addConsumption(cow.getWaterConsumption());
		}
		else
		{
			cout << "You entered undefined input";
		}
	}
	cout << accumulator.getTotalConsumption();

	return 0;
}
