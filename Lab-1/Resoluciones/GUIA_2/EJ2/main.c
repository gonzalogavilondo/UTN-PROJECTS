#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int longitudPila(P_Pila pila);
/**
    2- Contar los elementos de una pila (usar variables enteras)
**/
int main()
{
    Pila pila;
    int cntElementos = 0;

    ///Inicializamos todas las pilas
    inicpila(&pila);

    ///Cargamos ambas pilas
    printf("Ingrese los datos para la pila\n");
    cargarPila(&pila);

    ///PAUSA Y LIMPIAMOS PANTALLA
    system("pause");
    system("cls || clear");

    ///MOSTRAMOS LAS PILAS ORIGINALES
    printf("--PILA--\n");
    mostrar(&pila);

    ///Llamo a la funcion longitudPila y almaceno el valor que devuelve en cntElementos
    cntElementos = longitudPila(&pila);

    printf("La cantidad de elementos de la pila es: %d\n", cntElementos);


    return 0;
}

int longitudPila(P_Pila pila)
{
    Pila aux;
    inicpila(&aux);

    int cnt = 0;
    while(!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));
        cnt++;
    }

    ///Volvemos a poner la pila original como estaba
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return cnt;
}
