#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char nombre[30];
}Alumno;

typedef struct
{
    int codigo;
    char nombreMat[20];
}Materia ;

typedef struct
{
    int matricula;
    int codigo;
    int nota;
}Nota;




#endif // DECLARACIONES_H_INCLUDED
