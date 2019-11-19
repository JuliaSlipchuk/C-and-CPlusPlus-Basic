#include <stdio.h>
#include <stdlib.h>

int main()
{

    setbuf(stdout, 0);
    long number;
    printf("Enter the number (greater than 0 and less than 1 048 576): ");
    scanf("%ld", &number);
    char letters[26];
    int i = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        letters[i] = ch;
        i++;
    }
    if (number > 0 && number < 1048576)
    {
        char* array = (char*)(malloc(number * sizeof(char)));
        for (int i = 0; i < number; i++)
        {
            int help;
            help = i;
            while(help > 25)
            {
                help -= 26;
            }
            array[i] = letters[help];
        }
        if (number > 400)
            number = 400;
        for (int i = 0; i < number; i++)
        {
            printf("%c", array[i]);
            if (i != 0 && i % 40 == 0)
                printf("\n");
        }
    }
    else
        printf("Too much or too less memory requested");*/

    return 0;
}
