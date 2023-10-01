#include "declaraciones.h"

int main()
{
    RegistroCompraCliente *registro = NULL;
    int cnt;
    ///Creo el nodo
    NodoPedido *lista = inicLista();

    ///Creo una lista en base al archivo binario
    lista = crearListaPedidos("Archivo binario.dat");

    //lista = ingresarPedido(lista);

    ///Contamos la cantidad de pedidos de una lista
    cnt = contarPedidos(lista);

    ///Copiamos los mayores a 5000
    registro = copiarPedidosMayores5000(lista, &cnt);

    ///Mostramos la lista
    mostrarLista(lista);

    ///Calculamos el monto total de la compra
    printf("El resultado de la compra es: %.2f\n", calcularTotalMontoCompra(lista));

    puts("\n\n---------------------------------------------------------------------------\n");
    printf("\n--REGISTROS CON COMPRAS MAYOR A 5000--\n\n");
    mostrarPedidos(registro, cnt);

    ///Liberamos la lista y el arreglo dinamico
    liberarLista(lista);
    free(registro);

    return 0;
}
