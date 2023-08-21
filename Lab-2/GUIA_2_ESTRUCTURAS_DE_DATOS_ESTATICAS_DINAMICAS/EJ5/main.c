#include "declaraciones.h"
#include "algoritmos.h"
#include "funciones_aritmeticas.h"

/**
    Función insertar orden en un arreglo.
**/
int main()
{
    int *vec = NULL;
    int cntElementos = 0,
        valor        = 0;

    ///Reservo memoria primero para un vector de dimension maxima
    vec = ReservarMemoria(MAXDIM);

    ///Cargo el vector de manera dinamica y devuelvo la cantidad de elementos
    cntElementos = CargarVector(vec);

    ///Mostramos el vector original
    printf("\n--VECTOR ORIGINAL--\n\n");
    MostrarVector(vec, cntElementos);

    ///Ordenamos el vector
    OrdenarPorSeleccion(vec, cntElementos);

    ///Mostramos el vector ordenado
    printf("\n--VECTOR ORDENADO--\n\n");
    MostrarVector(vec, cntElementos);

    ///Cargamos un valor
    printf("Insertar un valor al vector: ");
    scanf("%d", &valor);
    cntElementos = InsertarOrdenado(vec, cntElementos, valor); //Actualizo el valor de cntElementos

    ///Mostramos el vector original
    printf("\n--VECTOR DESPUES DE INSERTAR EL %d--\n\n", valor);
    MostrarVector(vec, cntElementos);

    ///Liberamos memoria:
    free(vec);

    return 0;
}
