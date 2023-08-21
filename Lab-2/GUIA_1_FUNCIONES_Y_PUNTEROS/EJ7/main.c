#include <stdio.h>
#include <stdlib.h>

/**
    Hacer una función que intercambie el contenido de dos variables. (pasaje de parámetros por referencia)
**/

void intercambiarValores(int *, int *);
int main()
{

    int a = 0,
        b = 0;


    ///Ingreso los valores a intercambiar
    printf("Ingrese el valor de a: ");
    scanf("%d", &a);
    printf("Ingrese el valor de b: ");
    scanf("%d", &b);

    ///Muestro los valores antes de llamar a la funcion intercambiar
    printf("\na: %d\nb: %d\n", a, b);

    ///Llamo a la funcion intercambiar
    intercambiarValores(&a, &b);

    ///Muestro los valores despues de llamar a la funcion intercambiar
    printf("\nNuevos valores:\na: %d\nb: %d\n", a, b);

    return 0;
}

void intercambiarValores(int *a, int *b)
{
    int aux = 0;

    aux = *a; //Guardo en una variable auxiliar el contenido de a
    *a = *b;  //Asigno a "a" el valor de b
    *b = aux; //Asigno a b el valor anterior de a.

}
