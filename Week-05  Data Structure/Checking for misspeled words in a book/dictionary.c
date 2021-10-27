// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// Number of buckets in hash table
const unsigned int N = 676; //26*26=676

// Hash table
node *table[N];

//count total number of words in dictionary
int word_count = 0;

//function for unloading dictionary
void unloading(node *tmp);


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char tmp[LENGTH + 1];
    strcpy(tmp, word);
    for (int i = 0 ; i <= strlen(tmp) ; i++)
    {
        tmp[i] = tolower(tmp[i]);
    }

    int h = hash(word);
    node *search = table[h];

    while (search != NULL)
    {
        if (strcmp(search->word, tmp) == 0)
        {
            return true;
        }
        else
        {
            search = search->next;
        }
    }

    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    int o;

    if (word[1] == '\0')
    {
        char c = word[0];
        c = tolower(c);

        o = (((int)c - 97) * 26) + 1;   //by taking aa = 1, ab = 2, ac = 3....and so on till zz = 676

        o = o - 1; //because 0 to 675 array
    }

    else if (word[1] == '\'')
    {
        char c = word[0];
        c = tolower(c);

        o = (((int)c - 97) * 26) + 1;    //by taking aa = 1, ab = 2, ac = 3....and so on till zz = 676

        o = o - 1; //because 0 to 675 array
    }
    else
    {
        char c[2];
        c[0] = word[0];
        c[1] = word[1];

        for (int i = 0; i < 2; i++)
        {
            c[i] = tolower(c[i]);
        }

        o = (((int)c[0] - 97) * 26) + ((int)c[1] - 96);   //by taking aa = 1, ab = 2, ac = 3....and so on till zz = 676

        o = o - 1; //because 0 to 675 array
    }
    return o;
}



// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }


    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *p = malloc(sizeof(node));
        if (p == NULL)
        {
            unload();
            return false;
        }
        p->next = NULL;

        strcpy(p->word, word);


        int h = hash(word);
        node *first = table[h];
        //add struct at starting as order doesn't matter to us
        if (first == NULL)
        {
            table[h] = p;
            word_count++;
        }
        else
        {
            p->next = table[h];
            table[h] = p;
            word_count++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0 ; i < N ; i++)
    {
        unloading(table[i]);
    }
    return true;
}
void unloading(node *tmp)
{
    if (tmp == NULL)
    {
        return;
    }
    unloading(tmp -> next);
    free(tmp);
}