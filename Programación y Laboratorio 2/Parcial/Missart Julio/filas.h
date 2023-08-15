#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

typedef struct {
    struct nodo2* cabecera;
    struct nodo2* cola;
}Fila;

typedef struct nodo2{
    stPersona dato;
    struct nodo2 *anterior;
    struct nodo2 *siguiente;
}nodo2;

void inicFila(Fila* fila);
void agregar(Fila* fila, stPersona dato);
nodo2* crearNodo2(stPersona dato);

nodo2* inicLista2();

nodo2* agregarAlFinal2(nodo2* lista, nodo2* nuevo);
nodo2* buscarUltimo2(nodo2* lista);
void muestraFila(Fila* fila);
void muestraLista2(nodo2* lista);
void muestraNodo2(nodo2* lista);

#endif // FILAS_H_INCLUDED
