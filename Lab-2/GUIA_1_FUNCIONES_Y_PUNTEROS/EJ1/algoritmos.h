#ifndef ALGORITMOS_H_INCLUDED
#define ALGORITMOS_H_INCLUDED

#include "declaraciones.h"

///ALGORITMOS ENTEROS
int PosicionMenorElemento(int *, int);
int PosicionMayorElemento(int *, int);
int PosicionMenorDesdePosicionInicial(int *, int, int);
int PosicionMayorDesdePosicionInicial(int *, int, int);
void OrdenarPorSeleccion(int *, int);
void IntercambiarValores(int *, int *);
void OrdenarPorInsercion(int *, int);
int InsertarOrdenado(int *, int, int);

///ALGORITMOS CARACTERES
int EstaEnVector(char, char *, int );
int InsertarOrdenadoString(char *, int, char);


#endif // ALGORITMOS_H_INCLUDED
