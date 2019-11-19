#include <iostream>

using namespace std;

int  getNumberOfDays(int month, int year)
{
    if( month == 2)
    {
        if ((year%400==0) || (year%4==0 && year%100!=0))
            return 29;
        else
            return 28;
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
            ||month == 10 || month==12)
        return 31;
    else
        return 30;
}
class Calendar
{
private:
    int day;
    int month;
    int year;
public:
    Calendar(int day, int month, int year)
    {
        if (year < 1970)
            throw "Year must be greater or equels 1970";
        if (day >= 1 && day <= 31 && month >= 1 && month <= 12)
        {
            this->day = day;
            this->month = month;
            this->year = year;
        }
    }
    enum Week
    {
        Thursday,
        Friday,
        Saturday,
        Sunday,
        Monday,
        Tuesday,
        Wednesday
    };
    enum Month
    {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };
    void print()
    {
        long countOfDays;
        for (int i = 1970; i < this->year; i++)
        {
            if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
                countOfDays += 366;
            else
                countOfDays += 365;
        }
        for (int i = 1; i < this->month; i++)
        {
            countOfDays += getNumberOfDays(i, this->year);
        }
        for (int i = 1; i < this->day - 1; i++)
        {
            countOfDays += 1;
        }

        Week dayOfWeekEnum = (Week)(countOfDays % 7);
        Month monthEnum = (Month)month;
        string dayOfWeek;
        string monthOfYear;

        switch (dayOfWeekEnum)
        {
            case 0:
                dayOfWeek = "Friday";
                break;
            case 1:
                dayOfWeek = "Saturday";
                break;
            case 2:
                dayOfWeek = "Sunday";
                break;
            case 3:
                dayOfWeek = "Monday";
                break;
            case 4:
                dayOfWeek = "Tuesday";
                break;
            case 5:
                dayOfWeek = "Wednesday";
                break;
            case 6:
                dayOfWeek = "Thursday";
                break;
        }
        switch (monthEnum)
        {
            case 1:
                monthOfYear = "January";
                break;
            case 2:
                monthOfYear = "February";
                break;
            case 3:
                monthOfYear = "March";
                break;
            case 4:
                monthOfYear = "April";
                break;
            case 5:
                monthOfYear = "May";
                break;
            case 6:
                monthOfYear = "June";
                break;
            case 7:
                monthOfYear = "July";
                break;
            case 8:
                monthOfYear = "August";
                break;
            case 9:
                monthOfYear = "September";
                break;
            case 10:
                monthOfYear = "October";
                break;
            case 11:
                monthOfYear = "November";
                break;
            case 12:
                monthOfYear = "December";
                break;
        }

        cout << this->day << " " << monthOfYear << " " << this->year << " - " << dayOfWeek << " - " << countOfDays << " days since 1st January 1970";
    }
};

int main()
{
    // second part
    Calendar calendar(13, 3, 2016);
    calendar.print();

    return 0;
}