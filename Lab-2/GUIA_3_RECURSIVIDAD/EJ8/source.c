#include "header.h"

int buscar_menor_elemento_file(FILE *archivo, int menor_actual)
{
    int numero;

    ///Intentamos leer un numero del archivo
    if(fscanf(archivo, "%d", &numero) == EOF)
    {
        ///Fin del archivo, devolvemos el menor actual
        return menor_actual;
    }

    ///Si el numero leido es menor que el menor actual, actualizamos el valor
    if(numero < menor_actual)
    {
        menor_actual = numero;
    }

    ///Llamada recursiva para seguir buscando
    return buscar_menor_elemento_file(archivo, menor_actual);
}

void apertura_archivo(FILE **archivo)
{
    *archivo = fopen("numeros.txt", "r");
    if(*archivo == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(0);//Codigo de error
    }
}
