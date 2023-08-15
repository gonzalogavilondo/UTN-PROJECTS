#include "funciones_aritmeticas.h"

/**
    SumaContenido
    Parametros: Vector y cantidad de elementos validos
    Suma el contenido del vector y devuelve el total de la suma.
**/
int SumaContenidoVector(int *vector, int validos)
{
    int res = 0;
    for(int i = 0; i < validos; i++)
    {
        res += vector[i];
    }
    return res;
}

/**
    PromedioVector
    Parametros

**/
float PromedioVector(int *vector, int validos)
{
    int   sumaElementos = 0;
    float promedio      = 0.0;

    for(int i = 0; i < validos; i++)
    {
        sumaElementos += vector[i];
    }
    promedio = (float)sumaElementos / validos;

    return promedio;
}
