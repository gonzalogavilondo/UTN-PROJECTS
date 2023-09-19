#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RegistroCompraCliente
{
    int NroCliente;
    char NyA[30];
    int NroPedido;
    float MontoCompra;

}RegistroCompraCliente;

typedef struct Cliente
{
    int NroCliente;
    char NyA[30];

} Cliente;

typedef struct NodoPedido
{
    int NroPedido;
    Cliente cliente;
    float MontoCompra;
    struct NodoPedido * siguiente;

} NodoPedido;

NodoPedido* inicLista();
NodoPedido* crearNodoPedido(RegistroCompraCliente);
NodoPedido* agregarNodoPedido(NodoPedido *, RegistroCompraCliente);
NodoPedido* buscaUltimoLista(NodoPedido *);
NodoPedido* crearListaPedidos(const char *);
NodoPedido* agregarAlFinalPedido(NodoPedido *, NodoPedido *);
void mostrarUnNodo(NodoPedido *);
void mostrarLista(NodoPedido *);
NodoPedido* liberarLista(NodoPedido *);
NodoPedido* ingresarPedido(NodoPedido *);
float calcularTotalMontoCompra(NodoPedido *);
RegistroCompraCliente* copiarPedidosMayores5000(NodoPedido *, int *);
void lista2array(NodoPedido*, RegistroCompraCliente*);

#endif // DECLARACIONES_H_INCLUDED
