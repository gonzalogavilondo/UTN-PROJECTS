#include <stdio.h>
#include <stdlib.h>

/**
    Calcular la potencia de un número en forma recursiva.
**/
int potencia(int, int);

int main()
{
    int num = 0,
        pot = 0;

    printf("Ingrese un numero: ");
    scanf("%d", &num);
    printf("Ingrese su potencia: ");
    scanf("%d", &pot);

    printf("\nLa potencia de %d a la %d es: %d\n", num, pot, potencia(num, pot));



    return 0;
}

int potencia(int num, int pot)
{
    int resultado;

    if(pot == 0) //Condicion de corte
    {
        resultado = 1;
    }
    else
    {
        resultado = num * potencia(num, pot - 1); //Acercamiento a la condicion de corte y su solucion trivial.
    }

    return resultado;
}
