#include "listas.h"

int main()
{

    /**
    char archivoEnteros[] = "enteros.dat";
    char archivoEnterosResult[] = "enterosR.dat";

    ///Genero un archivo de enteros aleatorios
    generaArchivoBin_int(archivoEnteros);

    ///Declaro la lista
    nodo *lista;
    nodo *lista2;

    ///Inicializo la lista en NULL
    lista = inicLista();
    lista2 = inicLista();

    ///Guardo lo de la lista en un archivo
    lista = archivoBin2lista_int(lista, archivoEnteros);
    mostrarListaEnteros(lista);

    ///Lo pongo en un archivo binario
    lista2archivoBin_int(lista, archivoEnterosResult);

    ///Levanto lo escrito por lista en lista2
    lista2 = archivoBin2lista_int(lista2, archivoEnterosResult);
    mostrarListaEnteros(lista2);
    **/

    char archivoEnteros[] = "enteros.txt";
    char archivoEnterosResult[] = "enterosR.txt";

    ///Genero un archivo de enteros aleatorios
    generaArchivoTxt_int(archivoEnteros);

    ///Declaro la lista
    nodo *lista;
    nodo *lista2;

    ///Inicializo la lista en NULL
    lista = inicLista();
    lista2 = inicLista();

    ///Guardo lo de la lista en un archivo
    lista = archivoTxt2lista_int(lista, archivoEnteros);
    mostrarListaEnteros(lista);

    ///Lo pongo en un archivo binario
    lista2archivoTxt_int(lista, archivoEnterosResult);

    ///Levanto lo escrito por lista en lista2
    lista2 = archivoTxt2lista_int(lista2, archivoEnterosResult);
    mostrarListaEnteros(lista2);

    ///Libero memoria de lista
    free(lista);
    free(lista2);


    return 0;
}
