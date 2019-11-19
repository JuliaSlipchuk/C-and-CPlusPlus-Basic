#include <stdio.h>

int main()
{

    setbuf(stdout, 0);
    int fibonacci[10];
    printf("Fibonacci sequence: \n");
    for (int i = 0; i < sizeof(fibonacci) / sizeof(int); i++)
    {
        if (i == 0 || i == 1)
            fibonacci[i] = 1;
        else
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        printf("%d\n", fibonacci[i]);
    }
    printf("Fibonacci sequence (odd index in array): \n");
    for (int i = 0; i < sizeof(fibonacci)/ sizeof(int); i+=2)
        printf("%d\n", fibonacci[i]);
    printf("Fibonacci sequence (even index in array): \n");
    for (int i = 1; i < sizeof(fibonacci)/ sizeof(int); i+=2)
        printf("%d\n", fibonacci[i]);

 
    setbuf(stdout, 0);
    char letters[26];
    int i = 0;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        letters[i] = ch;
        i++;
    }
    for (int j = 26; j >= 0; j--)
    {
        printf("%c\n", letters[j]);
    }
    char great[]  = {letters[6], letters[17], letters[4], letters[0], letters[19], '\0'};
    printf("%s\n", great);

    return 0;
}
