#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//lo que hace el programa es basicamente itera en cada char del string y lo resta con A (para el caso de las mayusculas) es decir resta 65 al valor de la letra del string actual y el resultado del mismo es la posicion del vector que es sumado en score

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    //Get input words form both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //Scores both word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}


int compute_score(string word)
{
    int score = 0;

    //compute score for each character
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i]))   //check whether a character is uppercase
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))   //check whether a character is lowercase
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}