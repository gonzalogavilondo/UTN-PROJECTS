#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "listas.h"
#include "persona.h"
#include "filas.h"
#include "listasDoble.h"

nodo2* inicLista2(){
    return NULL;
}

nodo2* agregarAlFinal(nodo2* lista, nodo2* nuevo) {
    if(!lista) {
        lista = nuevoNodo;
    }
    else {
        nodo2* ultimo = buscarUltimo2(lista);
        ultimo->ste = nuevoNodo;
        nuevoNodo->ante = ultimo;
    }
    return lista;
}
