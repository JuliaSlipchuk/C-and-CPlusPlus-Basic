#include <stdio.h>

int main()
{
    // first part
    int a = 10;
    if (a > 9)
        puts("First condition is true");
    else
        puts("First condition is false");
    if (a < 9)
        puts("Second condition is true");
    else
        puts("Second condition is false");
    if (a == 9 + 1)
        puts("Third condition is true");
    else
        puts("Third condition is false");

    return 0;
}