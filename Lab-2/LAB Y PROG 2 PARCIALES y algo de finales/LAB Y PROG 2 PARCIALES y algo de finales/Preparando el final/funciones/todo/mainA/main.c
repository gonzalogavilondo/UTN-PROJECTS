#include <stdio.h>
#include <stdlib.h>






int main()
{
    printf("Hello world!\n");
    return 0;
}





























/////////////***arreglo de arboles*///////////
typedef struct{
    int idSector;
    char sector[30];///los sectores son (y están escritos tal cual): "ropa","muebles","electro"
    int dni;
    char nombreYapellido[40];
    int ventasDiarias;
}stRegistroVendedor;



typedef struct{
    int idSector;
    char sector[30];
}stSector;


typedef struct{
    int dni;
    char nombreYapellido [40];
    int ventasDiarias;
}stVendedor;

typedef struct {
    stVendedor dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;


typedef struct{
    stSector sector;
    nodoArbol *arbolVendedores;
}celda;


/////////////////////////////
int pasarArchivoToADA(celda arreglo[],int  dimension);
int alta(celda arreglo[],int validos, stRegistroVendedor aux);
nodoArbol *crearNodoArbol(stRegistroVendedor aux);
stVendedor cargarDatoArbol (stRegistroVendedor aux);
int buscarPosicion(celda arreglo[],int validos, int idSector);
int agregarSector (celda arreglo[],int validos, int idSector, char sector[]);
nodoArbol *insertarNodo(nodoArbol *arbol, nodoArbol *nuevo);
nodoArbol  *inicArbol();


/////////////////////////////
int main()
{
    printf("Hello world!\n");
    return 0;
}




/**ejercicio 1**/
int pasarArchivoToADA(celda arreglo[],int  dimension){

    int validos=0;
    FILE *buf=fopen("archivoRegistroVendedor.bin","rb");
    stRegistroVendedor aux;

    if(buf){
        while(fread(&aux,sizeof(stRegistroVendedor),1,buf)>0 && validos <dimension){
            validos=alta(arreglo,validos,aux);

        }
        fclose(buf);

    }
    else{
        printf("Error al abrir el archivo \n");
    }


return validos;
}


int alta(celda arreglo[],int validos, stRegistroVendedor aux){

    int pos=buscarPosicion(arreglo,validos,aux.idSector);

    if(pos==-1){
        validos=agregarSector(arreglo,validos,aux.idSector, aux.sector);
        pos=validos-1;

    }
    nodoArbol *nuevo=crearNodoArbol(aux);
    arreglo[pos].arbolVendedores=insertarNodo(arreglo[pos].arbolVendedores,nuevo);

    return validos;
}


nodoArbol *crearNodoArbol(stRegistroVendedor aux){

    nodoArbol *nuevo=malloc(sizeof(nodoArbol));

    nuevo->dato=cargarDatoArbol(aux);
    nuevo->izq= NULL;
    nuevo->der=NULL;

    return nuevo;
}

stVendedor cargarDatoArbol (stRegistroVendedor aux){

    stVendedor nuevo;
    nuevo.dni=aux.dni;
    strcpy(nuevo.nombreYapellido,aux.nombreYapellido);
    nuevo.ventasDiarias=aux.ventasDiarias;

    return nuevo;
}

int buscarPosicion(celda arreglo[],int validos, int idSector){

    int pos=-1;
    int i=0;


    while(i<validos && pos==-1){

        if(arreglo[i].sector.idSector==idSector)
            pos=i;
        i++;
    }
return pos;
}

int agregarSector (celda arreglo[],int validos, int idSector, char sector[]){

    arreglo[validos].sector.idSector=idSector;
    strcpy(arreglo[validos].sector.sector,sector);
    arreglo[validos].arbolVendedores=inicArbol();

    return validos;
}
nodoArbol  *inicArbol(){

    return NULL;
}

nodoArbol *insertarNodo(nodoArbol  *arbol, nodoArbol *nuevo){

  if(!arbol){
    arbol=nuevo;
  }
  else{
     if (nuevo->dato.dni> arbol->dato.dni)
        arbol->der=insertarNodo(arbol->der,nuevo);
     else
        arbol->izq=insertarNodo(arbol->izq,nuevo);
  }
  return arbol;
}

/*ejercicio 2*/

void mostrarADA (celda arreglo[],int validos ){

    int i=0;

    while(i<validos){
        printf("----------------------------------------------------\n");
        printf("Sector %s (ID %i) \n", arreglo[i].sector.sector,arreglo[i].sector.idSector);
        printf("--------------------------------------------------\n");
        printf("--------------------------------------------------\n");
        inorder(arreglo[i].arbolVendedores);
        i++;

    }

}
void inorder(nodoArbol *arbol){

    if(arbol){
        inorder(arbol->izq);
        mostrarVendedor(arbol->dato);
        inorder(arbol->der);
    }
}
void mostrarVendedor(stVendedor aux){
    printf("DNI: %i\n",aux.dni);
    printf("NOMBRE Y APELLIDO: %s\n",aux.nombreYapellido);
    printf("Ventas Diarias : $%i \n",aux.ventasDiarias);
    printf("-----------------------\n");
}

///////// *Ejercicio 3 */////

nodoArbol *buscaVendedorArreglo(celda arreglo[],int validos,int dni){


    int i=0;
    nodoArbol *busc=NULL;

    while(i<validos && !busc){
        busc=buscaVendedorArbol(arreglo[i].arbolVendedores,dni);
        i++

    }
return busc;
}

nodoArbol *buscaVendedorArbol(nodoArbol *arbol, int dni){


    nodoArbol *busc=null;

    if(arbol){
        if(dni==arbol->dato.dni)
            busc=arbol;
        else{
            if (dni>arbol->dato.dni)
                busc=buscaVendedorArbol(arbol->der,dni);
            else
                busc=buscaVendedorArbol(arbol->izq,dni);
        }
    }


return busc;

}


/////////////*Ejercicio 4*/
int cantidadVendedoresSuperiores(celda arreglo[],int validos, int idSector, int ventas){

    int pos=buscarPosicion(arreglo,validos,idSector);

    if(pos!=-1){
        int cantidad= cantidadVendedoresSUperioresSector(arreglo[pos].arbolVendedores,ventas);
        return cantidad;
    }
    else
        return -1;
}
////esta es otra version posible
int cantidadVendedoresSuperioresSector2(nodoArbol *arbol ,int ventas){


    int rta=0;

    if(arbol==NULL){
        rta=0;
    }
    else  {
        if(arbol->dato.ventasDiarias>ventas)
            rta=1+cantidadVendedoresSuperioresSector2(arbol->izq,ventas) +cantidadVendedoresSuperioresSector2(arbol->der, ventas);
        else
            rta=cantidadVendedoresSuperioresSector2(arbol->izq,ventas) +cantidadVendedoresSuperioresSector2(arbol->der, ventas);
    }
return rta;
}

int cantidadVendedoresSuperioresSector(nodoArbol *arbol,int ventas){

 int cantidad=0;

     if(arbol){

        if(arbol->dato.ventasDiarias>ventas){
            cantidad++
            cantidad+=cantidadVendedoresSuperioresSector(arbol->izq,ventas);
            cantidad+=cantidadVendedoresSuperioresSector(arbol->der,ventas);
            }
     }
  return cantidad;
 }


 /////////////////////////arreglo de listas///////////////////////////

 #include <string.h>

const int dimension=10;


///Contenido en el archivo.
typedef struct
{
 int idRegistro;///
 int idProducto;
 char nombreProducto[30];
 char categoria[30];///
 int cantidadStock;
 char fechaExpiracion [11];
} stRegistroProductos;

///Estructuras para la lista.

typedef struct
{
 int idProducto;
 char nombreProducto[30];
 int cantidadStock;
 char fechaExpiracion [11];
} stProducto;


typedef struct nodo
{
 stProducto datos;
 struct nodo* siguiente;
} nodo;

///Estructura del arreglo.
typedef struct
{
    char categoria[30];
    nodo* lista;
}celdaProductos;


nodo* inicLista();

void inicArreglo(celdaProductos* A[],int dimension);
char ingresarCategoria();
stProducto ingresaProducto();

nodo* crearNodo(stProducto p);
///Funciones para agregar a la lista
nodo* buscaUltimoNodo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo);
///Validación de los datos.
int agregarCelda(celdaProductos A[],char categoria[], int validos);
int buscaPosArreglo(celdaProductos A[],char categoria[],int validos);
int alta(celdaProductos A[],stProducto producto,char categoria[], int validos);
int ingresaProductosPorCategoria(celdaProductos A[],int validos,int dimension);
///Mostrar arreglo de productos.
void mostrarUnProducto(stProducto producto);
void mostrarLista(nodo* lista);
void mostrarArreglo(celdaProductos A[],int validos);

int menu();

int main()
{
    celdaProductos array[dimension];  txt
    int validos=0;
    char categoria[30];
    stProducto prod;
    int seleccion;

    do
    {
        seleccion=menu();
        switch(seleccion)
        {
        case 1:
            system("cls");
            validos=ingresaProductosPorCategoria(array,validos,dimension);
            printf("%d",validos);
            mostrarArreglo(array,validos);
            system("PAUSE");
            break;
        case 2:
            system("cls");
            printf("Ingrese nueva categoria:\n");
            fflush(stdin);
            scanf("%s",categoria);
            validos=alta(array,ingresaProducto(),categoria,validos);
            mostrarArreglo(array,validos);
            system("PAUSE");
            break;
        case 0:
            system("cls");
            printf("\n FIN. \n");
            system("PAUSE");

        }
    }while(seleccion!=0);
    return 0;
}

///Menú


int menu()

{
    int input;
    printf("\n Ejercicio 1.\n");
    printf("\n Ejercicio 2.\n");
    printf("\n 0 para finalizar. \n");
    scanf("%d",&input);

    return input;
}
///Inicializo la lista.
nodo* inicLista()
{
    return NULL;
}

///Inicializo el arreglo.
void inicArreglo(celdaProductos* A[],int dimension)
{
    for(int i=0;i<dimension;i++)
    {
        A[i]=NULL;///Como el arreglo es de punteros
    }             ///por definición puedo asignar NULL a sus elementos
}

///Ingreso y validación.

stProducto ingresaProducto()
{
    stProducto p;
    printf("\n Ingrese el id del producto: \n");
    scanf("%d",&p.idProducto);
    printf("\n Ingrese el nombre del producto: \n");
    fflush(stdin);
    scanf("%s",p.nombreProducto);
    printf("\n Ingrese la cantidad en stock del producto: \n");
    scanf("%d",&p.cantidadStock);
    printf("\n Ingrese la fecha de expiracion del producto: \n");
    fflush(stdin);
    scanf("%s",p.fechaExpiracion);

    return p;
}


///Creo nodo de la lista.
nodo* crearNodo(stProducto p)
{
    nodo* aux=(nodo*) malloc(sizeof(stProducto));
    aux->datos=p;
    aux->siguiente=NULL;

    return aux;
}


///Agregar a la lista

nodo* buscarUltimo(nodo* lista)
{
   nodo* seg = lista;
   if(seg != NULL)
      while(seg->siguiente != NULL)
        {
         seg = seg->siguiente;
        }
    return seg;
 }


 nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo)
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


///Busco la posicion de la categoria en el arreglo
int buscaPosArreglo(celdaProductos A[],char categoria[],int validos)

{
    int rta=-1;
    int i=0;
    while (i<validos && rta==-1)
    {
        if(strcmp(A[i].categoria,categoria)==0)
        {
            rta=i;
        }
        i++;
    }
    return rta;
}

///Agrego celda al arreglo.
int agregarCelda(celdaProductos A[], char categoria[],int validos)
{
    strcpy(A[validos].categoria,categoria);
    A[validos].lista=inicLista();
    validos++;

    return validos;
}

///Validacion del producto.

int alta(celdaProductos A[],stProducto producto,char categoria[], int validos)
{
  nodo* aux=crearNodo(producto);
  int pos=buscaPosArreglo(A,categoria,validos);

  if(pos==-1)
  {
      validos=agregarCelda(A,categoria,validos);
      pos=validos-1;
  }
  A[pos].lista=agregarAlFinal(A[pos].lista,aux);

  return validos;
}


int ingresaProductosPorCategoria(celdaProductos A[],int validos,int dimension)
{
  char categoria[30];
  stProducto producto;
  char salir='s';

  while(salir=='s' && validos<dimension)
  {
      printf("\n Ingrese la categoria del producto: \n");
      fflush(stdin);
      scanf("%s",categoria);
      producto=ingresaProducto();
      validos=alta(A,producto,categoria,validos);
      printf("\n ¿Desea continuar? s/n \n");
      fflush(stdin);
      scanf("%c",&salir);
  }
  return validos;
}

///Mostrar arreglo de productos.

void mostrarUnProducto(stProducto producto)
{
    printf(" -------------------------- \n");
    printf(" idProducto            : %d \n" , producto.idProducto);
    printf(" Nombre del producto   : %s \n" , producto.nombreProducto);
    printf(" Cantidad en stock     : %d \n" , producto.cantidadStock);
    printf(" Fecha de expiracion   : %s \n" , producto.fechaExpiracion);
    printf(" -------------------------- \n\n");
}


void mostrarLista(nodo* lista)
{
    nodo* aux=lista;

    while(aux!=NULL)
    {
      mostrarUnProducto(aux->datos);
      aux=aux->siguiente;
    }
}

void mostrarArreglo(celdaProductos A[],int validos)
{
    int i=0;
    printf("\n TODAS LAS CATEGORIAS.\n");
    while(i<validos)
    {
        printf("Categoria: %s\n", A[i].categoria);
        mostrarLista(A[i].lista);
        printf("\n");
        printf("-------------------------");
        printf("\n");
        i++;
    }
}

 ///////////////////////////////////////



///////lista de listas/**********
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



















////****arbol*////

struct nodoArbol
{
int dato;
nodoArbol *izq;
nodoArbol *der;
};



int main()
{
    printf("Hello world!\n");
    return 0;
}


nodoArbol * inicArbol()
{
return NULL;
}
nodoArbol * crearNodoArbol(int dato)
{
nodoArbol * aux = (nodoArbol *) malloc(sizeof( nodoArbol ) );
aux->dato=dato;
aux->der=NULL;
aux->izq=NULL;
return aux;
}

nodoArbol * insertar(nodoArbol * arbol, int dato)
{
if(arbol==NULL)
arbol = crearNodoArbol(dato);
else
{
if(dato>arbol->dato)
arbol->der = insertar(arbol->der, dato);
else
arbol->izq = insertar(arbol->izq, dato);
}
return arbol;
}


void preorder(nodoArbol * arbol)
{
if(arbol != NULL)
{
printf("%d ", arbol->dato);
preorder(arbol->izq);
preorder(arbol->der);
}
}
void inorder(nodoArbol * arbol)
{
if(arbol != NULL)
{
inorder(arbol->izq);
printf("%d ", arbol->dato);
inorder(arbol->der);
}
}

void postorder(nodoArbol * arbol)
{
if(arbol != NULL)
{
postorder(arbol->izq);
postorder(arbol->der);
printf("%d ", arbol->dato);
}
}

nodoArbol * buscar(nodoArbol * arbol, int dato)
{
nodoArbol * rta=NULL;
if(arbol!=NULL)
{
if(dato == arbol->dato)
rta = arbol;
else
if(dato>arbol->dato)
rta = buscar(arbol->der, dato);
else
rta = buscar(arbol->izq, dato);
}
return rta;
}




//***///fin arboll***//


//*///filas*/////

typedef struct{
    int dato;
    struct nodo2* sig;
    struct nodo2 *ant;

}nodo2;


typedef struct {

    struct nodo2* cabecera;   //inicio lista
    struct nodo2* cola;          //final lista
}Fila;







int main()
{
    printf("Hello world!\n");
    return 0;
}

nodo2 *inicLista(){

return NULL;

}

void inicFila(Fila *fila){

    fila->cabecera=inicLista();
    fila->cola=inicLista();
}
///////////
void agregar (Fila *fila, int dato ){

    nodo2 *nuevo=crearNodo(dato);

    if(fila->cabecera==NULL){
        fila->cabecera=nuevo;
        fila->cola=nuevo;
    }
    else{
        fila->cabecera=agregarAlFinal(fila->cabecera,nuevo);
        fila->cola=nuevo;
    }
}


nodo2 *agregarAlFinal(nodo2 *lista, nodo2 *nuevoNodo){

    if(lista==NULL){
        lista=nuevoNodo;
    }
    else{
        nodo2 *ultimo=buscarUltimoDobleRecursivo(lista);
        ultimo->sig=nuevoNodo;
        nuevoNodo->ant=ultimo;
    }
return lista;

}
///////
nodoDoble * buscarUltimoDobleRecursivo (nodoDoble * lista) {
    nodoDoble * rta;
    if (lista==NULL)
        rta=NULL;
    else
        if(lista->siguiente==NULL)
            rta=lista;
        else
            rta=buscarUltimoDobleRecursivo(lista->siguiente);
return rta;
/////
nodoDoble * crearNodoDoble (persona dato) {
    nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
    aux->dato = dato;
    //asigna valor NULL a los campos que contienen la dirección de memoria
    //de los nodos anterior y siguiente
    aux->ant = NULL;
    aux->sig = NULL;
return aux;
}


/////////////
nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo) {
nuevo->siguiente = lista;
if(lista != NULL)
lista->anterior=nuevo;
return nuevo;
}

//////////////////
int extraer(Fila *fila){

    int resp;

    if(fila->cabecera!=NULL){
        resp=verPrimer(fila->cabecera);
        fila->cabecera=borrarPrimero(fila->cabecera);
        if(fila->cabecera==NULL){
            fila->cola=inicLista();
        }
    }
return resp;
}


int verPrimero(nodo2 *lista){


    int rta=0;
    if (lista)
        rta=lista->dato;

return rta;
}

nodo2 *borrarPrimero(nodo2 *lista){

    nodo2 *aBorrar=lista;

    if(lista!=NULL){
        lista=lista->sig;
        if(lista!=NULL)
            lista->ant=NULL;
       free(aBorrar);
    }
return lista;


}

/****fin filas*///


/****lista doble*////

typedef struct {
char nombre[20];
int edad;
} persona;

typedef struct {
persona dato;
struct nodoDoble * anterior;
struct nodoDoble * siguiente;
} nodoDoble;





int main()
{
    nodoDoble * listaDoble ;
    return 0;
}



nodoDoble * inicListaDoble() {
return NULL;
}


nodoDoble * crearNodoDoble (persona dato) {
nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
aux->dato = dato;
//asigna valor NULL a los campos que contienen la dirección de memoria
//de los nodos anterior y siguiente
aux->anterior = NULL;
aux->siguiente = NULL;
return aux;
}



nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo) {
nuevo->siguiente = lista;
if(lista != NULL)
lista->anterior=nuevo;
return nuevo;
}




nodoDoble * buscarUltimoDobleRecursivo (nodoDoble * lista) {
nodoDoble * rta;
if (lista==NULL)
rta=NULL;
else
if(lista->siguiente==NULL)
rta=lista;
else
rta=buscarUltimoDobleRecursivo(lista->siguiente);
return rta;
}



nodoDoble * agregarFinalDoble(nodoDoble * lista, nodoDoble * nuevo) {
if(lista == NULL) {
lista = nuevo;
} else {
nodoDoble * ultimo = buscarUltimoDobleRecursivo(lista);
ultimo->siguiente = nuevo;
nuevo->anterior = ultimo;
}
return lista;
}




nodoDoble * agregarEnOrdenDoble (nodoDoble * lista, nodoDoble * nuevo) {
if(lista == NULL) {
lista = nuevo;
}else {
if(strcmp(nuevo->dato.nombre,lista->dato.nombre)<0){
lista = agregarPpioDoble(lista, nuevo);
} else {
// se puede recorrer la lista utilizando un solo puntero??
nodoDoble * ante = lista;
nodoDoble * seg = lista->siguiente;
while((seg != NULL)
&&(strcmp(nuevo->dato.nombre,seg->dato.nombre)>0)) {
ante = seg;
seg = seg->siguiente;
}
ante->siguiente = nuevo;
nuevo->anterior = ante;
nuevo->siguiente = seg;
if (seg!=NULL)
seg->anterior=nuevo;
}
}
return lista;
}

/*** fin lista doble *///


/*** lista simple *///


typedef struct {
char nombre[20];
int edad;
} persona

typedef struct {
persona dato;
struct nodo * siguiente;
} nodo;


int main()
{
    printf("Hello world!\n");
    return 0;
}



nodo * inicLista() {
return NULL;
}

nodo * crearNodo (persona dato) {
//crea un puntero de tipo nodo
nodo * aux = (nodo*) malloc(sizeof(nodo));
//asigna valores a sus campos de información
aux->dato = dato;
//asigna valor NULL al campo que contiene la dirección de memoria del
//siguiente nodo
aux->siguiente = NULL;
//retorna la dirección de memoria del nuevo nodo, que deberá ser
asignada a una variable de tipo "puntero a nodo".
return aux;
}




nodo * agregarPpio (nodo * lista, nodo * nuevoNodo) {
//si la lista está vacía, ahora apuntará al nuevo nodo.
if(lista == NULL) {
lista = nuevoNodo;
}else
//si la lista no está vacía, inserta el nuevo nodo al comienzo de la
//misma, y el viejo primer nodo pasa a ser el segundo de la lista.
{
nuevoNodo->siguiente = lista;
lista = nuevoNodo;
}
return lista;
}



nodo * buscarUltimo(nodo * lista) {
nodo * seg = lista;
if(seg != NULL)
while(seg->siguiente != NULL) {
seg = seg->siguiente;
}
return seg;
}



nodo * buscarNodo(nodo * lista, char nombre[20]) {
//busca un nodo por nombre y retorna su posición de memoria
//si no lo encuentra retorna NULL.
nodo * seg; //apunta al nodo de la lista que está siendo procesado
seg = lista; //con esto evito cambiar el valor de la variable
//lista, que contiene un puntero al primer nodo de la
//lista vinculada
while ((seg != NULL) && ( strcmp(nombre, seg->dato.nombre)!=0 )) {
//busco mientras me quede lista por recorrer y no haya encontrado el nombre
seg=seg->siguiente; //avanzo hacia el siguiente nodo.
}
//en este punto puede haber fallado alguna de las dos condiciones
//del while. si falla la primera es debido a que no encontró lo
//que buscaba (seg es NULL), si falla la segunda es debido a que se
//encontró el nodo buscado.
return seg;
}




nodo * agregarFinal(nodo * lista, nodo * nuevoNodo) {
if(lista == NULL) {
lista = nuevoNodo;
} else {
nodo * ultimo = buscarUltimo(lista);
ultimo->siguiente = nuevoNodo;
}
return lista;
}



nodo * borrarNodo(nodo * lista, char nombre[20]) {
nodo * seg;
nodo * ante; //apunta al nodo anterior que seg.
if((lista != NULL) && (strcmp(nombre, lista->dato.nombre)==0 )) {
nodo * aux = lista;
lista = lista->siguiente; //salteo el primer nodo.
free(aux); //elimino el primer nodo.
}else {
seg = lista;
while((seg != NULL) && (strcmp(nombre, seg->dato.nombre)!=0 )) {
ante = seg; //adelanto una posición la variable ante.
seg = seg->siguiente; //avanzo al siguiente nodo.
}
//en este punto tengo en la variable ante la dirección de
//memoria del nodo anterior al buscado, y en la variable seg,
//la dirección de memoria del nodo que quiero borrar.
if(seg!=NULL) {
ante->siguiente = seg->siguiente;
//salteo el nodo que quiero eliminar.
free(seg);
//elimino el nodo.
}
}
return lista;
}




nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo) {
// agrega un nuevo nodo a la lista manteniendo el orden.
//si la lista está vacía agrego el primer elemento.
if(lista == NULL) {
lista = nuevoNodo;
}else {
//si el nuevo elemento es menor que el primero de la lista,
//agrego al principio
if(strcmp(nuevoNodo->dato.nombre,lista->dato.nombre)<0){
lista = agregarPpio(lista, nuevoNodo);
} else {
//busco el lugar en donde insertar el nuevo elemento.
//necesito mantener la dirección de memoria del nodo anterior
//al nodo que tiene un nombre mayor al del nuevo nodo.
nodo * ante = lista;
nodo * seg = lista->siguiente;
while((seg != NULL)
&&(strcmp(nuevoNodo->dato.nombre,seg->dato.nombre)>0)) {
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


nodo * borrarTodaLaLista(nodo * lista) {
nodo * proximo;
nodo * seg;
seg = lista;
while(seg != NULL) {
proximo = seg->siguiente; //tomo la dir del siguiente.
free(seg); //borro el actual.
seg = proximo; //actualizo el actual con la dir del
//siguiente, para avanzar.
}
return seg; // retorna NULL a la variable lista del main()
}

int sumarEdadesLista(nodo * lista) {
//recorro la lista y sumo las edades de los socios.
int suma = 0;
nodo * seg = lista;
while (seg != NULL) {
suma = suma + seg->dato.edad;
seg = seg->siguiente;
}
return suma;
}


/*** fin lista simple *///
