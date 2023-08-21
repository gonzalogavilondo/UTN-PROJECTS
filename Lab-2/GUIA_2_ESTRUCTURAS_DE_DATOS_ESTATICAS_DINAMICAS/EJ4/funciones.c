#include "declaraciones.h"

void insertarEnOrden(Pila *pila, int dato)
{
    Pila aux;
    inicPila(&aux);

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
    inicPila(&pilaMenor);
    inicPila(&aux);

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

int sumarElementosPila(Pila *pila)
{
    ///Definimos e inicializamos pilas
    Pila aux;
    int sumatoria = 0;

    inicPila(&aux);

    ///Recorro la pila sumando sus elementos
    while(!pilavacia(pila))
    {
        sumatoria += tope(pila);
        apilar(&aux, desapilar(pila));
    }

    ///Uso aux para dejar la pila como estaba antes
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return sumatoria;
}

int calcularPromedioPila(int suma, int cantidad)
{
    return suma/cantidad;
}

int promedioElementosPila(Pila *pila)
{
    int cntElementos  = 0,
        sumaElementos = 0,
        promedio      = 0;

    cntElementos = longitudPila(pila);
    sumaElementos = sumarElementosPila(pila);
    promedio = calcularPromedioPila(sumaElementos, cntElementos);

    return promedio;
}

int pilaAdecimal(Pila *pila)
{
    Pila aux, aux2;
    inicPila(&aux);
    inicPila(&aux2);

    int decimal = 0;
    int multiplicador = 1;

    while (!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));
    }

    while (!pilavacia(&aux))
    {

        decimal = decimal + (tope(&aux) * multiplicador);
        apilar(&aux2, desapilar(&aux));
        multiplicador = multiplicador * 10;
    }

    return decimal;
}

void insertarPilaEnOrden(Pila *origen, Pila *destino)
{
    while(!pilavacia(origen))
    {
        insertarEnOrden(destino, desapilar(origen));
    }
}
