#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct persona
{
    int nroCliente;
    char nombre_apellido [30];
    int cantProductos;
}persona;

typedef struct nodo
{
    persona dato;
    struct nodo * siguiente;
}nodo;
typedef struct caja
{
    int nroCaja;
    char medio_Pago [30];
}caja;

typedef struct nodoCaja
{
    caja c;
    nodo * listaClientes;
    struct nodoCaja * siguiente;
}nodoCaja;

///DECLARACION DE FUNCIONES:

///FUNCIONES BASICAS PARA EL MANEJO DE LISTAS:
nodoCaja * inicListaCaja();
nodoCaja * crearNodoCaja(caja c); /// hace uso de la estrucutra persona... pero es de funcionamiento básico del tda
nodoCaja * agregarPpioCaja(nodoCaja * lista, nodoCaja * nuevoNodo);
nodoCaja * alta (nodoCaja *listaCajas, nodo * nuevoCliente, int nroCaja);
nodoCaja * buscarCaja(nodoCaja * lista, int nroCaja);
caja ingresarCaja(int);
void recorrerYmostrarCajasClientes(nodoCaja * lista);
void mostrarNodoCaja(nodoCaja * c);



///DECLARACION DE FUNCIONES:

///FUNCIONES BASICAS PARA EL MANEJO DE LISTAS:
nodoCaja * inicListaCaja();
nodoCaja * crearNodoCaja(); /// hace uso de la estrucutra persona... pero es de funcionamiento básico del tda
nodoCaja * agregarPpioCaja(nodoCaja * lista, nodoCaja * nuevoNodo);


///DECLARACION DE FUNCIONES:

///FUNCIONES BASICAS PARA EL MANEJO DE LISTAS:
nodo * inicLista();
nodo * crearNodo(persona dato); /// hace uso de la estrucutra persona... pero es de funcionamiento básico del tda
nodo * agregarPpio(nodo * lista, nodo * nuevoNodo);
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
nodo * borrarTodaLaLista(nodo * lista);
nodo * eliminaUltimoNodo(nodo * lista);
nodo * eliminaPrimerNodo(nodo * lista);
void recorrerYmostrarClientes(nodo * lista);

/// funciones que hacen uso de la estructura persona
void mostrarNodo(nodo * aux);
nodo * buscarNodo(nodo * lista, char nombre[20]);
nodo * borrarNodo(nodo * lista, char nombre[20]);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);
nodoCaja * ingresarCajas(nodoCaja *lista);

int main()
{
    nodoCaja * listaCajaClientes = inicListaCaja();
    listaCajaClientes = ingresarCajas(listaCajaClientes);
    recorrerYmostrarCajasClientes(listaCajaClientes);
}

nodoCaja * ingresarCajas(nodoCaja *lista)
{
char continuar='s';
persona p;
int nroDeCaja;

    while(continuar=='s')
    {
        printf("\nIngresar Nro de Cliente:  ");
        fflush(stdin);
        scanf("%d", &p.nroCliente);

        printf("\nIngresar NOMBRE Y APELLIDO del Cliente:  ");
        fflush(stdin);
        gets(p.nombre_apellido);

        printf("\nIngresar CANTIDAD DE Producto:  ");
        fflush(stdin);
        scanf("%d", &p.cantProductos);

        printf("\n¿A QUE NUMERO DE CAJA DESEA INGRESAR EL CLIENTE?  \n");
        fflush(stdin);
        scanf("%d", &nroDeCaja);

        nodo * cliente = crearNodo(p);
        lista = alta(lista,cliente,nroDeCaja);

        printf("\n\nDesea continuar presione s:  ");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n\n");
    }
return lista;
}

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(persona dato)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->dato= dato;
    aux->siguiente = NULL;
    return aux;
}

nodo * agregarPpio(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodo * agregarFinal(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;
    if(seg)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * proximo;
    nodo * seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;//tomo la dir del siguiente.
        free(seg);//borro el actual.
        seg = proximo;//actualizo el actual con la dir del siguiente, para avanzar
    }
    return seg;
}

void recorrerYmostrarClientes(nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        mostrarNodo(seg);
        seg= seg->siguiente;
    }
}

nodo * eliminaUltimoNodo(nodo * lista)
{
    nodo * aux;
    nodo * ante;

    if(lista)
    {
        if(lista->siguiente==NULL) /// la lista tiene un solo nodo
        {
            aux=lista;
            lista=lista->siguiente;
            free(aux);
        }
        else  /// la lista tiene mas de un nodo
        {
            aux=lista;
            while(aux->siguiente!=NULL)
            {
                ante=aux;
                aux=aux->siguiente;
            }
            free(aux);
            ante->siguiente=NULL;
        }
    }
    return lista;
}

nodo * eliminaPrimerNodo(nodo * lista)
{
    nodo * aux=lista;
    if(lista)
    {
        lista=lista->siguiente;
        free(aux);
    }
    return lista;
}

/** //////////////////////////////////////////////////*/
/// funciones que usan la estructura de persona
/** //////////////////////////////////////////////////*/
void mostrarPersona(persona dato)
{
    printf("-----------------------\n");
    printf("Nombre: %s \n", dato.nombre_apellido);
    printf("  Cantidad de Productos: %d \n", dato.cantProductos);
    printf("-----------------------\n");
}

persona cargarPersona()
{
    persona aux;
    fflush(stdin);
    printf("Ingrese Nro de Cliente: ");
    scanf("%d", &aux.nroCliente);
    fflush(stdin);
    printf("Ingrese nombre y apellido: ");
    gets(aux.nombre_apellido);
    fflush(stdin);
    printf("Ingrese Cantidad de productos:");
    scanf("%d", &aux.cantProductos);

    return aux;
}

void mostrarNodo(nodo * aux)
{
    mostrarPersona(aux->dato);
}

nodo * buscarNodo( nodo * lista, char nombre[20])
///busca un nodo por nombre y retorna su posici¢n de memoria
///si no lo encuentra retorna NULL.
{
    nodo * seg;
    seg = lista;
    while ((seg != NULL) && ( strcmp(nombre, seg->dato.nombre_apellido)!=0 ))
    {
        seg=seg->siguiente;
    }
    return seg;
}

nodo * borrarNodo(nodo * lista, char nombre[20])
{
    nodo * seg;
    nodo * ante;	//apunta al nodo anterior que seg.

    if((lista != NULL) && (strcmp(nombre, lista->dato.nombre_apellido)==0 ))
    {
        nodo * aux = lista;
        lista = lista->siguiente; //salteo el primer nodo.
        free(aux); //elimino el primer nodo.
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->dato.nombre_apellido)!=0 ))
        {
            ante = seg;	//adelanto una posicion la var ante.
            seg = seg->siguiente; //avanzo al siguiente nodo.
        }
        //en este punto tengo en la variable ante la direccion de memoria del
        //nodo anterior al buscado, y en la variable seg, la dir de memoria del
        //nodo que quiero borrar.
        if( seg!= NULL)
        {
            ante->siguiente = seg->siguiente; //salteo el nodo que quiero eliminar.
            free(seg); //elimino el nodo.
        }
    }
    return lista; //debo retornar el puntero al primer nodo, por el tipo de pasaje de parametros.
    //No puedo modificar el contenido de la var lista, que no es lo mismo
    //que modificar *lista (contenido de la direccion de memoria apuntada
    //por lista.
    //Otra forma de resolverlo es poner el par metro **lista. :)
}

nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)
// agrega un nuevo nodo a la lista manteniendo el orden.
{
    //Si la lista esta vacia agrego el primer elemento.
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        // si el nuevo elemento es menor que el primero de la lista,
        // agrego al principio.
        if(strcmp(nuevoNodo->dato.nombre_apellido,lista->dato.nombre_apellido)<0)
            lista = agregarPpio(lista, nuevoNodo);
        else
        {
            // busco el lugar en donde insertar el nuevo elemento.
            // necesito mantener la direccion de memoria del nodo anterior
            // al nodo que tiene un nombre mayor al del nuevo nodo.
            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            while( (seg != NULL)&&(strcmp(nuevoNodo->dato.nombre_apellido,seg->dato.nombre_apellido)>=0) )
            {
                ante = seg;
                seg = seg->siguiente;
            }
            // inserto el nuevo nodo en el lugar indicado.
            nuevoNodo->siguiente = seg;
            ante->siguiente = nuevoNodo;
        }
    }
    return lista;

}
nodoCaja * inicListaCaja()
{
    return NULL;
}

nodoCaja * crearNodoCaja(caja c)
{
    nodoCaja * aux = (nodoCaja*)malloc(sizeof(nodo));
    aux->c = c;
    aux->listaClientes = inicLista();
    aux->siguiente = NULL;
    return aux;
}

nodoCaja * agregarPpioCaja(nodoCaja * lista, nodoCaja * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodoCaja * alta (nodoCaja *listaCajas, nodo * nuevoCliente, int nroCaja)
{
    nodoCaja *cajaEncontrada = buscarCaja(listaCajas,nroCaja);
    if(cajaEncontrada==NULL)
    {
        caja c = ingresarCaja(nroCaja);
        nodoCaja *nuevaCaja = crearNodoCaja(c);
        listaCajas = agregarPpioCaja(listaCajas, nuevaCaja);
        listaCajas->listaClientes = agregarFinal(listaCajas->listaClientes, nuevoCliente);
    }
    else
    {
        cajaEncontrada->listaClientes = agregarFinal(cajaEncontrada->listaClientes, nuevoCliente);
    }
return listaCajas;
}

nodoCaja * buscarCaja(nodoCaja * lista, int nroCaja)
{
    nodoCaja * seg = lista;
    nodoCaja *cajaEncontrada = NULL;
    int flag = 0;
        while(seg!= NULL && flag == 0)
        {
            if(seg->c.nroCaja == nroCaja)
            {
                cajaEncontrada = seg;
                flag=1;
            }
            seg = seg->siguiente;
        }
    return cajaEncontrada;
}

caja ingresarCaja(int nroCaja)
{
    caja c;
    c.nroCaja = nroCaja;
    printf("Ingresar Medio de Pago: \n");
    fflush(stdin);
    scanf("%s", c.medio_Pago);
return c;
}

void recorrerYmostrarCajasClientes(nodoCaja * lista)
{
    nodoCaja * seg = lista;
    while (seg != NULL)
    {
        mostrarNodoCaja(seg);
        recorrerYmostrarClientes(seg->listaClientes);
        seg= seg->siguiente;
    }
}

void mostrarNodoCaja(nodoCaja * c)
{
    printf("Nro de Caja: %d\n", c->c.nroCaja);
    printf("Medio de Pago: %s", c->c.medio_Pago);
}



