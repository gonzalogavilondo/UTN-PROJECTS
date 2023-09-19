#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "declaraciones.h"
#include "persona.h"


typedef struct nodo
{
    int dato;
    struct nodo* siguiente;
}nodo;

typedef struct nodoSt
{
    persona dato;
    struct nodoSt * siguiente;
} nodoSt;

/**
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS
**/
nodo *inicLista();
nodo *crearNodo(int);
nodo *agregarAlInicio(nodo*, nodo*);
nodo *buscaUltimoLista(nodo *);
nodo *agregarAlFinal(nodo*, nodo*);
nodo *agregarOrdenado(nodo*, nodo*);
nodo *borrarNodo(int, nodo*);
int borrarNodosRepetidos(int, nodo **);
nodo *borrarPrimerNodo(nodo *);
nodo *borrarUltimoNodo(nodo *);
nodo *buscarNodo(int dato, nodo *);
nodo *borrarLista(nodo *lista);
nodo *intercalarListas(nodo *, nodo*, nodo*);
nodo *listaRandomOrdenado(nodo *, int);
nodo *listaRandom50(nodo *, int);
nodo *invertirLista(nodo *);
void mostrarListaEnteros(nodo*);
int lista2array(nodo *, int **);
int recorrerLista(nodo *, int **);


/**
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS CON ARCHIVOS
**/

///ENTEROS: ARCHIVOS BINARIOS
void generaArchivoBin_int(char archivo[]);
void muestraArchivoBin_int(char archivo[]);
nodo *archivoBin2lista_int(nodo*, char archivo[]);
nodo *archivoBin2listaOrdenado_int(nodo*, char archivo[]);
void lista2archivoBin_int(nodo*, char archivo[]);

///ENTEROS: ARCHIVOS DE TEXTO
void generaArchivoTxt_int(char archivo[]);
void lista2archivoTxt_int(nodo*, char archivo[]);
nodo* archivoTxt2lista_int(nodo*, char archivo[]);


/*********************************************************************************************************************/


/**
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS CON ESTRUCTURAS
**/
nodoSt *inicListaSt();
nodoSt *crearNodoSt(persona);
nodoSt *agregarAlInicioSt(nodoSt*, nodoSt*);
nodoSt *buscaUltimoListaSt(nodoSt *);
nodoSt *agregarAlFinalSt(nodoSt*, nodoSt*);
nodoSt *agregarOrdenadoSt(nodoSt *, nodoSt *);
nodoSt *agregarOrdenadoEdadSt(nodoSt *, nodoSt *);
nodoSt *borrarNodoSt(nodoSt *, char nombre[20]);
nodoSt *borrarPrimerNodoSt(nodoSt *);
nodoSt *borrarUltimoNodoSt(nodoSt *);
nodoSt *buscarNodoSt(nodoSt *, char nombre[20]);
nodoSt *borrarListaSt(nodoSt *);
void borrarListaRecurSt(nodoSt*);
nodoSt *intercalarListasSt(nodoSt *, nodoSt*, nodoSt*);
nodoSt *crearListaOrdenadaSt(nodoSt *);
nodoSt *invertirListaSt(nodoSt *);
void mostrarUnNodoSt(nodoSt *);
void mostrarListaStruct(nodoSt *);
void recorrerYmostrarRecursivaSt(nodoSt *);
int sumarEdadesLista(nodoSt *);

/**
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS CON ARCHIVOS CON ESTRUCTURAS
**/

///ARCHIVOS BINARIOS
void generaArchivoBin_struct(const char *);
nodoSt* archivoBin2lista_struct(nodoSt *, const char *);
void lista2archivoBin_struct(nodoSt *, const char *);

///ARCHIVOS DE TEXTO
void generaArchivoTxt_struct(const char *);
void lista2archivoTxt_struct(nodoSt *, const char *);
nodoSt* archivoTxt2lista_struct(nodoSt *, const char *);




#endif // LISTAS_H_INCLUDED
