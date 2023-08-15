#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include "pila.h"

void cargarPila(Pila *);
int menorPila(Pila *);
void pasarPila(Pila *, Pila *);
void ordenamientoPorSeleccion(Pila *, Pila *);
void insertarEnOrden(Pila *, int);
int longitudPila(Pila *);
int sumarElementosPila(Pila *);
float promedioElementosPila(Pila *);
float calcularPromedioPila(int, int);

#endif // DECLARACIONES_H_INCLUDED
