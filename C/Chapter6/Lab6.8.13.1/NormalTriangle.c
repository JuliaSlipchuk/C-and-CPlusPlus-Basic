#include <stdio.h>

void NormalTriangle(int numb)
{
    for (int i = 1; i <= numb; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("\\");
        }
        printf("\n");
    }
}
