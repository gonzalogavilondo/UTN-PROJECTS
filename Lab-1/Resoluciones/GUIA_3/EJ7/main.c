#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"
#include "pila.h"

/**
    7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
       nueva pila ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción)
**/

int main()
{
    Pila pila, pilaOrdenada;
    int num;

    /// Inicializamos las pilas.
    inicpila(&pila);
    inicpila(&pilaOrdenada);

    /// Cargamos una pila de forma ordenada como pide el enunciado.
    printf("CARGUE LA PILA: \n");
    cargarPila(&pila);

    ///Pausa y limpiar pantalla
    system("pause");
    system("cls || clear");

    ///Mostramos la pila.
    printf("--PILA--\n");
    mostrar(&pila);

    ///Llamamos a ordenamientoPorInsercion
    ordenamientoPorInsercion(&pila, &pilaOrdenada);

    ///Mostramos la pila actualizada.
    printf("\n\n--PILA ORDENADA POR METODO DE INSERCION--\n");
    mostrar(&pilaOrdenada);

    return 0;
}

