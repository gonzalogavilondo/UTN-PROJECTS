#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pila.h"

typedef struct{
    char origen[30];
    char destino[30];
    char tipo[30];//”aereo”,“ferrocarril”
    float costo;
    int tiempoViaje;
}registroEnvios;

typedef struct{
    char nombre[30];
    float costo;
    int tiempoViaje;
    struct nodoDestino* sig;
}nodoDestino;

typedef struct{
    char nombre[30];
    nodoDestino* destinosAereos;
    nodoDestino* destinosFerro;
    struct nodoOrigen* sig;
}nodoOrigen;

typedef struct{
int cantDestinosAereos;
char ciudadOrigen[30];
float costoPromedioAereo;
float tiempoPromedioAereo;
}destinosAereos;

typedef struct{
int cantDestinosFerro;;
char ciudadOrigen[30];
float costoPromedioFerro;
float tiempoPromedioFerro;
}destinosFerro;

nodoOrigen *inicLista();
nodoDestino *crearNodoDestino(char nombre[], float costo, int tiempoViaje);
nodoOrigen *crearNodoOrigen(char nombre[]);
nodoOrigen *archivoToListaOrigen(nodoOrigen *lista);
nodoOrigen *insertarRecursivo(nodoOrigen *lista, nodoOrigen *nuevo);
nodoOrigen *alta(nodoOrigen *lista, registroEnvios aux);
nodoOrigen *buscarOrigen(nodoOrigen *lista, char origen[]);
nodoDestino *agregarAlFinal(nodoDestino *lista, nodoDestino *nuevo);
nodoDestino *buscarUltimo(nodoDestino *lista);

float promedioTiempoAereo(nodoOrigen *lista, nodoDestino *listaAereos, char origen[], int cant);

float promedio(nodoOrigen *listaOrigenes, char nombreOrigen[]);
float promedioFerro(nodoOrigen *listaOrigenes, char nombreOrigen[]);
float promedioAux(nodoDestino *destinoActual, int cont, int total);

float costoPromedioFerro(nodoOrigen *listaOrigenes, char nombreOrigen[]);
float costoPromedioAereo(nodoOrigen *listaOrigenes, char nombreOrigen[]);
float costoPromedioAux(nodoDestino *destinoActual, int cont, int total);
int cantidadDestinos(nodoDestino *lista);

nodoOrigen *eliminarSegunTiempoViaje(nodoOrigen *lista);
nodoDestino *eliminarDestino(nodoDestino *lista);

nodoOrigen *eliminarSegunDestino(nodoOrigen *lista, char destino[]);
nodoOrigen *eliminarSegunOrigen(nodoOrigen *lista, char origen[]);
nodoDestino *eliminarSegunDestinoAux(nodoDestino *lista, char destino[]);

int main()
{
    nodoOrigen *lista = inicLista();
    lista = archivoToListaOrigen(lista);

    lista = eliminarSegunDestino(lista, "Arias");
    mostrarListaOrigen(lista);

    ///guardarEnArchivoDestinosAereosYFerro(lista);
    ///mostrarRegistroAereos();
    ///mostrarRegistroFerro();





    return 0;
}

nodoOrigen *inicLista(){
    return NULL;
}

nodoDestino *crearNodoDestino(char nombre[], float costo, int tiempoViaje){
    nodoDestino *nuevo = (nodoDestino*)malloc(sizeof(nodoDestino));

    strcpy(nuevo->nombre, nombre);
    nuevo->costo = costo;
    nuevo->tiempoViaje = tiempoViaje;
    nuevo->sig = NULL;

    return nuevo;
}

nodoOrigen *crearNodoOrigen(char nombre[]){
    nodoOrigen *nuevo = (nodoOrigen*)malloc(sizeof(nodoOrigen));

    strcpy(nuevo->nombre, nombre);
    nuevo->destinosAereos = inicLista();
    nuevo->destinosFerro = inicLista();
    nuevo->sig = NULL;

    return nuevo;
}

nodoOrigen *archivoToListaOrigen(nodoOrigen *lista){
    FILE *buf = fopen("registroEnvios.bin", "rb");
    registroEnvios aux;

    if(!buf){
        printf("EL ARCHIVO NO SE PUEDE ABRIR.");
    }else{
        while(fread(&aux, sizeof(registroEnvios), 1, buf) > 0){
            lista = alta(lista, aux);
        }
        fclose(buf);
    }
    return lista;
}

nodoOrigen *insertarRecursivo(nodoOrigen *lista, nodoOrigen *nuevo){
    if(!lista){
        lista = nuevo;
    }else if(strcmpi(nuevo->nombre, lista->nombre) < 0){
        nuevo->sig = lista;
        lista = nuevo;
    }else{
        lista->sig = insertarRecursivo(lista->sig, nuevo);
    }
    return lista;
}

nodoOrigen *alta(nodoOrigen *lista, registroEnvios aux){
    nodoOrigen *origenEncontrado = buscarOrigen(lista, aux.origen);
    nodoDestino *nuevoDestino = crearNodoDestino(aux.destino, aux.costo, aux.tiempoViaje);
    if(!origenEncontrado){
        nodoOrigen *nuevoOrigen = crearNodoOrigen(aux.origen);
        lista = insertarRecursivo(lista, nuevoOrigen);
            if(strcmpi(aux.tipo, "aereo") == 0){
                lista->destinosAereos = agregarAlFinal(lista->destinosAereos, nuevoDestino);
            }else{
                lista->destinosFerro = agregarAlFinal(lista->destinosFerro, nuevoDestino);
            }
    }else{
        if(strcmpi(aux.tipo, "aereo") == 0){
            origenEncontrado->destinosAereos = agregarAlFinal(origenEncontrado->destinosAereos, nuevoDestino);
        }else{
            origenEncontrado->destinosFerro = agregarAlFinal(origenEncontrado->destinosFerro, nuevoDestino);
        }
    }
    return lista;
}

nodoOrigen *buscarOrigen(nodoOrigen *lista, char origen[]){
    nodoOrigen *seg = lista;
    nodoOrigen *encontrado = NULL;

    while(seg){
        if(strcmpi(seg->nombre, origen) == 0){
            encontrado = seg;
            break;
        }
        seg = seg->sig;
    }
    return encontrado;
}

nodoDestino *agregarAlFinal(nodoDestino *lista, nodoDestino *nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodoDestino *ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }
    return lista;
}

nodoDestino *buscarUltimo(nodoDestino *lista){
    nodoDestino *ultimo = lista;
    if(ultimo){
        while(ultimo->sig){
            ultimo = ultimo->sig;
        }
    }
    return ultimo;
}

nodoOrigen *agregarAlPrincipio(nodoOrigen *lista, nodoOrigen *nuevo){
    if(lista){
        nuevo->sig = lista;
    }
    lista = nuevo;
    return lista;
}

nodoOrigen *agregarAlFinal(nodoOrigen *lista, nodoOrigen *nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodoOrigen *ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }
    return lista;
}

nodoOrigen *buscarUltimo(nodoOrigen *lista){
    nodoOrigen *ultimo = lista;
    if(ultimo){
        while(ultimo->sig){
            ultimo = ultimo->sig
        }
    }
    return ultimo;
}

void mostrarListaOrigen(nodoOrigen *lista){
    nodoOrigen *seg = lista;

    while(seg){
        printf("------------------------------------------\n");
        printf("-------> ORIGEN: %s\n", seg->nombre);
        printf("------------------------------------------\n");

        printf("\n \\\\\\\\ DESTINOS AEREOS /////\n\n");
        while(seg->destinosAereos){
            printf("------------------------------------------\n");
            printf("     DESTINO: %s \n", seg->destinosAereos->nombre);
            printf("       COSTO: %f \n", seg->destinosAereos->costo);
            printf("TIEMPO VIAJE: %i \n", seg->destinosAereos->tiempoViaje);
            printf("------------------------------------------\n");
            seg->destinosAereos = seg->destinosAereos->sig;
        }

        printf("\n <<<<< DESTINOS FERROCARRIL >>>>>\n\n");
        while(seg->destinosFerro){
            printf("------------------------------------------\n");
            printf("     DESTINO: %s \n", seg->destinosFerro->nombre);
            printf("       COSTO: %f \n", seg->destinosFerro->costo);
            printf("TIEMPO VIAJE: %i \n", seg->destinosFerro->tiempoViaje);
            printf("------------------------------------------\n");
            seg->destinosFerro = seg->destinosFerro->sig;
        }
        seg = seg->sig;
    }
}

void mostrarRegistro(){
    FILE *buf = fopen("registroEnvios.bin", "rb");
    registroEnvios aux;

    if(!buf){
        printf("EL ARCHIVO NO SE PUEDE ABRIR.");
    }else{
        while(fread(&aux, sizeof(registroEnvios), 1, buf) > 0){
        printf("------------------------------------------\n");
        printf(" ORIGEN: %s\n", aux.origen);
        printf("DESTINO: %s\n", aux.destino);
        printf("   TIPO: %s\n", aux.tipo);
        printf("  COSTO: %.2f\n", aux.costo);
        printf(" TIEMPO: %i\n", aux.tiempoViaje);
        printf("------------------------------------------\n");
        }
        fclose(buf);
    }
}

/// 2

float promedio(nodoOrigen *listaOrigenes, char nombreOrigen[]){
    if(!listaOrigenes){
        return 0.0;
    }if(strcmpi(listaOrigenes->nombre, nombreOrigen) == 0){
        return promedioAux(listaOrigenes->destinosAereos, 0, 0);
    }
    return promedio(listaOrigenes->sig, nombreOrigen);
}

float promedioFerro(nodoOrigen *listaOrigenes, char nombreOrigen[]){
    if(!listaOrigenes){
        return 0.0;
    }if(strcmpi(listaOrigenes->nombre, nombreOrigen) == 0){
        return promedioAux(listaOrigenes->destinosFerro, 0, 0);
    }
    return promedio(listaOrigenes->sig, nombreOrigen);
}

float promedioAux(nodoDestino *destinoActual, int cont, int total){
    if(!destinoActual){
        if(cont == 0){
            return 0.0;
        }
        return (float)total/cont;
    }
    return promedioAux(destinoActual->sig, cont+1, total + destinoActual->tiempoViaje);
}

/// 3

void guardarEnArchivoDestinosAereosYFerro(nodoOrigen *lista){
    FILE *bufAereo = fopen("destinosAereos.bin", "ab");
    FILE *bufFerro = fopen("destinosFerro.bin", "ab");

    destinosAereos auxAereo;
    destinosFerro auxFerro;

    while(lista){
        auxAereo.cantDestinosAereos = cantidadDestinos(lista->destinosAereos);
        strcpy(auxAereo.ciudadOrigen, lista->nombre);
        auxAereo.costoPromedioAereo = costoPromedioAereo(lista, lista->nombre);
        auxAereo.tiempoPromedioAereo = promedio(lista, lista->nombre);
        fwrite(&auxAereo, sizeof(destinosAereos), 1, bufAereo);

        auxFerro.cantDestinosFerro = cantidadDestinos(lista->destinosFerro);
        strcpy(auxFerro.ciudadOrigen, lista->nombre);
        auxFerro.costoPromedioFerro = costoPromedioFerro(lista, lista->nombre);
        auxFerro.tiempoPromedioFerro = promedioFerro(lista, lista->nombre);
        fwrite(&auxFerro, sizeof(destinosFerro), 1, bufFerro);

        lista = lista->sig;
    }
    fclose(bufAereo);
    fclose(bufFerro);
}

float costoPromedioFerro(nodoOrigen *listaOrigenes, char nombreOrigen[]){
    if(!listaOrigenes){
        return 0.0;
    }if(strcmpi(listaOrigenes->nombre, nombreOrigen) == 0){
        return costoPromedioAux(listaOrigenes->destinosFerro, 0, 0);
    }
    return promedio(listaOrigenes->sig, nombreOrigen);
}

float costoPromedioAereo(nodoOrigen *listaOrigenes, char nombreOrigen[]){
    if(!listaOrigenes){
        return 0.0;
    }if(strcmpi(listaOrigenes->nombre, nombreOrigen) == 0){
        return costoPromedioAux(listaOrigenes->destinosAereos, 0, 0);
    }
    return promedio(listaOrigenes->sig, nombreOrigen);
}

float costoPromedioAux(nodoDestino *destinoActual, int cont, int total){
    if(!destinoActual){
        if(cont == 0){
            return 0.0;
        }
        return (float)total/cont;
    }
    return promedioAux(destinoActual->sig, cont+1, total + destinoActual->costo);
}

int cantidadDestinos(nodoDestino *lista){
    int cont = 0;

    while(lista){
        cont ++;
        lista = lista->sig;
    }
    return cont;
}

void mostrarRegistroAereos(){
    FILE *bufAereo = fopen("destinosAereos.bin", "rb");
    destinosAereos aux;

    while(fread(&aux, sizeof(destinosAereos), 1, bufAereo) > 0){
        printf("---------------------------------------------------\n");
        printf("CANTIDAD DESTINOS AEREOS: %i\n", aux.cantDestinosAereos);
        printf("           CIUDAD ORIGEN: %s\n", aux.ciudadOrigen);
        printf("          COSTO PROMEDIO: %.2f\n", aux.costoPromedioAereo);
        printf("         TIEMPO PROMEDIO: %.2f\n", aux.tiempoPromedioAereo);
        printf("---------------------------------------------------\n");
    }
}

void mostrarRegistroFerro(){
    FILE *bufFerro = fopen("destinosFerro.bin", "rb");
    destinosFerro aux;

    while(fread(&aux, sizeof(destinosFerro), 1, bufFerro) > 0){
        printf("---------------------------------------------------\n");
        printf(" CANTIDAD DESTINOS FERRO: %i\n", aux.cantDestinosFerro);
        printf("           CIUDAD ORIGEN: %s\n", aux.ciudadOrigen);
        printf("          COSTO PROMEDIO: %.2f\n", aux.costoPromedioFerro);
        printf("         TIEMPO PROMEDIO: %.2f\n", aux.tiempoPromedioFerro);
        printf("---------------------------------------------------\n");
    }
}

/// 4

nodoOrigen *eliminarSegunTiempoViaje(nodoOrigen *lista){
    nodoOrigen *seg = lista;

    while(seg){
        nodoDestino *destinoActual = seg->destinosAereos;
        while(destinoActual){
            if(destinoActual->tiempoViaje < 3){
                seg->destinosAereos = eliminarDestino(destinoActual);
                destinoActual = seg->destinosAereos;
            }else{
                destinoActual = destinoActual->sig;
            }
        }
        seg = seg->sig;
    }
    return lista;
}

nodoDestino *eliminarDestino(nodoDestino *lista){
    nodoDestino *borrar = lista;
    lista = lista->sig;
    free(borrar);
    return lista;
}

nodoOrigen *eliminarSegunDestino(nodoOrigen *lista, char destino[]){
    nodoOrigen *seg = lista;

    while(seg){
        nodoDestino *destinoActual = seg->destinosAereos;
        destinoActual = eliminarSegunDestinoAux(destinoActual, destino);
        if(seg->destinosAereos == NULL && seg->destinosFerro == NULL){
            seg = eliminarSegunOrigen(seg, seg->nombre);
        }
        seg = seg->sig;
    }
    return lista;
}

nodoDestino *eliminarSegunDestinoAux(nodoDestino *lista, char destino[]){
    if(strcmpi(lista->nombre, destino) == 0){
            nodoDestino *borrar = lista;
            lista = lista->sig;
            free(borrar);
        }else{
            nodoDestino *ant = lista;
            nodoDestino *seg = lista->sig;

            while(seg != NULL && strcmpi(seg->nombre, destino) != 0){
                ant = seg;
                seg = seg->sig;
            }
            if(seg != NULL){
                ant->sig = seg->sig;
                free(seg);
            }
        }
    return lista;
}

nodoOrigen *eliminarSegunOrigen(nodoOrigen *lista, char origen[]){
    if(strcmpi(lista->nombre, origen) == 0){
        nodoOrigen *borrar = lista;
        lista = lista->sig;
        free(borrar);
    }else{
        nodoOrigen *ant = lista;
        nodoOrigen *seg = lista->sig;

        while(seg != NULL && strcmpi(seg->nombre, origen) != 0){
            ant = seg;
            seg = seg->sig;
        }
        if(seg != NULL){
            ant->sig = seg->sig;
            free(seg);
        }
    }
    return lista;
}
