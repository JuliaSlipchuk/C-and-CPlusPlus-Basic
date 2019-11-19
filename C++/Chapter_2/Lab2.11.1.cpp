
#include <iostream>

using namespace std;

struct time
{
	int hour;
	int minute;
};

int main()
{

	time start;
	int duration;
	cout << "Enter hours: ";
	cin >> start.hour;
	cout << "\nEnter minutes: ";
	cin >> start.minute;
	cout << "\nEnter duration: ";
	cin >> duration;

	time end;
	end.hour = 0; end.minute = 0;
	end.hour += start.hour + duration / 60;
	end.minute += start.minute + duration % 60;
	
	if (end.hour > 24)
	{
		end.hour = end.hour % 24;
	}
	if (end.minute > 60)
	{
		end.hour += end.minute / 60;
		end.minute = end.minute % 60;
	}
	printf("%d:%d", end.hour, end.minute);

	
	return 0;
}

