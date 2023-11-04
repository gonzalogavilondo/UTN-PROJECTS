#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registroArchivo.h"
#include "utilidades.h"

typedef struct stAnimal
{
    char nombreAnimal[30];
    int cantidad;
    int habitat;
// 1 - selva, 2- savana, 3-bosque, 4-mar
} stAnimal;

/// estructura de datos
typedef struct nodoArbol
{
   stAnimal dato;
   struct nodoArbol* izq;
   struct nodoArbol* der;
} nodoArbol;

/// funciones basicas
nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stAnimal dato);
nodoArbol* insertar (nodoArbol* arbol, nodoArbol* nuevo);
void inorder(nodoArbol* arbol);
void preorder(nodoArbol* arbol);
void postorder(nodoArbol* arbol);
void mostrarNodo(nodoArbol* arbol);
nodoArbol* buscar(nodoArbol* arbol, char animal[]);
void mostrarUnAnimal(stAnimal a);

/// funciones extras
int sumarCantAnimalesArbol(nodoArbol* arbol);
int sumarCantNodosArbol(nodoArbol* arbol);

#endif // ARBOL_H_INCLUDED
