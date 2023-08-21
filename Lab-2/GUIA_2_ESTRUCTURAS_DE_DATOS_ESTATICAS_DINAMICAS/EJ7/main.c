#include "declaraciones.h"
#include "algoritmos.h"
#include "funciones_aritmeticas.h"

/**
    Función eliminar un elemento de un arreglo. (ver por desplazamiento si es ordenado)
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
    OrdenarPorInsercion(vec, cntElementos);

    ///Mostramos el vector ordenado
    printf("\n--VECTOR ORDENADO--\n\n");
    MostrarVector(vec, cntElementos);

    ///Eliminar un valor
    printf("Ingrese el valor a eliminar: ");
    scanf("%d", &valor);

    EliminarElemento(vec, cntElementos, valor);

    printf("\n--VECTOR FINAL--\n\n");
    MostrarVector(vec, cntElementos-1);

    ///Liberamos memoria:
    free(vec);

    return 0;
}
