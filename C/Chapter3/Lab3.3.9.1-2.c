#include <stdio.h>

int main()
{
    setbuf(stdout, 0);
    float numb;
    printf("Enter the number: ");
    scanf("%f", &numb);
    if (numb >= 1. && numb < 2.)
        printf("Very bad");
    else if (numb >= 2. && numb < 3.)
        printf("Bad");
    else if (numb >= 3. && numb < 4.)
        printf("Neutral");
    else if (numb >= 4. && numb < 5.)
        printf("Good");
    else if (numb >= 5. && numb < 6.)
        printf("Very good");

    setbuf(stdout, 0);
    float notExactFive = 5.4;
    float notExactNumber = 6.7;
    int exactFive;
    int roundedNumber;
    if (notExactNumber - notExactFive > 0.5)
    {
        roundedNumber = (int)notExactNumber + 1;
    }
    else
    {
        roundedNumber = (int)notExactNumber;
    }
    exactFive = (int)notExactFive;
    printf("Five is: %d\n", exactFive);
    printf("Rounded to seven: %d\n", roundedNumber);

    return 0;
}
