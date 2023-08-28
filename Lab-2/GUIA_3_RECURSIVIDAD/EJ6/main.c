#include <stdio.h>
#include <stdlib.h>

/**
    Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de
    la suma.
**/

int suma(int arr[], int, int);

int main()
{
    int arr[] = {1, 2, 3, 2, 1};
    int tam = sizeof(arr) / sizeof(arr[0]); //Calcular el tamaño del arreglo
    printf("Resultado: %d\n", suma(arr, tam, 0));

    return 0;
}

int suma(int arr[], int validos, int posActual)
{
    if (posActual < validos) //Condicion de corte.
    {
        return arr[posActual] + suma(arr, validos, posActual + 1);
    }
    else
    {
        return 0; //Cuando posActual = validos, entonces llegue al final, sumo 0.
    }
}
