//
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    //
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    
    //
    string text = get_string("plaintext: ");
    int n = strlen(text);
    char cipher[n];
    
    //
    int o = 0;
    int ten = 1;
    for (int i = strlen(argv[1]) - 1; i >= 0; i--)
    {
        o = ((argv[1][i] - 48) * ten) + o;  
        //here problem was comming that argv which is a string has input 3 three as string which was converted to 51 according to assci charachters as 3 was taking as char not int  /// ascii 
        ten = ten * 10;
    }
    
    //
    for (int i = 0 ; i < n ; i++)
    {
        if (isalpha(text[i]))
        {
            int a = (int)text[i];

            if (a > 64 && a < 91)
            {
                a = a - 64;
                a = a + o;
                if (a > 26)
                {
                    a = a % 26;
                }
                a = a + 64;
                cipher[i] = a;
            }

            if (a > 96 && a < 123)
            {
                a = a - 96;
                a = a + o;
                if (a > 26)
                {
                    a = a % 26;
                }
                a = a + 96;
                cipher[i] = a;
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
