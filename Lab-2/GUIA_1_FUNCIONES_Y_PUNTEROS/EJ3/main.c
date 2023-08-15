#include "algoritmos.h"
#include "funciones_aritmeticas.h"

/**
     Hacer una funci�n que reciba como par�metro un arreglo de n�meros enteros de un d�gito y retorne el valor
     decimal de dicho n�mero. Por ejemplo, un arreglo que tiene cargados los valores 3, 2, 8 y 9, la fn retorna
     el valor 3289.

**/

int main()
{
    int *vector = NULL;
    int  cntElementos  = 0,
         resultado     = 0;

    ///Reservo memoria para un string de dimension MAXDIM
    vector = ReservarMemoria(MAXDIM);

    ///Cargo el vector(Realloca la memoria con la cantidad utilizada y devuelve la cantidad de caracteres validos)
    cntElementos = CargarVector(vector);

    ///Hago la funcion requerida
    resultado = ArrayToInt(vector, cntElementos);

    ///Muestro los resultados
    MostrarVector(vector, cntElementos);
    printf("El valor del entero resulta: %d\n", resultado);

    return 0;
}
