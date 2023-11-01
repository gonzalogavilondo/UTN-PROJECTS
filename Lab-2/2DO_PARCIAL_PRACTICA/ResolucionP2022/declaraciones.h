#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

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
    int idSsector;
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

int archivo2ADA(arreglo, dimension);


#endif // DECLARACIONES_H_INCLUDED
