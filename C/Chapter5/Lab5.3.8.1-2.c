#include <stdio.h>

int main()
{

    setbuf(stdout, 0);
    char chess[8][8];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 1 || i == 2)
                chess[i][j] = 'P';
            else
            {
                switch (j)
                {
                    case 0:
                    case 7:
                        chess[i][j] = 'R';
                        break;
                    case 1:
                    case 6:
                        chess[i][j] = 'N';
                        break;
                    case 2:
                    case 5:
                        chess[i][j] = 'B';
                        break;
                    case 3:
                        chess[i][j] = 'Q';
                        break;
                    case 4:
                        chess[i][j] = 'K';
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c", chess[i][j]);
        }
        printf("\n");
        if (i == 1)
            printf("\n\n");
    }

    setbuf(stdout, 0);
    char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int numbOfDay;
    printf("Enter the number of the day (0-6): ");
    scanf("%d", &numbOfDay);
    if (numbOfDay < 0 || numbOfDay > 6)
        printf("Error, no such day.");
    else
    {
        printf("Array index version: ");
        for (int i = 0; i < 7; i++)
        {
            if (numbOfDay == i)
                printf("%s\n", days[i]);
        }
        printf("Pointer version: ");
        for (int i = 0; i < 7; i++)
        {
            if (numbOfDay == i)
                printf("%s\n", *(days + i));
        }
    }

    return 0;
}
