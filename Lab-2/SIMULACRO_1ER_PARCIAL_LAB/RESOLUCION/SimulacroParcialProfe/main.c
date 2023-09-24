#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO_BINARIO "./registroCompraCliente.dat"

///estructura Cliente
typedef struct
{
    int NroCliente;
    char NyA[30];
} Cliente;

///estructura NodoPedido
typedef struct NodoPedido
{
    int NroPedido;
    Cliente cliente;
    float MontoCompra;
    struct NodoPedido* siguiente;
} NodoPedido;

///estructura RegistroCompraCliente
typedef struct
{
    int NroCliente;
    char NyA[30];
    int NroPedido;
    float MontoCompra;
} RegistroCompraCliente;


/// Función para crear un nuevo nodo Pedido
NodoPedido* crearNodoPedido(RegistroCompraCliente registro)
{
    NodoPedido* nuevoNodo = (NodoPedido*)malloc(sizeof(NodoPedido));
    if (nuevoNodo == NULL)
    {
        printf("Error al asignar memoria para el nodo Pedido");
        exit(1);
    }
    nuevoNodo->NroPedido = registro.NroPedido;
    nuevoNodo->cliente.NroCliente = registro.NroCliente;
    strcpy(nuevoNodo->cliente.NyA, registro.NyA);
    nuevoNodo->MontoCompra = registro.MontoCompra;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

/// Función para agregar un nodo Pedido al final de la lista
NodoPedido* agregarNodoPedido(NodoPedido* lista, RegistroCompraCliente registro)
{
    NodoPedido* nuevoNodo = crearNodoPedido(registro);
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        NodoPedido* seg = lista;
        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
        seg->siguiente = nuevoNodo;
    }
    return lista;
}

/// Función para recorrer el archivo y crear la lista de Pedidos
NodoPedido* crearListaPedidos()
{
    FILE* archivo;
    archivo = fopen("registroCompraCliente.dat", "rb");

    RegistroCompraCliente registro;
    NodoPedido* lista = NULL;

    ///FILE * archivo = fopen("registroCompraCliente.dat", "rb"); //otra opcion
    ///FILE * archivo = fopen(ARCHIVO_BINARIO, "rb");// otra opcion

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }

    while (fread(&registro, sizeof(RegistroCompraCliente), 1, archivo) == 1)
    {
        lista = agregarNodoPedido(lista, registro);
    }

    fclose(archivo);
    return lista;
}

/// Función recursiva para mostrar la lista de Pedidos
void mostrarListaRecursiva(NodoPedido* lista)
{
    if (lista == NULL) {
        return;
    } else {
        printf("NroPedido: %d\n", lista->NroPedido);
        printf("Cliente: %d - %s\n", lista->cliente.NroCliente, lista->cliente.NyA);
        printf("MontoCompra: %.2f\n\n", lista->MontoCompra);
        mostrarListaRecursiva(lista->siguiente);
    }
}

/// Función para liberar la lista de Pedidos
void liberarLista(NodoPedido* lista)
{
    NodoPedido* seg = lista;
    while (seg != NULL)
    {
        NodoPedido* siguiente = seg->siguiente;
        free(seg);
        seg = siguiente;///falto liberar lista! :(
    }
}

/// Función para pedir al usuario los datos de un Pedido y agregarlo a la lista
NodoPedido* ingresarPedido(NodoPedido* lista)
{
    int NroPedido, NroCliente;
    char NyA[30];
    float MontoCompra;

    RegistroCompraCliente pedido;

    printf("Ingrese el número de pedido: ");
    scanf("%d", &pedido.NroPedido);
    printf("Ingrese el número de cliente: ");
    scanf("%d", &pedido.NroCliente);
    printf("Ingrese el nombre y apellido del cliente: ");
    scanf("%s", NyA);
    strcpy(pedido.NyA,NyA);
    printf("Ingrese el monto de compra: ");
    scanf("%f", &pedido.MontoCompra);

    NodoPedido* nuevoNodo = crearNodoPedido(pedido);
    lista = agregarNodoPedido(lista, pedido);

    printf("Pedido agregado correctamente.\n");

    return lista;
}

///funcion recursiva para calcular el total del monto de las compras (version 1)
float calcularTotalMontoCompra(NodoPedido* lista)
{
    float monto = 0;
    if (lista != NULL)
    {
        monto = lista->MontoCompra + calcularTotalMontoCompra(lista->siguiente);
    }
    return monto;
}

///funcion recursiva para calcular el total del monto de las compras (version 2)
//float calcularTotalMontoCompra(NodoPedido* lista)
//{
//    float monto = 0;
//    if (lista == NULL)
//    {
//        return 0.0;
//    }
//    else
//    {
//        return lista->MontoCompra + calcularTotalMontoCompra(lista->siguiente);
//    }
//}

/// Función para calcular el total del MontoCompra en la lista (no recursiva)
float calcularTotalMontoCompraNoRecursiva(NodoPedido* lista)
{
    float total = 0.0;
    NodoPedido* seg = lista;
    while (seg != NULL) {
        total += seg->MontoCompra;
        seg = seg->siguiente;
    }
    return total;
}

/// Función para contar la cantidad de pedidos en la lista
int contarPedidos(NodoPedido* lista) {
    int cantidad = 0;
    NodoPedido* seg = lista;
    while (seg != NULL) {
        cantidad++;
        seg = seg->siguiente;
    }
    return cantidad;
}

/// Función para copiar pedidos con MontoCompra mayor a $5,000 en un arreglo dinámico
RegistroCompraCliente* copiarPedidosMayores5000(NodoPedido* lista, int* cantidadPedidos)
{
    /// Contar la cantidad de pedidos que cumplen con la condición
    int cantidad = 0;
    NodoPedido* seg = lista;
    while (seg != NULL)
    {
        if (seg->MontoCompra > 5000.0)
        {
            cantidad++;
        }
        seg = seg->siguiente;
    }

    /// se crea un arreglo dinámico para almacenar los pedidos que cumplen con la condición
    RegistroCompraCliente* pedidosMayores5000 = (RegistroCompraCliente*)malloc(cantidad * sizeof(RegistroCompraCliente));
    if (pedidosMayores5000 == NULL)
    {
        printf("Error al asignar memoria para el arreglo de pedidos");
        return 1;
    }

    /// copiar los pedidos que cumplen con la condición al arreglo dinámico
    seg = lista;
    int i = 0;
    while (seg != NULL)
    {
        if (seg->MontoCompra > 5000.0)
        {
            pedidosMayores5000[i].NroCliente = seg->cliente.NroCliente;
            strcpy(pedidosMayores5000[i].NyA, seg->cliente.NyA);
            pedidosMayores5000[i].NroPedido = seg->NroPedido;
            pedidosMayores5000[i].MontoCompra = seg->MontoCompra;
            i++;
        }
        seg = seg->siguiente;
    }

    /// Actualizar la cantidad de pedidos copiados (se paso por referencia)
    *cantidadPedidos = cantidad;

    return pedidosMayores5000;
}

/// Función para mostrar el contenido del arreglo dinámico de pedidos
void mostrarPedidos(RegistroCompraCliente* pedidos, int cantidadPedidos)
{
    printf("Pedidos con MontoCompra mayor a $5,000.00:\n");
    for (int i = 0; i < cantidadPedidos; i++)
    {
        printf("NroPedido: %d\n", pedidos[i].NroPedido);
        printf("Cliente: %d - %s\n", pedidos[i].NroCliente, pedidos[i].NyA);
        printf("MontoCompra: %.2f\n\n", pedidos[i].MontoCompra);
    }
}

///==============================================================================================================

int main()
{
    NodoPedido* lista = NULL;
    lista = crearListaPedidos();

    /// en este momento, "lista" contiene la lista de pedidos leída desde el archivo.
    NodoPedido* seg = lista;

    mostrarListaRecursiva(lista);


    printf(" ========= FIN DE LA LISTA GENERADA DESDE EL ARCHIVO ==========\n");
    system("pause");
    system("cls");

    /// Pedir al usuario que ingrese pedidos
    char continuar;
    do
    {
        lista = ingresarPedido(lista);
        printf("¿Desea ingresar otro pedido? (S/N): ");
        scanf(" %c", &continuar);
    }
    while (continuar == 'S' || continuar == 's');
    /// en este momento, "lista" contiene la lista + pedidos ingresados por el usuario.

    seg = lista;
    mostrarListaRecursiva(lista);
    printf(" ========= FIN DE LA LISTA GENERADA DESDE EL ARCHIVO + PEDIDOS INGRESADOS P/USUARIO ==========\n");
    system("pause");
    system("cls");

    /// Calcular el total de MontoCompra en la lista utilizando la función recursiva
    float totalMontoCompra = calcularTotalMontoCompra(lista);
    printf("Total de MontoCompra en la lista: %.2f\n", totalMontoCompra);
    system("pause");
    system("cls");

    ///uso una funcion para contar cantidad de pedidos
    printf("Cantidad total de pedidos de la LISTA: %d\n",contarPedidos(lista));
    system("pause");

    int cantidadPedidos = 0;///recordar que este contador va por referencia a la funcion
    RegistroCompraCliente* pedidosMayores5000 = copiarPedidosMayores5000(lista, &cantidadPedidos);
    printf("Cantidad total de pedidos del ARREGLO DINAMICO: %d\n",cantidadPedidos);
    system("pause");

    /// Llamamos a la función para mostrar los pedidos en el arreglo dinámico
    system("cls");
    mostrarPedidos(pedidosMayores5000, cantidadPedidos);
    printf(" ========= FIN DEL ARREGLO DINAMICO CON PEDIDOS >5000 ==========\n");

    /// Liberar la memoria de lista y del arreglo dinámico
    liberarLista(lista);
    free(pedidosMayores5000);

    return 0;
}
