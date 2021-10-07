//for cypher text of letters to letters make array of 52(26+26 alphabets) words and just increase the assighnment value of it
//i am creating the cypher text for convertion of alphabets to symbols

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    //
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    //
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!(isalpha(argv[1][i])))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    //
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
        }
    }
    
    //
    string text = get_string("plaintext: ");
    int n = strlen(text);
    char cipher[n];
    
    //
    for (int i = 0 ; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            int a = (int)text[i];

            if (a > 64 && a < 91)
            {
                a = a - 65;
                cipher[i] = toupper(argv[1][a]);
            }

            if (a > 96 && a < 123)
            {
                a = a - 97;
                cipher[i] = tolower(argv[1][a]);
            }

        }
        else
        {
            cipher[i] = text[i];
        }
    }
    
    //
    printf("ciphertext: ");

    for (int i = 0; i < n; i++)
    {
        printf("%c", cipher[i]);
    }

    printf("\n");
}
