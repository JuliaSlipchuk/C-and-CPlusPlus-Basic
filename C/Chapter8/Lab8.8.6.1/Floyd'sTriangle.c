#include <stdio.h>
#include "Triangles.h"
void FloydsTriangle(int numb)
{
    int val = 1;
    for (int i = 1; i <= numb; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%4d", val);
            val++;
        }
        printf("\n");
    }
}
