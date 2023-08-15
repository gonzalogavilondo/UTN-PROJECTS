#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED

void InicializarMatriz(int, int, float **);
void CargarFilasColumnas(int *, int *);
void MostrarMatriz(int, int, float **);
void CompletarMatriz(int, int, float **, char);
void CondicionOpcion(int, int *, int *, int *, int *);
float **ReservarMemoria(int, int);

#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
