#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.
**/

void pasarPila (Pila *, Pila *);
void pasarPilaOrdenado(Pila *origen, Pila *destino);

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
    pasarPilaOrdenado(&pila, &aux);

    ///RESULTADOS FINALES
    printf("\n--PILA RESULTANTE--\n");
    mostrar(&pila);
    printf("--AUXILIAR RESULTANTE--\n");
    mostrar(&aux);

    return 0;
}

void pasarPila(Pila *origen, Pila *destino)
{
    while (!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

void pasarPilaOrdenado(Pila *origen, Pila *destino)
{
    Pila aux;
    inicpila(&aux);
    pasarPila(origen, &aux);
    pasarPila(&aux, destino);
}
