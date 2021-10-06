//for calculating number of coins to be retuned to customer if we have to return some amount of money.
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //
    float change = 0.0;
    int a = 0, b = 0, c = 0, d = 0;
    
    //
    do
    {
        change = round(get_float("Change owed: ") * 100);
    }
    while (change < 0);
    
    //
    if (change >= 25)
    {
        //
        while (change >= 25)
        {
            a++;
            change = change - 25;
        }

        //printf("\nNumber of 0.25 coins : %i \n", a);
    }

    //
    if (change >= 10)
    {
        while (change >= 10)
        {
            b++;
            change = change - 10;
        }

        //printf("Number of 0.10 coins : %i \n", b);
    }
    
    //
    if (change >= 5)
    {
        while (change >= 5)
        {
            c++;
            change = change - 5;
        }

        //printf("Number of 0.05 coins : %i \n", c);
    }

    //
    if (change >= 1)
    {
        while (change > 0)
        {
            d++;
            change = change - 1;
        }

        //printf("Number of 0.01 coins : %i \n", d);
    }
    
    //
    int e = a + b + c + d;
    printf("%i\n", e);
}