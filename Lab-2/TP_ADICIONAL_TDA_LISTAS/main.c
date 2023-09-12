#include "declaraciones.h"
#include "listas.h"

int main()
{
/**
    EJ 1 AL 3
**/
//    int *vec    = NULL,
//        *vecBin = NULL,
//        *vecTxt = NULL;
//
//    int cntElementos = 0,
//        sizeBin      = 0,
//        sizeTxt      = 0;
//
//    nodo *lista;
//
//    lista = inicLista();
//
//    lista = agregarOrdenado(crearNodo(5), lista);
//    lista = agregarOrdenado(crearNodo(2), lista);
//    lista = agregarOrdenado(crearNodo(3), lista);
//    lista = agregarOrdenado(crearNodo(6), lista);
//    lista = agregarOrdenado(crearNodo(5), lista);
//
//    ///Elimino los nodos y devuelvo cuantos nodos borre
//
//
//    ///Reservo memoria primero para un vector de dimension maxima
//    vec = ReservarMemoria(MAXDIM);
//
//    ///Cargo el vector de manera dinamica y devuelvo la cantidad de elementos
//    cntElementos = CargarVector(vec);
//    printf("\nVECTOR ORIGINAL\n\n");
//    MostrarVector(vec, cntElementos);
//
//    ///Guardo el vector en un archivo binario y txt
//    Vector2ArchivoBin(vec, cntElementos, "vector.dat");
//    Vector2ArchivoTxt(vec, cntElementos, "vector.txt");
//
//    ///Levanto el archivo binario al vector
//    sizeBin = ArchivoBin2Vector(&vecBin, "vector.dat");
//    sizeTxt = ArchivoTxt2Vector(&vecTxt, "vector.txt");
//
//    ///Mostramos los vectores
//    printf("\nVECTOR BIN\n\n");
//    MostrarVector(vecBin, sizeBin);
//
//    printf("\nVECTOR TXT\n\n");
//    MostrarVector(vecTxt, sizeTxt);
//
//    ///Liberamos memoria:
//    free(vec);
//    free(vecBin);
//    free(vecTxt);

/**
    EJ 4
**/
    int cntNodosBorrados;
    nodo *lista;
    int numAborrar;

    lista = inicLista();

    lista = agregarOrdenado(crearNodo(5), lista);
    lista = agregarOrdenado(crearNodo(2), lista);
    lista = agregarOrdenado(crearNodo(3), lista);
    lista = agregarOrdenado(crearNodo(6), lista);
    lista = agregarOrdenado(crearNodo(5), lista);
    lista = agregarAlInicio(crearNodo(1), lista);
    lista = agregarAlFinal(crearNodo(1), lista);

    ///Muestro la lista original
    mostrarListaEnteros(lista);

    ///Elijo el numero a borrar de la lista
    numAborrar = 1;

    ///Elimino los nodos y devuelvo cuantos nodos borre
    cntNodosBorrados = borrarNodosRepetidos(numAborrar, &lista);

    ///Muestro la lista final
    mostrarListaEnteros(lista);

    printf("La cantidad de %d borrados es: %d", numAborrar, cntNodosBorrados);


    return 0;
}
