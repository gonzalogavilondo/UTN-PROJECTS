#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int dato;
    struct nodo2* sig;
    struct nodo2 *ant;

}nodo2;


typedef struct {

    struct nodo2* cabecera;   //inicio lista
    struct nodo2* cola;          //final lista
}Fila;







int main()
{
    printf("Hello world!\n");
    return 0;
}

nodo2 *inicLista(){

return NULL;

}

void inicFila(Fila *fila){

    fila->cabecera=inicLista();
    fila->cola=inicLista();
}
///////////
void agregar (Fila *fila, int dato ){

    nodo2 *nuevo=crearNodo(dato);

    if(fila->cabecera==NULL){
        fila->cabecera=nuevo;
        fila->cola=nuevo;
    }
    else{
        fila->cabecera=agregarAlFinal(fila->cabecera,nuevo);
        fila->cola=nuevo;
    }
}


nodo2 *agregarAlFinal(nodo2 *lista, nodo2 *nuevoNodo){

    if(lista==NULL){
        lista=nuevoNodo;
    }
    else{
        nodo2 *ultimo=buscarUltimoDobleRecursivo(lista);
        ultimo->sig=nuevoNodo;
        nuevoNodo->ant=ultimo;
    }
return lista;

}
///////
nodoDoble * buscarUltimoDobleRecursivo (nodoDoble * lista) {
    nodoDoble * rta;
    if (lista==NULL)
        rta=NULL;
    else
        if(lista->siguiente==NULL)
            rta=lista;
        else
            rta=buscarUltimoDobleRecursivo(lista->siguiente);
return rta;
/////
nodoDoble * crearNodoDoble (persona dato) {
    nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
    aux->dato = dato;
    //asigna valor NULL a los campos que contienen la dirección de memoria
    //de los nodos anterior y siguiente
    aux->ant = NULL;
    aux->sig = NULL;
return aux;
}


/////////////
nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo) {
nuevo->siguiente = lista;
if(lista != NULL)
lista->anterior=nuevo;
return nuevo;
}

//////////////////
int extraer(Fila *fila){

    int resp;

    if(fila->cabecera!=NULL){
        resp=verPrimer(fila->cabecera);
        fila->cabecera=borrarPrimero(fila->cabecera);
        if(fila->cabecera==NULL){
            fila->cola=inicLista();
        }
    }
return resp;
}


int verPrimero(nodo2 *lista){


    int rta=0;
    if (lista)
        rta=lista->dato;

return rta;
}

nodo2 *borrarPrimero(nodo2 *lista){

    nodo2 *aBorrar=lista;

    if(lista!=NULL){
        lista=lista->sig;
        if(lista!=NULL)
            lista->ant=NULL;
       free(aBorrar);
    }
return lista;


}

