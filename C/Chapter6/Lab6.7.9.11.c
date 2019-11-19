#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int isDigit(char* val)
{
    for (int i = 0; i < strlen(val); i++)
    {
        if (val[i] < '0' || val[i] > '9')
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    /*// first part
    setbuf(stdout, 0);
    int res;
    bool check = true;
    if (isDigit(argv[2]) == 1 && isDigit(argv[3]) == 1)
    {
        if (strcmp(argv[1], "add") == 0)
            res = add(atoi(argv[2]), atoi(argv[3]));
        else if (strcmp(argv[1], "sub") == 0)
            res = sub(atoi(argv[2]), atoi(argv[3]));
        else if (strcmp(argv[1], "mul") == 0)
            res = mul(atoi(argv[2]), atoi(argv[3]));
        else
        {
            check = false;
            printf("You entered unidentified command\n");
        }
    }
    else
    {
        check = false;
        printf("You entered not a number\n");
    }
    if (check)
        printf("%s %d %d: %d", argv[1], atoi(argv[2]), atoi(argv[3]), res);*/

    return 0;
}