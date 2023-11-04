#ifndef ESPECIE_H_INCLUDED
#define ESPECIE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "utilidades.h"
#include "registroArchivo.h"
#include "arbol.h"

typedef struct stEspecie
{
    int idEspecie;
    char especie[20];
} stEspecie;

typedef struct stCeldaEspecie
{
    stEspecie e;
    nodoArbol* arbolDeAnimales;
} stCeldaEspecie;

int buscaPosEspecie(stCeldaEspecie ada[], stEspecie e, int validos);
int agregar(stCeldaEspecie ada[], stEspecie e, int validos);
int alta(stCeldaEspecie ada[], stEspecie e, stAnimal a, int validos);
int archivo2ada(stCeldaEspecie ada[], int validos, int dim);
void mostrarADA(stCeldaEspecie ada[], int validos);
void guardarEspecies(stCeldaEspecie ada[],int validos);
void guardarArbol(FILE* pf, nodoArbol* arbol);
void mostrarAnimales(char archivo[]);

#endif // ESPECIE_H_INCLUDED
