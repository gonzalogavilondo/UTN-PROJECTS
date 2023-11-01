
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

const int dimension=30;




typedef struct
{
    char nombre[30];
    char apellido[30];
    int edad;
}stPersona;

typedef struct nodo
{
    stPersona datos;
    struct nodo* siguiente;
}nodo;


int menu();
nodo * inicLista();
nodo* crearNodo(char nombre[30],char apellido[30], int edad);
nodo * agregarPpio (nodo * lista, nodo * nuevoNodo);
nodo * cargarNodoAlprincipio (nodo * lista);
nodo* borrarInicLista(nodo* lista);
nodo * buscarUltimo(nodo * lista);
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo) ;

///Ejercicio 1.
void cargarArchPersonas(char nombreArch[]);
void guardarPersona(char nombreArch[] , stPersona persona);
void mostrarPersona(stPersona persona);
void mostrarArchivoPersonas(char nombreArch[]);
void lista(char nombreArch[], nodo * lista);




int main(int argc, char *argv[])
{

    char nombreArch[]="Personas.bin";
    nodo * lista1=NULL;
    int selected;
    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
               system("cls");
               cargarArchPersonas(nombreArch);
               mostrarArchivoPersonas(nombreArch);
               ///listas
               lista(nombreArch,lista1);
               system("PAUSE");
            break;
        case 2:
              system("cls");

              system("PAUSE");
            break;
        case 3:
              system("cls");

              system("PAUSE");
            break;
        case 4:
              system("cls");

              system("PAUSE");
            break;
        case 5:
              system("cls");

              system("PAUSE");
            break;
        case 6:
              system("cls");

              system("PAUSE");
            break;
        case 7:
              system("cls");

              system("PAUSE");
            break;


        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");

            break;
        }

    }
    while(selected!=0);

    system("PAUSE");
    return 0;
}

int menu()
{
    system("color 1F");
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n 1-Ejercicio 1 \n");
    printf("\n 2-Ejercicio 2 \n");
    printf("\n 3-Ejercicio 3 \n");
    printf("\n 4-Ejercicio 4 \n");
    printf("\n 5-Ejercicio 5 \n");
    printf("\n 6-Ejercicio 6 \n");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);
    return input;
}

/// funciones de lista


nodo * inicLista()
{
    return NULL;
}

nodo* crearNodo(char nombre[30],char apellido[30], int edad)
{

    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->datos.edad=edad;
    strcpy(aux->datos.nombre, nombre);
    strcpy(aux->datos.apellido, apellido);

    aux->siguiente = NULL;

    return aux;
}

nodo * agregarPpio (nodo * lista, nodo * nuevoNodo)
{
    if (lista==NULL)
        lista=nuevoNodo;
    else
    {
        nuevoNodo -> siguiente=lista;
        lista=nuevoNodo;
    }

    return lista;///Devuelve el puntero a la lista
}

nodo * cargarNodoAlprincipio (nodo * lista)
{
    nodo * nuevoNodo;
    char control='s',nombre[30], apellido[30];
    int edad;

    while(control=='s')
    {

        printf("\n Ingrese nombre:\n");
        fflush(stdin);
        scanf("%s", nombre);
        printf("\n Ingrese apellido:\n");
        fflush(stdin);
        scanf("%s", apellido);
        printf("\n Ingrese la edad:\n");
        scanf("%d", &edad);
        nuevoNodo= crearNodo(nombre,apellido,edad);
        lista=agregarPpio(lista, nuevoNodo);

        printf("\n ¿Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return lista;
}


nodo * buscarUltimo(nodo * lista)
{
   nodo * seg = lista;
   if(seg != NULL)
      while(seg->siguiente != NULL)
        {
         seg = seg->siguiente;
        }
    return seg;
 }


nodo * agregarFinal(nodo * lista, nodo * nuevoNodo)
{


   if(lista == NULL)
      lista = nuevoNodo;
    else
    {
      nodo * ultimo = buscarUltimo(lista);
      ultimo->siguiente = nuevoNodo;
    }
   return lista;
}


nodo* borrarInicLista(nodo* lista)
{
    nodo* aux = lista;

    lista = lista->siguiente;

    free(aux);

    return lista;
}

//////////Funciones de archivos////////////////

/* carga un archivo de personas */

void cargarArchPersonas(char nombreArch[])
{
    stPersona persona;
    char continuar = 's';

    while(continuar == 's'){
        system("cls");

        printf(" CARGANDO ARCHIVO DE PERSONAS... \n\n");
        printf(" Ingresar nombre: ");
        fflush(stdin);
        gets(persona.nombre);
        printf(" Ingresar apellido: ");
        fflush(stdin);
        gets(persona.apellido);
        printf(" Ingresar edad: ");
        scanf("%d" , &persona.edad);

        guardarPersona(nombreArch, persona);

        printf("\n %cQuieres ingresar otra persona? s=SI / n=No " , 168);
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n\n");

    }
}

/* guarda una la persona en el archivo */
void guardarPersona(char nombreArch[] , stPersona persona)
{
    FILE *pArchivo;

    pArchivo = fopen(nombreArch, "ab");

    if(pArchivo!= NULL){
        fwrite(&persona , sizeof(stPersona) , 1 , pArchivo);
        fclose(pArchivo);
    }else{
        printf(" ERROR en la apertura del archivo. \n\n");
    }
}

/* recorre el archivo e imprime por pantalla */
void mostrarArchivoPersonas(char nombreArch[])
{
    int numPersona = 0;
    stPersona aux;
    FILE *pArchivo;

    pArchivo = fopen(nombreArch , "rb");

    if(pArchivo != NULL)
        {
        while(fread(&aux , sizeof(stPersona) , 1 , pArchivo) > 0)
            {
            printf(" Persona N%d \n" , numPersona+1);
            mostrarPersona(aux);
            numPersona++;
            }

        }
    else
    {
        printf(" ERROR en la lectura del archivo. \n\n");
    }
    fclose(pArchivo);
}

void mostrarPersona(stPersona persona)
{
    printf(" -------------------------- \n");
    printf(" Nombre/s  : %s \n" , persona.nombre);
    printf(" Apellido/s: %s \n" , persona.apellido);
    printf(" Edad      : %d \n" , persona.edad);
    printf(" -------------------------- \n\n");
}

///1. Hacer un programa que lea de un archivo datos
/// y los inserte en una lista.


void lista(char nombreArch[], nodo * lista)
{
    stPersona auxPersona;
    nodo *auxNodo;
    FILE *pArchivo=fopen(nombreArch,"rb");
    if(fread(&auxPersona,sizeof(stPersona),1,pArchivo)>0)
    {
       while(!feof(pArchivo))
        {
          lista=agregarPpio(lista,crearNodo(auxPersona.nombre,auxPersona.apellido,auxPersona.edad));
          fread(&auxPersona,sizeof(stPersona),1,pArchivo);
        }
    }
    auxNodo=lista;
    while(auxNodo!=NULL)
    {
        printf(" \n%s %s %d \n", auxNodo->datos.nombre,auxNodo->datos.apellido,auxNodo->datos.edad);
        auxNodo=auxNodo->siguiente;
    }
    fclose(pArchivo);
}

/// 2. Hacer un programa que lea de un archivo
///datos y los inserte en una lista en forma ordenada.

nodo* insertarOrdenado(nodo* lista , nodo* nuevoNodo)
{
    nodo* ante;
    nodo* seguidor;

    if(lista == NULL)
        lista = nuevoNodo;
    else
        {
          if(strcmp(nuevoNodo->datos.nombre , lista->datos.nombre) < 0)
             lista = agregarPpio(lista , nuevoNodo);
          else
            {
            ante = lista;
            seguidor = lista->siguiente;

            while((seguidor != NULL) && (strcmp(nuevoNodo->datos.nombre , seguidor->datos.nombre) >= 0))
               {
                ante = seguidor;
                seguidor = seguidor->siguiente;
               }
            nuevoNodo->siguiente = seguidor;
            ante->siguiente = nuevoNodo;
           }
        }

    return lista;
}


///3. Hacer una función que retorne un 1 (uno) o 0 (cero)
///si existe un determinado elemento en una lista dada.
///(considerar caso ordenada y caso desordenada)

int verificaSiExistePersona(nodo* lista , char nombre[])
{
    int flag = 0;
    nodo* seguidor = lista;

    while((seguidor != NULL) && (flag == 0))
      {
        if(strcmpi(seguidor->datos.nombre , nombre) == 0)
            flag = 1; // retorna 1 si la persona se encuentra en la lista.
        else
            seguidor = seguidor->siguiente;
      }

    return flag;
}

stPersona buscarPersona(nodo* lista , char nombre[])
{
    stPersona personaEncontrada;
    nodo* seguidor = lista;
    int flag = 0;

    while((flag == 0) && (seguidor != NULL)){  // se usa una variable de control para la condición de corte.
        if(strcmpi(seguidor->datos.nombre , nombre) == 0){
            flag = 1;
            personaEncontrada = seguidor->datos;
        }else{
            seguidor = seguidor->siguiente;
        }
    }

    return personaEncontrada;
}

///4. Hacer una función que intercale en orden los
///elementos de dos listas ordenadas
/// generando una nueva lista.
///Se deben redireccionar los punteros,
///no se deben crear nuevos nodos.



nodo* intercalarListasOrdenadas(nodo* lista1 , nodo* lista2 , nodo* listaDestino)
{
    nodo* aux;

    while((lista1 != NULL) && (lista2 != NULL)){
        if(lista1->datos.edad <= lista2->datos.edad){
            aux = lista1;
            lista1 = lista1->siguiente;
        }else{
            aux = lista2;
            lista2 = lista2->siguiente;
        }

        aux->siguiente = NULL;
        listaDestino = agregarFinal(listaDestino , aux);
    }

    if(lista1 != NULL){
        listaDestino = agregarFinal(listaDestino , lista1);
    }else if(lista2 != NULL){
        listaDestino = agregarFinal(listaDestino , lista2);
    }

    return listaDestino;
}


///5. Codificar el TDA Pila con las funciones necesarias,
/// implementada con una
///lista enlazada (Similar al ejercicio hecho con arreglo).


void inicPila(Pila* p)
{
    *p = inicLista();
}

void apilar(Pila* p , int numero)
{
    Pila aux;

    aux = crearNodo(*p , numero);
    *p = agregarPpio(*p , aux);
}


int desapilar(Pila* p)
{
    int aux;

    if(*p != NULL){
        aux = (*p)->valor;
        *p = borrarInicLista(*p);
    }else{
        printf(" La pila esta vacia , por lo tanto se retorna basura. \n\n" , 160 , 161);
    }

    return aux;
}

int tope(Pila* p)
{
    int topePila;

    if(!pilaVacia(p)){
       topePila = (*p)->valor;
    }else{
        printf(" La pila está vacia. \n\n" , 160 , 161);
    }

    return topePila;
}

void mostrar(Pila* p)
{
    if(!pilaVacia(p)){
        printf("- TOPE \n");
        mostrarLista(*p);
        printf("- BASE \n\n");
    }else{
        printf(" La pila está vacia. \n\n" , 160 , 161);
    }
}

void leer(Pila* p)
{
    int num = 0;

    printf(" Ingresar numero entero: " , 163);
    scanf("%d" , &num);
    apilar(p , num);
}

int pilaVacia(Pila* p)
{
    int pVacia;

    if(*p == NULL){
        pVacia = 1;
    }else{
        pVacia = 0;
    }

    return pVacia;
}


///6. Invertir los elementos de una lista
///redireccionando solamente los punteros.
///(No se deben crear nuevos nodos).

