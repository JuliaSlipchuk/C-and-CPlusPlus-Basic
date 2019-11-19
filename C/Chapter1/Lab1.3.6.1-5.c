#include <stdio.h>

int main()
{
    // sixth part
    int ten  = 10;
    printf("The value of ten is: %d \n", ten);

    // seven part
    int secInMin = 60;
    int fiftyMin = 60;
    printf("One hour is %d seconds\n", secInMin * fiftyMin);

    // eight part
    int ipPart1 = 127;
    int ipPart2 = 0;
    int ipPart3 = 0;
    int ipPart4 = 1;
    printf("Localhost IP is %d.%d.%d.%d\n", ipPart1, ipPart2, ipPart3, ipPart4);

    // nine part
    int daysInCurrentFebruary = 28;
    int daysInJanuary = 31;
    int daysInFebruary = daysInCurrentFebruary;
    int daysInMarch = 31;
    int daysInApril = 30;
    int daysInMay = 31;
    int daysInJune = 30;
    int daysInJuly = 31;
    int daysInAugust = 31;
    int daysInSeptember = 30;
    int daysInOctober = 31;
    int daysInNovember = 30;
    int daysInDecember = 31;
    int daysInFirstHalf = daysInJanuary + daysInFebruary + daysInMarch + daysInApril + daysInMay + daysInJune;
    int daysInSecondHalf = daysInJuly + daysInAugust + daysInSeptember + daysInOctober + daysInNovember + daysInDecember;
    printf("Days in the first half of the current year: %d\n", daysInFirstHalf);
    printf("Days in the second half of the current year: %d\n", daysInSecondHalf);
    printf("Days in the current year: %d\n", daysInFirstHalf + daysInSecondHalf);

    // ten part
    int daysInCurrentFebruary = 28;
    int daysInJanuary = 31;
    int daysInFebruary = daysInCurrentFebruary;
    int daysInMarch = 31;
    int daysInApril = 30;
    int daysInMay = 31;
    int daysInJune = 30;
    int daysInJuly = 31;
    int daysInAugust = 31;
    int daysInSeptember = 30;
    int daysInOctober = 31;
    int daysInNovember = 30;
    int daysInDecember = 31;
    int daysFirstTriptet = daysInJanuary + daysInFebruary + daysInMarch;
    int daysSecondTriptet = daysInApril + daysInMay + daysInJune;
    int daysThirdTriptet = daysInJuly + daysInAugust + daysInSeptember;
    int daysFourthTriptet = daysInOctober + daysInNovember + daysInDecember;

    printf("Days in Q1 of the current year: %d\n", daysFirstTriptet);
    printf("Days in Q2 of the current year: %d\n", daysSecondTriptet);
    printf("Days in Q3 of the current year: %d\n", daysThirdTriptet);
    printf("Days in Q4 of the current year: %d\n", daysFourthTriptet);

   
    return 0;
}
