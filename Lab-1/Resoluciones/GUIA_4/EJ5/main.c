#include "declaraciones.h"
#include "operaciones.h"

int main()
{
    float *vec = NULL;
    float resultado = 0.0;
    int cntElementos = 0;

    ///Primero se reserva memoria para un vector de longitud maxima, luego se va reallocando la memoria con lo usado.
    vec = ReservarMemoriaReales(MAXDIM);

    ///Cargamos el vector y recuperamos la cantidad de elementos
    cntElementos = CargarVectorReales(vec);

    ///Realizamos la suma de sus elementos
    resultado = sumarElementosVectorReales(vec, cntElementos);

    ///Mostramos el vector final
    printf("\t-VECTOR FINAL-\n\n");
    MostrarVectorReales(vec, cntElementos);
    printf("\nLa suma de sus elementos es: %.2f\n", resultado);

    ///Liberamos memoria:
    free(vec);

    return 0;
}
