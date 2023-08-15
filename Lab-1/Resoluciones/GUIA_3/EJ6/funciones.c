#include "declaraciones.h"

/**
    Para insertar un elemento en una pila ordenada de menor a mayor sin utilizar variables enteras adicionales,
    se puede utilizar una pila auxiliar para desapilar los elementos de la pila original que son mayores que el
    elemento a insertar y apilarlos en la pila auxiliar. Luego, se apila el nuevo elemento en la pila original y
    se desapilan los elementos de la pila auxiliar y se apilan de nuevo en la pila original. De esta manera, se
    garantiza que la pila esté ordenada de menor a mayor después de la inserción del nuevo elemento.
**/

void insertarEnOrden(Pila *pila, int dato)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(pila) && tope(pila) > dato)
    {
        apilar(&aux, desapilar(pila));
    }
    apilar(pila, dato);

    while (!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }
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
    while(!pilavacia(origen))
    {
        apilar(destino, menorPila(origen));
    }
}
