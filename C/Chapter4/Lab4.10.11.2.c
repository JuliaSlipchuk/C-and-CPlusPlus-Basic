#include <stdio.h>
#include <string.h>

int main()
{

    setbuf(stdout, 0);
    char word[30];
    printf("Enter the word: ");
    gets(word);
    int i = 0;
    int len = strlen(word);
    char res[strlen(word)];
    for (int j = strlen(word) - 1; j >= 0; j--)
    {
        res[i] = word[j];
        i++;
    }
    printf("%s\n", res);

    return 0;
}
