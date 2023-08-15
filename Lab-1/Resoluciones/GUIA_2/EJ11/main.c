#include "declaraciones.h"

/**
    11. Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando
    el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).
**/

int main()
{
    Pila pilaA, pilaB, pilaFinal, auxFinal;

    ///Inicializamos las pilas
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&pilaFinal);
    inicpila(&auxFinal);

    ///Cargamos las pilas
    printf("--CARGAR PILA A--\n");
    cargarPila(&pilaA);
    printf("\n--CARGAR PILA B--\n");
    cargarPila(&pilaB);

    ///Hacemos una pausa y limpiamos pantalla
    system("pause");
    system("cls || clear");

    ///Mostramos las pilas
    printf("--PILA A--\n");
    mostrar(&pilaA);

    printf("\n--PILA B--\n");
    mostrar(&pilaB);

    ///Ordenamos ambas pilas que es la condicion del ejercicio, que ambas esten ordenadas
    ordenamientoSeleccion(&pilaA);
    ordenamientoSeleccion(&pilaB);

    ///Mostramos las pilas ordenadas
    printf("--PILA A ORDENADA--\n");
    mostrar(&pilaA);

    printf("\n--PILA B ORDENADA--\n");
    mostrar(&pilaB);

    ///Procesamiento principal
    while(!pilavacia(&pilaA)&& !pilavacia(&pilaB))
    {
        if (tope(&pilaA) > tope(&pilaB))
        {
            apilar(&pilaFinal, desapilar(&pilaA));
        }
        else
        {
            apilar(&pilaFinal, desapilar(&pilaB));
        }
    }

    ///Ahora evaluo si quedo algo en alguna de las dos pilas
    if(!pilavacia(&pilaA))
    {
        while(!pilavacia(&pilaA))
        {
            apilar(&pilaFinal, desapilar(&pilaA));
        }
    }
    else
    {
        while(!pilavacia(&pilaB))
        {
            apilar(&pilaFinal, desapilar(&pilaB));
        }
    }

    ///Damos vuelta la pila final y la guardamos en aux para mostrarla por pantalla bien.
    while(!pilavacia(&pilaFinal))
    {
        apilar(&auxFinal, desapilar(&pilaFinal));
    }

    ///Mostramos la pila resultante
    printf("\n--PILA FINAL--\n");
    mostrar(&auxFinal);

    return 0;
}
