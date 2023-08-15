#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "listas.h"
#include "persona.h"
#include "filas.h"

void inicFila(Fila* fila) {
    fila->cabecera = inicLista();
    fila->cola = inicLista();
}

void agregar(Fila* fila, stPersona dato) {
    nodo2* nuevo = crearNodo2(dato);

    if(fila->cabecera==NULL) {
        fila->cabecera=nuevo;
        fila->cola=nuevo;
    }
    else {
        fila->cabecera=agregarAlFinal2(fila->cabecera, nuevo);
        fila->cola = nuevo;
    }
}

nodo2* crearNodo2(stPersona dato) {
    nodo2* aux = (nodo2*) malloc(sizeof(nodo2));
    aux->dato = dato;
    aux->anterior = NULL;
    aux->siguiente = NULL;
    return aux;
}

nodo2* inicLista2(){
    return NULL;
}

nodo2* agregarAlFinal2(nodo2* lista, nodo2* nuevo) {
    if(!lista) {
        lista = nuevo;
    }
    else {
        nodo2* ultimo = buscarUltimo2(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    return lista;
}

nodo2* buscarUltimo2(nodo2* lista){
    nodo2* seg = lista;
    while(seg->siguiente){
        seg = seg->siguiente;
    }

    return seg;
}

void muestraFila(Fila* fila){
    muestraLista2(fila->cabecera);
}

void muestraLista2(nodo2* lista){
    nodo2* seg = lista;
    while(seg){  /// while(lista!=NULL)
        muestraNodo2(seg);
        seg = seg->siguiente;
    }
}

void muestraNodo2(nodo2* lista){
    muestraUnaPersona(lista->dato);
}
