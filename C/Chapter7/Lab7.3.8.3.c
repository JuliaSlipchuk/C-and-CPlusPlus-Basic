#include <stdio.h>
#include <string.h>
#include <io.h>
#include <stdlib.h>

#define MAXCHAR 1000
int main()
{
    
    setbuf(stdout, 0);
    char source[100];
    char destination[100];
    printf("Enter the path to the source file: ");
    gets(source);
    printf("\nEnter the path to the destination file: ");
    gets(destination);
    if (access(source, F_OK) != 1)
    {
        int limit = 7;
        int counter = 0;
        char* newDestination = destination;
        while(access(newDestination, F_OK) != -1 && counter < limit)
        {
            counter++;
            //newDestination=strcat(destination,itoa(counter));
            sprintf(newDestination,"%s%d",destination,counter);
        }
        if (access(newDestination, F_OK) != -1)
            printf("Limit is exhausted and file cannot be created");
        else
        {
            FILE* sourceFile;
            FILE* destinationFile;
            sourceFile = fopen(source, "r");
            destinationFile = fopen(newDestination, "w");
            if (sourceFile == NULL || destinationFile == NULL)
                printf("Cannot open source file or cannot create a new file");
            else
            {
                char str[MAXCHAR];
                while (fgets(str, MAXCHAR, sourceFile) != NULL)
                {
                    fprintf(destinationFile, str);
                }
                printf("All done successfully");
            }
        }
    }
    else
    {
        printf("File %s does not exist");
    }

    return 0;
}
