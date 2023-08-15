#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "arbol.h"

typedef struct _nodoLista {
    persona dato;
    struct _nodoLista* siguiente;
} nodoLista;

nodoLista* inicLista();
nodoLista* arbol2Lista(nodoArbol* arbol, nodoLista* lista);
nodoLista* crearNodoLista(persona dato);
nodoLista* agregarAlFinal(nodoLista* lista, nodoLista* nuevo);
nodoLista* buscaUltimoLista(nodoLista* lista);
void muestraLista(nodoLista* lista);

#endif // LISTA_H_INCLUDED
