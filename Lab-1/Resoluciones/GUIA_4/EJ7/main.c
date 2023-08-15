#include "declaraciones.h"
#include "operaciones.h"

int main()
{
    char vector[] = {'a', 'c', 'd', 'f', 'h'};
    int size = sizeof(vector)/sizeof(vector[0]); // obtener el tamaño del vector
    char c = 'b'; //El elemento a insertar

    ///Mostramos el vector
    printf("\t-VECTOR-\n\n");
    MostrarVectorString(vector, size);

    ///Inserto un valor y actualizo el size del vector
    size = InsertarOrdenadoString(vector, size, c);

    ///Mostramos el vector final
    printf("\t-VECTOR FINAL-\n\n");
    MostrarVectorString(vector, size);

    return 0;
}
