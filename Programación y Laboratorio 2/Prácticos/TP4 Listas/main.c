#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define ESC 27

typedef struct {
    int dato;
    struct nodo* siguiente;
} nodo;

void muestraMenu();
void generaArchivoEnteros(char archivo[]);
void guardaUnEntero(int dato, char archivo[]);
void muestraUnEntero(int dato);
void muestraArchivoEnteros(char archivo[]);
nodo* inicLista();
nodo* archivo2lista(nodo* lista, char archivo[]);
nodo* crearNodo(int entero);
nodo* buscaUltimoLista(nodo* lista);
nodo* agregarAlInicio(nodo* nuevo, nodo* lista);
nodo* agregarAlFinal(nodo* nuevo, nodo* lista);
nodo* agregaOrdenado(nodo* nuevo, nodo* lista);
void mostrarLista(nodo* lista);
nodo* archivo2ListaOrdenado(nodo* lista, char archivo[]);
nodo* borrarNodo(int entero, nodo* lista);



char archivoEnteros[] = "enteros.dat";
char opcion;

int main()
{
    int detalle;
    generaArchivoEnteros(archivoEnteros);
    nodo* lista;
    lista = inicLista();

    do{
            system("cls");
            muestraMenu();
            opcion = getch();

            switch(opcion) {
            case 49:
                generaArchivoEnteros(archivoEnteros);
                break;
            case 50:
                system("cls");
                muestraArchivoEnteros(archivoEnteros);
                system("pause");
                break;
            case 51:
                lista = archivo2lista(lista, archivoEnteros);
                break;
            case 52:
                system("cls");
                mostrarLista(lista);
                system("pause");
                break;
            case 53:
                lista = archivo2ListaOrdenado(lista, archivoEnteros);
                break;
            case 54:
                system("cls");
                printf("\nIngrese el dato que quiera borrar de la lista: ");
                scanf("%d", &detalle);
                lista = borrarNodo(detalle, lista);
                system("pause");
                break;
            }

    }while(opcion!=ESC);


    return 0;
}

void muestraMenu(){

    printf("\n\t\t - Trabajo Practico 4 - Listas Simples - Missart Julio - \n\n");
    printf("\n1. - Genera un nuevo archivo de enteros con 10 datos (Borra el anterior si ya existe).");
    printf("\n2. - Mostrar archivo de Enteros.");
    printf("\n3. - Leer archivo y agregar elementos a la lista.");
    printf("\n4. - Mostrar Lista.");
    printf("\n5. - Leer archivo e insertar elementos en lista de forma ordenada.");
    printf("\n6. - Borrar nodo.");

}


void generaArchivoEnteros(char archivo[]) {

    FILE *pArchEnteros = fopen(archivo, "wb");

    srand(time(0));

    if (pArchEnteros) {

        for (int i = 0; i < 10; i++) {
            int random = rand()%100;
            fwrite(&random, sizeof(int), 1, pArchEnteros);
        }
        fclose(pArchEnteros);
    }
}

void muestraUnEntero(int dato) {
    printf(" %d -", dato);
}

void muestraArchivoEnteros(char archivo[]) {

    FILE *pArchEnteros = fopen(archivo, "rb");
    int aux;

    if (pArchEnteros) {
        while (fread(&aux, sizeof(int), 1, pArchEnteros) > 0) {
            muestraUnEntero(aux);
        }
        fclose(pArchEnteros);
    }
    printf("\n");
}

nodo* inicLista() {
    return NULL;
}

nodo* archivo2lista(nodo* lista, char archivo[]) {

    FILE *pArch = fopen(archivo, "rb");
    int entero;

    if (pArch) {
        while (fread(&entero, sizeof(int), 1, pArch) > 0){
            lista = agregarAlFinal(crearNodo(entero), lista);
        }
        fclose(pArch);
    }
    return lista;
}

nodo* crearNodo(int entero) {

    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = entero;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodo* buscaUltimoLista(nodo* lista) {

    nodo* copia = lista;

    while(copia->siguiente) {
        copia = copia->siguiente;
    }

    return copia;
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

nodo* agregarAlFinal(nodo* nuevo, nodo* lista){

    if(lista == NULL) {
        lista = nuevo;
    }
    else {
        nodo* ultimo = buscaUltimoLista(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}


nodo* agregaOrdenado(nodo* nuevo, nodo* lista) {

    int flag = 0;

    if(lista == NULL) {
        lista = nuevo;
    }
    else {
        if(nuevo->dato < lista->dato) {
            lista = agregarAlInicio(nuevo, lista);
        }
        else {
            nodo* ante = lista;
            nodo* aux = lista;
            while(aux && nuevo->dato > aux->dato) {
                ante = aux;
                aux = aux->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->siguiente = aux;
        }
    }

    return lista;
}

void mostrarLista(nodo* lista) {

    nodo* copia = lista;
    while (copia) {
        printf("\nDato: %d", copia->dato);
        copia = copia->siguiente;
    }
    printf("\n");
}

nodo* archivo2ListaOrdenado(nodo* lista, char archivo[]) {

    FILE *pArch = fopen(archivo, "rb");
    int entero;

    if (pArch) {
        while (fread(&entero, sizeof(int), 1, pArch) > 0){
            lista = agregaOrdenado(crearNodo(entero), lista);
        }
        fclose(pArch);
    }
    return lista;
}

nodo* borrarNodo(int entero, nodo* lista) {

    nodo* aux;
    nodo* ante;
    if (lista && entero == lista->dato) {
        aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else {
        aux = lista;
        while(aux && entero != aux->dato) {
            ante = aux;
            aux = aux->siguiente;
        }

        if(aux) {
            ante->siguiente = aux->siguiente;
            free(aux);
        }
    }
    printf("\nNodo borrado satisfactoriamente.\n");
    return lista;
}

