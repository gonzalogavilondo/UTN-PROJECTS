#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int sumarElementosDePila(P_Pila);

/**
    1- Sumar los elementos de una pila (usar variables enteras)
**/
int main()
{
    Pila pila;
    int sumatoria = 0;

    inicpila(&pila);

    ///Cargamos ambas pilas
    printf("Ingrese los elementos para la pila\n");
    cargarPila(&pila);

    ///PAUSA Y LIMPIAMOS PANTALLA
    system("pause");
    system("cls || clear");

    ///MOSTRAMOS LAS PILAS ORIGINALES
    printf("--PILA--\n");
    mostrar(&pila);

    sumatoria = sumarElementosDePila(&pila);
    printf("La sumatoria es: %d\n\n", sumatoria);

    return 0;
}

int sumarElementosDePila(P_Pila pila)
{
    ///Definimos e inicializamos pilas
    Pila aux;
    int sumatoria = 0;

    inicpila(&aux);

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
