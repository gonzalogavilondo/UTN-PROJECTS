#include "Fila.h"

void inicFila(Fila* f)
{
 (*f).pri = NULL;
 (*f).ult = NULL;
}


nodoD* crearNodo(Telemento dato)
{
    nodoD* nuevo = (nodoD*)malloc(sizeof(nodoD));
    nuevo->ant=NULL;
    nuevo->sig=NULL;
    nuevo->dato = dato;
    return nuevo;
}


void poneFila(Fila* f,Telemento dato)
{
   ///COMPLETAR
}


Telemento sacaFila(Fila* f)
{
   ///COMPLETAR

}


//retorna 1 si esta vacia, sino 0
int filaVacia(Fila f)
{
    return (f.pri==NULL);

}

