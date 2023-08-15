#include "arbol.h"
#include "lista.h"
#include "registroArchivo.h"
#include <string.h>

/// Crea un nodoArbol con una nueva especialidad
nodoArbol* crearNodoArbol(stEspecialidadMedica espec) {
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));

    nuevo->espec = espec;
    nuevo->listaPacientes = inicLista();
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

/// Inserta al arbol la nueva especialidad. Ejercicio 2.
nodoArbol* insertarNuevaEspec(nodoArbol* arbol, nodoArbol* nuevo) {

    if(!arbol) {
        arbol = nuevo;
    }else{
        if(nuevo->espec.idEspecialidad > arbol->espec.idEspecialidad){
            arbol->der = insertarNuevaEspec(arbol->der, nuevo);
        }else if(nuevo->espec.idEspecialidad < arbol->espec.idEspecialidad){
            arbol->izq = insertarNuevaEspec(arbol->izq, nuevo);
        }
    }
    return arbol;
}



/// Ejercicio 3
int buscaEspecialidad(nodoArbol* arbol, char datoNombre[]){
    int flag = 0;

    if(arbol) {
        if(strcmp(arbol->espec.especialidadMedica, datoNombre) == 0) {
            flag = 1;
        }else{
            flag = buscaEspecialidad(arbol->izq, datoNombre);
            flag = buscaEspecialidad(arbol->der, datoNombre);
        }
    }

    return flag;
}

/// Para el ejercicio 5
nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo){
    if(!arbol){
        arbol = nuevo;
    }else{
        if (nuevo->espec.idEspecialidad == arbol->espec.idEspecialidad) {
            arbol->listaPacientes = agregarAlFinal(arbol->listaPacientes, nuevo->listaPacientes);
        }else if(nuevo->espec.idEspecialidad > arbol->espec.idEspecialidad){
            arbol->der = insertar(arbol->der, nuevo);
        }else{
            arbol->izq = insertar(arbol->izq, nuevo);
        }
    }
    return arbol;
}

/// Ejercicio 5
nodoArbol* archivo2arbol(nodoArbol* arbol) {

    FILE *pArch = fopen(arRegistro, "rb");

    stRegistroMedico aux;
    stEspecialidadMedica especAux;
    stPaciente pacienteAux;
    nodoArbol* auxArbol;
    nodoLista* auxLista;

    if (pArch) {
        while(fread(&aux, sizeof(stRegistroMedico), 1, pArch) > 0) {
            especAux.idEspecialidad = aux.idEspecialidad;
            strcpy(especAux.especialidadMedica, aux.especialidadMedica);
            pacienteAux.idPaciente = aux.idPaciente;
            strcpy(pacienteAux.nombrePaciente, aux.nombrePaciente);
            strcpy(pacienteAux.apellidoPaciente, aux.apellidoPaciente);
            strcpy(pacienteAux.diagnostico, aux.diagnostico);
            strcpy(pacienteAux.fechaAtencion, aux.fechaAtencion);
            strcpy(pacienteAux.nombreDoctor, aux.nombreDoctor);

            auxLista = crearNodo(pacienteAux);
            auxArbol = crearNodoArbol(especAux);

            if(auxArbol->listaPacientes) {
                auxArbol->listaPacientes = agregarAlFinal(auxArbol->listaPacientes, auxLista);
            } else {
                auxArbol->listaPacientes = auxLista;
            }

            arbol = insertar(arbol, auxArbol);
        }
        fclose(pArch);
    }


    return arbol;
}


/// EJERCICIO 6
void mostrarArbolDeListas(nodoArbol * arbol)
{
    if(arbol){
        mostrarEspecialidadMedica(arbol->espec);
        muestraLista(arbol->listaPacientes);
        mostrarArbolDeListas(arbol->izq);
        mostrarArbolDeListas(arbol->der);
    }
}
///Para el ejercicio 6
void mostrarEspecialidadMedica(stEspecialidadMedica espec) {
    printf("\n-------------------------------------------------------");
    printf("\nID Especialidad....: %d", espec.idEspecialidad);
    printf("\nNombre Especialidad: %s", espec.especialidadMedica);
    printf("\n-------------------------------------------------------");
}

/// Ejercicio 7
int pacienteAtendido(nodoArbol* arbol, char nombre[], char apellido[], char nombreEspecialidad[]) {
    int flag = 0;

    if(arbol) {
        if(strcmp(arbol->espec.especialidadMedica, nombreEspecialidad) == 0) {
            nodoLista* seg = arbol->listaPacientes;
            while(flag == 0 && seg) {
                if (strcmp(arbol->listaPacientes->dato.nombrePaciente, nombre) == 0 && strcmp(arbol->listaPacientes->dato.apellidoPaciente, apellido) == 0) {
                    flag = 1;
                }
                seg = seg->sig;
            }
        }else{
            flag = pacienteAtendido(arbol->izq, nombre, apellido, nombreEspecialidad);
            flag = pacienteAtendido(arbol->der, nombre, apellido, nombreEspecialidad);
        }
    }

    return flag;
}

/// Ejercicio 8
/*
void lista2Archivo(nodoLista* lista){
    nodoLista* seg = lista;
    FILE *pArch = fopen(arRegistro, "ab");

    while(seg){


        seg = seg->siguiente;
    }

}
*/
