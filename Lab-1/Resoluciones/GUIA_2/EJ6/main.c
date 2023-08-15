#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    6. Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que
    la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de
    ordenación por selección
**/
int menorPila(Pila *);

int main()
{
    ///Declaramos las pilas a utilizar y las inicializamos
    Pila pila, pilaOrdenada, aux;

    inicpila(&pila);
    inicpila(&pilaOrdenada);
    inicpila(&aux);

    ///Cargamos los elementos de la primera pila
    cargarPila(&pila);

    ///Pausa y limpiado de pantalla
    system("pause");
    system("cls || clear");

    ///Muestro pila
    printf("--PILA--\n");
    mostrar(&pila);

    while(!pilavacia(&pila))
    {
        apilar(&pilaOrdenada, menorPila(&pila));
    }

    ///Muestro el resultado final
    printf("--PILA ORDENADA POR METODO DE SELECCION--\n");
    mostrar(&pilaOrdenada);

    return 0;
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
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    ///Asigno el menor valor de la pila que va a quedar en el tope a valor.
    valor = desapilar(&pilaMenor);

    return valor;
}

