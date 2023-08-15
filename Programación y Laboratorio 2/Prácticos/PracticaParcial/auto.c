#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "auto.h"

#define ESC 27

void menu(){

    printf("\n1 - Cargar Autos a archivo.");
    printf("\n2 - Mostrar archivo de autos.");
    printf("\n3 - Archivo a Lista.");
    printf("\n4 - Mostrar lista.");
    printf("\n");
    printf("\n");
}

nodoAuto* inicLista() {
    return NULL;
}

nodoAuto* crearNodo (automovil auto1) {

    nodoAuto* nuevo = (nodoAuto*) malloc(sizeof(nodoAuto));

    nuevo->dato = auto1;
    nuevo->siguiente = NULL;

    return nuevo;
}

void agregarFinal(nodoAuto** lista, nodoAuto * nuevo) {

    if((*lista)==NULL) {
        (*lista) = nuevo;
    }
    else {
        nodoAuto* ultimo = buscarUltimoNodo(*lista);
        ultimo->siguiente = nuevo;
    }
}

nodoAuto* buscarUltimoNodo(nodoAuto* lista)
{
    nodoAuto* seg=lista;
    while(seg->siguiente!=NULL)
    {
        seg=seg->siguiente;
    }
    return seg;
}


automovil cargaUnAuto() {

    automovil autoaux;

    printf("\nIngrese patente: ");
    fflush(stdin);
    gets(autoaux.patente);

    printf("\nIngrese valor: ");
    scanf(" %d", &autoaux.valor);

    printf("\nIngrese una marca: ");
    fflush(stdin);
    gets(autoaux.marca);

    return autoaux;
}

void cicloCargaAutos(char F[]) {
    automovil aux;
    char opcion;

    do{
        aux = cargaUnAuto();
        guardarAuto(aux, F);
        opcion = getch();
    }while(opcion!=ESC);

}

void guardarAuto(automovil auto1, char F[]){

    FILE *pArch = fopen(F, "ab");

    if(pArch) {
        fwrite(&auto1, sizeof(automovil), 1, pArch);
        fclose(pArch);
    }
}

void muestraUnAuto(automovil auto1) {
    printf("\n--------------------");
    printf("\n%s", auto1.marca);
    printf("\n%d", auto1.valor);
    printf("\n%s", auto1.patente);
    printf("\n--------------------");
}

void mostrarAutosArchivo(char F[]) {

    automovil aux;
    FILE *pArch = fopen(F, "rb");

    if (pArch) {
        while(fread(&aux, sizeof(automovil), 1, pArch) > 0) {
        muestraUnAuto(aux);
        }
        fclose(pArch);
    }

}

nodoAuto* archivo2listaPD(char F[], nodoAuto* lista) {

    FILE *pArch = fopen(F, "rb");
    automovil aux;
    if(pArch) {
        while(fread(&aux, sizeof(automovil), 1, pArch) > 0){
            agregarFinal(&lista, crearNodo(aux));
        }
        fclose(pArch);
    }
    return lista;
}

void mostrarLista(nodoAuto* lista) {

    nodoAuto* seg = lista;

    while(seg) {
        muestraUnAuto(seg->dato);
        seg=seg->siguiente;
    }
}
