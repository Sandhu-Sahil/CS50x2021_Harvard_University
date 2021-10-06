//to check wether the bank card is valid or not.
#include <stdio.h>
#include <cs50.h>

int digit(long cardno);
int main(void)
{
    //
    long card;
    int s;

    card = get_long_long("Number: ");
    s = digit(card);
    
    //
    int no[16];
    long ten = 1;
    
    for (int i = 0; i < 16; i++)
    {
        long q = card % (ten * 10);
        long w = card % ten;

        no[i] = (q - w) / ten;
        ten = ten * 10;

    }
    
    int visa = no[15];
    int master = (no[15] * 10) + no[14];
    int amex = (no[14] * 10) + no[13];
    
    //
    int no1[8];
    int h = 0;
    for (int v = 1; v < 16; v = v + 2)
    {
        no[v] = no[v] * 2;


        no1[h] = ((no[v] % 100) - (no[v] % 10)) / 10;
        no[v] = no[v] % 10;

        h++;

    }
    
    //
    int a = 0;
    for (int o = 0; o < 16; o = o + 2)
    {
        a = a + no[o];
    }

    //
    int b = 0;
    for (int x = 1; x < 16; x = x + 2)
    {
        b = b + no[x];
    }

    //
    int e = 0;
    for (int y = 0; y < 8; y++)
    {
        e = e + no1[y];
    }
    int c = a + b + e;
    int d = c % 10;
    
    //
    if (d == 0)
    {
        if (s == 15)
        {
            if (amex == 34 || amex == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (s == 13)
        {
            printf("VISA\n");
        }
        else if (s == 16)
        {
            if (visa == 4)
            {
                printf("VISA\n");
            }
            else if (master == 51 || master == 52 || master == 53 || master == 54 || master == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

//
int digit(long cardno)
{
    //
    long d = 1, f;
    int e = 0;
    
    //
    do
    {
        f = cardno % d;
        d = d * 10;
        e++;
    }
    while (cardno != f);
    
    //
    e--;
    return e;
}