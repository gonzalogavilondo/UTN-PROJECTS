#include "declaraciones.h"
#include "operaciones.h"

/**
    8.Realizar una función que obtenga el máximo carácter de un arreglo dado.
**/
int main()
{
    char vector[] = {'a', 'c', 'd', 'f', 'h'};
    int size = sizeof(vector)/sizeof(vector[0]); // obtener el tamaño del vector
    char max;

    ///Mostramos el vector
    printf("\t-VECTOR-\n\n");
    MostrarVectorString(vector, size);

    ///Buscar y devolver el maximo caracter de un arreglo
    max = CaracterMaxString(vector, size);

    printf("\nEl maximo caracter del vector es: %c\n", max);

    return 0;
}
