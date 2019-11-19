#include <stdio.h>

int main()
{

    setbuf(stdout, 0);
    int i = 2;
    int* pi = &i;
    char ch = 'a';
    char* pch = &ch;
    printf("%d byte for chars\n", sizeof((char)'a'));
    printf("%d byte for char variables\n", sizeof(char));
    printf("%d byte for shorts\n", sizeof((short)2));
    printf("%d byte for short variables\n", sizeof(short));
    printf("%d byte for ints\n", sizeof(2));
    printf("%d byte for int variables\n", sizeof(int));
    printf("%d byte for longs\n", sizeof((long)2));
    printf("%d byte for long variables\n", sizeof(long));
    printf("%d byte for long longs\n", sizeof((long long)2));
    printf("%d byte for long long variables\n", sizeof(long long));
    printf("%d byte for floats\n", sizeof((float)2.));
    printf("%d byte for float variables\n", sizeof(float));
    printf("%d byte for doubles\n", sizeof(2.));
    printf("%d byte for double variables\n", sizeof(double));
    printf("%d byte for pointers\n", sizeof((int*)pi));
    printf("%d byte for double variables\n", sizeof(int*));
    printf("%d bytes for address of char variable\n", sizeof(&ch));
    printf("%d bytes for pointer to char variable\n", sizeof(char*));
    printf("%d bytes for value stored by pointer to char variable\n", sizeof(*pch));

    return 0;
}
