#ifndef ESPECIALIDAD_H_INCLUDED
#define ESPECIALIDAD_H_INCLUDED
#include "paciente.h"

typedef struct{
    int idEspecialidad;
    char especialidadMedica[30];
    struct stPaciente * listaPacientes;
}stEspecialidadMedica;

int cargarEspecialidad(stEspecialidadMedica a[], int v, int dim);
int buscaEspecialidadMedica(stEspecialidadMedica a[], int v, char nombreEspecialidad[]);
void muestraEstructura(stEspecialidadMedica a[], int v);
int pacienteAtendido(stEspecialidadMedica a[], int v, char nombrePaciente[], char apellidoPaciente[], char especialidad[]);


#endif // ESPECIALIDAD_H_INCLUDED
