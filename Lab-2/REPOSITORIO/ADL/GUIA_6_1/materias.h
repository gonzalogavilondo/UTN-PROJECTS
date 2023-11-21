#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED
#include "utilidades.h"
#include "listas.h"
#include "registroArchivo.h"

typedef struct
{
    int idMateria;
    char materia[40];
}stMateria;

typedef struct
{
    stMateria m;
    nodoSt* listaDeNotas;
}stCelda;

int buscaPosMateria(stCelda adl[], stMateria m, int validos);
int agregar(stCelda adl[], stMateria m, int validos);
int alta (stCelda adl[], stMateria m, stNotaAlumno n, int validos);
int archivo2adl(stCelda adl[], int validos, int dim);
void mostrarADL(stCelda adl[], int validos);
void guardarAprobDesaprob(stCelda adl[],int validos);

#endif // MATERIAS_H_INCLUDED
