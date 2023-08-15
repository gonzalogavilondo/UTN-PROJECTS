#include "declaraciones.h"
#include "operaciones.h"

/**
    9. Realizar una función que determine si un arreglo es capicúa
**/
int main()
{
    int vector[] = {1, 2, 2, 1};
    //int vector[] = {1, 2, 3, 1};
    int size = sizeof(vector)/sizeof(vector[0]); // obtener el tamaño del vector

    ///Mostramos el vector
    printf("\t-VECTOR-\n\n");
    MostrarVector(vector, size);

    ///Comparar si es capicua o no
    if(EsCapicua(vector, size))
    {
        printf("\nEl vector es capicua.\n");
    }
    else
    {
        printf("\nEl vector no es capicua.\n");
    }

    return 0;
}
