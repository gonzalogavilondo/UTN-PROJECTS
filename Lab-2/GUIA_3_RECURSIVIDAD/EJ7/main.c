#include <stdio.h>
#include <stdlib.h>

/**
    Buscar el menor elemento de un arreglo en forma recursiva.
**/

int posMenor(int arr[], int);

int main()
{
    int arr[] = {5, 3, 8, 1, 9, 2};
    int tam = sizeof(arr) / sizeof(arr[0]); // Calcular el tamaño del arreglo
    int menor = posMenor(arr, tam); // Llamar a la función para encontrar el menor
    printf("Menor elemento: %d", menor);

    return 0;
}

int posMenor(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0]; //Este es el caso base de la recursión. Cuando solo hay un elemento en el arreglo (cuando n es 1), el valor de ese único elemento se retorna como el menor valor.
    }
    else
    {
        int menorResto = posMenor(arr, n - 1); // Encontrar el menor en el subarreglo restante
        return (menorResto < arr[n - 1]) ? menorResto : arr[n - 1]; // Comparar con el último elemento
        /**
            Cuando hay más de un elemento en el arreglo (cuando n no es 1), la función se llama recursivamente con el subarreglo que excluye el último elemento. Esto se hace usando encontrarMenor(arr, n - 1).
            Después de obtener el menor valor en el subarreglo restante, se compara con el último elemento del arreglo actual (arr[n - 1]). El valor más pequeño de estos dos se retorna como el menor valor.
        **/
    }
}
