#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{

    setbuf(stdout, 0);
    char ipAddrr[16];
    printf("Enter the ip-address: ");
    gets(ipAddrr);
    char delim[] = ".";
    char* octets = strtok(ipAddrr, delim);
    int countPoints = -1;
    int arrOfOctets[4]; int index = 0;
    bool check = true;
    while (octets != NULL)
    {
        countPoints++;
        if (atoi(octets) < 0 || atoi(octets) > 255)
        {
            check = false;
            printf("Error: not a valid address.");
            break;
        }
        arrOfOctets[index] = atoi(octets);
        index++;
        octets = strtok(NULL, delim);
    }
    if (countPoints != 3 && check)
        printf("Error: not a valid address.");
    else if (check)
    {
        if (arrOfOctets[0] < 0 || arrOfOctets[0] > 255 || arrOfOctets[1] < 0 || arrOfOctets[1] > 255 || arrOfOctets[2] < 0 || arrOfOctets[2] > 255 || arrOfOctets[3] < 0 || arrOfOctets[3] > 255)
            printf("Error: not a valid address.");
        else
        {
            for (int i = 0; i < sizeof(arrOfOctets)/sizeof(int); i++)
            {
                if (i > 0)
                {
                    printf("Last %d parts: ", sizeof(arrOfOctets)/ sizeof(int) - i);
                    for (int j = i; j < sizeof(arrOfOctets)/ sizeof(int); j++)
                    {
                        printf("%d", arrOfOctets[j]);
                        if (j != sizeof(arrOfOctets)/ sizeof(int) - 1)
                            printf(".");
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
