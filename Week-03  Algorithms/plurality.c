#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
            i--;
            //i-- is for if invalid vote happens it repeats same vote so that the total votes remains same and total votes occur
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO

    for (int b = 0 ; b < candidate_count ; b++)
    {
        if (strcmp(name, candidates[b].name) == 0)
        {
            candidates[b].votes = candidates[b].votes + 1;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO

    for (int i = 0 ; i < candidate_count ; i++)
    {
        for (int a = 0 ; a < (candidate_count - 1) ; a++)
        {
            if (candidates[a].votes > candidates[a + 1].votes)
            {
                int x = candidates[a].votes;
                candidates[a].votes = candidates[a + 1].votes;
                candidates[a + 1].votes = x;

                string y = candidates[a].name;
                candidates[a].name = candidates[a + 1].name;
                candidates[a + 1].name = y;
            }
        }
    }


    if (candidates[(candidate_count) - 1].votes == candidates[(candidate_count) - 2].votes)
    {

        printf("%s\n", candidates[(candidate_count) - 1].name);

        for (int i = candidate_count; i > 0; i--)
        {
            if (candidates[(i) - 1].votes == candidates[(i) - 2].votes)
            {
                printf("%s\n", candidates[(i) - 2].name);
            }
        }

    }
    else
    {
        printf("%s\n", candidates[(candidate_count) - 1].name);
    }

    return;
}

