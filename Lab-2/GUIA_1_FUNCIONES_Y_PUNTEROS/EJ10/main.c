#include <stdio.h>
#include <stdlib.h>

/**
    Hacer una funci�n que reciba como par�metros de entrada un arreglo de enteros y su dimensi�n, y tres par�metros
    de salida, tres n�meros enteros que representen: valor m�ximo, valor m�nimo y promedio. Se debe usar pasaje de
    par�metros por referencia.
**/
void calcularMaxMinPromedio(int arreglo[], int tam, int *maximo, int *minimo, float *promedio);

int main()
{
    const int  tam = 5;
    int     maximo = 0,
            minimo = 0;
    float promedio = 0.0;
    int numeros[tam];

    printf("Ingrese %d numeros enteros:\n", tam);

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &numeros[i]);
    }

    calcularMaxMinPromedio(numeros, tam, &maximo, &minimo, &promedio);
    printf("\nMaximo: %d\n", maximo);
    printf("Minimo: %d\n", minimo);
    printf("Promedio: %.2f\n", promedio);
    return 0;
}

void calcularMaxMinPromedio(int arreglo[], int tam, int *maximo, int *minimo, float *promedio)
{
    *maximo = arreglo[0];
    *minimo = arreglo[0];
    int suma = arreglo[0];
    for (int i = 1; i < tam; i++)
    {
        if (arreglo[i] > *maximo)
        {
            *maximo = arreglo[i];
        }
        if (arreglo[i] < *minimo)
        {
            *minimo = arreglo[i];
        }
        suma += arreglo[i];
    }
    *promedio = (float)suma / tam;
}
