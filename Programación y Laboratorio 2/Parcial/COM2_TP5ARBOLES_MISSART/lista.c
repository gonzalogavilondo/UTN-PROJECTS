#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/***
* \brief Inicializa una lista.
*/
nodoLista* inicLista(){
    return NULL;
}

/***
* \brief Pasaje de datos desde un arbol hacia una lista simple.
* \param Recibe un arbol binario.
* \param Recibe una lista simple.
* \return Devuelve la lista simple.
*/
nodoLista* arbol2Lista(nodoArbol* arbol, nodoLista* lista){
    if(arbol){
        lista = arbol2Lista(arbol->izq, lista);
        lista = agregarAlFinal(lista, crearNodoLista(arbol->dato));
        lista = arbol2Lista(arbol->der, lista);
    }

    return lista;
}

/***
* \brief Crea un nodo para una lista simple.
* \param Recibe un dato tipo persona.
* \return Devuelve un nodo.
*/
nodoLista* crearNodoLista(persona dato) {
    nodoLista* nuevo = (nodoLista*) malloc(sizeof(nodoLista));

    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

/***
* \brief Agrega un nodo al final de una lista simple.
* \param Recibe una lista simple.
* \param Recibe el nodo a cargar en la lista.
* \return Devuelve la lista.
*/
nodoLista* agregarAlFinal(nodoLista* lista, nodoLista* nuevo){

    if(lista == NULL) {
        lista = nuevo;
    }
    else {
        nodoLista* ultimo = buscaUltimoLista(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

/***
* \param Busca el ultimo nodo dentro de una lista simple y lo retorna.
* \return Devuelve un nodo.
*/
nodoLista* buscaUltimoLista(nodoLista* lista){
    nodoLista* seg = lista;
    while(seg->siguiente){
        seg = seg->siguiente;
    }
    return seg;
}

/***
* \brief Muestra el contenido de un nodo.
* \param Recibe un nodo.
*/
void muestraNodo(nodoLista* nodo){
    printf("\nLegajo: %d", nodo->dato.legajo);
    printf("\nNombre: %s", nodo->dato.nombre);
    printf("\nEdad..: %d", nodo->dato.edad);
    printf("\n-------------------");
}

/***
* \brief Muestra el contenido de una lista.
* \param Recibe una lista.
*/
void muestraLista(nodoLista* lista){
    nodoLista* seg = lista;
    while(seg){
        muestraNodo(seg);
        seg = seg->siguiente;
    }
}
