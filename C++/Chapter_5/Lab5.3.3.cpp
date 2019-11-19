
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	void set_id(int id);
	int get_id();
	void set_capacity(int capacity);
	void set_reserved(int reserved);
	void add(int n);
	void cancel(int n);
	static FlightBooking* create(int id, int capacity);
	static void deleteF (vector<FlightBooking*> &vector, int id);
	static void add(int id, int n, vector<FlightBooking*> &vector);
	static void cancel(int id, int n, vector<FlightBooking*> &vector);
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
void FlightBooking::set_id(int id)
{
	this->id = id;
}
int FlightBooking::get_id()
{
	return this->id;
}
void FlightBooking::set_capacity(int capacity)
{
	if (capacity >= 1)
		this->capacity = capacity;
	else
		this->capacity = 10;
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
FlightBooking* FlightBooking::create(int id, int capacity)
{
	if (capacity >= 1 && id >= 1)
		return new FlightBooking(id, capacity, 0);
	else
	{
		cout << "Cannot perform this operation";
		return NULL;
	}
}
int select(vector<FlightBooking*> &vector, int id)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i]->get_id() == id)
		{
			return i;
		}
	}
	return -1;
}
void FlightBooking::deleteF(vector<FlightBooking*> &vector, int id)
{
	int indexFlight = select(vector, id);
	if (indexFlight != -1)
	{
		vector.erase(vector.begin() + indexFlight);
	}
	else
		cout << "Cannot perform this operation";
}
void FlightBooking::add(int id, int n, vector<FlightBooking*> &vector)
{
	int flightIndex = select(vector, id);
	if (flightIndex != -1)
	{
		if (vector[flightIndex]->reserved + n <= vector[flightIndex]->capacity)
			vector[flightIndex]->reserved += n;
		else
			cout << "Cannot perform this operation";
	}
	else
		cout << "Cannot perform this operation";
}
void FlightBooking::cancel(int id, int n, vector<FlightBooking*> &vector)
{
	int flightIndex = select(vector, id);
	if (flightIndex != 1)
	{
		if (vector[flightIndex]->reserved - n >= 0)
			vector[flightIndex]->reserved -= n;
		else
			cout << "Cannot perform this operation";
	}
	else
		cout << "Cannot perform this operation";
}

int main() {
	
	vector<FlightBooking*> flights;
	int capacity = 0, reserved = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	flights.push_back(&booking);
	string command;
	while (true)
	{
		cout << "Enter a command: ";
		cin >> command;
		if (command == "quit")
			break;
		int id;
		int numb;
		cout << "Enter the id: ";
		cin >> id;
		cout << "Enter the number: ";
		cin >> numb;
		if (command == "add")
			booking.add(id, numb, flights);
		else if (command == "cancel")
			booking.cancel(id, numb, flights);
		else
			printf("undefined");
		booking.printStatus();
	}

	return 0;
}


