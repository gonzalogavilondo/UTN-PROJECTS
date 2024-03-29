#include "arbol.h"

nodoArbol* inicArbol() {
    return NULL
}


nodoArbol* crearNodoArbol(int dato) {
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));

    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

/**
* \brief Inserta un nuevo nodo en un arbol ya existente, de lo contrario crea un nuevo arbol.
* \param el arbol nodoArbol* puntero a arbol
* \param el nodo nuevo nodoArbol* nuevo
* \return el arbol
**/
nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo) {
    if(!arbol) {
        arbol = nuevo;
    } else {
        if(nuevo->dato > arbol->dato} {
            arbol->der = insertar(arbol->der, nuevo};
        }else {
            arbol->izq = insertar(arbol->izq, nuevo);
        }
        return arbol;
}

nodoArbol* insertarSinRepetidos(nodoArbol* arbol, nodoArbol* nuevo) {
    if(!arbol) {
        arbol = nuevo;
    } else {
        if(nuevo->dato > arbol->dato} {
            arbol->der = insertar(arbol->der, nuevo);
        }else if(nuevo->dato < arbol->dato){
            arbol->izq = insertar(arbol->izq, nuevo);
        }
        return arbol;
}

void mostrarNodoArbol(nodoArbol* nodo) {
    printf(" %d -", nodo->dato);
}
