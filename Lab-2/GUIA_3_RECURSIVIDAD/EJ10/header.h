#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //Es para la constante INT_MAX, donde define los limites de los tipos de datos

int buscar_menor_elemento_file(FILE *, int);
void mostrar_archivo_invertido(FILE *);
void apertura_archivo(FILE **);


#endif // HEADER_H_INCLUDED
