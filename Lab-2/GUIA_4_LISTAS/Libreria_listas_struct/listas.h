#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#include "persona.h"


typedef struct nodo
{
    persona dato;
    struct nodo * siguiente;
} nodo;


/**
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS CON ESTRUCTURAS
**/
nodo *inicLista();
nodo *crearNodo(persona);
nodo *agregarAlInicio(nodo*, nodo*);
nodo *buscaUltimoLista(nodo *);
nodo *agregarAlFinal(nodo*, nodo*);
nodo *agregarOrdenado(nodo *, nodo *);
nodo *agregarOrdenadoEdad(nodo *, nodo *);
nodo *borrarNodo(nodo *, char nombre[20]);
nodo *borrarPrimerNodo(nodo *);
nodo *borrarUltimoNodo(nodo *);
nodo *buscarNodo(nodo *, char nombre[20]);
nodo *borrarLista(nodo *);
void borrarListaRecur(nodo*);
nodo *intercalarListas(nodo *, nodo*, nodo*);
nodo *crearListaOrdenada(nodo *);
nodo *invertirLista(nodo *);
void mostrarUnNodo(nodo *);
void mostrarListaStruct(nodo *);
void recorrerYmostrarRecursiva(nodo *);
int sumarEdadesLista(nodo *);

/**
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS CON ARCHIVOS CON ESTRUCTURAS
**/

///ARCHIVOS BINARIOS
void generaArchivoBin_struct(const char *);
nodo* archivoBin2lista_struct(nodo *, const char *);
void lista2archivoBin_struct(nodo *, const char *);

///ARCHIVOS DE TEXTO
void generaArchivoTxt_struct(const char *);
void lista2archivoTxt_struct(nodo *, const char *);
nodo* archivoTxt2lista_struct(nodo *, const char *);



#endif // LISTAS_H_INCLUDED
