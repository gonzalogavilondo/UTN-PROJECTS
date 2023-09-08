#include "listas.h"

int main()
{
    ///Genero un archivo de enteros aleatorios
    generaArchivoTxt_struct(ARCHIVO);

    ///Declaro la lista
    nodo *lista;
    nodo *lista2;

    ///Inicializo la lista en NULL
    lista = inicLista();
    lista2 = inicLista();

    ///Guardo lo del archivo en la lista
    lista = archivoTxt2lista_struct(lista, ARCHIVO);
    mostrarListaStruct(lista);

    ///guardo la lista en un txt
    lista2archivoTxt_struct(lista, ARCHIVO_R);

    ///Levanto lo escrito por lista en lista2
    lista2 = archivoTxt2lista_struct(lista2, ARCHIVO_R);
    mostrarListaStruct(lista2);

    ///Libero memoria de lista
    free(lista);
    free(lista2);


    return 0;
}
