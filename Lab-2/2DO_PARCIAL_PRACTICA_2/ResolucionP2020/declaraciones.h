#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIM 30

typedef struct stRegistroMedico
{
    int idRegistro;
    int idPaciente;
    int idEspecialidad;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11]; /// formato: AAAA-mm-DD
    char especialidadMedica[30];
    char nombreDoctor[30];
}stRegistroMedico;

typedef struct stPaciente
{
    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
}stPaciente;

typedef struct stEspecialidadMedica
{
    int idEspecialidad;
    char especialidadMedica[30];
    char diagnostico[100];
    char fechaAtencion[11]; /// formato: AAAA-mm-DD
    char nombreDoctor[30];
}stEspecialidadMedica;


typedef struct nodoArbol
{
    stPaciente dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;

typedef struct celda
{
    stEspecialidadMedica especialidad;
    nodoArbol *arbolEspecialidades;
}celda;


/**
*   Ejercicio 1
**/
int archivo2ADA(celda arreglo[], int);
int alta(celda arreglo[], int, stRegistroMedico);
nodoArbol* crearNodoArbol(stRegistroMedico);
stPaciente cargarDatoArbol(stRegistroMedico);
int buscarPosicion(celda arreglo[], int, int);
int agregarEspecialidad(celda arreglo[], int validos, int idEspecialidad, char especialidadMedica[], char diagnostico[], char fechaAtencion[], char nombreDoctor[]);
nodoArbol *inicArbol();
nodoArbol *insertarNodo(nodoArbol *, nodoArbol *);

/**
*   Ejercicio 2
**/

void mostrarADA(celda arreglo[], int);
void inorder(nodoArbol *);
void mostrarPaciente(stPaciente);
//
///**
//* Ejercicio 3
//**/
//nodoArbol *buscarVendedorArreglo(celda arreglo[], int, int);
//nodoArbol *buscarVendedorArbol(nodoArbol *, int);
//
///**
//* Ejercicio 4
//**/
//
//int cantidadVendedoresSuperiores(celda arreglo[], int, int, int);
//int cantidadVendedoresSuperioresSector2(nodoArbol *, int);
//int cantidadVendedoresSuperioresSector(nodoArbol *, int);
//
///**
//*   Ejercicio 5
//**/
//int sectorMasVentas(celda arreglo[], int);
//int sumarVentasSector(nodoArbol *);
//int sumarValoresArbol(nodoArbol *);
//
///**
//*   Ejercicio 6
//**/
//float porcentajeVentas(celda arreglo[], int, int );
//int calcularVentasTotales(celda arreglo[], int);


#endif // DECLARACIONES_H_INCLUDED
