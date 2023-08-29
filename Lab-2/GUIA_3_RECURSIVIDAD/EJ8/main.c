#include "header.h"

/**
    Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)
**/
void apertura_archivo(FILE **);
int buscar_menor_elemento(FILE *, int);

int main()
{
    FILE *archivo;
    int menor = INT_MAX, ///Inicializamos con un valor maximo
    resultado = 0;

    ///Abre el archivo para lectura
    apertura_archivo(&archivo);

    ///Llamamos al procesamiento principal
    resultado = buscar_menor_elemento_file(archivo, menor);

    ///Cierro el archivo
    fclose(archivo);

    printf("El menor elemento del archivo es: %d\n", resultado);

    return 0;
}
