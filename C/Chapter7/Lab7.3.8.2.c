#include <stdio.h>
#include <string.h>
#include <io.h>
#include <stdlib.h>

#define MAXCHAR 1000
int main()
{
    
    char* source = "D:\\C\\Lab7.3\\Source1.txt";
    FILE* sourceFile;
    sourceFile = fopen(source, "r");
    if (sourceFile == NULL)
        printf("Error opening the file\n");
    else
    {
        char str[MAXCHAR];
        int countLines = 0;
        int countWhitespaces = 0;
        int characters = 0;
        int letters[26];
        for (int i = 0; i < 26; i++)
            letters[i] = 0;
        while (fgets(str, MAXCHAR, sourceFile) != NULL)
        {
            for (int i = 0; i < strlen(str); i++)
            {
                if (str[i] == ' ')
                {
                    countWhitespaces++;
                    continue;
                }
                for (int j = 0; j < 26; j++)
                {
                    if (str[i] - 'a' == j)
                    {
                        letters[j]++;
                        characters++;
                        break;
                    }
                }
            }
            countLines++;
        }
        printf("Lines: %d\n", countLines);
        printf("Whitespaces: %d\n", countWhitespaces);
        printf("Characters: %d\n", characters);
        for (int i = 0; i < 26; i++)
        {
            printf("Small letter: %c : %d\n", (char)(i + 'a'), letters[i]);
        }
    }
    fclose(sourceFile);

    return 0;
}
