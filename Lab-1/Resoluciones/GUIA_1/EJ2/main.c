#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
/***
    2.	Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
    Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.
***/

    Pila origen,
         destino;

    ///Inicializamos la pila
    inicpila(&origen);
    inicpila(&destino);

    ///Cargo los valores de la pila
    cargarPila(&origen);

    ///Mostramos por pantalla los valores de la pila recien cargada
    printf("\n\nPila origen\n");
    mostrar(&origen);

    ///Recorro la pila y apilo en destino lo que desapilo de origen.
    while(!pilavacia(&origen))
    {
        apilar(&destino, desapilar(&origen));
    }

    ///Muestro resultado por pantalla
    printf("Pila origen\n");
    mostrar(&origen);
    printf("Pila destino\n");
    mostrar(&destino);

    return 0;
}
