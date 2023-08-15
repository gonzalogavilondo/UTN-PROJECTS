#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
    nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)
**/
void pasarPila(Pila *, Pila *);
int menorPila(Pila *);
void ordenamientoPorSeleccion(Pila *, Pila *);

int main()
{
    ///Declaramos las pilas a utilizar y las inicializamos
    Pila pila, pilaOrdenada;

    inicpila(&pila);
    inicpila(&pilaOrdenada);

    ///Cargamos los elementos de la primera pila
    cargarPila(&pila);

    ///Pausa y limpiado de pantalla
    system("pause");
    system("cls || clear");

    ///Muestro pila
    printf("--PILA--\n");
    mostrar(&pila);

    ///Procesamiento de ordenamiento por seleccion
    ordenamientoPorSeleccion(&pila, &pilaOrdenada);

    ///Muestro el resultado final
    printf("--PILA ORDENADA POR METODO DE SELECCION--\n");
    mostrar(&pilaOrdenada);

    return 0;
}

void pasarPila(Pila *origen, Pila *destino)
{
    while (!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

int menorPila(Pila *pila)
{
    Pila pilaMenor, aux;
    int flagEncontrado = 0,
        valor          = 0;

    ///Inicializamos todas las pilas
    inicpila(&pilaMenor);
    inicpila(&aux);

    while (!pilavacia(pila))
    {
        valor = desapilar(pila);
        if (!flagEncontrado || valor < tope(&pilaMenor))
        {
            if (flagEncontrado)
            {
                apilar(&aux, desapilar(&pilaMenor));
            }
            apilar(&pilaMenor, valor);
            flagEncontrado = 1; //Flag que se encontro un nuevo valor menor.
        }
        else
        {
            apilar(&aux, valor);
        }
    }

    ///Volvemos a dejar la pila con todos sus valores menos el menor encontrado
    pasarPila(&aux, pila);

    ///Asigno el menor valor de la pila que va a quedar en el tope a valor.
    valor = desapilar(&pilaMenor);

    return valor;
}

void ordenamientoPorSeleccion(Pila *origen, Pila *destino)
{
    ///Declaramos las pilas a utilizar y las inicializamos
    Pila aux;

    inicpila(&aux);

    while(!pilavacia(origen))
    {
        apilar(destino, menorPila(origen));
    }

}

