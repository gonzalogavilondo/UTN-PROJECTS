#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    2. Hacer una función que pase todos los elementos de una pila a otra.
**/

void pasarPila (Pila *, Pila *);
int main()
{
    Pila pila, aux;

    ///Inicializamos las pilas
    inicpila(&pila);
    inicpila(&aux);

    ///Cargamos las pila
    printf("--CARGAR PILA--\n");
    cargarPila(&pila);

    ///Hacemos una pausa y limpiamos pantalla
    system("pause");
    system("cls || clear");

    printf("--PILA--\n");
    mostrar(&pila);
    printf("--AUXILIAR--\n");
    mostrar(&aux);

    ///Procesamiento principal
    pasarPila(&pila, &aux);

    ///RESULTADOS FINALES
    printf("\n--PILA RESULTANTE--\n");
    mostrar(&pila);
    printf("--AUXILIAR RESULTANTE--\n");
    mostrar(&aux);

    return 0;
}

void pasarPila (Pila *origen, Pila *destino)
{
    while (!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}
