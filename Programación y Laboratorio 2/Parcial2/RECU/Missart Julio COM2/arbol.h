#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "lista.h"

typedef struct {
    int idEspecialidad;
    char especialidadMedica[30];
}stEspecialidadMedica;

typedef struct nodoArbol {

    stEspecialidadMedica espec;
    nodoLista* listaPacientes;
    struct nodoArbol* izq;
    struct nodoArbol* der;

}nodoArbol;

void mostrarEspecialidadMedica(stEspecialidadMedica espec);

#endif // ARBOL_H_INCLUDED
