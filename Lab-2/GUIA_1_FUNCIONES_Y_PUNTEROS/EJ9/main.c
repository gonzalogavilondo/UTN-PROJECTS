#include <stdio.h>
#include <stdlib.h>

/**
    Dados dos arreglos paralelos, uno con apellidos y otro con edades. Se debe hacer un programa para encontrar el
    apellido de la persona de mayor edad. Se debe modularizar
**/

void encontrarMayorEdad(char apellidos[][100], int edades[], int tam, char apellidoMayor[]);

int main()
{
    const int tam = 5;
    char apellidos[tam][100];
    int edades[tam];
    char apellidoMayor[100];

    printf("Ingrese los apellidos y edades de la forma <Apellido Edad>: \n");
    for (int i = 0; i < tam; i++)
    {
        scanf("%s %d", apellidos[i], &edades[i]);
    }

    encontrarMayorEdad(apellidos, edades, tam, apellidoMayor);
    printf("\nEl apellido de la persona de mayor edad es: %s\n", apellidoMayor);

    return 0;
}

void encontrarMayorEdad(char apellidos[][100], int edades[], int tam, char apellidoMayor[])
{
    int maxEdad = edades[0];
    int posMaxEdad = 0;

    for (int i = 1; i < tam; i++)
    {
        if (edades[i] > maxEdad)
        {
            maxEdad = edades[i];
            posMaxEdad = i;
        }
    }
    strcpy(apellidoMayor, apellidos[posMaxEdad]);
}
