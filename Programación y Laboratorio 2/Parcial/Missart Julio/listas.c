#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "listas.h"
#include "persona.h"
#include "filas.h"

nodo* inicLista() {
    return NULL;
}


nodo* archivo2lista(nodo* lista, char archivo[]) {

    FILE *pArch = fopen(archivo, "rb");
    stPersona aux;

    if (pArch) {
        while (fread(&aux, sizeof(stPersona), 1, pArch) > 0){
            lista = agregarEnOrden(lista, crearNodo(aux));
        }
        fclose(pArch);
    }
    return lista;
}

nodo* crearNodo(stPersona persona) {

    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = persona;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->siguiente){
        seg = seg->siguiente;
    }

    return seg;
}


nodo* agregarAlInicio(nodo* nuevo, nodo* lista) {

    if(lista == NULL) {
        lista = nuevo;
    }
    else {
        nuevo->siguiente = lista;
        lista = nuevo;
    }

    return lista;
}

nodo* agregarEnOrden(nodo* lista, nodo* nuevo)///por apellido
{
    if(lista==NULL)
    {
        lista = nuevo;
    }
    else
    {
        if(strcmp(nuevo->dato.apellido, lista->dato.apellido) < 0)
        {
            agregarAlPrincipioPD(lista,nuevo);
        }
        else
        {
            nodo* ante = lista;
            nodo* seg=lista->siguiente;
            while(seg && strcmp(nuevo->dato.apellido, seg->dato.apellido) > 0)
            {
                ante = seg;
                seg = seg-> siguiente;
            }
            nuevo->siguiente=seg;
            ante->siguiente= nuevo;
        }
    }
    return lista;
}

void muestraNodo(nodo* nodo){
    printf("\n nodo: %p - nodo->siguiente: %p",  nodo, nodo->siguiente);
    muestraUnaPersona(nodo->dato);
}

void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg){  /// while(lista!=NULL)
        muestraNodo(seg);
        seg = seg->siguiente;
    }
}
/*
void muestaListaRecursiva(nodo* lista){
    if(lista){
        muestraNodo(lista->dato);
        muestraListaRecursiva(lista->siguiente);
    }
}*/

int sumaListaRecursiva(nodo* lista){
    int rta;
    if(!lista){
        rta=0;
    }else{
        rta=lista->dato.id+sumaListaRecursiva(lista->siguiente);
    }

    return rta;
}

int cantPersonas(nodo* lista) {
    int rta = 0;
    nodo* seg = lista;
    while(seg) {
        rta++;
        seg = seg->siguiente;
    }

    return rta;
}

int sumaListaRecursivaPro(nodo* lista){
    int rta=0;
    if(lista){
        if(atoi(lista->dato.edad)%2 == 0 && lista->dato.edad > 17) {
            rta=1+sumaListaRecursivaPro(lista->siguiente);
        } else {
            rta = sumaListaRecursivaPro(lista->siguiente);
        }
    }

    return rta;
}


/*
nodo* archivo2ListaOrdenado(nodo* lista, char archivo[]) {

    FILE *pArch = fopen(archivo, "rb");
    int entero;

    if (pArch) {
        while (fread(&entero, sizeof(int), 1, pArch) > 0){
            lista = agregarEnOrden(lista, crearNodo(entero));
        }
        fclose(pArch);
    }
    return lista;
}*/

nodo* borrarLista(nodo* lista){
    nodo* proximo;
    nodo* seg = lista;
    while(seg){   /// esto es igual a while(seg!=NULL)
        proximo = seg->siguiente;   /// tomo la direccion del siguiente nodo
        free(seg);              /// libero la memoria del nodo actual
        seg = proximo;          /// me muevo al siguiente nodo
    }
    return seg;
}
/*
nodo* borrarNodoPorBusqueda(nodo* lista, char apellido[]){
    nodo* seg;
    nodo* ante;
    if(lista && strcmp(lista->dato.persona.apellido, apellido)==0){
        nodo* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else {
        seg = lista;
        while(seg && strcmp(lista->dato.persona.apellido, apellido)!=0){
            ante = seg;                                                       //Guardamos el anterior para linkear con el siguiente del que vamos a borrar
            seg = seg->siguiente;
        }

        if(seg){
            ante->siguiente = seg->siguiente;                                 //Re-Linkeamos la lista
            free(seg);                                                        //Borramos el nodo.
        }
    }
    return lista;
}*/

nodo* eliminarUltimoNodo(nodo* lista){
    nodo* seg = lista;
    nodo* ante;
    while(seg->siguiente){
        ante = seg;
        seg=seg->siguiente;
    }
    free(seg);
    ante->siguiente=NULL;
    return lista;
}

nodo* eliminarPrimerNodo(nodo* lista){
    nodo* seg=lista;
    lista=lista->siguiente;
    free(seg);
    return lista;
}

int cuentaLista(nodo* lista){
    nodo* seg=lista;
    int cont=0;
    while(seg){
        cont++;
        seg = seg->siguiente;
    }
    return cont;
}

/*stCliente verPrimero(nodo* lista){
    return lista->dato;
}*/

// DOBLE PUNTERO
/*
void agregarFinal(nodo** lista, nodo * nuevo) {

    if((*lista)==NULL) {
        (*lista) = nuevo;
    }
    else {
        nodo* ultimo = buscarUltimoNodo(*lista);
        ultimo->siguiente = nuevo;
    }
}*/

void agregarAlPrincipioPD(nodo **lista, nodo* nuevoNodo){
    nuevoNodo->siguiente = (*lista);
    (*lista)=nuevoNodo;
}
/*
nodo* archivo2listaPD(char F[], nodo* lista) {

    FILE *pArch = fopen(F, "rb");
    stPersona aux;
    if(pArch) {
        while(fread(&aux, sizeof(stPersona), 1, pArch) > 0){
            agregarFinal(&lista, crearNodo(aux));
        }
        fclose(pArch);
    }
    return lista;
}*/

void buscarUltimoPD(nodo** lista){
    nodo* seg = (*lista);
    while(seg->siguiente!=NULL){
        seg = seg->siguiente;
    }
}

stPersona buscaMenorRecursiva(nodo* lista)
{
    stPersona menor;

    if(lista->siguiente)
    {
        menor = buscaMenorRecursiva(lista->siguiente);
        if(lista->dato.edad < menor.edad) {
            menor = lista->dato;
        }
    }
    return menor;
}

void lista2fila(nodo* lista, Fila* fila, char x) {
    nodo* seg = lista;

    if(seg) {
        while(seg){  /// while(lista!=NULL)
            if(seg->dato.apellido[0] == x) {
            agregar(fila, seg->dato);
            }
            seg = seg->siguiente;
        }
    }
}

int cantPersonasPorEdad (nodo* lista, int edad2)
{
    int total = 0;
    if (lista && lista->dato.edad >= edad2){
        total = cantPersonasPorEdad(lista->siguiente, edad2);
        total = total+1;
    } else {
    cantPersonasPorEdad(lista->siguiente, edad2);
    }
    return total;
}

int mayoresEdad(nodo* lista, int edad) ///5///
{
    int cont=0;
    if(lista)
    {
        if(lista->dato.edad >= edad)
        {
            cont=mayoresEdad(lista->siguiente,edad);
            cont=cont+1;
        }
        else
        {
            mayoresEdad(lista->siguiente,edad);

        }
    }
    return cont;


}

float porcentListaSegunEdad(nodo* lista, int edad)
{
    nodo* seg=lista;
    float rta;
    int i, total;
    i = 50;
    if(lista)
    {
        total=cantPersonasPorEdad(lista,0);///cuenta a todas las personas
    }


    rta= total*i /100;

    return total;
}
