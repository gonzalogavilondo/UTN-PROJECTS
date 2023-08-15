#include "declaraciones.h"

int main()
{
    int *vec = NULL;
    int cntElementos = 0;

    ///Primero se reserva memoria para un vector de longitud maxima, luego se va reallocando la memoria con lo usado.
    vec = ReservarMemoria(MAXDIM);

    ///Cargamos el vector y recuperamos la cantidad de elementos
    cntElementos = CargarVector(vec);

    ///Mostramos el vector final
    printf("\t-VECTOR FINAL-\n\n");
    MostrarVector(vec, cntElementos);

    ///Liberamos memoria:
    free(vec);

    return 0;
}
