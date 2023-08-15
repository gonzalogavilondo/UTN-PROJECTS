#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#define MAXDIM 25
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

///FUNCIONES BASICAS DE VECTORES ENTEROS
int *ReservarMemoria(int);
void CompletarVector(int *, int);
int CargarVector(int *);
void MostrarDescendente(int *, int);
void MostrarVector(int *, int);

///FUNCIONES BASICAS DE VECTORES REALES
float *ReservarMemoriaReales(int);
void CompletarVectorReales(float *, int);
int CargarVectorReales(float *);
void MostrarDescendenteReales(float *, int);
void MostrarVectorReales(float *, int);

///FUNCIONES BASICAS DE VECTORES CARACTERES
char *ReservarMemoriaString(int);
void CompletarVectorString(char *, int);
int CargarVectorString(char *);
void MostrarDescendenteString(char *, int);
void MostrarVectorString(char *, int);

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
char CaracterMaxString(char *, int);



#endif // DECLARACIONES_H_INCLUDED
