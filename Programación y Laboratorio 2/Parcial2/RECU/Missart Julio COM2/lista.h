#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


typedef struct{

    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];
    char nombreDoctor[30];

}stPaciente;

typedef struct{

    stPaciente dato;
    struct nodoLista* sig;

}nodoLista;

nodoLista* inicLista();
nodoLista* crearNodo(stPaciente p);
void muestraLista(nodoLista* lista);

void muestraNodoLista(nodoLista *nodo);
nodoLista* agregarAlFinal(nodoLista* lista, nodoLista* nuevo);
#endif // LISTA_H_INCLUDED
