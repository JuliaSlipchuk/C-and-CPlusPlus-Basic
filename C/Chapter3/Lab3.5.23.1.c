#include <stdio.h>
#include <math.h>

int main()
{
   
    setbuf(stdout, 0);
    int numb;
    printf("Enter the number less or equal 256: ");
    scanf("%d", &numb);
    char bits[8];
    char reverseBits[8];
    int nibbleH = 0, nibbleL = 0;
    if (numb >= 0 && numb <= 256)
    {
        for(int i = 0; i < 8; i++)
        {
            reverseBits[i] = numb % 2;
            numb /= 2;
        }
        for (int i = 7, j = 0; i >= 0; i--, j++)
        {
            bits[j] = reverseBits[i];
        }
        int power;
        for(int i = 0; i < 4; i++)
        {
            if (bits[i] == 1)
            {
                nibbleH += pow(2, 3 - i);
            }
        }
        for(int i = 0; i < 4; i++)
        {
            if (bits[7 - i] == 1)
            {
                nibbleL += pow(2, i);
            }
        }
        printf("H nibble: %d\n", nibbleH);
        printf("L nibble: %d\n", nibbleL);
    }

    return 0;
}
