#include <stdio.h>
#include <stdlib.h>

/**
    Determinar en forma recursiva si un arreglo es capic�a.
**/

int esCapicua(int arr[], int, int);

int main()
{
    int arr[] = {1, 2, 3, 2, 1};
    int tam = sizeof(arr) / sizeof(arr[0]); //Calcular el tama�o del arreglo
    printf("Resultado: %d", esCapicua(arr, 0, tam - 1)); //Pasar el �ndice final correcto

    return 0;
}

int esCapicua(int arr[], int i, int j)
{
    int rta = 1; //Supongamos que el subarreglo es capic�a por defecto

    if (i <= j)
    {
        if (arr[i] != arr[j])
        {
            rta = 0; //Si los elementos en las posiciones i y j no coinciden, no es capic�a
        }
        else
        {
            rta = esCapicua(arr, i + 1, j - 1); //Comprobar el subarreglo interno
        }
    }

    return rta;
}
