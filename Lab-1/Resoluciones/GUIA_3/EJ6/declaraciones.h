#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include "pila.h"

int menorPila(Pila *);
void pasarPila(Pila *, Pila *);
void ordenamientoPorSeleccion(Pila *, Pila *);
void insertarEnOrden(Pila *, int);

#endif // DECLARACIONES_H_INCLUDED
