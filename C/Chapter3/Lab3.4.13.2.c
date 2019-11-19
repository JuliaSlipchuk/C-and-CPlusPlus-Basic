#include <stdio.h>

int main()
{
    setbuf(stdout, 0);
    int numb;
    printf("Enter the number: ");
    scanf("%d", &numb);
    int count = 0;
    if (numb < 1)
    {
        printf("*#");
    }
    else if (numb > 20)
    {
        do
        {
            int i = 0;
            do
            {
                i++;
                printf("*#");
            }
            while (i <= count);
            printf("\n");
            count++;
        }
        while (count < 20);
    }
    else
    {
        do
        {
            int i = 0;
            do
            {
                i++;
                printf("*#");
            }
            while (i <= count);
            printf("\n");
            count++;
        }
        while(count < numb);
    }

    return 0;
}
