#include "Fila.h"


// Funci�n para crear un nodo con un puntero a NodoPedido
nodoD* crearNodo(NodoPedido* pedido)
{
    nodoD* nuevo = (nodoD*)malloc(sizeof(nodoD));
    nuevo->pedido = pedido;
    nuevo->ant = NULL;
    nuevo->sig = NULL;
    return nuevo;
}

// Funci�n para inicializar una fila
void inicFila(Fila* f)
{
    f->pri = NULL;
    f->ult = NULL;
}

// Funci�n para verificar si la fila est� vac�a
int vaciaFila(Fila* f)
{
    return (f->pri == NULL);
}

// Funci�n para agregar un elemento al final de la fila
void poneFila(Fila* f, NodoPedido* pedido)
{
    nodoD* nuevo = crearNodo(pedido);

    if (vaciaFila(f))
    {
        f->pri = nuevo;
        f->ult = nuevo;
    }
    else
    {
        f->ult->sig = nuevo;
        nuevo->ant = f->ult;
        f->ult = nuevo;
    }
}

// Funci�n para eliminar y obtener el elemento del frente de la fila
NodoPedido* sacaFila(Fila* f)
{
    NodoPedido* pedido = NULL;

    if (!vaciaFila(f))
    {
        nodoD* nodoBorrar = f->pri;

        pedido = f->pri->pedido;

        f->pri = f->pri->sig;

        if (f->pri != NULL)
        {
            f->pri->ant = NULL;
        }
        else
        {
            f->ult = NULL;
        }

        free(nodoBorrar);
    }

    return pedido;
}

// Funci�n para obtener el elemento del frente de la fila sin eliminarlo
NodoPedido* frenteFila(Fila* f)
{
    NodoPedido* pedido = NULL;

    if (!vaciaFila(f))
    {
        pedido = f->pri->pedido;
    }

    return pedido;
}

// Funci�n para mostrar el contenido de la fila
void mostrarFila(Fila* f)
{
    nodoD* seg = f->pri;

    if (seg == NULL)
    {
        printf("La fila est� vac�a.\n");
    }
    else
    {
        printf("Contenido de la fila:\n");
        while (seg != NULL)
        {
            printf("NroPedido: %d, MontoCompra: %.2f, NroCliente: %d, NyA: %s\n",
                   seg->pedido->NroPedido, seg->pedido->MontoCompra,
                   seg->pedido->cliente.NroCliente, seg->pedido->cliente.NyA);
            seg = seg->sig;
        }
    }
}

// Funci�n para buscar un nodo con un valor espec�fico en la fila
nodoD* buscarNodo(Fila* f, int datoBuscado)
{
    nodoD* seg = f->pri;

    while (seg != NULL && seg->pedido->NroPedido != datoBuscado)
    {
        seg = seg->sig;
    }

    return seg;
}

// Funci�n para eliminar un nodo en una posici�n intermedia
void eliminarNodoIntermedio(Fila* f, nodoD* nodoAEliminar)
{
    if (nodoAEliminar == NULL)
    {
        return;
    }

    nodoD* anterior = nodoAEliminar->ant;
    nodoD* siguiente = nodoAEliminar->sig;

    if (anterior != NULL)
    {
        anterior->sig = siguiente;
    }
    else
    {
        f->pri = siguiente;
        if (siguiente != NULL)
        {
            siguiente->ant = NULL;
        }
    }

    if (siguiente != NULL)
    {
        siguiente->ant = anterior;
    }

    free(nodoAEliminar);
}


Fila armaFilaPedidos(NodoPedido* listaPedidos)
{
    Fila filaPedidos; // Declarar la FILA que contendr� los pedidos mayores a 20000
    inicFila(&filaPedidos); // Inicializar la FILA

    // Recorrer la lista de pedidos
    NodoPedido* actual = listaPedidos;
    while (actual != NULL)
    {
        if (actual->MontoCompra > 20000)
        {
            // Si el monto del pedido es mayor a 20000, agregarlo a la FILA
            poneFila(&filaPedidos, actual);
        }
        actual = actual->siguiente;
    }

    return filaPedidos; // Devolver la FILA con los pedidos mayores a 20000
}

void buscaPedido(Fila* filaPedidos, int numeroPedidoBuscado)
{
    nodoD* actual = filaPedidos->pri;
    int encontrado = 0; // Bandera para verificar si se encontr� el pedido

    while (actual != NULL)
    {
        if (actual->pedido->NroPedido == numeroPedidoBuscado)
        {
            // Si se encuentra el pedido, mostrar su informaci�n
            printf("Pedido encontrado:\n");
            printf("N�mero de cliente: %d\n", actual->pedido->cliente.NroCliente);
            printf("Nombre y apellido: %s\n", actual->pedido->cliente.NyA);
            printf("N�mero de pedido: %d\n", actual->pedido->NroPedido);
            printf("Monto de la compra: %.2f\n", actual->pedido->MontoCompra);
            encontrado = 1; // Establecer la bandera a 1 para indicar que se encontr� el pedido
            break; // Salir del bucle una vez que se encuentra el pedido
        }
        actual = actual->sig;
    }

    if (!encontrado)
    {
        printf("Pedido con n�mero %d no encontrado en la FILA.\n", numeroPedidoBuscado);
    }
}
