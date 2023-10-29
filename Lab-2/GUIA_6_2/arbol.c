#include "arbol.h"


nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stAnimal dato){
    nodoArbol* aux = (nodoArbol *) malloc(sizeof(nodoArbol));

    aux->dato=dato;
    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}

/// 1. Hacer una función que sume el contenido de un árbol binario de números enteros.
/// Considerar que la suma del árbol será igual a la suma del dato de la Raíz más la
/// suma del subárbol izquierdo más la suma del subárbol derecho.

int sumarCantAnimalesArbol(nodoArbol* arbol)
{
    return (arbol)?arbol->dato.cantidad+sumarCantAnimalesArbol(arbol->izq)+sumarCantAnimalesArbol(arbol->der):0;
}

int sumarCantNodosArbol(nodoArbol* arbol)
{
    return (arbol)?1+sumarCantNodosArbol(arbol->izq)+sumarCantNodosArbol(arbol->der):0;
}

nodoArbol* insertar (nodoArbol* arbol, nodoArbol* nuevo){
    if(arbol==NULL){
        arbol = nuevo;
    }else{
        if(nuevo->dato.cantidad > arbol->dato.cantidad){
            arbol->der=insertar(arbol->der, nuevo);
        }else{
            arbol->izq=insertar(arbol->izq, nuevo);
        }
    }
    return arbol;
}

void inorder(nodoArbol* arbol){
    if(arbol){
        inorder(arbol->izq);
        mostrarNodo(arbol);
        inorder(arbol->der);
    }
}

void preorder(nodoArbol* arbol){
    if(arbol){
        mostrarNodo(arbol);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void postorder(nodoArbol* arbol){
    if(arbol){
        postorder(arbol->izq);
        postorder(arbol->der);
        mostrarNodo(arbol);
    }
}

void mostrarNodo(nodoArbol* arbol){
    mostrarUnAnimal(arbol->dato);
}

nodoArbol* buscar(nodoArbol* arbol, char dato[])
{
    nodoArbol* rta=NULL;
    if(arbol){
        if(strcmp(dato,arbol->dato.nombreAnimal)==0)
            rta = arbol;
        else if(strcmp(dato,arbol->dato.nombreAnimal)>0)
            rta = buscar(arbol->der, dato);
        else
            rta = buscar(arbol->izq, dato);
    }
    return rta;
}

void mostrarUnAnimal(stAnimal a){
    char habitat[10];
    getHabitatChar(a.habitat,habitat);
    printf("\n Animal.....................: %s",a.nombreAnimal);
    printf("\n Cantidad...................: %d",a.cantidad);
    printf("\n Habitat....................: %d - %s\n",a.habitat,habitat);
    replicante('_',50);
}
