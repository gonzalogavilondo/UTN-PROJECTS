#ifndef CANCIONES_H_INCLUDED
#define CANCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "string.h"
#include "time.h"
#include "Usuarios.h"

#define arCanciones "Canciones.dat"



typedef struct{
    int idCancion;
    char titulo[40];
    char artista[40];
    int duracion;
    char album[40];
    int anio;
    char genero[20];
    char comentario[100];
    int eliminado;
}stCancion;

///====FUNCIONES CANCIONES====
void cargaArchiCanciones();
void guardarCancion(stCancion a);

int buscaUltimoIdCancion();

void mostrarCanciones();
void muestraUnaCancion(stCancion a);
void mostrarCancionesEliminada();
void muestraUnaCancionEliminada(stCancion a);

void elimininarCancion(char nombreCancion[]);
void recuperarCancion(char nombreCancion[]);
void ConsultaCancion(char titulo[]);
void ConsultaCancionxID(char id);

int passTOarchivoCanciones(stCancion b[],int dimension,int validos);

///Validacion
int validacionCancionXId(int id);

void cancionesRecomendadas();
//Ordenaciones
int posMenorTitulo (stCancion a[], int pos, int cant);
void ordenarTitulo(stCancion a[], int cant);
int posMenorGenero (stCancion a[], int pos, int cant);
void ordenarGenero(stCancion a[], int cant);
int passTOarchivo(stCancion b[],int dimension,int validos);
void mostrarArregloCanciones(stCancion a[],int validos);

//====MODIFICACIONES CANCIONES====
void elimininarCancion(char nombreCancion[]);
void recuperarCancion(char nombreCancion[]);
void modificarTituloCancion(char tituloN[],int idIngresado);
void modificarArtistaCancion(char artistaN[],int idIngresado);
void modificarDuracionCancion(int duracionN,int idIngresado);
void modificarAlbumCancion(char albumN[],int idIngresado);
void modificarAnioCancion(int anioN,int idIngresado);
void modificarGeneroCancion(char generoN[],int idIngresado);

/// ////////////////////////////////////////////////////////////////////////////////

typedef struct
{
    stCancion cancion;
    struct nodoArbolCancion * izq;
    struct nodoArbolCancion * der;
} nodoArbolCancion;

nodoArbolCancion*inicArbol ();
nodoArbolCancion*crearNodoArbol ();
nodoArbolCancion*ingresarNodoArbolOrdenado(nodoArbolCancion*arbol,nodoArbolCancion*nuevoNodo);
void mostrarPosorder(nodoArbolCancion*arbol);
void mostrarInorder(nodoArbolCancion*arbol);
void mostrarPreorder(nodoArbolCancion*arbol);
nodoArbolCancion*buscarXIdCancion(nodoArbolCancion*arbol,int id);
nodoArbolCancion*borrarID(nodoArbolCancion*arbol,int id);
nodoArbolCancion*NMD(nodoArbolCancion*arbol);
nodoArbolCancion*NMI(nodoArbolCancion*arbol);
nodoArbolCancion*array2Arbol(nodoArbolCancion*arbol);
nodoArbolCancion*passArray2Arbol(nodoArbolCancion*arbol,stCancion arr[],int validos);

void mostrarPosorderEnColumna(nodoArbolCancion*arbol);

int cantSong();
#endif // CANCIONES_H_INCLUDED
