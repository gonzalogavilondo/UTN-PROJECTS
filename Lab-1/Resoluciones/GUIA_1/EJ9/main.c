#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado
**/
int main()
{
    Pila pila1,
         pila2;

    int cntPila1 = 0,
        cntPila2  = 0;

    ///Inicializamos las pilas
    inicpila(&pila1);
    inicpila(&pila2);

    ///Cargamos las pilas
    printf("--PILA 1--\n");
    cargarPila(&pila1);
    printf("\n--PILA 2--\n");
    cargarPila(&pila2);

    ///Hacemos una pausa y limpiamos pantalla
    system("pause");
    system("cls || clear");

    ///Guardo en una pila auxiliar los datos para contar la cantidad de datos
    cntPila1 = longitudPila(&pila1);
    cntPila2 = longitudPila(&pila2);

    ///Mostramos las pilas con sus cantidades de elementos
    mostrar(&pila1);
    printf("La cantidad de elementos de la pila 1 es: %d", cntPila1);
    mostrar(&pila2);
    printf("La cantidad de elementos de la pila 2 es: %d", cntPila2);

    return 0;
}
