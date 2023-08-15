#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED

float **ReservarMemoria(int, int);
void CargarFilasColumnas(int *, int *);
void MostrarMatriz(int, int, float **);
void CompletarMatriz(int, int, float **, char);
void CondicionOpcion(int, int *, int *, int *, int *);

#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
