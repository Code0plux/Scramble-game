#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype
int compute_score(char *word);

int main(void)
{
    char word1[30], word2[30];

    // Get input words from both players
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 won!! The score is %i\n", score1);
    }
    else if (score2 > score1)
    {
        printf("Player 2 won!! The score is %i\n", score2);
    }
    else
    {
        printf("It's a tie!\n");
    }
    return 0;
}

int compute_score(char *word)
{
    int n = strlen(word);
    int pos = 0;
    int score = 0;

    for (int i = 0; i < n; i++)
    {
        if (isupper(word[i]))
        {
            pos = word[i] - 'A';
            score += POINTS[pos];
        }
        else if (islower(word[i]))
        {
            pos = word[i] - 'a';
            score += POINTS[pos];
        }
    }
    return score;
}
