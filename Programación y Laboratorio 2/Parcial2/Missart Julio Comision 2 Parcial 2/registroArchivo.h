#ifndef REGISTROARCHIVO_H_INCLUDED
#define REGISTROARCHIVO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "especialidad.h"

#define arRegistro "registroMedico.dat"

typedef struct{
    int idRegistro;

    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];
    int idEspecialidad;
    char especialidadMedica[30];
    char nombreDoctor[30];
} stRegistroMedico;


void mostrarUnRegistro(stRegistroMedico r);
void especialidad2archivo(stEspecialidadMedica a[], char nombreEspecialidad[], int v);

#endif // REGISTROARCHIVO_H_INCLUDED
