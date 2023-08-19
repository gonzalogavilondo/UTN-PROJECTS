#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int matriz[][31], int, int);
int diaMaximaPrecipitacion(int matriz[][31], int, int);
void cargarMaximosPorMes(int matriz[][31], int, int, int maximos[]);
void imprimirVector(int [], int);

#endif // DECLARACIONES_H_INCLUDED
