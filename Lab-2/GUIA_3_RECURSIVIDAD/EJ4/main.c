#include <stdio.h>
#include <stdlib.h>

/**
    Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
    forma invertida (recursivo).
**/

void mostrarArregloRecursivoInv(int array [], int, int);

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int elementos = 5;

    mostrarArregloRecursivoInv(arr, elementos, 0);


    return 0;
}

void mostrarArregloRecursivoInv(int array [], int validos, int posInicial)
{
    if(posInicial < validos)
    {
        printf("[%d] ", array[validos - 1]);
        mostrarArregloRecursivoInv(array, validos - 1, posInicial);
    }
    else
    {
        printf("\n"); // Imprimir salto de línea al final del arreglo
    }
}
