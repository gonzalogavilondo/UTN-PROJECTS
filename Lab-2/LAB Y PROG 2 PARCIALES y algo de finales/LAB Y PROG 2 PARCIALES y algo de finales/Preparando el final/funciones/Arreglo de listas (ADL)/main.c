#include <stdio.h>
#include <stdlib.h>
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
    celdaProductos array[dimension];
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


