#include <stdio.h>
#include <stdlib.h>
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

//////////////Prototipos////////////////////

void cargarArchPersonas(char nombreArch[]);

void guardarPersona(char nombreArch[] , stPersona persona);
void mostrarArchivoPersonas(char nombreArch[]);

void mostrarPersona(stPersona persona);
nodo  *cargarLista(char nombreArch[], nodo * lista);
nodo  *crearNodo(stPersona persona);
nodo  *agregarPpio (nodo * lista, nodo * nuevoNodo);
void mostrarLista(nodo *lista);
int buscaApellido(nodo* lista , char apellido[]);

nodo* insertarOrdenado(char nombreArch[], nodo * lista);
nodo* intercalarListasOrdenadas(nodo* lista1 , nodo* lista2 , nodo* listaDestino);

nodo * agregarFinal(nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
nodo * borrarNodo(nodo * lista, char nombre[20]);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);

//////////////******Main**********/////////////////
int main()
{
    int op;
    char apellido[20];
    char nombreArch[]="Personas.bin";
    char nombreArch2[]="Lugares.bin";
    nodo * lista1=NULL; /// Inicio la lista con NULL
    nodo * lista2=NULL; /// Inicio la lista con NULL
    nodo * lista3=NULL; /// Inicio la lista con NULL
    stPersona aux;


    printf("\n 1. Hacer un programa que lea de un archivo datos y los inserte en una lista.\n");
    printf("\n 2. Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.\n");
    printf("\n 3. Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada. (considerar caso ordenada y caso desordenada)\n");
    printf("\n 4. Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista. Se deben redireccionar los punteros, no se deben crear nuevos nodos.");
    printf("\n  estos no son de la guia \n");
    printf("\n 5. quitar un elemento de la lista conservando el orden ");
    printf("\n 6. quitar un elemento de la lista conservando el orden ");
    printf("\n ingrese una opcion \n");
    scanf("%i",&op);
    switch(op){
    case 1:
        system("cls");
        printf("\n 1. Hacer un programa que lea de un archivo datos y los inserte en una lista.\n");
         cargarArchPersonas(nombreArch);
        //mostrarArchivoPersonas(nombreArch);
        ///listas
        lista1=cargarLista(nombreArch,lista1);
        mostrarLista(lista1);

        break;

        case 2:
        system("cls");
        printf("\n   2. Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.\n");
        lista1=insertarOrdenado(nombreArch,lista1);
        mostrarLista(lista1);



        break;
        case 3:
        system("cls");
        printf("\n 3. Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada. (considerar caso ordenada y caso desordenada)\n");
        printf("\n ingrese un apellido para buscar en la lista \n");
        fflush(stdin);
        lista1=insertarOrdenado(nombreArch,lista1);

        scanf("%s",apellido);
        if(buscaApellido(lista1,apellido)==1)
            printf("\n el apellido %s se encuentra en la lista \n",apellido);
        else
            printf("\n el apellido buscado no se encuentra en la lista \n");

        mostrarLista(lista1);


        break;
        case 4:
        system("cls");
        printf("\n 4. Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista. Se deben redireccionar los punteros, no se deben crear nuevos nodos.");
        printf("\n ingrese un apellido para buscar en la lista \n");

        lista1=insertarOrdenado(nombreArch,lista1);
        lista2=insertarOrdenado(nombreArch2,lista2);
        lista3=intercalarListasOrdenadas(lista1,lista2,lista3);


       mostrarLista(lista3);
      //  mostrarLista(lista1);


        break;
        case 5:
        system("cls");
        printf("\n 5. quitar un elemento de la lista conservando el orden ");
        lista1=insertarOrdenado(nombreArch,lista1);
        mostrarLista(lista1);
        printf("\n ingrese el nombre para sacar de la lista  \n");
        fflush(stdin);
        scanf("%s",apellido);


        //lista2=insertarOrdenado(nombreArch2,lista2);
        //lista3=intercalarListasOrdenadas(lista1,lista2,lista3);

        lista1=borrarNodo(lista1,apellido);

        mostrarLista(lista1);
        //  mostrarLista(lista1);


        break;


        case 6:

        system("cls");
        printf("\n 6. agregar un elemento de la lista conservando el orden ");
        lista1=insertarOrdenado(nombreArch,lista1);
        mostrarLista(lista1);
        printf("\n ingrese el nombre para agregar de la lista  \n");
        fflush(stdin);
        scanf("%s",aux.nombre);
        printf("\n ingrese el Apellido   \n");
        fflush(stdin);
        scanf("%s",aux.apellido);
        printf("\n ingrese edad \n");
        scanf("%d",&aux.edad);


        //lista2=insertarOrdenado(nombreArch2,lista2);
        //lista3=intercalarListasOrdenadas(lista1,lista2,lista3);

        lista1=agregarEnOrden(lista1,crearNodo(aux));

        mostrarLista(lista1);
        //  mostrarLista(lista1);


        break;



    }
    return 0;
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


///////////////////
//1. Hacer un programa que lea de un archivo datos
/// y los inserte en una lista.


nodo  *cargarLista(char nombreArch[], nodo * lista)
{
    stPersona auxPersona;


    FILE *pArchivo=fopen(nombreArch,"rb");
    if(fread(&auxPersona,sizeof(stPersona),1,pArchivo)>0)
    {
       while(!feof(pArchivo))
        {
          lista=agregarPpio(lista,crearNodo(auxPersona));
          fread(&auxPersona,sizeof(stPersona),1,pArchivo);
        }
    }

    fclose(pArchivo);
    return lista;
}
void mostrarLista(nodo *lista){
    nodo *auxNodo;
    auxNodo=lista;
    while(auxNodo!=NULL)
    {
        printf(" \n%s %s %d \n", auxNodo->datos.nombre,auxNodo->datos.apellido,auxNodo->datos.edad);
        auxNodo=auxNodo->siguiente;
    }


}

nodo* crearNodo(stPersona persona)
{

    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->datos.edad=persona.edad;
    strcpy(aux->datos.nombre, persona.nombre);
    strcpy(aux->datos.apellido, persona.apellido);

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


////////////
nodo* insertarOrdenado(char nombreArch[], nodo * lista)
{
    nodo* ante=NULL;
    nodo* seguidor;
    nodo* actual;

    stPersona auxPersona;

    FILE *pArchivo=fopen(nombreArch,"rb");
    if(fread(&auxPersona,sizeof(stPersona),1,pArchivo)>0)
    {
       while(!feof(pArchivo))
        {

            if(lista == NULL)
                lista = agregarPpio(lista , crearNodo(auxPersona));
            else
            {
              if(strcmp(auxPersona.nombre , lista->datos.nombre) < 0)
                 lista = agregarPpio(lista ,crearNodo(auxPersona));
              else
                {
                ante = lista;
                seguidor = lista->siguiente;

                while((seguidor != NULL) && (strcmp(auxPersona.nombre , seguidor->datos.nombre) >= 0))
                   {
                    ante = seguidor;
                    seguidor = seguidor->siguiente;
                   }
                  actual=crearNodo(auxPersona);
                actual->siguiente = seguidor;
                ante->siguiente = actual;
               }
            }
              fread(&auxPersona,sizeof(stPersona),1,pArchivo);
        }
    }

    fclose(pArchivo);





    return lista;
}

////////////////////////////////////
int buscaApellido(nodo* lista , char apellido[])
{
    int flag = 0;
    nodo* aux = lista;

    while((aux != NULL) && (flag == 0))
      {
        if(strcmpi(aux->datos.apellido , apellido) == 0)
            flag = 1; // retorna 1 si la persona se encuentra en la lista.
        else
            aux = aux->siguiente;
      }

    return flag;
}
//////////////////////////////////
nodo* intercalarListasOrdenadas(nodo* lista1 , nodo* lista2 , nodo* listaDestino)
{
    nodo* aux;

    while((lista1 != NULL) && (lista2 != NULL)){
        if(strcmp(lista1->datos.nombre , lista2->datos.nombre) < 0){
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
////////////////////////////////////////////////////////
nodo * borrarNodo(nodo * lista, char nombre[20]) {
    nodo * seg;
    nodo * ante; //apunta al nodo anterior que seg.
    if((lista != NULL) && (strcmp(nombre, lista->datos.nombre)==0 )) {
        nodo * aux = lista;
        lista = lista->siguiente; //salteo el primer nodo.
        free(aux); //elimino el primer nodo.
    }else {
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->datos.nombre)!=0 )) {
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

///////////
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo) {
    // agrega un nuevo nodo a la lista manteniendo el orden.
    //si la lista está vacía agrego el primer elemento.
    if(lista == NULL) {
        lista = nuevoNodo;
    }else {
        //si el nuevo elemento es menor que el primero de la lista,
        //agrego al principio
        if(strcmp(nuevoNodo->datos.nombre,lista->datos.nombre)<0){
            lista = agregarPpio(lista, nuevoNodo);
        } else {
        //busco el lugar en donde insertar el nuevo elemento.
        //necesito mantener la dirección de memoria del nodo anterior
        //al nodo que tiene un nombre mayor al del nuevo nodo.
        nodo * ante = lista;
        nodo * seg = lista->siguiente;
        while((seg != NULL)
            &&(strcmp(nuevoNodo->datos.nombre,seg->datos.nombre)>0)) {
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
