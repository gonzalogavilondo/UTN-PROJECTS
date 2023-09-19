#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#define MAXDIM 25
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>


///FUNCIONES BASICAS DE VECTORES ENTEROS
int *ReservarMemoria(int);
void InicializarVector(int *, int);
void CompletarVector(int *, int);
int CargarVector(int *);
void MostrarDescendente(int *, int);
void MostrarVector(int *, int);
void Vector2ArchivoBin(int *, int , const char *);
int ArchivoBin2Vector(int **, const char *);
void Vector2ArchivoTxt(int *, int, const char *);
int ArchivoTxt2Vector(int **, const char *);
void AgregarAlFinalVec(int **, int, int);


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



#endif // DECLARACIONES_H_INCLUDED
