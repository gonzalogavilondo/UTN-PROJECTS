#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
nodoArbol* inicArbol() {
    return NULL;
}


nodoArbol* crearNodoArbol(persona dato) {
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));

    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

/**
* \brief Inserta un nuevo nodo en un arbol ya existente, de lo contrario crea un nuevo arbol.
* \param el arbol nodoArbol* puntero a arbol
* \param el nodo nuevo nodoArbol* nuevo
* \return el arbol
**/
nodoArbol* insertarPorLegajo(nodoArbol* arbol, nodoArbol* nuevo){
    if(!arbol){
        arbol = nuevo;
    }else{
        if(nuevo->dato.legajo > arbol->dato.legajo){
            arbol->der = insertarPorLegajo(arbol->der, nuevo);
        }else{
            arbol->izq = insertarPorLegajo(arbol->izq, nuevo);
        }
    }
    return arbol;
}


void mostrarNodoArbol(nodoArbol* nodo) {
    printf(" %d -", nodo->dato.legajo);
    printf(" %s -", nodo->dato.nombre);
    printf(" %d -", nodo->dato.edad);
}

void muestraNodosTerminales(nodoArbol* arbol){
    if(arbol){
        if(!arbol->izq && !arbol->der) {
            mostrarNodoArbol(arbol);
            }
        muestraNodosTerminales(arbol->izq);
        muestraNodosTerminales(arbol->der);
    }
}


int cuentaNodosTerminales(nodoArbol* arbol) {
    int cont = 0;

    if (!arbol) {
        cont = 0;
    }else{
        if (!arbol->izq && !arbol->der) {
            cont = cont + 1;
        } else {
            cont = cuentaNodosTerminales(arbol->izq) + cuentaNodosTerminales(arbol->der);
        }
    }
    return cont;
}

int cuentaNodos(nodoArbol* arbol)
{
    int cont = 0;
    if(arbol)
    {
        cont= 1+ cuentaNodos(arbol->izq) + cuentaNodos(arbol->der);
    }
    return cont;
}

void preOrder(nodoArbol* arbol){
    if(arbol){
        mostrarNodoArbol(arbol);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

void inOrder(nodoArbol* arbol){
    if(arbol){
        inOrder(arbol->izq);
        mostrarNodoArbol(arbol);
        inOrder(arbol->der);
    }
}

void postOrder(nodoArbol* arbol){
    if(arbol){
        postOrder(arbol->izq);
        postOrder(arbol->der);
        mostrarNodoArbol(arbol);
    }
}


nodoArbol* buscaLegajo(nodoArbol* arbol, int datoLegajo){
    nodoArbol* found = NULL;

    if(arbol) {
        if(arbol->dato.legajo == datoLegajo) {
            found = arbol;
        }else if (arbol->dato.legajo > datoLegajo) {
            found = buscaLegajo(arbol->izq, datoLegajo);
        } else {
            found = buscaLegajo(arbol->der, datoLegajo);
        }
    }

    return found;
}

nodoArbol* buscaPorNombre(nodoArbol* arbol, char datoNombre[]){
    nodoArbol* found = NULL;

    if(arbol) {
        if(strcmp(arbol->dato.nombre, datoNombre) == 0) {
            found = arbol;
        }else{
            found = buscaPorNombre(arbol->izq, datoNombre);
            found = buscaPorNombre(arbol->der, datoNombre);
        }
    }

    return found;
}

int cuentaAltura(nodoArbol* arbol) {
    int leftAcum = 0;
    int rightAcum = 0;
    int result;

    if(!arbol) {
        result = 0;
    }else{
        leftAcum = 1 + cuentaAltura(arbol->izq);
        rightAcum = 1 + cuentaAltura(arbol->der);
    }

    if(leftAcum > rightAcum) {
        result = leftAcum;
    } else {
    result = rightAcum;
    }
    return result;
}

nodoArbol* buscarMasIzq (nodoArbol* arbol){
    nodoArbol* aux = arbol;

    while(aux && aux->izq != NULL){
        aux = aux->izq;
    }
    return aux;
}

nodoArbol* buscarMasDer (nodoArbol* arbol){
    nodoArbol* aux = arbol;

    while(aux && aux->der != NULL){
        aux = aux->der;
    }
    return aux;
}

nodoArbol* borrarNodo(nodoArbol* arbol, int dato)///por numero de legajo
{
    if(arbol)
    {
        if(dato < arbol->dato.legajo)///si el dato a borrar es menor al dato actual del arbol
        {
            arbol->izq = borrarNodo(arbol->izq, dato);///avanzo por la izquierda
        }
        else if(dato >  arbol->dato.legajo) ///si el dato a borrar es mayor al dato actual del arbol
        {
            arbol->der = borrarNodo(arbol->der, dato);///avanzo por la derecha
        }
        else  ///aca solo accede cuando lo encuentra
        {
            if(!arbol->izq && !arbol->der)///si los siguientes nodos del arbol actual son NULL:
            {
                free(arbol);///libera el nodo de una, ya que al ser terminal no hace falta mover nada.
                arbol=NULL;
            }
            else if(!arbol->izq)  ///si el nodo actual no posee otros nodos a la izq:
            {
                nodoArbol* aux= arbol;///guarda el nodo actual en un auxiliar
                arbol=arbol->der;///sobreescribe  el nodo actual con el nodo siguiente que si tiene (recordar que no tiene nodos a la izq)
                free(aux);///libera el espacio de memoria de aux
            }
            else if(!arbol->der) ///si el nodo actual no posee otros nodos a la der:
            {
                nodoArbol* aux= arbol;
                arbol=arbol->izq;///sobreescribe  el nodo actual con el nodo siguiente que si tiene (recordar que no tiene nodos a la der)
                free(aux);
            }else
            {
                nodoArbol* aux= encuentraMenorIzq(arbol->der);///guarda el menor de los 2 nodos que le sigue al actual en una variable aux
                arbol->dato=aux->dato;///guarda el dato actual del nodo en el aux
                arbol->der = borrarNodo(arbol->der, aux->dato.legajo);///borra el dato auxiliar desde el nodo de la derecha.
            }

        }
    }
    return arbol;
}
/**********************
*\brief descripcion corta
*\param parametros de la func
*
*\return que retorna
*/
nodoArbol* encuentraMenorIzq(nodoArbol* arbol)///recorre el nodo actual de manera no recursiva solo en una direccion
{
    nodoArbol* aux= arbol;
    while(aux && aux->izq !=NULL)
    {
        aux=aux->izq;
    }
    return aux;
}
