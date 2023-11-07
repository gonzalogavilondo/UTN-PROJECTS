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
    nodoArbol *arbolPacientes;
}celda;


/**
*   Ejercicio 1 y 2
**/
int archivo2ADA(celda arreglo[]);
int alta(celda arreglo[], int, stRegistroMedico);
nodoArbol* crearNodoArbol(stRegistroMedico);
stPaciente cargarDatoArbol(stRegistroMedico);
int buscarPosicion(celda arreglo[], int, int);
int agregarEspecialidad(celda arreglo[], int validos, int idEspecialidad, char especialidadMedica[], char diagnostico[], char fechaAtencion[], char nombreDoctor[]);
nodoArbol *inicArbol();
nodoArbol *insertarNodo(nodoArbol *, nodoArbol *);

/**
*   Ejercicio 3
**/

void mostrarADA(celda arreglo[], int);
void inorder(nodoArbol *);
void mostrarPaciente(stPaciente);

void agregarNuevaAtencion(celda arreglo[], int validos);

int buscarPacienteEnEspecialidad(celda arreglo[], int validos, char nombrePaciente[], char apellidoPaciente[], int idEspecialidad);
nodoArbol* buscarPacienteEnArbol(nodoArbol* arbol, char nombrePaciente[], char apellidoPaciente[]);

void especialidadConMasAtenciones(celda arreglo[], int validos);
int contarAtencionesEnEspecialidad(nodoArbol* arbol);

void guardarEspecialidadEnArchivo(celda arreglo[], int validos, char nombreEspecialidad[], char nombreArchivo[]);
void guardarArbolEnArchivo(nodoArbol* arbol, FILE* archivo);



#endif // DECLARACIONES_H_INCLUDED
