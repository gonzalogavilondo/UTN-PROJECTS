#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

///Nodo doblemente enlazado
typedef struct nodoD
{
    int dato;
    struct nodoD *ant;
    struct nodoD *sig;
} nodoD;


///Estructura de la fila/cola
typedef struct Fila
{
    nodoD *pri;
    nodoD *ult;
} Fila;

nodoD * crearNodo(int);
void inicFila(Fila *);
int frenteFila(Fila);
void poneFila(Fila *, int);
int sacaFila(Fila *);
int vaciaFila(Fila);
void mostrarFila(Fila);
nodoD * buscarNodo (Fila, int);
void eliminarNodoIntermedio(Fila *, nodoD *);


#endif // FILA_H_INCLUDED
