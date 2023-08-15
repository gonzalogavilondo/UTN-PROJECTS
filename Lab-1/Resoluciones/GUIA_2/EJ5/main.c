#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    5- Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal
    que se conserve el orden. (sin variables enteras, solo pilas)
**/

int main()
{
    Pila pila, aux;
    int num;

    /// Inicializamos las pilas.
    inicpila(&pila);
    inicpila(&aux);

    /// Cargamos una pila de forma ordenada como pide el enunciado.
    for(int i = 10; i > 0; i -= 2)
    {
        apilar(&pila, i);
    }

    ///Mostramos la pila.
    printf("--PILA--\n");
    mostrar(&pila);

    ///Pedimos el elemento a insertar.
    printf("Ingrese un elemento: ");
    scanf("%d", &num);

    ///Insertamos el elemento en la posición correcta.
    while (!pilavacia(&pila) && tope(&pila) < num)
    {
        apilar(&aux, desapilar(&pila));
    }
    apilar(&pila, num);

    while (!pilavacia(&aux))
    {
        apilar(&pila, desapilar(&aux));
    }

    // Mostramos la pila actualizada.
    printf("\n\n--PILA ACTUALIZADA--\n");
    mostrar(&pila);

    return 0;
}

/**
    Para insertar un elemento en una pila ordenada de menor a mayor sin utilizar variables enteras adicionales,
    se puede utilizar una pila auxiliar para desapilar los elementos de la pila original que son mayores que el
    elemento a insertar y apilarlos en la pila auxiliar. Luego, se apila el nuevo elemento en la pila original y
    se desapilan los elementos de la pila auxiliar y se apilan de nuevo en la pila original. De esta manera, se
    garantiza que la pila esté ordenada de menor a mayor después de la inserción del nuevo elemento.
**/
