#include "declaraciones.h"

int main()
{
    RegistroCompraCliente *registro = NULL;
    int cnt = 10;
    ///Creo el nodo
    NodoPedido *lista = inicLista();

    ///Creo una lista en base al archivo binario
    lista = crearListaPedidos("Archivo binario.dat");

    //lista = ingresarPedido(lista);

    ///Copiamos los mayores a 5000
    registro = copiarPedidosMayores5000(lista, &cnt);

    ///Mostramos la lista
    mostrarLista(lista);

    ///Calculamos el monto total de la compra
    printf("El resultado de la compra es: %.2f\n", calcularTotalMontoCompra(lista));

    puts("\n\n---------------------------------------------------------------------------\n");
    printf("\n--REGISTROS CON COMPRAS MAYOR A 5000--\n\n");
    mostrarPedidos(registro, cnt);

    ///Liberamos la lista
    liberarLista(lista);

    return 0;
}
