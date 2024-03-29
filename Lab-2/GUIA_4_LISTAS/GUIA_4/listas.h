#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define ESC 27


typedef struct nodo
{
    int dato;
    struct nodo* siguiente;
}nodo;

void mostrarMenu();
void generaArchivoEnteros(char archivo[]);
void guardaUnEntero(int, char archivo[]);
void muestraUnEntero(int);
void muestraArchivoEnteros(char archivo[]);
nodo *inicLista();
nodo *archivo2lista(nodo* lista, char archivo[]);
nodo *crearNodo(int);
nodo *buscaUltimoLista(nodo*);
nodo *agregarAlInicio(nodo*, nodo*);
nodo *agregarAlFinal(nodo*, nodo*);
nodo *agregarOrdenado(nodo*, nodo*);
void mostrarListaEnteros(nodo*);
nodo *archivo2ListaOrdenado(nodo*, char archivo[]);
nodo *borrarNodo(int, nodo*);
nodo *borrarPrimerNodo(nodo *);
nodo *borrarUltimoNodo(nodo *);
nodo *buscarNodo(int dato, nodo *);
nodo *borrarLista(nodo *lista);
nodo *intercalarListas(nodo *, nodo*, nodo*);
nodo *listaRandomOrdenado(nodo *, int);
nodo *invertirLista(nodo *);

#endif // LISTAS_H_INCLUDED
