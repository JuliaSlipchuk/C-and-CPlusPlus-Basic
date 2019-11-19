
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
	time end;
	cout << "Enter start hours: ";
	cin >> start.hour;
	cout << "\nEnter start minutes: ";
	cin >> start.minute;
	cout << "\nEnter end hours: ";
	cin >> end.hour;
	cout << "\nEnter end minutes: ";
	cin >> end.minute;
	
	if (start.hour > end.hour)
	{
		int tempHour, tempMinute;
		tempHour = start.hour; tempMinute = start.minute;
		start.hour = end.hour; start.minute = end.minute;
		end.hour = tempHour; end.minute = tempMinute;
	}
	int diffHour = end.hour - start.hour;
	int diffMinute = end.minute - start.minute;
	if (diffMinute < 0)
	{
		diffHour--;
		diffMinute = 60 + diffMinute;
	}
	printf("\n%d:%d", diffHour, diffMinute);
	
	return 0;
}

