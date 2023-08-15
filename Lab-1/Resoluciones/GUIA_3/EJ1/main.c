#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el
    usuario.
**/

void cargarPila(Pila *); ///Esta funcion ya la habia hecho antes y esta aplicada en todos los ejercicios de las guias anteriores.

int main()
{
    Pila pila;

    ///Inicializamos las pilas
    inicpila(&pila);

    ///Cargamos las pila
    printf("--CARGAR PILA--\n");
    cargarPila(&pila);

    ///Hacemos una pausa y limpiamos pantalla
    system("pause");
    system("cls || clear");

    printf("--PILA RESULTANTE--\n");
    mostrar(&pila);

    return 0;
}

void cargarPila(Pila *p)
{
    char control = '0';
    int num = 0;
    do
    {
        printf("Ingrese numeros a la pila o 0 para terminar: ");
        fflush(stdin);
        scanf("%d", &num);
        if(num != 0)
        {
            apilar(p, num);
        }
        else
        {
            printf("Desea agregar el '0' a la pila? <SI/NO> <S/CUALQ. OTRA LETRA> ");
            fflush(stdin);
            scanf("%c", &control);
            if(control == 'S' || control == 's')
            {
                apilar(p, num);
                num = 1; //Cambio el numero para que se siga agregando valores
            }
        }

    }while (num != 0 );
}
