#include <stdio.h>
#include <stdlib.h>

int main()
{

    setbuf(stdout, 0);
    int widthHeight ;
    printf("Enter width (height): ");
    scanf("%d", &widthHeight);
    if (widthHeight > 20)
        printf("Matrix too big.");
    else
    {
        int* array[widthHeight];
        for (int i = 0; i < widthHeight; i++)
        {
            array[i] = (int*)malloc(widthHeight * sizeof(int));
            for (int j = 0; j < widthHeight; j++)
            {
                array[i][j] = (i + 1) * (j + 1);
            }
        }
        for (int i = 0 ; i < widthHeight; i++)
        {
            for (int j = 0; j < widthHeight; j++)
            {
                printf("%4d", array[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < widthHeight; i++)
            free(array[i]);
    }

    return 0;
}
