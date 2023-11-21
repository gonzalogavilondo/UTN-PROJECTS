#include "declaraciones.h"

int main()
{
    int cntVendedores = 0,
            cntVentas = 0,
             idSector = 0,
              validos = 0;

    float pVentas = 0.0;

    celda arreglo[MAXDIM];
    nodoArbol *arbol = NULL;

    ///Ejercicio 1
    validos = archivo2ADA(arreglo);

    ///Ejercicio 2
    mostrarADA(arreglo, validos);

    ///Ejercicio 3
    arbol = buscarVendedorArreglo(arreglo, validos, 10030956);
    puts("\n\n----------------------EJERCICIO 3---------------------------");
    printf("\t--EMPLEADO BUSCADO-- \n");
    mostrarVendedor(arbol->dato);

    ///Ejercicio 4 (Cuantos vendedores de un sector por ejemplo 3, que superen las 2 ventas)
    cntVentas = 2;
    idSector = 3;
    cntVendedores = cantidadVendedoresSuperiores(arreglo, validos, idSector, cntVentas);
    puts("\n\n----------------------EJERCICIO 4---------------------------");
    printf("La cantidad de vendedores que superan las %d ventas son: %d", cntVentas, cntVendedores);
    puts("\n\n------------------------------------------------------------\n");

    ///Ejercicio 5
    idSector = sectorMasVentas(arreglo, validos);
    puts("\n\n----------------------EJERCICIO 5---------------------------");
    printf("El sector que mas ventas tuvo es el: %d", idSector);
    puts("\n\n------------------------------------------------------------\n");

    ///Ejercicio 6 (Se va a usar para probar el sector que tuvo mas ventas)
    pVentas = porcentajeVentas(arreglo, validos, idSector);
    puts("\n\n----------------------EJERCICIO 6---------------------------");
    printf("El porcentaje de ventas del sector %d es: %.2f", idSector, pVentas);
    puts("\n\n------------------------------------------------------------\n");


    return 0;
}
