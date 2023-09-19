#include "declaraciones.h"

int main()
{
    //RegistroCompraCliente registro;

    ///Creo el nodo
    NodoPedido *lista = inicLista();

    ///Creo una lista en base al archivo binario
    lista = crearListaPedidos("Archivo binario.dat");

    //lista = ingresarPedido(lista);

    ///Mostramos la lista
    mostrarLista(lista);

    ///Calculamos el monto total de la compra
    printf("El resultado de la compra es: %.2f", calcularTotalMontoCompra(lista));


    ///Liberamos la lista
    liberarLista(lista);



    return 0;
}
