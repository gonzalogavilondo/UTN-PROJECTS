#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIM 30

#define ARCHIVO_VENDEDORES "archivoRegistrosVendedor.bin"

typedef struct stRegistroVendedor
{
    int idSector;
    char sector[30]; ///Los sectores son (y estan escritos tal cual): ropa, muebles, etc
    int dni;
    char nombreYapellido[40];
    int ventasDiarias;
}stRegistroVendedor;

typedef struct stSector
{
    int idSector;
    char sector[30];
}stSector;

typedef struct stVendedor
{
    int dni;
    char nombreYapellido[40];
    int ventasDiarias;
}stVendedor;

typedef struct nodoArbol
{
    stVendedor dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;

typedef struct listaCeldas
{
    stSector sector;
    nodoArbol *arbolVendedores;
    struct listaCeldas *siguiente;
}listaCeldas;

/**
*   Ejercicio 1
**/
listaCeldas* archivo2LDA();
listaCeldas* altaEnLista(listaCeldas *lista, stRegistroVendedor aux);
void agregarCeldaALista(stSector datos, nodoArbol *arbolVendedores, listaCeldas **lista);
int buscarPosicionEnLista(listaCeldas *lista, int idSector);
nodoArbol* crearNodoArbol(stRegistroVendedor);
stVendedor cargarDatoArbol(stRegistroVendedor);
nodoArbol *inicArbol();
nodoArbol *insertarNodo(nodoArbol *, nodoArbol *);

/**
*   Ejercicio 2
**/
void mostrarLDA(listaCeldas *);
void inorder(nodoArbol *arbol);
void mostrarVendedor(stVendedor);

/**
* Ejercicio 3
**/
nodoArbol *buscarVendedorLista(listaCeldas *lista, int dni);
nodoArbol *buscarVendedorArbol(nodoArbol *, int);

/**
* Ejercicio 4
**/

int cantidadVendedoresSuperiores(listaCeldas *lista, int idSector, int ventas);
int cantidadVendedoresSuperioresSector2(nodoArbol *, int);
int cantidadVendedoresSuperioresSector(nodoArbol *, int);

/**
*   Ejercicio 5
**/
int sectorMasVentas(listaCeldas *lista);
int sumarVentasSector(nodoArbol *);
int sumarValoresArbol(nodoArbol *);

/**
*   Ejercicio 6
**/
float porcentajeVentas(listaCeldas *lista, int idSector);
int calcularVentasTotalesLista(listaCeldas *lista);


void liberarListaCeldas(listaCeldas *lista);
void lda2archivo(listaCeldas *lista);
nodoArbol* leerArbolDesdeArchivo(FILE *archivo);


#endif // DECLARACIONES_H_INCLUDED
