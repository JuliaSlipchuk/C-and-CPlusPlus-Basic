#include <iostream>
#include <cmath>

int main()
{
    // first part
    int a = 10;
    if (a > 9)
        puts("First condition is true");
    if (a < 9)
        puts("Second condition is true");
    if (a == 9 + 1)
        puts("Third condition is true");

    // second part
    int n = -3;
    if (n < 0)
    {
        printf("The absolute value of %d is %d \n", n, abs(n));
    }
    printf("The value of n is %d", n);

    // third part
    int dayOfWeek = 1;
    printf("The day of the week is: ");
    if (dayOfWeek == 1)
        printf("Monday");
    else if (dayOfWeek == 2)
        printf("Tuesday");
    else if (dayOfWeek == 3)
        printf("Wednesday");
    else if (dayOfWeek == 4)
        printf("Thursday");
    else if (dayOfWeek == 5)
        printf("Friday");
    else if (dayOfWeek == 6)
        printf("Saturday");
    else
        printf("Sunday");

    return 0;
}
