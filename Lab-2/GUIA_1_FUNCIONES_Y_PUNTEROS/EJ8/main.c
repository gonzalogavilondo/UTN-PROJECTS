#include <stdio.h>
#include <stdlib.h>

/**
    Dados dos arreglos de números enteros ordenados de menor a mayor, hacer una función que los reciba como
    parámetros y retorne un tercer arreglo que contenga los datos de los arreglos anteriores, también ordenados. Se los
    debe intercalar.
**/
void interclasificar(int arr1[], int tam1, int arr2[], int tam2, int resultado[]);
void mostrarArreglo(int arreglo[], int tam);

int main()
{

    const int tam1 = 5;
    const int tam2 = 7;
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10, 12, 14};
    int *resultado = (int *)malloc((tam1 + tam2) * sizeof(int));
    interclasificar(arr1, tam1, arr2, tam2, resultado);
    mostrarArreglo(resultado, tam1 + tam2);

    free(resultado);

    return 0;
}

/**
    Esta función combina los arreglos arr1 y arr2 en un solo arreglo resultado, manteniendo el orden ascendente.
    El bucle principal compara los elementos actuales en arr1 y arr2 y los coloca en resultado de manera ordenada,
    mientras que los bucles adicionales añaden los elementos restantes si alguno de los arreglos es más largo que el otro.
**/
void interclasificar(int arr1[], int tam1, int arr2[], int tam2, int resultado[])
{
    int i = 0,
        j = 0,
        k = 0;

    while (i < tam1 && j < tam2)
    {
        if (arr1[i] < arr2[j])      //Si el elemento actual en arr1 es menor que el elemento actual en arr2, entonces:
        {
            resultado[k] = arr1[i]; //Se asigna el valor de arr1[i] al arreglo resultado en la posición k.
            i++;                    //Se incrementa i para moverse al siguiente elemento en arr1.
        }
        else                        //Si el elemento actual en arr1 no es menor que el elemento actual en arr2, entonces:
        {
            resultado[k] = arr2[j]; //Se asigna el valor de arr2[j] al arreglo resultado en la posición k.
            j++;                    //Se incrementa j para moverse al siguiente elemento en arr2.
        }
        k++;                        //En ambos casos, se incrementa k para avanzar a la siguiente posición en resultado.
    }
    /**
        Después de salir del primer bucle while, se pueden quedar elementos en uno de los arreglos sin procesar
        (ya que uno de los arreglos puede ser más largo que el otro). Por lo tanto, se usan dos bucles while
        adicionales para agregar los elementos restantes a resultado:
    **/
    while (i < tam1) //Si aún quedan elementos en arr1, se copian al arreglo resultado.
    {
        resultado[k] = arr1[i];
        i++;
        k++;
    }
    while (j < tam2) //Si aún quedan elementos en arr2, se copian al arreglo resultado.
    {
        resultado[k] = arr2[j];
        j++;
        k++;
    }
}

void mostrarArreglo(int arreglo[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}
