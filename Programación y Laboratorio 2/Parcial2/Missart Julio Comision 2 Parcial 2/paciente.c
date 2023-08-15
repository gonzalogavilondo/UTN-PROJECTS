#include <stdio.h>
#include <stdlib.h>
#include "registroArchivo.h"
#include "especialidad.h"
#include "paciente.h"

#define ESC 27

/**
* \brief Inicializa una lista.
*
*/
stPaciente * inicLista() {
    return NULL;
}

/**
* \brief Recorre y muestra una lista de pacientes, PARA EJERCICIO 6 MODULARIZAR.
* \param Recibe un nodo lista.
*/
void mostrarListaPacientes(stPaciente* lista){
    stPaciente* seg = lista;
     while(seg){
        muestraNodoPaciente(seg);
        seg=seg->sig;
    }
}

/**
* \brief Muestra el contenido de un nodo stPaciente, PARA EJERCICIO 6 MODULARIZAR.
* \param Recibe un nodo stPaciente
*/
void muestraNodoPaciente(stPaciente* paciente){
    printf("\t\t\n --------------------------------------------------");
    printf("\t\t\n ID Paciente..........: %d", paciente->idPaciente);
    printf("\t\t\n Nombre del Paciente..: %s", paciente->nombrePaciente);
    printf("\t\t\n Apellido del Paciente: %s", paciente->apellidoPaciente);
    printf("\t\t\n Nombre del Doctor....: %s", paciente->nombreDoctor);
    printf("\t\t\n Diagnostico..........: %s", paciente->diagnostico);
    printf("\t\t\n fechaAtencion........: %s", paciente->fechaAtencion);
    printf("\t\t\n --------------------------------------------------");
}
