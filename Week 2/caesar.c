#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool validkey(string s);
void encrypt(string s, string ciphertext, int k);

int main(int argc, string argv[])
{

    if (argc != 2 || !validkey(argv[1]))                                                     //1.Check that program was run with one command-line argumen
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]);
    string s = get_string("plaintext");
    int n = strlen(s);
    char ciphertext[n + 1];
    encrypt(s, ciphertext, k);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

void encrypt(string plaintext, string ciphertext, int k)
{
    int i = 0;
    for (i = 0; i < strlen(plaintext); i++)
    {
        char ch = plaintext[i];
        if (isalpha(ch))
        {
            char temp = tolower(ch);
            int pi = temp - 'a';
            char ci = ((pi + k) % 26) + 'a';
            ciphertext[i] = islower(ch) ? ci : toupper(ci);
        }
        else
        {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0';
}

bool validkey(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char ch = s[i];
        if (!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}