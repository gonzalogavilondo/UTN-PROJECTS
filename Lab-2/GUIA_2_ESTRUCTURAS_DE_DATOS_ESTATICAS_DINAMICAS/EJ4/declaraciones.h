#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include "pila.h"

int menorPila(Pila *);
void pasarPila(Pila *, Pila *);
void ordenamientoPorSeleccion(Pila *, Pila *);
void insertarEnOrden(Pila *, int);
int sumarElementosPila(Pila *);
int promedioElementosPila(Pila *);
int pilaAdecimal(Pila *);
void insertarPilaEnOrden(Pila *, Pila *);

#endif // DECLARACIONES_H_INCLUDED
