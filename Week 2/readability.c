#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int get_index(string text);


int main(void)
{
    //Input text
    string text = get_string("Text: ");

    //process the word to get the amout of letters, sentences and words there are in it
    int index = get_index(text);


    //print the level of the text
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
int get_index(string text)
{
    int letters = 0, sentences = 0, words = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char x = text[i];
        if (isalpha(x))
        {
            letters++;
        }
        if (isspace(x))
        {
            words++;
        }
        if (x == '.' || x == '!' || x == '?')
        {
            sentences++;
        }
    }
    words++;

    float L = (letters * 100.0f) / words;
    float S = (sentences * 100.0f) / words;
    return round(0.0588 * L - 0.296 * S - 15.8);

}


