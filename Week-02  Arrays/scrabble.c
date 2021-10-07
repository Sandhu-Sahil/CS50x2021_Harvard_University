//scrabble game......
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int point[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    //
    string word1 = get_string("Player1: ");
    string word2 = get_string("Player2: ");

    //
    int sum1 = compute_score(word1);
    int sum2 = compute_score(word2);

    //
    if (sum1 > sum2)
    {
        printf("Player 1 wins!\n");
    }
    else if (sum2 > sum1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}


int compute_score(string word1)
{
    //

    int n1 = strlen(word1);

    for (int i = 0; i < n1 ; i++)
    {
        word1[i] = toupper(word1[i]);
    }

    int alphabet1[n1];

    for (int i = 0 ; i < n1 ; i++)
    {
        alphabet1[i] = (int)((int)word1[i] - 65);
    }

    int sum1 = 0;

    for (int i = 0 ; i < n1 ; i++)
    {
        sum1 = sum1 + point[(int)alphabet1[i]];
    }

    return (sum1);
}