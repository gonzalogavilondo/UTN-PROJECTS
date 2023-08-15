#include "operaciones.h"

/**
    sumarElementosVector
    Parametros: vector y su cantidad de elementos
    Suma los elementos de un vector de flotantes y lo devuelve como int.

**/
int sumarElementosVector(int *vector, int validos)
{
    int resultado = 0;
    for (int i = 0; i < validos ; i++)
    {
        resultado += vector[i];
    }

    return resultado;
}
