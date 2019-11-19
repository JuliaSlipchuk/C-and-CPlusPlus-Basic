#include <stdio.h>

int main()
{
    // first part
    printf("Diff beetween '%c' and '%c' is : %d\n", 'c', 'a', 'c' - 'a');
    printf("Diff beetween '%c' and '%c' is : %d\n", 'a', 'c', 'a' - 'c');

    // second part
    char firstLetter = 'A';
    char firstSmallLetter = 'a';
    char lastLetter = 'Z';
    char lastSmallLetter = 'z';
    printf("Upper case letters beetween (and with) '%c' and '%c' is : %d\n",
           lastLetter, firstLetter, lastLetter - firstLetter + 1);
    printf("Lower case letters beetween (and with) '%c' and '%c' is : %d\n",
           lastSmallLetter, firstSmallLetter, lastSmallLetter - firstSmallLetter + 1);

    // third part
    char zero = '0';
    for(char ch = '1'; ch <= '9'; ch++)
    {
        printf("'%c' - '%c' is %d \n", ch, zero, ch - zero);
    }
    printf("'%c' - '%c' is %d \n", zero, zero, zero - zero);

    return 0;
}
