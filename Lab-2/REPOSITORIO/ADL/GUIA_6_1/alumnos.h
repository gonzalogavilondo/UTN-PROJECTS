#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct stNotaAlumno
{
    int legajo;
    char apeNom[40];
    int nota;

} stNotaAlumno;

void mostrarUnaNota(stNotaAlumno);
void cargarAlumno(stNotaAlumno **);


#endif // ALUMNOS_H_INCLUDED
