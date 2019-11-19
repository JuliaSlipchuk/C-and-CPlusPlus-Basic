#include <stdio.h>
#include <stdlib.h>

int main()
{

    setbuf(stdout, 0);
    char firstName[20];
    char secondName[20];
    char thirdName[20];
    char fourthName[20];
    printf("Enter the first name: ");
    gets(firstName);
    printf("Enter the second name: ");
    gets(secondName);
    printf("Enter the third name: ");
    gets(thirdName);
    printf("Enter the fourth name: ");
    gets(fourthName);
    printf("%s\n", fourthName);
    printf("%s\n", thirdName);
    printf("%s\n", secondName);
    printf("%s\n", firstName);


    setbuf(stdout, 0);
    char firstOctet[4];
    char secondOctet[4];
    char thirdOctet[4];
    char fourthOctet[4];
    printf("Enter the first octet: ");
    //scanf("%s", firstOctet);
    gets(firstOctet);
    printf("Enter the second octet: ");
    //scanf("%s", secondOctet);
    gets(secondOctet);
    printf("Enter the third octet: ");
    //scanf("%s", thirdOctet);
    gets(thirdOctet);
    printf("Enter the fourth octet: ");
    //scanf("%s", fourthOctet);
    gets(fourthOctet);
    if (atoi(firstOctet) >= 0 && atoi(firstOctet) <= 255 && atoi(secondOctet) >= 0 && atoi(secondOctet) <= 255 && atoi(thirdOctet) >= 0 && atoi(thirdOctet) <= 255 && atoi(fourthOctet) >= 0 && atoi(fourthOctet) <= 255)
    {
        char buffer[50];
        sprintf(buffer, "%d.%d.%d.%d", atoi(firstOctet), atoi(secondOctet), atoi(thirdOctet), atoi(fourthOctet));
        printf("%s\n", buffer);
    }
    else
        printf("Each octet must be greater than -1 and less than 256");

    return 0;
}
