#include "declaraciones.h"

/**
     Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma:
    a. Hacer una funci�n para la carga del arreglo.
    b. Hacer una funci�n para invertir el arreglo.
    c. Hacer una funci�n para mostrar el contenido del arreglo.
    d. Hacer la funci�n main con el men� correspondiente.

**/

int main()
{
    char *vectorString          = NULL,
         *vectorStringInvertido = NULL;
    int  cntElementos  = 0;

    ///Reservo memoria para un string de dimension MAXDIM
    vectorString = ReservarMemoriaString(MAXDIM);

    ///a. Hacer una funci�n para la carga del arreglo.
    ///(Realloca la memoria con la cantidad utilizada y devuelve la cantidad de caracteres validos)
    cntElementos = CargarVectorString(vectorString);

    ///b.Hacer una funci�n para invertir el arreglo.
    vectorStringInvertido = InvertirVectorString(vectorString, cntElementos);

    ///Muestro el resultado por pantalla de ambos vectores (original e invertido)
    printf("VECTOR ORIGINAL\n");
    MostrarVectorString(vectorString, cntElementos);
    printf("VECTOR INVERTIDO\n");
    MostrarVectorString(vectorStringInvertido, cntElementos);


    return 0;
}
