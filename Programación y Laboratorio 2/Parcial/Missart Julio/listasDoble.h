#ifndef LISTASDOBLE_H_INCLUDED
#define LISTASDOBLE_H_INCLUDED

typedef struct _nodo2{
    stPersona dato;
    struct _nodo2 *anterior;
    struct _nodo2 *siguiente;
}nodo2;

nodo2* inicLista2();

nodo2* agregarAlFinal(nodo2* lista, nodo2* nuevo);

#endif // LISTASDOBLE_H_INCLUDED
