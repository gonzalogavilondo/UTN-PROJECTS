#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "empleado.h"

typedef struct nodo{
    stEmpleado dato;
    struct nodo* siguiente;
}nodo;

nodo* crearNodo(stEmpleado empleado);
nodo * agregarAlPrincipio(nodo * lista, nodo* nuevo);
nodo* iniclista();
void mostrarLista(nodo* lista);
void lista2archivo(nodo * lista, char archivo[]);
nodo* archivo2lista(nodo * lista, char archivo[]);
void mostrarListaRecu(nodo* lista);



#endif // LISTA_H_INCLUDED
