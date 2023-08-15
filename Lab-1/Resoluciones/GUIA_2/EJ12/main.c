#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    12. Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el
    resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.
**/

int main()
{
    Pila origen, aux, receptora;

    ///Inicializamos las pilas
    inicpila(&origen);
    inicpila(&aux);
    inicpila(&receptora);

    ///Cargamos las pilas
    printf("--CARGAR PILA ORIGEN--\n");
    cargarPila(&origen);

    ///Hacemos una pausa y limpiamos pantalla
    system("pause");
    system("cls || clear");

    while(!pilavacia(&origen))
    {
        while (!pilavacia(&receptora) && tope(&origen) > tope(&receptora))
        {
            apilar(&aux, desapilar(&receptora));
        }

        apilar(&receptora, desapilar(&origen));

        while(!pilavacia(&aux))
        {
            apilar(&receptora, desapilar(&aux));
        }
    }

    while(!pilavacia(&receptora))
    {
        apilar(&origen, desapilar(&receptora));
    }

    printf("--PILA ORIGEN RESULTANTE--\n");
    mostrar(&origen);

    return 0;
}
