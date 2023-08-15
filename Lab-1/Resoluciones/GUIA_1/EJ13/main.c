#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/**
    13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores
    o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila
    MENORES
**/

int main()
{
    Pila limite,
         dada,
         mayores,
         menores;

    ///Inicializamos todas las pilas
    inicpila(&limite);
    inicpila(&dada);
    inicpila(&mayores);
    inicpila(&menores);

    ///Cargamos ambas pilas
    printf("Ingrese los datos para la pila LIMITE\n");
    cargarPila(&limite);
    printf("\nIngrese los datos para la pila DADA\n");
    cargarPila(&dada);

    ///PAUSA Y LIMPIAMOS PANTALLA
    system("pause");
    system("cls || clear");

    ///MOSTRAMOS LAS PILAS ORIGINALES
    printf("--PILA LIMITE--\n");
    mostrar(&limite);
    printf("\n\n--PILA DADA--\n");
    mostrar(&dada);

    ///Recorremos para eliminar los datos que no quiero en dada

    while (!pilavacia(&dada))
    {
        if (tope(&dada) > tope(&limite))
        {
            apilar(&mayores,desapilar(&dada));
        }
        else //SI SON MENORES O IGUALES VA A LA PILA DE MENORES.
        {
            apilar(&menores, desapilar(&dada));
        }
    }

    ///MOSTRAMOS LAS PILAS RESULTANTES
    printf("\n--PILAS RESULTANTES--\n\n");
    printf("\n\n--PILA MENORES--\n");
    mostrar(&menores);
    printf("\n\n--PILA MAYORES--\n");
    mostrar(&mayores);

    return 0;
}
