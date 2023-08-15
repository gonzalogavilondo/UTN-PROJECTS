#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    9. Verificar si una pila DADA es capicúa.
**/

int compararPilas(Pila *, Pila *);
int longitudPila(Pila *);

int main()
{
    Pila dada,
         aux;

    int cntElementos = 0,
        flagCapicua  = 0,
        contador     = 0,
        dato         = 0;

    ///Inicializamos las pilas
    inicpila(&dada);
    inicpila(&aux);

    ///Cargamos la pila
    printf("--PILA--\n");
    cargarPila(&dada);

    ///Hacemos una pausa y limpiamos pantalla
    system("pause");
    system("cls || clear");

    ///Mostramos las pilas con sus cantidades de elementos
    mostrar(&dada);

    cntElementos = longitudPila(&dada);

    while(!pilavacia(&dada) && contador < cntElementos/2)
    {
        apilar(&aux, desapilar(&dada));
        contador++;
    }

    if(!(cntElementos % 2 == 0))
    {
        dato = desapilar(&dada); ///Guardo el dato del medio de la pila que no me interesa para no perderlo
    }

    flagCapicua = compararPilas(&dada, &aux);

    if(flagCapicua == 1)
    {
        printf("La pila es CAPICUA.\n");
    }
    else
    {
        printf("La pila no es CAPICUA.\n");
    }
    printf("El valor del dato eliminado (solo en pila impar) es: %d", dato);

    return 0;
}

int longitudPila(Pila *pila)
{
    Pila aux;
    inicpila(&aux);

    int cnt = 0;
    while(!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));
        cnt++;
    }

    ///Volvemos a poner la pila original como estaba
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return cnt;
}

int compararPilas(Pila *pilaA, Pila *pilaB)
{
    Pila auxA,
         auxB;

    int flag = 0;

    ///Inicializamos las pilas
    inicpila(&auxA);
    inicpila(&auxB);

    while(!pilavacia(pilaA) && !pilavacia(pilaB) && (tope(pilaA) == tope(pilaB)))
    {
        apilar(&auxA, desapilar(pilaA));
        apilar(&auxB, desapilar(pilaB));
    }

    if(pilavacia(pilaA) && pilavacia(pilaB))
    {
        flag = 1; ///LAS PILAS SON IGUALES
    }
    else
    {
        flag = 0; ///LAS PILAS SON DISTINTAS
    }

    return flag;
}

