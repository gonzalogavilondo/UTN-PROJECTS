#include <stdio.h>
#include <stdlib.h>
/**
    1. Calcular el factorial de un número en forma recursiva.
**/

int factorial(int);
int main()
{
    int num = 0;

    printf("Ingrese un numero para calcular su factorial: ");
    scanf("%d", &num);


    printf("\nEl factorial de %d es: %d\n", num, factorial(num));

    return 0;
}

int factorial(int num)
{
    int resultado;
    if(num != 0)
    {
        resultado = num * factorial(num - 1); //Acercamiento a la condicion de corte (--num)
    }
    else
    {
        resultado = 1; // Caso base: factorial de 0 es 1. Es la condicion de corte.
    }

    return resultado;
}

/**
    Pensamiento: Yo lo que se es que el factorial de 0 = 1. 0! = 1.
**/
