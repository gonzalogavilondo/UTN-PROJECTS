#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    10. Cargar las pilas A y B, y luego compararlas, evaluando si son completamente iguales (en cantidad de
        elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado
**/
int main()
{
    Pila pilaA,
         pilaB,
         auxA,
         auxB;

    ///Inicializamos las pilas
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&auxA);
    inicpila(&auxB);

    ///Cargamos las pilas
    printf("--PILA A--\n");
    cargarPila(&pilaA);
    printf("\n--PILA B--\n");
    cargarPila(&pilaB);

    ///Hacemos una pausa y limpiamos pantalla
    system("pause");
    system("cls || clear");

    ///Mostramos las pilas con sus cantidades de elementos
    mostrar(&pilaA);
    mostrar(&pilaB);

    while(!pilavacia(&pilaA) && !pilavacia(&pilaB) && (tope(&pilaA) == tope(&pilaB)))
    {
        apilar(&auxA, desapilar(&pilaA));
        apilar(&auxB, desapilar(&pilaB));
    }

    if(pilavacia(&pilaA) && pilavacia(&pilaB))
    {
        printf("Las pilas son iguales.\n");
    }
    else
    {
        printf("Las pilas son distintas.\n");
    }

    return 0;
}
