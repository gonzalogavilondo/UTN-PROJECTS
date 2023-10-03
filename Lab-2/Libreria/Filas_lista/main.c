#include "Fila.h"

int main()
{
    Fila fila;
    inicFila(&fila);

    // Crear algunos nodos de pedido para pruebas
    NodoPedido pedido1 = {1, {1, "Cliente 1"}, 100.0, NULL};
    NodoPedido pedido2 = {2, {2, "Cliente 2"}, 200.0, NULL};
    NodoPedido pedido3 = {3, {3, "Cliente 3"}, 300.0, NULL};

    // Agregar los nodos a la fila
    poneFila(&fila, &pedido1);
    poneFila(&fila, &pedido2);
    poneFila(&fila, &pedido3);

    // Mostrar el frente de la fila
    printf("Frente de la fila:\n");
    NodoPedido* frente = frenteFila(&fila);
    if (frente != NULL)
    {
        printf("NroPedido: %d, MontoCompra: %.2f, NroCliente: %d, NyA: %s\n",
               frente->NroPedido, frente->MontoCompra, frente->cliente.NroCliente, frente->cliente.NyA);
    }
    else
    {
        printf("La fila está vacía.\n");
    }

    // Mostrar el contenido de la fila
    printf("\nContenido de la fila:\n");
    mostrarFila(&fila);

    // Sacar un elemento de la fila
    printf("\nSaca un elemento de la fila:\n");
    NodoPedido* sacado = sacaFila(&fila);
    if (sacado != NULL)
    {
        printf("NroPedido: %d, MontoCompra: %.2f, NroCliente: %d, NyA: %s\n",
               sacado->NroPedido, sacado->MontoCompra, sacado->cliente.NroCliente, sacado->cliente.NyA);
    }
    else
    {
        printf("La fila está vacía.\n");
    }

    return 0;
}
