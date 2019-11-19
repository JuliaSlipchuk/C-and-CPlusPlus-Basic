#include <stdio.h>
#include <stdbool.h>

int main()
{
    // fourth part
    int seven = 0;
    float pi = 0.0;
    printf("Enter 7: ");
    scanf("%d", &seven);
    printf("Enter pi(3.14): ");
    scanf("%f", &pi);
    printf("How many days in the week: %d\n", seven);
    printf("The value of Pi to two points: %.2f\n", pi);
    printf("There are %d in a week\n", seven);
    printf("Pi value is %f\n", pi);

    // fifth part
    float a = 0;
    float b = 0;
    setbuf(stdout, 0);
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Value A: %.3f\n", a);
    printf("Value B: %.3f\n", b);
    printf("%f + %f = %f\n", a, b, a + b);
    printf("%f - %f = %f\n", a, b, a - b);
    printf("%f * %f = %f\n", a, b, a * b);

    // six part
    setbuf(stdout, 0);
    int days = 0, month = 0;
    printf("Enter the day: ");
    scanf("%d", &days);
    printf("Enter the month: ");
    scanf("%d", &month);
    int daysInYear = 0;
    for (int m = 1; m < month; m++)
    {
        if (m == 2)
        {
            daysInYear += 29;
        }
        else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {
            daysInYear += 31;
        }
        else
        {
            daysInYear += 30;
        }
    }
    daysInYear += days;
    printf("The day of the year: %d", daysInYear);

    // seven part
    setbuf(stdout, 0);
    int dayOfTheWeek = 0;
    printf("Enter the day of the week (0 - 6): ");
    scanf("%d", &dayOfTheWeek);
    if (dayOfTheWeek == 0)
        printf("The day of week is: Sunday");
    else if (dayOfTheWeek == 1)
        printf("The day of week is: Monday");
    else if (dayOfTheWeek == 2)
        printf("The day of week is: Tuesday");
    else if (dayOfTheWeek == 3)
        printf("The day of week is: Wednesday");
    else if (dayOfTheWeek == 4)
        printf("The day of week is: Thursday");
    else if (dayOfTheWeek == 5)
        printf("The day of week is: Friday");
    else if (dayOfTheWeek == 6)
        printf("The day of week is: Saturday");
    else
        printf("There is no such day: %d. Input value must be from 0 to 6.", dayOfTheWeek);

    // eight part
    setbuf(stdout, 0);
    int year = 0, month = 0, day = 0;
    printf("Enter the day: ");
    scanf("%d", &day);
    printf("Enter the month: ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);
    bool isLeap = false;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        isLeap = true;
    int daysInYear = 0;
    for (int m = 1; m < month; m++)
    {
        if (m == 2)
        {
            if (isLeap)
                daysInYear += 29;
            else
                daysInYear += 28;
        }
        else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {
            daysInYear += 31;
        }
        else
        {
            daysInYear += 30;
        }
    }
    daysInYear += day;
    printf("The day of the year: %d", daysInYear);

    return 0;
}
