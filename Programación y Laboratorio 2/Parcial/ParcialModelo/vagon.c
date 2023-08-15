#include <stdio.h>
#include <stdlib.h>

#include "vagon.h"

nodoVagon* inicLista() {
    return NULL;
}

nodoVagon* crearNodo(float peso) {

    nodoVagon* nuevo = (nodoVagon*) malloc(sizeof(nodoVagon));
    nuevo->pesoIngresado = peso;
    nuevo->sig = NULL;

    return nuevo;
}

nodoVagon* agregarAlFinal(nodoVagon* lista, nodoVagon* nuevo){

    if(lista == NULL) {
        lista = nuevo;
    } else {
        nodoVagon* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }

    return lista;
}

nodoVagon* buscarUltimo(nodoVagon* lista){
    nodoVagon* seg = lista;
    while(seg->sig){
        seg = seg->sig;
    }

    return seg;
}
