#include "Fila.h"

int main()
{

    Fila f;
    inicFila(&f);

    poneFila(&f,1);
    poneFila(&f,2);
    poneFila(&f,3);
    poneFila(&f,4);

    if(vaciaFila(f)!= 1)
    {
        printf(" ");
        sacaFila(&f);
    }

    mostrarFila(f);

    ///ATENCION: ESTA PARTE DEL CODIGO CONTRADICE LA DEFINICION DE FILA/COLA, LO HACEMOS
    ///SOLO A MODO DE PRACTICA
    int datoAEliminar;
    printf("Ingrese dato a eliminar: \n");
    scanf("%d",&datoAEliminar);

    ///voy a buscar el nodo que quiero eliminar
    nodoD * nodoAEliminar;
    nodoAEliminar = buscarNodo(f,datoAEliminar);

    ///si el nodo existe...
    if(nodoAEliminar != NULL)
    {
        eliminarNodoIntermedio(&f,nodoAEliminar);
    }
    else
    {
        printf("NO existe el dato que se quiere eliminar...\n");
    }
    mostrarFila(f);


    return 0;
}

