#include <cs50.h>
#include <stdio.h>

//PROTOTIPE
int get_positive_int (void);

int main(void)
{
    int i = get_positive_int();
    printf("%i\n", i);
}

int get_postive_int(void)
{
    int n;
    do
    {
        n = get_int("Introducir numero entero positivo: ");
    }
    while (n < 1);
    return n
}