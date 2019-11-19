#include <stdio.h>

int main()
{
    // seven part
    int xValue = 5;
    int yValue = 9;
    int result = (xValue + yValue) * 2;
    int bigResult = xValue + (yValue * 6);
    printf("the result is: %d\n", result);
    printf("the big result is: %d\n", bigResult);

    // eight part
    int xValue = 3;
    int yValue = 2;
    int result = (xValue + yValue) * 2 * yValue;
    int smallResult = xValue + yValue * (4 - xValue);
    printf("the result is: %d\n", result);
    printf("the small result is: %d\n", smallResult);

    // nine part
    int xValue = 5;
    int yValue = 3;
    int result = xValue * yValue - 14 + yValue;
    int smallResult = xValue + 10 % 4 % xValue;
    printf("the result is: %d\n", result);
    printf("the small result is: %d\n", smallResult);

    // ten part
    float startValue = 100;
    float interestRate = 0.015;
    float firstYearValue = startValue + startValue * interestRate;
    float secondYearValue = firstYearValue + startValue * interestRate;
    float thirdYearValue = secondYearValue + startValue * interestRate;
    printf("After first year: %f\n", firstYearValue);
    printf("After second year: %f\n", secondYearValue);
    printf("After third year: %f\n", thirdYearValue);

    return 0;
}
