#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/**
    11. Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA todos los
    elementos que sean iguales al tope de la pila MODELO.
**/
int main()
{
    Pila modelo,
         dada,
         aux1,
         aux2;

    ///Inicializamos todas las pilas
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    ///Cargamos ambas pilas
    printf("Ingrese los datos para la pila MODELO\n");
    cargarPila(&modelo);
    printf("\nIngrese los datos para la pila DADA\n");
    cargarPila(&dada);

    ///PAUSA Y LIMPIAMOS PANTALLA
    system("pause");
    system("cls || clear");

    ///MOSTRAMOS LAS PILAS ORIGINALES
    printf("--PILA MODELO--\n");
    mostrar(&modelo);
    printf("\n\n--PILA DADA--\n");
    mostrar(&dada);

    ///Recorremos para eliminar los datos que no quiero en dada
    while(!pilavacia(&dada))
    {
        if(tope(&dada) == tope(&modelo))
        {
           apilar(&aux1, desapilar(&dada)); ///Utilizo aux1 para desapilar lo que quiero eliminar.
        }
        else
        {
           apilar(&aux2, desapilar(&dada)); ///Utilizo aux2 para desapilar lo que voy a mantener.
        }
    }

    while(!pilavacia(&aux2))
    {
        apilar(&dada, desapilar(&aux2));
    }

    ///Mostramos resultados finales
    printf("--PILAS DESPUES DE MODIFICAR--\n");
    printf("\n\n--PILA DADA--\n");
    mostrar(&dada);

    return 0;
}
