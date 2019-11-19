
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	void add(int n);
	void cancel(int n);
private:
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus()
{
	double percent = 0;
	if (this != nullptr)
	{
		percent = 100.0 * ((double)this->reserved / this->capacity);
		printf("Flight %d: %d/%d (%lf) seats taken", this->id, this->reserved, this->capacity, percent);
	}
}

void FlightBooking::set_reserved(int reserved)
{
	if (reserved < 0)
		this->reserved = 0;
	else if (reserved > this->capacity)
		cout << "Cannot perform this operation \n";
	else
		this->reserved = reserved;
}
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->set_capacity(capacity);
	this->set_reserved(reserved);
	if (this->reserved > this->capacity)
	{
		reserved = 0;
		cout << "Cannot perform this operation \n";
	}
}
void FlightBooking::add(int n)
{
	if (n > 0)
	{
		this->set_reserved(this->reserved + n);
	}
}
void FlightBooking::cancel(int n)
{
	if (this->reserved >= n)
	{
		this->set_reserved(this->reserved - n);
	}
}


int main() {

	int capacity = 0, reserved = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	string command;
	while (true)
	{
		cout << "Enter a command: ";
		cin >> command;
		if (command == "quit")
			break;
		cout << "Enter the number: ";
		int numb;
		if (command == "add")
		{
			cin >> numb;
			booking.add(numb);
		}
		else if (command == "cancel")
		{
			cin >> numb;
			booking.cancel(numb);
		}
		else
		{
			printf("undefined");
		}
	}

	return 0;
}


