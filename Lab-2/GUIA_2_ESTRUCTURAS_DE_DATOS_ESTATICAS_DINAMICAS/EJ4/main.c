#include "declaraciones.h"

/**
    Dadas dos pilas (como las anteriores) que se supone que tienen sus datos ordenados, generar una tercer pila que
    contenga los datos de las dos anteriores intercalados, de forma tal que queden ordenados.
**/

int main()
{
    Pila miPila,
         miPila2,
         miPilaFinal;

    inicPila(&miPila);
    inicPila(&miPila2);
    inicPila(&miPilaFinal);

    apilar(&miPila, 10);
    apilar(&miPila, 20);
    apilar(&miPila, 30);

    apilar(&miPila2, 35);
    apilar(&miPila2, 15);
    apilar(&miPila2, 45);

    printf("--PILA 1--\n");
    mostrar(&miPila);
    printf("\n--PILA 2--\n");
    mostrar(&miPila2);

    ///Ordeno por seleccion la primera pila y la almaceno en la destino que sera la pila final
    ordenamientoPorSeleccion(&miPila, &miPilaFinal);

    ///Inserto la segunda pila en la final de forma ordenada
    insertarPilaEnOrden(&miPila2, &miPilaFinal);

    printf("\n--PILA FINAL--\n");
    mostrar(&miPilaFinal);

    return 0;
}
