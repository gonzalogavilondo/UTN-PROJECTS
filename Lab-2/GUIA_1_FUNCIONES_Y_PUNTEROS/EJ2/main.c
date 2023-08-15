#include "declaraciones.h"

/**
     Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma:
    a. Hacer una función para la carga del arreglo.
    b. Hacer una función para invertir el arreglo.
    c. Hacer una función para mostrar el contenido del arreglo.
    d. Hacer la función main con el menú correspondiente.

**/

int main()
{
    char *vectorString          = NULL,
         *vectorStringInvertido = NULL;
    int  cntElementos  = 0;

    ///Reservo memoria para un string de dimension MAXDIM
    vectorString = ReservarMemoriaString(MAXDIM);

    ///a. Hacer una función para la carga del arreglo.
    ///(Realloca la memoria con la cantidad utilizada y devuelve la cantidad de caracteres validos)
    cntElementos = CargarVectorString(vectorString);

    ///b.Hacer una función para invertir el arreglo.
    vectorStringInvertido = InvertirVectorString(vectorString, cntElementos);

    ///Muestro el resultado por pantalla de ambos vectores (original e invertido)
    printf("VECTOR ORIGINAL\n");
    MostrarVectorString(vectorString, cntElementos);
    printf("VECTOR INVERTIDO\n");
    MostrarVectorString(vectorStringInvertido, cntElementos);


    return 0;
}
