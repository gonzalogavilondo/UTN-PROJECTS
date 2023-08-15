#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    Cargar por teclado una pila ORIGEN y pasar a la pila DISTINTO todos aquellos
    elementos que preceden al valor 5 (elementos entre el tope y el valor 5). No se asegura que exista algún
    valor 5”, se realizó el siguiente programa:
**/
int main()
{
    Pila origen,
         distinto,
         descarte;
    int  flag = 0;

    ///Inicializamos las pilas
    inicpila(&origen);
    inicpila(&distinto);
    inicpila(&descarte);

    ///Cargamos la pila
    printf("Ingrese los datos para la pila origen\n");
    cargarPila(&origen);

    ///Pausa y borramos pantalla
    system("pause");
    system("cls || clear");

    ///Mostramos la pila original
    printf("--PILA ORIGEN--\n");
    mostrar(&origen);

    ///Recorremos la pila mientras tope != 5
    while(!pilavacia(&origen) && !flag)
    {
        if (tope(&origen) != 5)
        {
            apilar(&distinto, desapilar(&origen));
        }
        else
        {
            flag = 1; //Se encontro el 5.
        }
    }

    ///Mostramos las pilas resultantes
    printf("PILAS RESULTANTES: \n");
    printf("\n--PILA ORIGEN--\n");
    mostrar(&origen);
    printf("\n--PILA DISTINTO--\n");
    mostrar(&distinto);

    return 0;
}

/**
    si no se encuentra el valor 5, entonces la pila Distinto debe contener todos los elementos que estaban antes del valor 5
    en la pila Origen, mientras que la pila Origen debe quedar vacía. De esta forma, se garantiza que el programa resuelve adecuadamente
    el problema planteado, que es pasar a la pila Distinto todos aquellos elementos que preceden al valor 5
**/
