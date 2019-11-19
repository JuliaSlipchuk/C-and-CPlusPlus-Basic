#include <stdio.h>

int main()
{
    setbuf(stdout, 0);
    int first = 0, second = -1;
    while(second != 0)
    {
        printf("Enter the first number: ");
        scanf("%d", &first);
        printf("Enter the second number: ");
        scanf("%d", &second);
        printf("Sum: %d\n", first + second);
        if (second == 0)
            printf("Finish");
    }

   
    return 0;
}
