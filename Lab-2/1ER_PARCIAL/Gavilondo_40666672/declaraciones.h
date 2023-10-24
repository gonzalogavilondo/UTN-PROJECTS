#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jugador
{
    int dni;
    char nombre_apellido[30];int
    edad;
    char equipo[30];
} jugador;

typedef struct nodoJugador
{
    jugador UnJugador;
    struct nodoJugador * sig;
} nodoJugador;

typedef struct nodoJugadorD
{
    jugador UnJugador;
    struct nodoJugadorD *siguiente;
    struct nodoJugadorD *anterior;
} nodoJugadorD;

typedef struct fila
{
    nodoJugadorD * pri;
    nodoJugadorD * ult;
}fila;

nodoJugador* inicLista();
nodoJugador* crearNodoJugador(jugador);
nodoJugador* agregarNodoJugador(nodoJugador *, jugador);
nodoJugador* buscaUltimoLista(nodoJugador *);
nodoJugador* armaListaJugadores(const char *);
void mostrarUnNodo(nodoJugador *);
void muestraLista (nodoJugador *);
nodoJugador* armaJugadoresSeleccionados(nodoJugador *);
jugador* restoEquipos(nodoJugador *, int );
int contarNoSeleccionados(nodoJugador*);
void lista2array(nodoJugador *lista, jugador *registro);
void muestraRestoEquipos(jugador *arregloResto, int cntRegistros);
void imprimirFila(fila);
void inicializarFila(fila*);
fila armaSeleccion(nodoJugador*);
void buscarJugador(fila*, int);
void poneFila(fila* f, nodoJugador* jug);
int vaciaFila(fila* f);
nodoJugadorD* crearNodoD(nodoJugador*);


#endif // DECLARACIONES_H_INCLUDED
