#include <stdio.h>
#include <cs50.h>

void space(void);
int main(void)
{
    int a, b, c, height ;
    
    //
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    //
    for (a = 0 ; a < height ; a++)
    {
        //
        for (b = (height - a) ; b > 1 ; b--)
        {
            printf(" ");
        }
        
        //
        for (c = 0 ; c <= a ; c++)
        {
            printf("#");
        }
        
        //
        printf("  ");

        
        for (c = 0 ; c <= a ; c++)
        {
            printf("#");
        }

        printf("\n");
    }


}




void space(void)
{
    printf("\t\b\b\b\b\b\b");
}