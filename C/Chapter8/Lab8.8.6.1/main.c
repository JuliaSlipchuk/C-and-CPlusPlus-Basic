#include <stdio.h>
#include "Triangles.h"

#define Log(func) printf("In line %d, file %s, before the "#func" function\n",__LINE__,__FILE__,func)


int main()
{
    // first part
    setbuf(stdout, 0);
    int numb;
    printf("Enter the number greater than 1 and less or equal 25: ");
    scanf("%d", &numb);
    if (numb > 1 && numb <= 25)
    {
        Log(NormalTriangle);
        NormalTriangle(numb);
        Log(FloydsTriangle);
        FloydsTriangle(numb);
    }
    else
        printf("You entered number less than 2 or greater then 25");

    return 0;
}