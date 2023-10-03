#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "declaraciones.h"
///Nodo doblemente enlazado

typedef struct NodoPedido NodoPedido; // Declaración adelantada para que la estructura nodoD pueda referenciarla.

typedef struct nodoD
{
    NodoPedido* pedido;
    struct nodoD* ant;
    struct nodoD* sig;
} nodoD;


///Estructura de la fila/cola
typedef struct Fila
{
    nodoD *pri;
    nodoD *ult;
} Fila;

nodoD* crearNodo(NodoPedido*);
void inicFila(Fila *);
NodoPedido* frenteFila(Fila*);
void poneFila(Fila*, NodoPedido*);
NodoPedido* sacaFila(Fila*);
int vaciaFila(Fila*);
void mostrarFila(Fila*);
nodoD *buscarNodo (Fila*, int);
void eliminarNodoIntermedio(Fila *, nodoD *);
Fila armaFilaPedidos(NodoPedido* listaPedidos);


#endif // FILA_H_INCLUDED
