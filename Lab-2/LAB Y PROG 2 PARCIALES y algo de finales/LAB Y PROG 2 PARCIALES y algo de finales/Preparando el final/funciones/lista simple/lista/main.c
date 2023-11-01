#include <stdio.h>
#include <stdlib.h>
typedef struct {
char nombre[20];
int edad;
} persona

typedef struct {
persona dato;
struct nodo * siguiente;
} nodo;


int main()
{
    printf("Hello world!\n");
    return 0;
}



nodo * inicLista() {
return NULL;
}

nodo * crearNodo (persona dato) {
//crea un puntero de tipo nodo
nodo * aux = (nodo*) malloc(sizeof(nodo));
//asigna valores a sus campos de información
aux->dato = dato;
//asigna valor NULL al campo que contiene la dirección de memoria del
//siguiente nodo
aux->siguiente = NULL;
//retorna la dirección de memoria del nuevo nodo, que deberá ser
asignada a una variable de tipo "puntero a nodo".
return aux;
}




nodo * agregarPpio (nodo * lista, nodo * nuevoNodo) {
//si la lista está vacía, ahora apuntará al nuevo nodo.
if(lista == NULL) {
lista = nuevoNodo;
}else
//si la lista no está vacía, inserta el nuevo nodo al comienzo de la
//misma, y el viejo primer nodo pasa a ser el segundo de la lista.
{
nuevoNodo->siguiente = lista;
lista = nuevoNodo;
}
return lista;
}



nodo * buscarUltimo(nodo * lista) {
nodo * seg = lista;
if(seg != NULL)
while(seg->siguiente != NULL) {
seg = seg->siguiente;
}
return seg;
}



nodo * buscarNodo(nodo * lista, char nombre[20]) {
//busca un nodo por nombre y retorna su posición de memoria
//si no lo encuentra retorna NULL.
nodo * seg; //apunta al nodo de la lista que está siendo procesado
seg = lista; //con esto evito cambiar el valor de la variable
//lista, que contiene un puntero al primer nodo de la
//lista vinculada
while ((seg != NULL) && ( strcmp(nombre, seg->dato.nombre)!=0 )) {
//busco mientras me quede lista por recorrer y no haya encontrado el nombre
seg=seg->siguiente; //avanzo hacia el siguiente nodo.
}
//en este punto puede haber fallado alguna de las dos condiciones
//del while. si falla la primera es debido a que no encontró lo
//que buscaba (seg es NULL), si falla la segunda es debido a que se
//encontró el nodo buscado.
return seg;
}




nodo * agregarFinal(nodo * lista, nodo * nuevoNodo) {
if(lista == NULL) {
lista = nuevoNodo;
} else {
nodo * ultimo = buscarUltimo(lista);
ultimo->siguiente = nuevoNodo;
}
return lista;
}



nodo * borrarNodo(nodo * lista, char nombre[20]) {
nodo * seg;
nodo * ante; //apunta al nodo anterior que seg.
if((lista != NULL) && (strcmp(nombre, lista->dato.nombre)==0 )) {
nodo * aux = lista;
lista = lista->siguiente; //salteo el primer nodo.
free(aux); //elimino el primer nodo.
}else {
seg = lista;
while((seg != NULL) && (strcmp(nombre, seg->dato.nombre)!=0 )) {
ante = seg; //adelanto una posición la variable ante.
seg = seg->siguiente; //avanzo al siguiente nodo.
}
//en este punto tengo en la variable ante la dirección de
//memoria del nodo anterior al buscado, y en la variable seg,
//la dirección de memoria del nodo que quiero borrar.
if(seg!=NULL) {
ante->siguiente = seg->siguiente;
//salteo el nodo que quiero eliminar.
free(seg);
//elimino el nodo.
}
}
return lista;
}




nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo) {
// agrega un nuevo nodo a la lista manteniendo el orden.
//si la lista está vacía agrego el primer elemento.
if(lista == NULL) {
lista = nuevoNodo;
}else {
//si el nuevo elemento es menor que el primero de la lista,
//agrego al principio
if(strcmp(nuevoNodo->dato.nombre,lista->dato.nombre)<0){
lista = agregarPpio(lista, nuevoNodo);
} else {
//busco el lugar en donde insertar el nuevo elemento.
//necesito mantener la dirección de memoria del nodo anterior
//al nodo que tiene un nombre mayor al del nuevo nodo.
nodo * ante = lista;
nodo * seg = lista->siguiente;
while((seg != NULL)
&&(strcmp(nuevoNodo->dato.nombre,seg->dato.nombre)>0)) {
ante = seg;
seg = seg->siguiente;
}
// inserto el nuevo nodo en el lugar indicado.
nuevoNodo->siguiente = seg;
ante->siguiente = nuevoNodo;
}
}
return lista;
}


nodo * borrarTodaLaLista(nodo * lista) {
nodo * proximo;
nodo * seg;
seg = lista;
while(seg != NULL) {
proximo = seg->siguiente; //tomo la dir del siguiente.
free(seg); //borro el actual.
seg = proximo; //actualizo el actual con la dir del
//siguiente, para avanzar.
}
return seg; // retorna NULL a la variable lista del main()
}

int sumarEdadesLista(nodo * lista) {
//recorro la lista y sumo las edades de los socios.
int suma = 0;
nodo * seg = lista;
while (seg != NULL) {
suma = suma + seg->dato.edad;
seg = seg->siguiente;
}
return suma;
}
