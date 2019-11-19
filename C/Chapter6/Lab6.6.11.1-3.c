#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double getSquare(double val);
int isValidIp(char* ip);
int compareMatrix(int size, int matrixA[size][size], int matrixB[size][size]);
void getMessageMatrix(int size, int matrixA[size][size], int matrixB[size][size]);

int main()
{
    // first part
    printf("square of %f is %.2f\n", 2.00, getSquare(2.00));
    printf("square of %f is %.2f\n", 6.00, getSquare(6.00));
    printf("square of %f is %.2f\n", 2.50, getSquare(2.50));
    printf("square of %f is %.2f\n", 12.12, getSquare(12.12));
    printf("square of %f is %.2f\n", 345.68, getSquare(345.68));

    // second part
    setbuf(stdout, 0);
    char* first = "127.0.0.1";
    char* second = "127.0.01";
    char* third = "127.0..1";
    char* fourth = "127.zero.0.1";
    char* fifth = "127.297.0.1";
    char* sixth = "127.2555.0.1";
    char* arr[6] = {first, (char *)second, (char *)third, (char *)fourth, (char *)fifth, (char *)sixth};
    for (int i = 0; i < 6; i++)
    {
        if (isValidIp(arr[i]) == 1)
            printf("%s is a valid IP\n", arr[i]);
        else
            printf("%s is not a valid IP\n", arr[i]);
    }

    // third part
    setbuf(stdout, 0);
    int matrixA[2][2] = {{2, 2}, {3, 3}};
    int matrixB[2][2] = {{2, 2}, {3, 3}};
    getMessageMatrix(2, matrixA, matrixB);
    matrixA[0][1] = 1;
    getMessageMatrix(2, matrixA, matrixB);
    matrixA[0][1] = 3;
    getMessageMatrix(2, matrixA, matrixB);
    matrixA[0][1] = 5; matrixB[0][1] = 5;
    getMessageMatrix(2, matrixA, matrixB);
    matrixA[1][1] = 2;
    getMessageMatrix(2, matrixA, matrixB);
    matrixA[1][0] = 7;
    getMessageMatrix(2, matrixA, matrixB);

    return 0;
}
double getSquare(double val)
{
    return val * val;
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
int compareMatrix(int size, int matrixA[size][size], int matrixB[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrixA[i][j] > matrixB[i][j])
                return 1;
            else if (matrixA[i][j] < matrixB[i][j])
                return -1;
        }
    }
    return 0;
}
void getMessageMatrix(int size, int matrixA[size][size], int matrixB[size][size])
{
    if (compareMatrix(size, matrixA, matrixB) == 1)
        printf("matrixA is greater than matrixB\n");
    else if (compareMatrix(size, matrixA, matrixB) == 0)
        printf("Both matrices are equal\n");
    else
        printf("matrixA is smaller than matrixB\n");
}
