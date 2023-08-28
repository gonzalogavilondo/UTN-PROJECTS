#include <stdio.h>
#include <stdlib.h>

/**
    Recorrer un arreglo y mostrar sus elementos en forma recursiva.
**/

void mostrarArregloRecursivo(int array [], int, int);

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int elementos = 5;

    mostrarArregloRecursivo(arr, elementos, 0);


    return 0;
}

void mostrarArregloRecursivo(int array [], int validos, int posActual)
{
    if(posActual < validos)
    {
        printf("[%d] ", array[posActual]);
        mostrarArregloRecursivo(array, validos, posActual + 1);
    }
    else
    {
        printf("\n"); // Imprimir salto de línea al final del arreglo
    }
}
