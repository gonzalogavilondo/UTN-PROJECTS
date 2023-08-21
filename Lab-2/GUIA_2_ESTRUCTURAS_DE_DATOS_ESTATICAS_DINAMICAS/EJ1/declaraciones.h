#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char nombre[30];
    char genero;
    int edad;
}persona;

void cargarPersonas(persona arreglo[], int);
int contarGenero(persona arreglo[], int, char);
persona* copiarGenero(persona arreglo[], int, char, int*);
void imprimirPersonas(persona arreglo[], int);


#endif // DECLARACIONES_H_INCLUDED
