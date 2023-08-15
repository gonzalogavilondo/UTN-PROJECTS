#ifndef VAGON_H_INCLUDED
#define VAGON_H_INCLUDED

typedef struct {
    float pesoIngresado;
   struct nodoVagon * sig;
}nodoVagon;

nodoVagon* inicLista();
nodoVagon* crearNodo(float peso);
nodoVagon* agregarAlFinal(nodoVagon* lista, nodoVagon* nuevo);
nodoVagon* buscarUltimo(nodoVagon* lista);

#endif // VAGON_H_INCLUDED

