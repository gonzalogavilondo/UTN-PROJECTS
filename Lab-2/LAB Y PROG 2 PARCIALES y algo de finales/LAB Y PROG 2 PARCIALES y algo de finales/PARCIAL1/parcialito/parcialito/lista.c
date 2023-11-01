#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include <string.h>

nodo* crearNodo(stEmpleado empleado)
{
    nodo* unNodo = (nodo*)malloc(sizeof(nodo));
    unNodo->siguiente= NULL;
    unNodo->dato=empleado;
    return unNodo;

}

nodo * agregarAlPrincipio(nodo * lista, nodo* nuevo)
{
    nuevo->siguiente=lista;
    return nuevo;
}
nodo* iniclista()
{
    return NULL;
}

void mostrarLista(nodo* lista)
{

    nodo*seg=lista;
    while(seg)
    {
        mostrarEmpleado(seg->dato);
        seg= seg->siguiente;
    }

}

void lista2archivo(nodo * lista, char archivo[]){

FILE * puntFile = fopen(archivo,"ab");
stEmpleado e;
if(puntFile){
    while(lista){
        e=lista->dato;
        fwrite(&e,sizeof(stEmpleado),1,puntFile);
        lista = lista->siguiente;
        }

    fclose(puntFile);
}
}

nodo* archivo2lista(nodo * lista, char archivo[]){
FILE *  puntFile = fopen(archivo,"rb");
stEmpleado e;
if(puntFile){
    while(fread(&e,sizeof(stEmpleado),1,puntFile)){
        lista=agregarAlPrincipio(lista,crearNodo(e));
    }
    fclose(puntFile);
}
return lista;
}

int buscarPorApellido(nodo*lista, char apellido[]){
int rta =0;
    while(lista){
        if(strcmpi(lista->dato.apellido,apellido)== 0){

            rta=1;

        }
        lista=lista->siguiente;
    }

return rta;
}

void mostrarListaRecu(nodo* lista){
if(lista){
    mostrarEmpleado(lista->dato);
    mostrarListaRecu(lista->siguiente);
}

}
