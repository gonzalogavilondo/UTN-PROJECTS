#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La
    misma debe eliminar ese dato de la pila.
**/
int menorPila(Pila *);

int main()
{
     ///Declaramos las pilas a utilizar y las inicializamos
    Pila pila;
    int menor = 0;

    inicpila(&pila);

    ///Cargamos los elementos de la primera pila
    cargarPila(&pila);

    ///Pausa y limpiado de pantalla
    system("pause");
    system("cls || clear");

    ///Muestro pila
    printf("--PILA--\n");
    mostrar(&pila);

    menor = menorPila(&pila);

    printf("El menor elemento de la pila es: %d\n\n", menor);

    printf("\n--PILA FINAL SIN EL MENOR--\n");
    mostrar(&pila);

    return 0;
}

int menorPila(Pila *pila)
{
    Pila pilaMenor, aux;
    int flagEncontrado = 0,
        valor          = 0;

    ///Inicializamos todas las pilas
    inicpila(&pilaMenor);
    inicpila(&aux);

    while (!pilavacia(pila))
    {
        valor = desapilar(pila);
        if (!flagEncontrado || valor < tope(&pilaMenor))
        {
            if (flagEncontrado)
            {
                apilar(&aux, desapilar(&pilaMenor));
            }
            apilar(&pilaMenor, valor);
            flagEncontrado = 1; //Flag que se encontro un nuevo valor menor.
        }
        else
        {
            apilar(&aux, valor);
        }
    }

    ///Volvemos a dejar la pila con todos sus valores menos el menor encontrado
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    ///Asigno el menor valor de la pila que va a quedar en el tope a valor.
    valor = desapilar(&pilaMenor);

    return valor;
}
