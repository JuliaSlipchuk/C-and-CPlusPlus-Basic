#include <stdio.h>
#include <string.h>

void hello()
{
    puts("Hello!");
}
void another()
{
    puts("It's me - another function.");
}
int getValue1(int paramA, float paramB)
{
    int result = 0;
    if (paramA > 10)
    {
        result += 2;
    }
    else
    {
        result += 1;
    }
    if (paramB > 5.5)
    {
        result += 4;
    }
    else
    {
        result += 3;
    }
    return result;
}
int getOneOrTwo(int param)
{
    if(param > 5)
        return 2;
    return 1;
}
double getMaxOfThree(double paramA, double paramB, double paramC)
{
    double res = (paramA > paramB && paramA > paramC) ? paramA : (paramB > paramA && paramB > paramC) ? paramB : paramC;
    return res;
}
double power(double base, int exponent)
{
    double res = 1;
    for (int i = 1; i <= exponent; i++)
    {
        res *= base;
    }
    return res;
}
int getValue(int paramA, float paramB)
{
    if (paramA >= 5 && paramB >= 2.5)
        return 25;
    else if ((paramA >= 5 && paramB < 2.5) || (paramA < 5 && paramB >= 2.5))
        return 30;
    else
        return 35;
}
int getExclusive(int paramA, int paramB)
{
    if ((paramA == 2 && paramB != 2) || (paramA != 2 && paramA == 2))
        return 2;
    return 0;
}
int stringCompare(char * first, char * second)
{
    int i;
    for (i = 0 ; first[i] != 0 && second[i] != 0 ; i++)
    {
        if(first[i] > second[i])
        {
            return 1;
        }
        else if (first[i] < second[i])
        {
            return -1;
        }
    }
    if (strlen(second) - strlen(first) >= 0)
    {
        if (strlen(first) - strlen(second) == 0)
            return 0;
        else
            return -1;
    }
    else
        return 1;
}
int main()
{
    // first part
    hello();
    hello();
    hello();
    another();
    hello();
    another();

    // second part
    int fiveValue = getValue1(5, 6);
    int sixValue = getValue1(20, 20);
    int sevenValue = getValue1(20,20) + getOneOrTwo(1);
    int eightValue = getValue1(11, 7) + getOneOrTwo(7);
    int nineValue = getValue1(5, 7) + getValue1(5, 4);
    printf("Five: %d\n", fiveValue);
    printf("Six: %d\n", sixValue);
    printf("Seven: %d\n", sevenValue);
    printf("Eight: %d\n", eightValue);
    printf("Nine: %d\n", nineValue);

    // third part
    double tenValue = getMaxOfThree(5, 9, 10);
    double bigValue = getMaxOfThree(555.4, 555.3, 556.4);
    printf("Ten: %.2f\n", tenValue);
    printf("The biggest value: %.2f\n", bigValue);

    // fourth part
    double twentyFiveValue = power(5.0, 2);
    double piSquaredValue = power(3.14159265, 2);
    double piCubedValue = power(3.14159265, 3);
    double bigPower = power(1.23, 20);
    double millionValue = power(10, 6);
    printf("Twenty five: %.4f\n", twentyFiveValue);
    printf("Pi squared: %.4f\n", piSquaredValue);
    printf("Pi cubed: %.4f\n", piCubedValue);
    printf("Not so big number: %.4f\n", bigPower);
    printf("Million: %.4f\n", millionValue);*/

    // fifth part
    int thirtyFiveValue = getValue(4, 2.4);
    int thirtyValue1 = getValue(4, 2.6);
    int thirtyValue2 = getValue(6, 2.4);
    int twentyValue = getValue(6, 2.6);
    int twoValue = getExclusive(2, 1);
    int zeroValue = getExclusive(2, 2);
    printf("Thirty five: %d\n", thirtyFiveValue);
    printf("Thirty: %d\n", thirtyValue1);
    printf("Thirty: %d\n", thirtyValue2);
    printf("Twenty: %d\n", twentyValue);
    printf("Two: %d\n", twoValue);
    printf("Zero: %d\n", zeroValue);

    // six part
    int result1 = stringCompare("AAA", "BBB");
    int result2 = stringCompare("AAC", "AAB");
    int result3 = stringCompare("AAC", "AAC");
    int result4 = stringCompare("AAC", "AACC");
    printf("result1: %d\n", result1);
    printf("result2: %d\n", result2);
    printf("result3: %d\n", result3);
    printf("result4: %d\n", result4);

    return 0;
}
