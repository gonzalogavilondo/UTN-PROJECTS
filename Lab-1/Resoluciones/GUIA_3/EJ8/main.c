#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior),
       sin alterar su contenido.
**/

int sumaTopeyAnterior (Pila *);
int main()
{
    Pila pila;
    int resultado = 0;

    ///Inicializamos las pilas.
    inicpila(&pila);

    ///Cargamos una pila de forma ordenada como pide el enunciado.
    printf("CARGUE LA PILA: \n");
    cargarPila(&pila);

    ///Pausa y limpiar pantalla
    system("pause");
    system("cls || clear");

    ///Mostramos la pila.
    printf("--PILA--\n");
    mostrar(&pila);

    ///Llamamos a ordenamientoPorInsercion+
    resultado = sumaTopeyAnterior(&pila);

    ///Mostramos el resultado
    printf("\nEl resultado de la suma del tope y el anterior es %d \n", resultado);

    return 0;
}

int sumaTopeyAnterior (Pila *pila)
{
    Pila aux;
    inicpila(&aux);

    int contador = 0;
    int respuesta = 0;

    while(!pilavacia(pila) && contador < 2)
    {
        respuesta = respuesta + tope(pila);
        apilar(&aux, desapilar(pila));
        contador++;
    }

    ///Vuelvo a poner la pila como estaba
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return respuesta;
}
