#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //no comments
    int i, j, size;
    do
    {
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);

    //print
    for (i = 1 ; i <= size ; i++)
    {
        //
        for (j = (size - i) ; j > 0 ; j--)
        {
            printf(" ");
        }
        
        //
        for (j = 1 ; j <= i ; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}