#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "declaraciones.h"


typedef struct nodo
{
    int dato;
    struct nodo* siguiente;
}nodo;

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



#endif // LISTAS_H_INCLUDED
