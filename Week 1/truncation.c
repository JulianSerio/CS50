#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //OBTENGO NUMEROS DEL USUARIO
    int x = get_int("X: ");
    int y = get_int("Y: ");

    //DIVIDO LOS VALORES Y LO ALMACENO EN Z
    float z = (float) x / (float) y;

    //IMPRIMO Z
    printf("%f\n", z);

}