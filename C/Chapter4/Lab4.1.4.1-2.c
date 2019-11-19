#include <stdio.h>

int main()
{

    setbuf(stdout, 0);
    int month;
    printf(" Enter the number of month (1-12): ");
    scanf("%d", &month);
    switch (month)
    {
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
        default:
            printf("Error: no such month in my calendar");
    }


    setbuf(stdout, 0);
    int month;
    printf(" Enter the number of month (1-12): ");
    scanf("%d", &month);
    int countOfDays = 0;
    switch (month)
    {
        case 12:
            countOfDays += 30;
        case 11:
            countOfDays += 31;
        case 10:
            countOfDays += 30;
        case 9:
            countOfDays += 31;
        case 8:
            countOfDays += 31;
        case 7:
            countOfDays += 30;
        case 6:
            countOfDays += 31;
        case 5:
            countOfDays += 30;
        case 4:
            countOfDays += 31;
        case 3:
            countOfDays += 29;
        case 2:
            countOfDays += 31;
        case 1:
            printf("There are %d days before the given month", countOfDays);
            break;
        default:
            printf("\"Error: no such month in my calendar");
    }

    return 0;
}
