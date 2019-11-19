#include <stdio>

int main()
{
    setbuf(stdout, 0);
    int numb;
    printf("Enter the number: ");
    scanf("%d", &numb);
    if (numb > 20)
        numb = 20;
    if (numb > 0)
    {
        for (int i = 0; i < numb; i++)
        {
            printf("*");
            for (int j = 0; j < i; j++)
            {
                printf(" ");
            }
            printf("*\n");
        }
        for (int i = numb - 1; i >= 0; i--)
        {
            printf("*");
            for (int j = 0; j < i; j++)
            {
                printf(" ");
            }
            printf("*\n");
        }
    }
    return 0;
}
