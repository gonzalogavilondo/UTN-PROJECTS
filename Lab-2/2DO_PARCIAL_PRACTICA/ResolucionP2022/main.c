#include "declaraciones.h"

int main()
{
    int validos = 0;
    celda arreglo[MAXDIM];
    nodoArbol *arbol = NULL;

    ///Ejercicio 1
    validos = archivo2ADA(arreglo, MAXDIM);

    ///Ejercicio 2
    mostrarADA(arreglo, validos);

    ///Ejercicio 3
    arbol = buscarVendedorArreglo(arreglo, validos, 10030956);

    printf("\n\n\t--EMPLEADO BUSCADO-- \n");
    mostrarVendedor(arbol->dato);

    ///Ejercicio 4


    return 0;
}
