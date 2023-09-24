#include "Fila.h"

nodoD * crearNodo(int dato)
{
    nodoD * nuevo = (nodoD*) malloc(sizeof(nodoD));

    nuevo->dato = dato;

    nuevo->ant = NULL;
    nuevo->sig = NULL;

    return nuevo;
}

void inicFila(Fila* f)
{
    (*f).pri = NULL;
    (*f).ult = NULL;
}

int frenteFila(Fila f)
{
    return (f.pri->dato);
}

void poneFila(Fila* f, int dato)
{
    nodoD * nuevo = crearNodo(dato);


    if((*f).pri ==  NULL)
    {
        (*f).pri = nuevo;
        (*f).ult = nuevo;
    }
    else
    {
        (*f).ult->sig = nuevo;
        nuevo->ant = (*f).ult;
        (*f).ult = nuevo;
    }
}

int sacaFila(Fila *f)
{
    int dato;

    ///ya se verifico que la fila no este vacia (vaciafila)

    dato = (*f).pri->dato;
    ///guardo la dir del nodo p/despues poder liberarlo
    nodoD * nodoBorrar=(*f).pri;

    (*f).pri->ant = NULL;
    (*f).pri = (*f).pri->sig;

    ///libero el nodo mas alla de haber actualizado la lista
    free(nodoBorrar);

    ///si el primero quedo en nulo, el ultimo tambien debe estarlo
    if ((*f).pri == NULL)
    {
        (*f).ult = NULL;
    }

    return dato;
}

int vaciaFila(Fila f)
{
    return (f.pri==NULL);
}

void mostrarFila(Fila f)
{
    nodoD *seg = f.pri;

    if (seg == NULL)
    {
        printf("La fila esta vacia.\n");
        return;
    }

    printf("Contenido de la fila:\n");

    while (seg != NULL)
    {
        printf("%d ", seg->dato);
        seg = seg->sig;
    }
    printf("\n");
}

nodoD * buscarNodo (Fila f, int datoBuscado)
{
    nodoD *seg = f.pri;
    if (seg == NULL)
    {
        printf("La fila esta vacia.\n");
        return;
    }
    while ((seg != NULL)&&(seg->dato != datoBuscado))
    {
        seg = seg->sig;
    }
    return seg;
}

void eliminarNodoIntermedio(Fila *f, nodoD *nodoAEliminar)
{
    ///antes de llamar a esta funcion, verificar que la fila no este vacia!

    nodoD *anterior = nodoAEliminar->ant;
    nodoD *siguiente = nodoAEliminar->sig;

    if (anterior != NULL)
    {
        anterior->sig = siguiente;
    }
    else ///esto NO debe hacerse ya que contradice la definicion de fila/cola
    {
        (*f).pri = (*f).pri->sig;
        (*f).pri->ant = NULL;
    }

    if (siguiente != NULL)
    {
        siguiente->ant = anterior;
    }


    free(nodoAEliminar);
}
