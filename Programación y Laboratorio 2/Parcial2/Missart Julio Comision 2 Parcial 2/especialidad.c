#include <stdio.h>
#include <stdlib.h>
#include "registroArchivo.h"
#include "especialidad.h"
#include "paciente.h"
#include "conio.h"
#include <string.h>

#define ESC 27

/**
* \brief ciclo de carga de un array de estructuras stEspecialidadMedica, EJERCICIO2.
* \param Recibe un arreglo de tipo stEspecialidadMedica
* \param Recibe sus validos
* \param Recibe la dimension del arreglo.
* \return Retorna la cantidad de validos del array actualizado.
*/
int cargarEspecialidad(stEspecialidadMedica a[], int v, int dim)
{
    char opcion;
    int flag = 0;

    while( v < dim && flag == 0)
    {
        system("cls");
        printf("\nIngrese el nombre de la especialidad: ");
        fflush(stdin);
        gets(a[v].especialidadMedica);
        a[v].listaPacientes = inicLista();
        a[v].idEspecialidad = v;
        v++;
        printf("\nDesea ingresar una nueva especialidad? Escape para salir.");
        fflush(stdin);
        opcion = getch();
        if(opcion == ESC)
        {
            flag = 1;
        }
    }

    return v;
}

/**
* \brief Busca si existe una determinada especialidad medica, EJERCICIO 3.
* \param recibe un arreglo tipo stEspecialidadMedica.
* \param recibe los validos del arreglo
* \param recibe el nombre de la especialidad.
* \return 1 si existe, 0 si no existe dentro del arreglo.
*/
int buscaEspecialidadMedica(stEspecialidadMedica a[], int v, char nombreEspecialidad[])
{
    int flag = 0;
    int i = 0;

    while(flag == 0 && i < v)
    {
        if(strcmp(nombreEspecialidad, a[i].especialidadMedica) == 0)
        {
            flag = 1;
        }
        i++;
    }
    return flag;
}

/***
* \brief Muestra el contenido de la estructura compuesta, EJERCICIO 6.
* \param Recibe un arreglo de tipo stEspecialidadMedica
* \param Recibe la cantidad de validos para recorrer el arreglo.
*/
void muestraEstructura(stEspecialidadMedica a[], int v)
{
    int i=0;
    while(i<v)
    {
        printf("\n ID Especialidad: %d", a[i].idEspecialidad);
        printf("\n Nombre de la especialidad: %s", a[i].especialidadMedica);
        mostrarListaPacientes(a[i].listaPacientes);
        i++;
    }
}

/**
* \brief Verifica si un paciente fue atendido en una especialidad especifica, EJERCICIO 7.
* \param Recibe un arreglo de tipo stEspecialidadMedica
* \param Recibe la cantidad de validos del arreglo.
* \param Recibe el nombre del paciente.
* \param Recibe el apellido del paciente.
* \param Recibe el nombre de la especialidad en la cual buscar.
* \return Retorna 1 si el paciente fue atendido en esa especialidad, 0 si no lo fue.
*
*/
int pacienteAtendido(stEspecialidadMedica a[], int v, char nombrePaciente[], char apellidoPaciente[], char especialidad[])
{
    int flag = 0;
    int i = 0;

    while(i < v && flag == 0)
    {
        if (strcmp(a[i].especialidadMedica, especialidad) == 0)
        {
            stPaciente* seg = a[i].listaPacientes;
            while(seg)
            {
                if(strcmp(a[i].listaPacientes->nombrePaciente, nombrePaciente) == 0 && strcmp(a[i].listaPacientes->apellidoPaciente, apellidoPaciente) == 0)
                {
                    flag = 1;
                }
                else
                {
                    seg=seg->sig;
                }
            }
        }
        i++;
    }
    return flag;
}
