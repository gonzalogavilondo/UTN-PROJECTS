#include "declaraciones.h"

int main()
{
    int cntVendedores = 0,
        cntVentas = 0,
        idSector = 0;

    float pVentas = 0.0;

    listaCeldas *lista = NULL; // Cambiando de arreglo a lista enlazada

    ///Ejercicio 1
    lista = archivo2LDA();

    ///Ejercicio 2
    mostrarLDA(lista);

    // Resto del código ...

    ///Ejercicio 3
    nodoArbol *arbol = buscarVendedorLista(lista, 10030956);
    puts("\n\n----------------------EJERCICIO 3---------------------------");
    if (arbol != NULL)
    {
        printf("\t--EMPLEADO BUSCADO-- \n");
        mostrarVendedor(arbol->dato);
    }
    else
    {
        printf("Empleado no encontrado.\n");
    }

    ///Ejercicio 4 (Cuantos vendedores de un sector, por ejemplo, 3, que superen las 2 ventas)
    cntVentas = 2;
    idSector = 3;
    cntVendedores = cantidadVendedoresSuperiores(lista, idSector, cntVentas);
    puts("\n\n----------------------EJERCICIO 4---------------------------");
    if (cntVendedores != -1)
    {
        printf("La cantidad de vendedores que superan las %d ventas en el sector %d son: %d\n", cntVentas, idSector, cntVendedores);
    }
    else
    {
        printf("Sector no encontrado.\n");
    }
    puts("\n\n------------------------------------------------------------\n");

    ///Ejercicio 5
    idSector = sectorMasVentas(lista);
    puts("\n\n----------------------EJERCICIO 5---------------------------");
    printf("El sector que mas ventas tuvo es el: %d\n", idSector);
    puts("\n\n------------------------------------------------------------\n");

    ///Ejercicio 6 (Se va a usar para probar el sector que tuvo más ventas)
    pVentas = porcentajeVentas(lista, idSector);
    puts("\n\n----------------------EJERCICIO 6---------------------------");
    if (pVentas != -1)
    {
        printf("El porcentaje de ventas del sector %d es: %.2f\n", idSector, pVentas);
    }
    else
    {
        printf("Sector no encontrado.\n");
    }
    puts("\n\n------------------------------------------------------------\n");

    // Liberar memoria utilizada por la lista antes de salir del programa
    liberarListaCeldas(lista);

    return 0;
}


