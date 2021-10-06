#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int start, end, years;
    
    // TODO: Prompt for start size
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    
    // TODO: Prompt for end size
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    years = 0;
    
    // TODO: Calculate number of years until we reach threshold
    while (start < end)
    {
        start = start + (start / 3) - (start / 4) ;
        years++ ;
    }
    
    // TODO: Print number of years
    printf("Years: %i \n", years);

}