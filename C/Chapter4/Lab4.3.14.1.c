#include <stdio.h>

int main()
{

    setbuf(stdout, 0);
    float numbers[10] = {5.6, 4.3, 6.2, 6.4, 7.3, 2.3, 8.3, 9.2, 0.1, 1.9};
    for (int i = 0; i < sizeof(numbers)/sizeof(float) - 1; i++)
    {
        for (int j = 0; j < sizeof(numbers)/ sizeof(float) - 2; j++)
        {
            if (numbers[j + 1] > numbers[j])
            {
                float temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
        for (int k = 0; k < sizeof(numbers)/ sizeof(float); k++)
        {
            printf("%.2f ", numbers[k]);
        }
        printf("\n");
    }


    return 0;
}
