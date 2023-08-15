#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    8. Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el
    mismo orden.

**/
int main()
{
    ///Declaramos las pilas a utilizar y las inicializamos
    Pila pila, aux, valorEncontrado;

    inicpila(&pila);
    inicpila(&aux);
    inicpila(&valorEncontrado);

    int flag = 0,
        dato = 0;

    ///Cargamos los elementos de la primera pila
    cargarPila(&pila);

    ///Pausa y limpiado de pantalla
    system("pause");
    system("cls || clear");

    ///Muestro pila
    printf("--PILA--\n");
    mostrar(&pila);

    printf("Ingrese el dato que desea buscar en la PILA: ");
    scanf("%d", &dato);

    ///Recorremos la pila y buscamos el dato, si lo encuentro asigno a flag el valor de 1 de verdadero
    while(!pilavacia(&pila))
    {
        if(tope(&pila) == dato)
        {
            flag = 1;
            apilar(&valorEncontrado, desapilar(&pila));
        }
        else
        {
            apilar(&aux, desapilar(&pila));
        }
    }

    ///Vuelvo a poner la pila como estaba
    while(!pilavacia(&aux))
    {
        apilar(&pila, desapilar(&aux));
    }

    ///Pausa
    system("pause");

    if(flag == 1)
    {
        printf("\nEl dato: %d fue encontrado y eliminado.\n", dato);
    }
    else
    {
        printf("\nEl dato: %d no fue encontrado. \n", dato);
    }

    ///Muestro pila como resultado final
    printf("--PILA FINAL--\n");
    mostrar(&pila);

    return 0;
}
