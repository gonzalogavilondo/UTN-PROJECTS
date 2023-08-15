#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    10. Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos
    sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.
    A : base 1 2 3 tope
    B: base 2 3 5 7 tope
    Pila AUB = base 3 2 1 7 5 tope
**/

int buscar(Pila *, int);

int main()
{
    Pila pilaA,
         pilaB,
         pilaC,
         auxA,
         auxB;
    int elemento = 0;

    ///Inicializamos las pilas
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&pilaC);
    inicpila(&auxA);
    inicpila(&auxB);

      ///Cargamos las pilas A y B
    printf("--PILA A--\n");
    cargarPila(&pilaA);

    printf("\n--PILA B--\n");
    cargarPila(&pilaB);

    ///Hacemos una pausa y limpiamos pantalla
    system("pause");
    system("cls || clear");

    ///Realizamos la operación de unión
    while(!pilavacia(&pilaA))
    {
        elemento = desapilar(&pilaA);
        apilar(&pilaC, elemento);
        apilar(&auxA, elemento); //Para mantener registro de lo que se ha agregado en la pila C de la pila A
    }

    while(!pilavacia(&pilaB))
    {
        elemento = desapilar(&pilaB);
        if(!buscar(&pilaC, elemento))
        {
            apilar(&pilaC, elemento);
        }
        apilar(&auxB, elemento); //Para mantener registro de lo que se ha agregado en la pila C de la pila B
    }

    ///Volvemos a guardar los valores de la pila A y pila B como estaban originalmente
    while(!pilavacia(&auxA))
    {
        apilar(&pilaA, desapilar(&auxA));
    }

    while(!pilavacia(&auxB))
    {
        apilar(&pilaB, desapilar(&auxB));
    }

    ///Mostramos los resultados
    printf("--PILA A--\n");
    mostrar(&pilaA);

    printf("\n--PILA B--\n");
    mostrar(&pilaB);

    printf("--PILA A U B--\n");
    mostrar(&pilaC);

    return 0;
}



int buscar(Pila *pila, int elemento)
{
    ///Declaramos las pilas a utilizar y las inicializamos
    Pila aux;
    inicpila(&aux);

    int flag = 0;

    ///Recorremos la pila y buscamos el dato, si lo encuentro asigno a flag el valor de 1 de verdadero
    while(!pilavacia(pila))
    {
        if(tope(pila) == elemento)
        {
            flag = 1;
        }
        apilar(&aux, desapilar(pila));
    }

    ///Vuelvo a poner la pila como estaba
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return flag;
}
