#include <stdio.h>
#include <stdlib.h>

typedef struct {
char nombre[20];
int edad;
} persona;

typedef struct {
persona dato;
struct nodoDoble * anterior;
struct nodoDoble * siguiente;
} nodoDoble;





int main()
{
    nodoDoble * listaDoble ;
    return 0;
}



nodoDoble * inicListaDoble() {
return NULL;
}


nodoDoble * crearNodoDoble (persona dato) {
nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
aux->dato = dato;
//asigna valor NULL a los campos que contienen la dirección de memoria
//de los nodos anterior y siguiente
aux->anterior = NULL;
aux->siguiente = NULL;
return aux;
}



nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo) {
nuevo->siguiente = lista;
if(lista != NULL)
lista->anterior=nuevo;
return nuevo;
}




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
}



nodoDoble * agregarFinalDoble(nodoDoble * lista, nodoDoble * nuevo) {
if(lista == NULL) {
lista = nuevo;
} else {
nodoDoble * ultimo = buscarUltimoDobleRecursivo(lista);
ultimo->siguiente = nuevo;
nuevo->anterior = ultimo;
}
return lista;
}




nodoDoble * agregarEnOrdenDoble (nodoDoble * lista, nodoDoble * nuevo) {
if(lista == NULL) {
lista = nuevo;
}else {
if(strcmp(nuevo->dato.nombre,lista->dato.nombre)<0){
lista = agregarPpioDoble(lista, nuevo);
} else {
// se puede recorrer la lista utilizando un solo puntero??
nodoDoble * ante = lista;
nodoDoble * seg = lista->siguiente;
while((seg != NULL)
&&(strcmp(nuevo->dato.nombre,seg->dato.nombre)>0)) {
ante = seg;
seg = seg->siguiente;
}
ante->siguiente = nuevo;
nuevo->anterior = ante;
nuevo->siguiente = seg;
if (seg!=NULL)
seg->anterior=nuevo;
}
}
return lista;
}
