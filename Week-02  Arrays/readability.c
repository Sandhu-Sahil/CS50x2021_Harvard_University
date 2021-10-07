#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //
    string text = get_string("TEXT....: ");
    int a = strlen(text);

    //
    int b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
    
    //
    //
    for (int i = 0 ; i < a ; i++)
    {
        //
        if (isalpha(text[i]))
        {
            b++;
        }
        if (isdigit(text[i]))
        {
            c++;
        }
        if (ispunct(text[i]))
        {
            d++;
        }
        if (isspace(text[i]))
        {
            e++;
        }
        if (text[i] == '.')
        {
            f++;
        }
        if (text[i] == '!')
        {
            g++;
        }
        if (text[i] == '?')
        {
            h++;
        }
    }
    
    //
    int i = f + g + h;
    int j = e + 1;
    //printf(" String length :%i\n Alphabets :%i\n Digits :%i\n Punctuation Character :%i\n Words :%i\n Lines :%i\n", a ,b ,c , d, j, i);

    double L = ((double)b + (double)c) / (double)j * 100;
    double S = (double)i / (double)j * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;

    //
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }

}