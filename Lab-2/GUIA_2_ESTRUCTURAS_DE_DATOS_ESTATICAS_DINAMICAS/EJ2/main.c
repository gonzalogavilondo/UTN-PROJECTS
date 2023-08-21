#include "declaraciones.h"
#include "algoritmos.h"
#include "funciones_aritmeticas.h"

int main()
{
    int *vec = NULL;
    int cntElementos = 0;

    ///Reservo memoria primero para un vector de dimension maxima
    vec = ReservarMemoria(MAXDIM);

    ///Cargo el vector de manera dinamica y devuelvo la cantidad de elementos
    cntElementos = CargarVector(vec);
    printf("VECTOR ORIGINAL\n");
    MostrarVector(vec, cntElementos);

    ///Ordenamos el vector por seleccion
    OrdenarPorSeleccion(vec, cntElementos);

    ///Mostramos el vector ordenado
    printf("-VECTOR ORDENADO POR SELECCION-\n");
    MostrarVector(vec, cntElementos);

    ///Liberamos memoria:
    free(vec);

    return 0;
}
