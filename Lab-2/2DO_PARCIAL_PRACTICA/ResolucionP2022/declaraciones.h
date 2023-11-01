#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIM 30

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

typedef struct celda
{
    stSector sector;
    nodoArbol *arbolVendedores;
}celda;

/**
*   Ejercicio 1
**/
int archivo2ADA(celda arreglo[], int);
int alta(celda arreglo[], int, stRegistroVendedor);
nodoArbol* crearNodoArbol(stRegistroVendedor);
stVendedor cargarDatoArbol(stRegistroVendedor);
int buscarPosicion(celda arreglo[], int, int);
int agregarSector(celda arreglo[], int, int, char sector[]);
nodoArbol *inicArbol();
nodoArbol *insertarNodo(nodoArbol *, nodoArbol *);

/**
*   Ejercicio 2
**/
void mostrarADA(celda arreglo[], int);
void inorder(nodoArbol *);
void mostrarVendedor(stVendedor);

/**
* Ejercicio 3
**/
nodoArbol *buscarVendedorArreglo(celda arreglo[], int, int);
nodoArbol *buscarVendedorArbol(nodoArbol *, int);

/**
* Ejercicio 4
**/

int cantidadVendedoresSuperiores(celda arreglo[], int, int, int);
int cantidadVendedoresSuperioresSector2(nodoArbol *, int);
int cantidadVendedoresSuperioresSector(nodoArbol *, int);

/**
*   Ejercicio 5
**/
int sectorMasVentas(celda arreglo[], int);
int sumarVentasSector(nodoArbol *);
int sumarValoresArbol(nodoArbol *);

/**
*   Ejercicio 6
**/
float porcentajeVentas(celda arreglo[], int, int );
int calcularVentasTotales(celda arreglo[], int);



#endif // DECLARACIONES_H_INCLUDED
