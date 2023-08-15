#include "declaraciones.h"
#include "operaciones.h"

int main()
{
    char *vec = NULL;
    char letra = 'd';
    int cntElementos = 0;

    ///Primero se reserva memoria para un vector de longitud maxima, luego se va reallocando la memoria con lo usado.
    vec = ReservarMemoriaString(MAXDIM);

    ///Cargamos el vector y recuperamos la cantidad de elementos
    cntElementos = CargarVectorString(vec);

    ///Mostramos el vector final
    printf("\t-VECTOR-\n\n");
    MostrarVectorString(vec, cntElementos);

    ///Buscamos la letra en el vector
    if(EstaEnVector(letra, vec, cntElementos))
    {
        printf("%c se encuentra en el vector.\n", letra);
    }
    else
    {
        printf("%c NO se encuentra en el vector.\n", letra);
    }

    ///Liberamos memoria:
    free(vec);


    return 0;
}
