#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FIRST_TEST "127.0.0.1"
#define SECOND_TEST "127.0.01"
#define THIRD_TEST "127.0..1"
#define FOURTH_TEST "127.zero.0.1"
#define FIFTH_TEST "127.297.0.1"
#define SIXTH_TEST "127.2555.0.1"
#define TEST_N 6

int isValidIp(char* ip);

int main()
{

    setbuf(stdout, 0);

    char* arr[TEST_N] = {FIRST_TEST, (char *)SECOND_TEST, (char *)THIRD_TEST, (char *)FOURTH_TEST, (char *)FIFTH_TEST, (char *)SIXTH_TEST};
    for (int i = 0; i < TEST_N; i++)
    {
        if (isValidIp(arr[i]) == 1)
            printf("%s is a valid IP\n", arr[i]);
        else
            printf("%s is not a valid IP\n", arr[i]);
    }

    return 0;
}

int isDigit(char* octet)
{
    for (int i = 0; i < strlen(octet); i++)
    {
        if (octet[i] < '0' || octet[i] > '9')
            return 0;
    }
    return 1;
}
int isValidIp(char* ip)
{
    char* arr[4];
    int i = 0;
    const char* delim = ".";
    char* copy = strdup(ip);
    char* ptr = strtok(copy, delim);
    int dotCount = -1;
    while (ptr != NULL)
    {
        arr[i] = ptr;
        ptr = strtok(NULL, delim);
        i++;
        dotCount++;
    }
    if (dotCount != 3)
        return 0;
    for (int i = 0; i < 4; i++)
    {
        if (isDigit(arr[i]) == 0 || atoi(arr[i]) < 0 || atoi(arr[i]) > 255)
            return 0;
    }
    return 1;
}