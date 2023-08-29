#include "header.h"

/**
    Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva.
**/

int main()
{
    FILE *archivo;
    int menor = INT_MAX, ///Inicializamos con un valor maximo
    resultado = 0;

    ///Abre el archivo para lectura
    apertura_archivo(&archivo);

    ///Llamamos al procesamiento principal
    resultado = buscar_menor_elemento_file(archivo, menor);

    ///Me aseguro de estar parado en la primera posicion del archivo
    fseek(archivo, 0, SEEK_SET);

    ///Invertimos el archivo
    printf("Contenido del archivo en orden inverso.\n");
    mostrar_archivo_invertido(archivo);

    ///Cierro el archivo
    fclose(archivo);

    printf("\n\nEl menor elemento del archivo es: %d\n", resultado);

    return 0;
}
