#ifndef REGISTROARCHIVO_H_INCLUDED
#define REGISTROARCHIVO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "utilidades.h"

#define arRegistro "registroArchivo.dat"

typedef struct stRegistroArchivo
{
   char animal[30];
   int cant;
   int habitat;
   int idEspecie;
   char especie[20];
} stRegistroArchivo;

void ingresarRegistros();
stRegistroArchivo ingresarUnRegistro();
void agregarRegistro(stRegistroArchivo r);
void mostrarUnRegistro(stRegistroArchivo r);
void mostrarRegistros(char archivo[]);
int getEspecie(char e[]);
void getAnimal(char a[],int idEspecie);
int getHabitat(int idEspecie);
void getHabitatChar(int n, char h[]);
int getCantidad();
stRegistroArchivo cargoRegistroArchivoRandom();
void guardaRegistroArchivo(char archivo[], stRegistroArchivo r);
void generaArchivoRandom(int cantidad);
int cuentaRegistros(char nombreArchivo[], int tamStruct);

#endif // REGISTROARCHIVO_H_INCLUDED
