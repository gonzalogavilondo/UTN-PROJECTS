#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
/***
 4.	Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
    Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.
***/

    Pila origen,
         destino,
         aux;

    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    ///Cargamos la pila
    cargarPila(&origen);

    printf("Origen\n");
    mostrar(&origen);

    ///Apilamos en la pila aux la pila invertida
    while (!pilavacia(&origen))
    {
        apilar(&aux, desapilar(&origen));
    }

    printf("Auxiliar\n");
    mostrar(&aux);

    ///Apilamos en destino la pila auxiliar que era la invertida para que vuelva a quedar como origen.
    while (!pilavacia(&aux))
    {
        apilar(&destino, desapilar(&aux));
    }

    ///Muestro origen y destino
    printf("Destino\n");
    mostrar(&destino);

    printf("Origen\n");
    mostrar(&origen);

    return 0;
}
