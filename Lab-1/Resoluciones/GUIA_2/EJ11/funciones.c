#include "declaraciones.h"

/**
    menorPila
    Parametros: Una pila
    Descripcion: Devuelve el menor de una pila.
**/
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
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    ///Asigno el menor valor de la pila que va a quedar en el tope a valor.
    valor = desapilar(&pilaMenor);

    return valor;
}


/**
    ordenamientoSeleccion
    Parametros: Una pila
    Descripcion: Ordena la pila ingresada por parametros por el metodo de seleccion.
**/
void ordenamientoSeleccion(Pila *pila)
{
    ///Declaramos las pilas a utilizar y las inicializamos
    Pila pilaOrdenada, aux;

    inicpila(&pilaOrdenada);
    inicpila(&aux);

    while(!pilavacia(pila))
    {
        apilar(&pilaOrdenada, menorPila(pila));
    }

    ///Vuelvo a poner todos los datos ordenados en la pila original, antes tiene que pasar por un auxiliar asi no vuelve dada vuelta
    while(!pilavacia(&pilaOrdenada))
    {
        apilar(&aux, desapilar(&pilaOrdenada));
    }

    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }
}
