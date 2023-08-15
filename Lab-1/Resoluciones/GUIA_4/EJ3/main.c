#include "declaraciones.h"
#include "operaciones.h"

int main()
{
    int *vec = NULL;
    int resultado = 0;
    int cntElementos = 0;

    ///Primero se reserva memoria para un vector de longitud maxima, luego se va reallocando la memoria con lo usado.
    vec = ReservarMemoria(MAXDIM);

    ///Cargamos el vector y recuperamos la cantidad de elementos
    cntElementos = CargarVector(vec);

    ///Realizamos la suma de sus elementos
    resultado = sumarElementosVector(vec, cntElementos);

    ///Mostramos el vector final
    printf("\t-VECTOR FINAL-\n\n");
    MostrarVector(vec, cntElementos);
    printf("\nLa suma de sus elementos es: %d\n", resultado);

    ///Liberamos memoria:
    free(vec);

    return 0;
}
