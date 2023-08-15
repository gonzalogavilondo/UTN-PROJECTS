#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int longitudPila(P_Pila);
int sumarElementosDePila(P_Pila);

/**
    3- Calcular el promedio de los valores de una pila (usar variables)
**/
int main()
{
    Pila pila;
    int cntElementos = 0,
        sumatoria    = 0;

    float promedio = 0.0;

    ///Inicializamos todas las pilas
    inicpila(&pila);

    ///Cargamos ambas pilas
    printf("Ingrese los datos para la pila\n");
    cargarPila(&pila);

    ///PAUSA Y LIMPIAMOS PANTALLA
    system("pause");
    system("cls || clear");

    ///MOSTRAMOS LA PILA
    printf("--PILA--\n");
    mostrar(&pila);

    ///Llamo a la funcion longitudPila y almaceno el valor que devuelve en cntElementos
    cntElementos = longitudPila(&pila);

    ///Llamo a la funcion sumarElementosDePila y que me devuelva la suma total de los elementos
    sumatoria = sumarElementosDePila(&pila);

    ///Calculo el promedio de los elementos de la pila
    promedio = sumatoria / cntElementos;

    ///Imprimo el resultado
    printf("La cantidad de elementos es: %d\n\n", cntElementos);
    printf("La sumatoria es: %d\n\n", sumatoria);
    printf("El promedio de los valores de la pila es: %.2f\n", promedio);

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
