#include "declaraciones.h"
#include "algoritmos.h"
#include "funciones_aritmeticas.h"

/**
    Algoritmo de ordenamiento por inserción.
**/

int main()
{
    int *vec = NULL;
    int cntElementos = 0;

    ///Reservo memoria primero para un vector de dimension maxima
    vec = ReservarMemoria(MAXDIM);

    ///Cargo el vector de manera dinamica y devuelvo la cantidad de elementos
    cntElementos = CargarVector(vec);

    ///Mostramos el vector original
    printf("\n--VECTOR ORIGINAL--\n\n");
    MostrarVector(vec, cntElementos);

    ///Ordenamos el vector
    OrdenarPorInsercion(vec, cntElementos);

    ///Mostramos el vector ordenado
    printf("\n--VECTOR ORDENADO--\n\n");
    MostrarVector(vec, cntElementos);

    ///Liberamos memoria:
    free(vec);

    return 0;
}
