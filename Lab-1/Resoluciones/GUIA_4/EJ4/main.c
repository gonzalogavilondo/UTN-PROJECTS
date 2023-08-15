#include "declaraciones.h"
#include "pila.h"
#include "operaciones.h"

/**
    4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
    cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
**/

void CopiarVectorEnPila(int *, int, Pila *);
int main()
{
    int *vec = NULL;
    int cntElementos = 0;

    Pila pila;

    /// Inicializamos las pilas.
    inicpila(&pila);

    ///Primero se reserva memoria para un vector de longitud maxima, luego se va reallocando la memoria con lo usado.
    vec = ReservarMemoria(MAXDIM);

    ///Cargamos el vector y recuperamos la cantidad de elementos
    cntElementos = CargarVector(vec);

    ///Realizamos la copia de los elementos del vector a la pila
    CopiarVectorEnPila(vec, cntElementos, &pila);

    ///Mostramos la pila y el vector final
    printf("--VECTOR--\n\n");
    MostrarVector(vec, cntElementos);

    printf("--PILA--\n");
    mostrar(&pila);

    ///Liberamos memoria:
    free(vec);

    return 0;
}

void CopiarVectorEnPila(int *vec, int validos, Pila *pila)
{
    for(int i = 0; i < validos; i++)
    {
        apilar(pila, vec[i]);
    }
}
