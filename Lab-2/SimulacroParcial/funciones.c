#include "declaraciones.h"

NodoPedido* inicLista()
{
    return NULL;
}

/**
   1.Crear la función (crearNodoPedido), que reciba como parámetro un registro de tipo RegistroCompraCliente, y
    devuelva un nodo de tipo nodoPedido
**/

NodoPedido* crearNodoPedido(RegistroCompraCliente registro)
{
    NodoPedido *nuevo = (NodoPedido*) malloc(sizeof(NodoPedido));
    if(nuevo == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }

    nuevo->NroPedido = registro.NroPedido;
    nuevo->MontoCompra = registro.MontoCompra;
    nuevo->cliente.NroCliente = registro.NroCliente;
    strcpy(nuevo->cliente.NyA, registro.NyA);
    nuevo->siguiente = NULL;

    return nuevo;
}

/**
    2.Crear la función (agregarNodoPedido), que reciba la lista y un registro del tipo RegistroCompraCliente y agregue ese
    nodo al final de la lista. Retornar la lista.
**/
NodoPedido* agregarNodoPedido(NodoPedido *lista, RegistroCompraCliente registro)
{

    NodoPedido *nuevo = crearNodoPedido(registro); ///Creo el nodo con la funcion anterior, con el registro que paso por parametro

    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        NodoPedido *ultimo = buscaUltimoLista(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

NodoPedido* buscaUltimoLista(NodoPedido *lista)
{
    NodoPedido *seg = lista; ///seg es seguidor
    if(seg != NULL) ///Lista esta vacia?
    {
        while(seg->siguiente != NULL) ///Recorro la lista
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}

/**
    3.Crear una función (crearListaPedidos) que permita recorrer el archivo y crear la lista de pedidos. La función puede
    recibir como parámetro el nombre del archivo o puede no recibiré ese parámetro si así lo prefiere. Retornar la lista
**/

NodoPedido* crearListaPedidos(const char *nombreArchivo)
{
    NodoPedido *lista = inicLista();
    RegistroCompraCliente pedidoNuevo; //Registro donde voy a guardar lo levantado
    FILE *archivo = fopen(nombreArchivo, "rb");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        exit(1); // Codigo de error
    }

    rewind(archivo);
    while(fread(&pedidoNuevo, sizeof(pedidoNuevo), 1, archivo) > 0) //fread devuelve el numero de datos leidos
    {
        lista = agregarAlFinalPedido(lista, crearNodoPedido(pedidoNuevo));
    }
    fclose(archivo);
    return lista;
}

NodoPedido* agregarAlFinalPedido(NodoPedido *nuevo, NodoPedido *lista)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        NodoPedido *ultimo = buscaUltimoLista(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

/**
    4.Crear una función (mostrarLista) que permita recorrer y mostrar la lista. La misma debe ser recursiva
**/

void mostrarUnNodo(NodoPedido *aux)
{
    if (aux != NULL)
    {
        printf("Numero de cliente: %d\n", aux->cliente.NroCliente);
        printf("Nombre y apellido: %s\n", aux->cliente.NyA);
        printf("Numero de la compra: %d\n", aux->NroPedido);
        printf("Monto de la compra: %.2f\n", aux->MontoCompra);
        puts("\n");
    }
    else
    {
        printf("Nodo no válido.\n");
    }
}

void mostrarLista(NodoPedido *lista)
{
    if(lista != NULL)
    {
        mostrarUnNodo(lista);
        mostrarLista(lista->siguiente);
    }
}

/**
    5.Crear la función (liberarLista), que reciba la lista y hacer lo indicado. La función no debe retornar nada (no importa que
    la cabecera no quede en NULL)
**/

NodoPedido* liberarLista(NodoPedido *lista)
{
    NodoPedido *proximo;
    NodoPedido *seg = lista;

    while(seg != NULL)
    {
        proximo = seg->siguiente; ///tomo la dir del siguiente.
        free(seg); ///borro el actual.
        seg = proximo; ///actualizo el actual con la dir del siguiente, para avanzar.
    }
    return seg; ///retorna NULL a la variable lista del main()
}

/**
    6.Crear la función (ingresarPedido), la cual recibirá la lista y solicitará al usuario los datos del pedido para finalmente
    agregar ese pedido a la lista y retornar la lista. Modularizar de ser conveniente.
**/

NodoPedido* ingresarPedido(NodoPedido *lista)
{
    RegistroCompraCliente registro;


    printf("Ingrese el numero del cliente: ");
    scanf("%d", &registro.NroCliente);
    printf("Ingrese el monto de la compra: ");
    scanf("%f", &registro.MontoCompra);
    printf("Ingrese el numero del pedido: ");
    scanf("%d", &registro.NroPedido);
    printf("Ingrese el nombre y apellido: ");
    fflush(stdin);
    gets(registro.NyA);
    lista = agregarNodoPedido(lista, registro); ///Finalmente agrego el pedido a la lista

    return lista;
}


/**
    7.Crear la función recursiva (calcularTotalMontoCompra), la cual retornará un float con el monto total de las compras y
    recibirá por parámetro la lista
**/

float calcularTotalMontoCompra(NodoPedido *lista)
{
    float resultado;
    if(lista != NULL)
    {
        resultado = lista->MontoCompra + calcularTotalMontoCompra(lista->siguiente);
    }
    return resultado;
}


/**
    8.Crear la función (copiarPedidosMayores5000) la cual recibirá como parámetros la lista y la cantidad de pedidos (como
    puntero) y a partir de esa info, deberá crear un arreglo dinámico de tipo RegistroCompraCliente con todos los pedidos
    de monto superior a 5000. Retornar un puntero al arreglo creado y actualizar el puntero recibido como parámetro
    (para saber cuántos pedidos se almacenaron el arreglo). Modularizar si lo considera necesario.
**/

RegistroCompraCliente* copiarPedidosMayores5000(NodoPedido *lista, int *cntPedidos)
{
    int cntAux = 0;
    RegistroCompraCliente* pedidosMayores5000 = (RegistroCompraCliente*)malloc(*cntPedidos * sizeof(RegistroCompraCliente));
    while(lista != NULL)
    {
        if(lista->MontoCompra > 5000)
        {
            lista2array(lista, &pedidosMayores5000[cntAux]);
            cntAux++;
        }
        lista = lista->siguiente;
    }
    pedidosMayores5000 = (RegistroCompraCliente*)realloc(pedidosMayores5000, cntAux * sizeof(RegistroCompraCliente));

    return pedidosMayores5000;
}

void lista2array(NodoPedido *lista, RegistroCompraCliente *registro)
{

    registro->MontoCompra = lista->MontoCompra;
    registro->NroCliente = lista->cliente.NroCliente;
    strcpy(registro->NyA, lista->cliente.NyA);
    registro->NroPedido = lista->NroPedido;
}
