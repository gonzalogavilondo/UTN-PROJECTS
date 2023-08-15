#include "declaraciones.h"

int main()
{
    int *vec = NULL;
    int cntElementos = 0;

    ///Reservo memoria primero para un vector de dimension maxima
    vec = ReservarMemoria(MAXDIM);
    ///Cargo el vector de manera dinamica y devuelvo la cantidad de elementos
    cntElementos = CargarVector(vec);
    printf("\t-ORDENAMIENTO DEL VECTOR-\n");
    OrdenarPorSeleccion(vec, cntElementos);
    printf("\n\nFORMA ASCENDENTE\n\n");
    MostrarVector(vec, cntElementos);
    printf("\n\nFORMA DESCENDENTE\n\n");
    MostrarDescendente(vec, cntElementos);

    ///Liberamos memoria:
    free(vec);

    return 0;
}
