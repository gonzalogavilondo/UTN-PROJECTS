#ifndef DECLARACIONES_FUNCIONES_REALES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_REALES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

void SumarMatrices(int, int, float **, float **, float **);
void RestarMatrices(int, int, float **, float **, float **);
void MultiplicarMatrices(int, int, int, int, float **, float **, float **);
void MultiplicarFilasMatriz(int, int, float **, float **);
float MultiplicacionEscalarMatrices(int, int, int, float **, float **);
void MultiplicarFilasMatriz(int, int, float **, float **);
float MultiplicacionEscalarMatriz(int, int, int, float **);
void DivisionEscalar(int, int, float **, float **);
void TraspuestaMatriz(int, int, float **, float **);

#endif // DECLARACIONES_FUNCIONES_REALES_H_INCLUDED
