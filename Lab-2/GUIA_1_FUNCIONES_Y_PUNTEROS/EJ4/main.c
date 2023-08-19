#include "declaraciones.h"
#include "algoritmos.h"
#include "funciones_aritmeticas.h"

int main()
{
    int *vec = NULL;
    int cntElementos = 0,
        max          = 0;

    ///Reservo memoria primero para un vector de dimension maxima
    vec = ReservarMemoria(MAXDIM);

    ///Cargo el vector de manera dinamica y devuelvo la cantidad de elementos
    cntElementos = CargarVector(vec);

    ///Mostramos el vector
    MostrarVector(vec, cntElementos);

    ///Busco la posicion del maximo elemento del vector
    max = PosicionMayorElemento(vec, cntElementos);

    printf("El valor maximo del vector es: %d, que se encuentra en la posicion: %d\n", vec[max], max+1);

    ///Liberamos memoria:
    free(vec);

    return 0;
}
