#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/**
    12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los
    elementos que existan en MODELO.
**/
int main()
{
    Pila modelo,
         dada,
         aux1,
         aux2;
    int eliminado = 0;

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
    while (!pilavacia(&modelo))
    {
        eliminado = 0; //Flag para indicar si se eliminó algún elemento en esta iteración
        while (!pilavacia(&dada))
        {
            if (tope(&dada) == tope(&modelo))
            {
                desapilar(&dada); //Elimina el elemento coincidente
                eliminado = 1;
            }
            else
            {
                apilar(&aux2, desapilar(&dada)); //Mantiene el elemento en aux2
            }
        }
        while (!pilavacia(&aux2))
        {
            apilar(&dada, desapilar(&aux2)); //Restaura los elementos conservados en dada
        }
        if (eliminado == 0)
        {
            desapilar(&modelo); //Desapila solo si no se eliminó ningún elemento
        }
    }

    ///Mostramos resultados finales
    printf("--PILAS DESPUES DE MODIFICAR--\n");
    printf("\n\n--PILA DADA--\n");
    mostrar(&dada);

    return 0;
}
