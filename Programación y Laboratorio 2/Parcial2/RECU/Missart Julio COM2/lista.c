#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

nodoLista* inicLista() {
    return NULL;
}

nodoLista* crearNodo(stPaciente p) {

    nodoLista* nuevo = (nodoLista*) malloc(sizeof(nodoLista));
    nuevo->dato = p;
    nuevo->sig = NULL;

    return nuevo;
}

///Para el ejercicio 6
void muestraLista(nodoLista* lista){
    nodoLista* seg = lista;
    while(seg){
        muestraNodoLista(seg);
        seg = seg->sig;
    }
}

///Para el ejercicio 6
void muestraNodoLista(nodoLista *nodo){

    printf("\n----------------------");
    printf("\nID del Paciente......: %d", nodo->dato.idPaciente);
    printf("\nNombre del Paciente..: %s", nodo->dato.nombrePaciente);
    printf("\nApellido del Paciente: %s", nodo->dato.apellidoPaciente);
    printf("\nDiagnostico..........: %s", nodo->dato.diagnostico);
    printf("\nFecha de Atención....: %s", nodo->dato.fechaAtencion);
    printf("\nNombre del Doctor....: %s", nodo->dato.nombreDoctor);
    printf("\n----------------------");

}

nodoLista* buscarUltimo(nodoLista* lista){
    nodoLista* seg = lista;
    while(seg->sig){
        seg = seg->sig;
    }

    return seg;
}

nodoLista* agregarAlFinal(nodoLista* lista, nodoLista* nuevo){

    if(lista == NULL) {
        lista = nuevo;
    }
    else {
        nodoLista* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }

    return lista;
}

