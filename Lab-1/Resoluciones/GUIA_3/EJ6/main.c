#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"
#include "pila.h"

/**
    6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden
    de ésta.
**/

int main()
{
    Pila pila, aux, pilaOrdenada;
    int num;

    /// Inicializamos las pilas.
    inicpila(&pila);
    inicpila(&aux);
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

    ///Ordenamos la pila porque por el enunciado tiene que estar ordenada
    ordenamientoPorSeleccion(&pila, &pilaOrdenada);

    ///Mostramos la pila.
    printf("--PILA ORDENADA--\n");
    mostrar(&pilaOrdenada);

    ///Pedimos el elemento a insertar.
    printf("Ingrese un elemento: ");
    scanf("%d", &num);

    ///Insertamos el elemento en la posición correcta.
    insertarEnOrden(&pilaOrdenada, num);

    ///Mostramos la pila actualizada.
    printf("\n\n--PILA ACTUALIZADA--\n");
    mostrar(&pilaOrdenada);

    return 0;
}

