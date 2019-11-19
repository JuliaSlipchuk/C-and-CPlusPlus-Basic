#include <stdio.h>

int main()
{
    // first part
    float halfValue = 0.6 - 0.1;
    float piValue = 0.141593 + 3;
    printf("The value of half is: %f\n", halfValue);
    printf("The value of Pi is: %f\n", piValue);

    // second part
    int fourValue = 2 * 2 / 1;
    int fiveValue = 2 + 3;
    printf("The value of four is: %d\n", fourValue);
    printf("The value of five is: %d\n", fiveValue);

    // third part
    float tenValue = 2 * 3 + 4;
    float twelveValue = 2 * 2.5 + 2 * 3.5 ;
    printf("The value of ten is: %f\n", tenValue);
    printf("The value of twelve is: %f\n", twelveValue);

    // fourth part
    int tenValue = 3 * 8 % 14;
    int twentyValue = 2 * tenValue + 10 % 5;
    printf("The value of ten is: %d\n", tenValue);
    printf("The value of twenty is: %d\n", twentyValue);

    // fifth part
    int xValue = 4 * 6 % 5;
    int eightValue = 2 * xValue + 10 % 5;
    printf("The value of eight is: %d\n", eightValue);

    // six part
    int xValue = 5;
    int yValue = 9;
    int result;
    int bigResult;

    xValue = xValue + 3;
    yValue = yValue - xValue;
    result = xValue * yValue;
    result = result + result;
    result = result - 1;
    result = result / yValue;
    result = result + result + xValue;
    bigResult = result * result * result;

    printf("result: %d\n", result);
    printf("big result: %d\n", bigResult);

    return 0;
}
