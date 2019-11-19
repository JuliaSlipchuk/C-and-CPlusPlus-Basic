#include <stdio.h>
#include <math.h>

int main()
{
    setbuf(stdout, 0);
    int firstPart, secondPart, thirdPart, fourthPart;
    printf("Enter the first octet of ip-address: ");
    scanf("%d", &firstPart);
    printf("Enter the second octet of ip-address: ");
    scanf("%d", &secondPart);
    printf("Enter the third octet of ip-address: ");
    scanf("%d", &thirdPart);
    printf("Enter the fourth octet of ip-address: ");
    scanf("%d", &fourthPart);
    int massBin[32];
    if (firstPart >= 0 && firstPart <= 255 && secondPart >= 0 && secondPart <= 255 && thirdPart >= 0 && thirdPart <= 255 && fourthPart >= 0 && fourthPart <= 255)
    {
        printf("Human readable IP address is: %d.%d.%d.%d\n", firstPart, secondPart, thirdPart, fourthPart);
        int counter = 0;
        int mass[4] = {firstPart, secondPart, thirdPart, fourthPart};
        for (int i = 0; i < 4; i++)
        {
            int helpMass[8];
            for (int j = 0; j < 8; j++)
            {
               helpMass[j] = *(mass + i) % 2;
               *(mass + i) /= 2;
            }
            for (int j = 7, k = counter; j >= 0; j--, k++)
            {
                massBin[k] = helpMass[j];
            }
            counter += 8;
        }
        int indexInBinMass = 31;
        long long ipIn32Bit = 0;
        for (int i = 0; i < 32; i++)
        {
            if (massBin[i] == 1)
                ipIn32Bit += pow(2, indexInBinMass);
            indexInBinMass--;
        }
        printf("IP address as a 32-bit number: %lld", ipIn32Bit);
    }
    else
        printf("Incorrect IP Address");

    return 0;
}
