#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**

**/

int main()
{
    Pila miPila;
    inicPila(&miPila);
    apilar(&miPila, 10);
    apilar(&miPila, 20);
    apilar(&miPila, 30);
    mostrar(&miPila);
    printf("Tope: %d\n", tope(&miPila));
    printf("Desapilado: %d\n", desapilar(&miPila));
    mostrar(&miPila);
    leer(&miPila);
    mostrar(&miPila);

    return 0;
}
