#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope
    de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR. (NO contar los elementos)
**/

int main()
{
    Pila dada,
         aux,
         par,
         impar;

    int cnt     = 0,
        flag    = 0,
        topeAux = 0;

    ///Inicializamos la pila
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&par);
    inicpila(&impar);

    ///Cargamos la pila
    printf("Ingrese los datos para la pila DADA\n");
    cargarPila(&dada);

    ///Pausa y borramos pantalla
    system("pause");
    system("cls || clear");

    ///Mostramos la pila original
    printf("--PILA DADA--\n");
    mostrar(&dada);

    ///En la pila aux va a estar la base de la pila dada
    while(!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
    }

    ///Mostramos la pila aux original
    printf("--PILA AUX--\n");
    mostrar(&aux);

    ///Guardo el tope en la pila aux
    topeAux = tope(&aux);

    /**
        Se reparte cada elemento de forma alternativa (como las cartas). El flag determina
        en donde termino de "repartir" cada elemento, si termino de "repartir" en la pila
        par, entonces la pila es impar, caso contrario la pila es par.
    **/
    while(!pilavacia(&aux))
    {
        if(cnt % 2 == 0) // Se reparte el elemento a la pila par
        {
            apilar(&par, desapilar(&aux));
            flag = 0; //La pila dada es impar
        }
        else // Se reparte el elemento a la pila impar
        {
            apilar(&impar, desapilar(&aux));
            flag = 1; //La pila dada es par
        }
        cnt++;
    }

    ///Vaciamos las pilas par e impar asi queda el tope de AUX en una sola
    while(!pilavacia(&par))
    {
        desapilar(&par);
    }
    while(!pilavacia(&impar))
    {
        desapilar(&impar);
    }

    if(flag == 1)
    {
        printf("La pila DADA es PAR.\n");
        apilar(&par, topeAux);
    }
    else
    {
        printf("La pila DADA es IMPAR.\n");
        apilar(&impar, topeAux);
    }


    ///Mostramos las pilas resultantes
    printf("\nElementos de la pila PAR:\n");
    mostrar(&par);
    printf("Elementos de la pila IMPAR:\n");
    mostrar(&impar);

    return 0;
}
