#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* registro disfraz */
typedef struct
{
    int idSucursal;
    char nombreSucursal[25];
    char nombreDisfraz[25];
    char generoDisfraz[25];
    int stockDisfraz;

}stRegistroDisfraz;

/* estructura de sucursual */
typedef struct{

    int idSucursal;
    char nombreSucursal[25];

}stSucursal;

/* estructura de disfraz */
typedef struct{
    char nombreDisfraz[25];
    char generoDisfraz[25];
    int stockDisfraz;
}Disfraz;

/* estructura del árbol */
typedef struct
{
    Disfraz disfraz;
    struct nodoArbol* izquierda;
    struct nodoArbol* derecha;

}nodoArbol;

/* estructura de la lista */
typedef struct
{
    stSucursal sucursal;
    nodoArbol* arbol;
    struct nodoLista* siguiente;

}nodoLista;


/* FUNCIONES DE LISTA */
nodoLista* inicLista(nodoLista* lista);
nodoLista* crearNodoLista(stSucursal sucursal);
void mostrarUnaScursal(stSucursal sucursal);
void mostrarListaSucursal(nodoLista* lista);
nodoLista* agregarPrincipioLista(nodoLista* lista , nodoLista* nuevoNodo);
nodoLista* buscarSucursalPorID(nodoLista* lista , int idSucursal);
/* ************************************************************ */

/* FUNCIONES DE ARBOL */
nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(Disfraz disfrazito);
nodoArbol* insertarNodo(nodoArbol* arbol , nodoArbol* nuevoNodo);
void mostrarUnDisfraz(Disfraz d);
void mostrarArbolInOrder(nodoArbol* arbol);
/* ************************************************************ */

/* FUNCIONES DEL PUNTO 1 */
nodoLista* pasarArchToLda(char nombreArchivo[] , nodoLista* lista);
stRegistroDisfraz cargaUnaSucursal(int idSucursal , char nombreSucursal[]);
Disfraz cargaUnDisfraz(char nombreDisfraz[] , char generoDisfraz[] , int stockDisfraz);
nodoLista* cargaListaArboles(nodoLista* lista , stSucursal sucur , Disfraz disfrazito);

/* FUNCIÓN DEL PUNTO 2 */
void mostrarLda(nodoLista* lista);

/* FUNCIONES DEL PUNTO 3 */
Disfraz buscarDisfraz(nodoArbol* arbol , char nombreDisfraz[] , char generoDisfraz[]);
int cargaArrayDisfraces(nodoArbol* arbol , Disfraz arrayDisfraces[] , int dimension);
void mostrarArrayDisfraces(Disfraz arrayDisfraces[] , int validos);

/* FUNCIONES DEL PUNTO 4 */
int contarDisfracesPorGenero(nodoArbol* arbol , char generoDisfraz[]);
stSucursal buscarMenorStockSucursal(nodoArbol* arbol ,  char generoDisfraz);



int main()
{


    return 0;
}

/* +++++++++++++++++++++++++++++++++++++++++++ */

/* TDA LISTAS */

/* inicializa la lista */
nodoLista* inicLista(nodoLista* lista)
{
    return NULL;
}

/* crea un nodo de lista */
nodoLista* crearNodoLista(stSucursal sucursal)
{
    nodoLista* auxNodo = (nodoLista*)malloc(sizeof(nodoLista));

    auxNodo->sucursal = sucursal;
    auxNodo->arbol = inicArbol();
    auxNodo->siguiente = NULL;

    return auxNodo;
}

/* agrea al principio de la lista */
nodoLista* agregarPrincipioLista(nodoLista* lista , nodoLista* nuevoNodo)
{
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }

    return lista;
}

/* muesta una sucursal */
void mostrarUnaScursal(stSucursal sucursal)
{
    printf(" *********************** \n");
    printf(" ID Sucursal: %d \n" , sucursal.idSucursal);
    printf(" Nombre de la sucursal: %s \n" , sucursal.nombreSucursal);
    printf(" *********************** \n\n");
}

void mostrarListaSucursal(nodoLista* lista)
{
    nodoLista* seguidora = lista;

    while(seguidora != NULL){
        mostrarUnaScursal(seguidora->sucursal);
        seguidora = seguidora->siguiente;
    }
}

/* busca la sucursal por ID */
nodoLista* buscarSucursalPorID(nodoLista* lista , int idSucursal)
{
    nodoLista* encontrada = NULL;
    nodoLista* seguidora = lista;

    while((encontrada == NULL) && (seguidora != NULL)){
        if(seguidora->sucursal.idSucursal == idSucursal){
            encontrada = seguidora;
        }

        seguidora = seguidora->siguiente;
    }

    return encontrado;
}

/* +++++++++++++++++++++++++++++++++++++++++++ */

/* +++++++++++++++++++++++++++++++++++++++++++ */

/* TDA ÁRBOLES */

/* inicializa el árbol */
nodoArbol* inicArbol()
{
    return NULL;
}

/* crea un nodoArbol */
nodoArbol* crearNodoArbol(Disfraz disfrazito)
{
    nodoArbol* auxNodoArbol = (nodoArbol*)malloc(sizeof(nodoArbol));

    auxNodoArbol->disfraz = disfrazito;
    auxNodoArbol->izquierda = NULL;
    auxNodoArbol->derecha = NULL;

    return auxNodoArbol;
}

/*  inserta un nodo al árbol , como critero de ordenación: nombre del disfráz */
nodoArbol* insertarNodo(nodoArbol* arbol , nodoArbol* nuevoNodo)
{
    if(arbol == NULL){
        arbol = nuevoNodo;
    }else{
        if(strcmpi(nuevoNodo->disfraz.nombreDisfraz , arbol->disfraz.nombreDisfraz) <= 0){
            arbol->izquierda = insertarNodo(arbol->izquierda , nuevoNodo);
        }else{
            arbol->derecha = insertarNodo(arbol->derecha , nuevoNodo);
        }
    }

    return arbol;
}

/* muestra un disfráz */
void mostrarUnDisfraz(Disfraz d)
{
    printf(" -------------------------- \n");
    printf(" Nombre del disfraz: %s \n" , d.nombreDisfraz);
    printf(" Genero del disfraz: %s \n" , d.generoDisfraz);
    printf(" Stock del disfraz: %d \n" , d.stockDisfraz);
    printf(" -------------------------- \n");
}

void mostrarArbolInOrder(nodoArbol* arbol)
{
    if(arbol != NULL){
        mostrarArbolInOrder(arbol->izquierda);
        mostrarUnDisfraz(arbol->disfraz);
        mostrarArbolInOrder(arbol->derecha);
    }
}

/* +++++++++++++++++++++++++++++++++++++++++++ */

/* ---------------------------------------- FUNCIONES - PUNTO 1  ---------------------------------------- */

/* ----------------------- FUNCIONES PRINCIPALES ----------------------- */

/* carga la lista de árboles */
nodoLista* pasarArchToLda(char nombreArchivo[] , nodoLista* lista)
{
    stRegistroDisfraz aux;
    FILE* pArchivo = fopen(nombreArchivo , "rb");
    stSucursal sucu;
    Disfraz disfrazito;

    if(pArchivo != NULL){
        while(fread(&aux , sizeof(stRegistroDisfraz) , 1 , pArchivo) > 0){
            sucu = cargaUnaSucursal(aux.idSucursal , aux.nombreSucursal);
            disfrazito = cargaUnDisfraz(aux.nombreDisfraz , aux.generoDisfraz , aux.stockDisfraz);

            lista = cargaListaArboles(lista , sucu , disfrazito);
        }
        fclose(pArchivo);
    }else{
        printf(" ERROR en la lectura del archivo. \n\n");
    }
}

/* carga los datos de una sucursal */
stRegistroDisfraz cargaUnaSucursal(int idSucursal , char nombreSucursal[])
{
    stSucursal sucu;

    sucu.idSucursal = idSucursal;
    strcpy(sucu.nombreSucursal , nombreSucursal);

    return sucu;
}

/* carga los datos del disfraz */
Disfraz cargaUnDisfraz(char nombreDisfraz[] , char generoDisfraz[] , int stockDisfraz)
{
    Disfraz disfrazito;

    strcpy(disfrazito.nombreDisfraz , nombreDisfraz);
    strcpy(disfrazito.generoDisfraz , generoDisfraz);
    disfrazito.stockDisfraz = stockDisfraz;

    return disfrazito;
}

/* agrega un nuevo disfraz en la sucursal correspondiente */
nodoLista* cargaListaArboles(nodoLista* lista , stSucursal sucur , Disfraz disfrazito)
{
    nodoLista* encontrada;
    nodoArbol* nuevoNodo = crearNodoArbol(disfrazito);

    encontrada = buscarSucursalPorID(lista , sucur.idSucursal);

    if(encontrada == NULL){
        nodoLista* nuevaSucursal = crearNodoLista(sucur);
        lista = agregarPrincipioLista(lista , nuevaSucursal);
        encontrada = lista;
    }

    encontrada->arbol = insertarNodo(encontrada->arbol , nuevoNodo);

    return lista;
}

/* --------------------------------------------------------------------------------- */


/* --------------------------------------- FIN FUNCIONES - PUNTO 1 --------------------------------------- */





/* ---------------------------------------- FUNCION - PUNTO 2  ---------------------------------------- */

void mostrarLda(nodoLista* lista)
{
    nodoLista* seguidora = lista;

    while(seguidora != NULL){
        mostrarUnaScursal(seguidora->sucursal);
        mostrarArbolInOrder(seguidora->arbol);
        seguidora = seguidora->siguiente;
    }
}

/* --------------------------------------- FIN FUNCION - PUNTO 2 --------------------------------------- */




/* ---------------------------------------- FUNCIONES - PUNTO 3  ---------------------------------------- */

/* busca un disfraz determinado */
Disfraz buscarDisfraz(nodoArbol* arbol , char nombreDisfraz[] , char generoDisfraz[])
{
    Disfraz encontrado;

    if(arbol != NULL){
        if((strcmpi(arbol->disfraz.nombreDisfraz , nombreDisfraz) == 0) && (strcmpi(arbol->disfraz.generoDisfraz , arbol->disfraz.generoDisfraz) == 0)){
            encontrado = arbol->disfraz;
        }else{
            encontrado = buscarDisfraz(arbol->izquierda , nombreDisfraz , generoDisfraz);
            encontrado = buscarDisfraz(arbol->derecha , nombreDisfraz , generoDisfraz);
        }
    }

    return encontrado;
}

/* carga el array de disfrazes  */
int cargaArrayDisfraces(nodoArbol* arbol , Disfraz arrayDisfraces[] , int dimension)
{
    int i;

    Disfraz disfrazito = buscarDisfraz(arbol , arbol->disfraz.nombreDisfraz , arbol->disfraz.generoDisfraz);

    for(i=0 ; i<dimension ; i++){
       arrayDisfraces[i] = disfrazito;
    }

    return i;
}

/* muestra el arrego de disfraces */
void mostrarArrayDisfraces(Disfraz arrayDisfraces[] , int validos)
{
    int i;

    for(i=0 ; i<validos ; i++){
        mostrarUnDisfraz(arrayDisfraces[i]);
    }
}

/* --------------------------------------- FIN FUNCIONES - PUNTO 3 --------------------------------------- */




/* ---------------------------------------- FUNCIONES - PUNTO 4  ---------------------------------------- */

/* cuenta el stock de disfraces de un determinado género */
int contarDisfracesPorGenero(nodoArbol* arbol , char generoDisfraz[])
{
    int stockTotal = 0;

    if(arbol != NULL){
        if(strcmpi(arbol->disfraz.generoDisfraz , generoDisfraz) == 0){
            stockTotal = 1 + contarDisfracesPorGenero(arbol->izquierda , generoDisfraz) + contarDisfracesPorGenero(arbol->derecha , generoDisfraz);
        }else{
            stockTotal = contarDisfracesPorGenero(arbol->izquierda , generoDisfraz) + contarDisfracesPorGenero(arbol->derecha , generoDisfraz);
        }
    }

    return stockTotal;
}

stSucursal buscarMenorStockSucursal(nodoArbol* arbol ,  char generoDisfraz)
{
    stSucursal menorStock;

    if(arbol != NULL){
        if(strcmpi(arbol->disfraz.generoDisfraz , generoDisfraz) < 0){
            menorStock = buscarMenorStockSucursal(arbol->izquierda , generoDisfraz);
        }else{
            menorStock = buscarMenorStockSucursal(arbol->derecha , generoDisfraz);
        }
    }

    return menorStock;
}


/* --------------------------------------- FIN FUNCIONES - PUNTO 4 --------------------------------------- */


