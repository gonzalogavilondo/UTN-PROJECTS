#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BORRAR_PANTALLA system("cls");

#define ARCHIVO "./archivos/personas.txt";

typedef struct
{
    char nombre[20];
    int edad;
} persona;

typedef struct
{
    persona dato;
    struct nodo * siguiente;
} nodo;

nodo* borrarLista(nodo* lista);



nodo* eliLisRec(lista);

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo (persona dato)
{
    ///crea un puntero de tipo nodo
    nodo * aux = (nodo*) malloc(sizeof(nodo));
    ///asigna valores a sus campos de información
    aux->dato = dato;
    ///asigna valor NULL al campo que contiene la dirección de memoria del
    ///siguiente nodo
    aux->siguiente = NULL;
    ///retorna la dirección de memoria del nuevo nodo, que deberá ser
    ///asignada a una variable de tipo "puntero a nodo".
    return aux;
}

nodo * agregarPpio (nodo * lista, nodo * nuevoNodo)
{
    ///si la lista está vacía, ahora apuntará al nuevo nodo.
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
        ///si la lista no está vacía, inserta el nuevo nodo al comienzo de la
        ///misma, y el viejo primer nodo pasa a ser el segundo de la lista.
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
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

nodo * buscarNodo(nodo * lista, char nombre[20])
{
    ///busca un nodo por nombre y retorna su posición de memoria
    ///si no lo encuentra retorna NULL.
    nodo * seg; ///apunta al nodo de la lista que está siendo procesado
    seg = lista; ///con esto evito cambiar el valor de la variable
    ///lista, que contiene un puntero al primer nodo de la
    ///lista vinculada
    while ((seg != NULL) && ( strcmp(nombre, seg->dato.nombre)!=0 ))
    {
        ///busco mientras me quede lista por recorrer y no haya encontrado el nombre
        seg=seg->siguiente; ///avanzo hacia el siguiente nodo.
    }
    ///en este punto puede haber fallado alguna de las dos condiciones
    ///del while. si falla la primera es debido a que no encontró lo
    ///que buscaba (seg es NULL), si falla la segunda es debido a que se
    ///encontró el nodo buscado.
    return seg;
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

nodo * borrarNodo(nodo * lista, char nombre[20])
{
    nodo * seg;
    nodo * ante; ///apunta al nodo anterior que seg.
    if((lista != NULL) && (strcmp(nombre, lista->dato.nombre)==0 ))///encontre el nodo...
    {
        nodo * aux = lista;
        lista = lista->siguiente; ///salteo el primer nodo.
        free(aux); ///elimino el primer nodo.
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->dato.nombre)!=0 ))///mientras no lo encuentre...
        {
            ante = seg; ///adelanto una posición la variable ante.
            seg = seg->siguiente; ///avanzo al siguiente nodo.
        }
        ///en este punto tengo en la variable "ante" la dirección de
        ///memoria del nodo anterior al buscado, y en la variable "seg",
        ///la dirección de memoria del nodo que quiero borrar.
        if(seg!=NULL)///corto porque lo encontro
        {
            ante->siguiente = seg->siguiente;///salteo el nodo que quiero eliminar.
            free(seg);///elimino el nodo.
        }
    }
    return lista;
}

nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)
{
    /// agrega un nuevo nodo a la lista manteniendo el orden.
    ///si la lista está vacía agrego el primer elemento.
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        ///si el nuevo elemento es menor que el primero de la lista,
        ///agrego al principio
        if(strcmp(nuevoNodo->dato.nombre,lista->dato.nombre)<0)
        {
            lista = agregarPpio(lista, nuevoNodo);
        }
        else
        {
            ///busco el lugar en donde insertar el nuevo elemento.
            ///necesito mantener la dirección de memoria del nodo anterior
            ///al nodo que tiene un nombre mayor al del nuevo nodo.
            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            while((seg != NULL)&&(strcmp(nuevoNodo->dato.nombre,seg->dato.nombre)>0))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            ///inserto el nuevo nodo en el lugar indicado.
            nuevoNodo->siguiente = seg;
            ante->siguiente = nuevoNodo;
        }
    }
    return lista;
}

nodo * agregarEnOrdenEdad(nodo * lista, nodo * nuevoNodo)
{
    /// agrega un nuevo nodo a la lista manteniendo el orden con respecto a la edad.
    ///si la lista está vacía agrego el primer elemento.
    if(lista == NULL)
    {
        ///printf("es el primero...\n");
        lista = nuevoNodo;
    }
    else
    {
        ///si el nuevo elemento es menor que el primero de la lista,
        ///agrego al principio
        if(nuevoNodo->dato.edad < lista->dato.edad)
        {
            ///printf("agrego al pcio...\n");
            lista = agregarPpio(lista, nuevoNodo);
        }
        else
        {
            ///printf("agrego en el medio/final...\n");
            ///busco el lugar en donde insertar el nuevo elemento.
            ///necesito mantener la dirección de memoria del nodo anterior
            ///al nodo que tiene un nombre mayor al del nuevo nodo.
            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            while((seg != NULL)&&(nuevoNodo->dato.edad > seg->dato.edad))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            ///inserto el nuevo nodo en el lugar indicado.
            nuevoNodo->siguiente = seg;
            ante->siguiente = nuevoNodo;
        }
    }

    return lista;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * proximo;
    nodo * seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente; ///tomo la dir del siguiente.
        free(seg); ///borro el actual.
        seg = proximo; ///actualizo el actual con la dir del siguiente, para avanzar.
    }
    return seg; /// retorna NULL a la variable lista del main()
}

int sumarEdadesLista(nodo * lista)
{
    ///recorro la lista y sumo las edades de los socios.
    int suma = 0;
    nodo * seg = lista;
    while (seg != NULL)
    {
        suma = suma + seg->dato.edad;
        seg = seg->siguiente;
    }
    return suma;
}

void mostrarUnNodo(nodo * aux)
{
    if (aux != NULL)
    {
        printf("Nombre: %s\n", aux->dato.nombre);
        printf("Edad: %d\n", aux->dato.edad);
    }
    else
    {
        printf("Nodo no válido.\n");
    }
}

void recorrerYmostrar(nodo * lista)
{
    nodo * aux=lista;
    while(aux != NULL)
    {
        mostrarUnNodo(aux);
        aux = aux->siguiente;
    }
}

void recorrerYmostrarRecursiva(nodo * lista)
{
    if(lista != NULL)
    {
        mostrarUnNodo(lista);
        recorrerYmostrarRecursiva(lista->siguiente);
    }
}

void muestraPersona(persona per)
{
    printf("Nombre: %s\n",per.nombre);
    printf("Edad: %d\n",per.edad);
}

void borrarTodaLaListaRecur(nodo* lista)
{
    if(lista)
    {
        borrarTodaLaListaRecur(lista->siguiente);
        free(lista);
    }
}

nodo * borraLista1(nodo * lista)
{
    if(lista != NULL)
    {
        lista=borraLista1(lista->siguiente);
    }
    free(lista);
    return lista;
}

nodo* borrarLista(nodo* lista)
{
    if(lista->siguiente!=NULL)
    {
        lista->siguiente = borrarLista(lista->siguiente);
    }
    free(lista);
    return lista->siguiente;
}

nodo * invertirLista(nodo * lista)
{
    /// la idea es extraer el primero de la lista original
    /// y luego agregarlo al principio de la nueva lista
    /// retornamos el puntero al inicio de la nueva lista
    /// para pisar la referencia del main

    nodo * listaInvertida=NULL;
    nodo * aux;
    while(lista!=NULL)
    {
        /// extraemos el primero (se puede modularizar)
        aux=lista;

        lista=lista->siguiente;

        aux->siguiente=NULL;

        /// lo agregamos al principio de la nueva lista invertida
        listaInvertida = agregarPpio(listaInvertida, aux);
    }

    return listaInvertida;

}

nodo * intercalarListas(nodo *lista_A, nodo *lista_B, nodo *lista_C)
{
    nodo * aux;
    while((lista_A!=NULL)&&(lista_B!=NULL))
    {
        if(lista_A->dato.edad < lista_B->dato.edad)
        {
            aux=lista_A;
            lista_A = lista_A->siguiente; /// avanzo uno en la lista A...
            aux->siguiente=NULL; /// lo desvinculo de la lista
            lista_C=agregarFinal(lista_C, aux); /// agrego al final en lista C
        }
        else
        {
            aux=lista_B;
            lista_B=lista_B->siguiente; /// avanzo uno en la lista b...
            aux->siguiente=NULL; /// lo desvinculo de la lista
            lista_C=agregarFinal(lista_C, aux); /// agrego al final en lista C
        }
    }

    /// si quedara algo en la lista A
    if(lista_A!=NULL)
    {
        lista_C=agregarFinal(lista_C, lista_A); /// agrego al final en lista C
    }

    /// si quedara algo en la lista B
    else if(lista_B!=NULL)
    {
        lista_C=agregarFinal(lista_C, lista_B); /// agrego al final en lista C
    }

    ///recorrerYmostrar(lista_C);
    return lista_C;
}


nodo *CrearListaOrdenada(nodo * lista)
{
    srand(time(NULL));
    char continua = 's';///para saber si continua o no...
    while (continua=='s')
    {
        ///esto debe hacerse bien, ahora cargo personas "a mano"...
        persona unaPersona;
        strcpy(unaPersona.nombre,"Isabel");
        unaPersona.edad = rand()%99+1;

        ///genero un nodo nuevo con la persona creada anteriormente
        nodo * nuevoNodo = crearNodo(unaPersona);
        mostrarUnNodo(nuevoNodo);

        ///voy insertando en la lista de manera ordenada segun la edad de la persona
        lista = agregarEnOrdenEdad(lista,nuevoNodo);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continua);
        printf("\n");
    }
    return lista;
}

void generarArchivoDeTexto(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "w");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }
    persona personaNueva;
    char continua = 's';
    while(continua == 's')
    {
        ///MODULARIZAR LA CARGA DE UNA PERSONA...
        printf("Ingrese el nombre: \n");
        scanf("%s",personaNueva.nombre);
        printf("Ingrese la edad: \n");
        scanf("%d",&personaNueva.edad);

        fwrite(&personaNueva,sizeof(personaNueva),1,archivo);

        printf("Ingrese otro nombre (s/n): \n");
        fflush(stdin);
        scanf("%c",&continua);
    }

    /// Cerrar el archivo
    fclose(archivo);

    printf("Datos guardados en el archivo '%s'.\n", nombreArchivo);
}

nodo * leerDeArchivoTextoALista(const char *nombreArchivo, nodo * lista)
{
    FILE *archivo = fopen(nombreArchivo, "r");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }
    persona personaNueva;
    rewind(archivo);
    while(fread(&personaNueva,sizeof(persona),1,archivo) >0)
    {
        lista = agregarFinal(lista,crearNodo(personaNueva));
    }
    fclose(archivo);
    return lista;
}



///=========================================================================================================================
///=========================================================================================================================
///=========================================================================================================================


int main()
{

    nodo * lista; ///creamos la lista
    lista = inicLista();///la iniciamos
    ///printf("lista iniciada: %p\n",lista);

 /*   persona unaPersona;///creamos 1 reg de tipo persona
    ///inicializamos la persona...
    unaPersona.edad = 18;
    strcpy(unaPersona.nombre,"Rocio");

    ///creamos un nodo con la persona
    nodo * nodoAux;
    nodoAux = crearNodo(unaPersona);

    ///agregamos el nodo a la lista al ppio
    lista = agregarPpio(lista,nodoAux);

    ///creamos un nodo con la persona
    unaPersona.edad = 18;
    strcpy(unaPersona.nombre,"Antonella");
    nodoAux = crearNodo(unaPersona);

    ///agregamos el nodo a la lista al final
    lista = agregarFinal(lista,nodoAux);

    ///recorro y muestro la lista
    ///recorrerYmostrar(lista);
    ///recorrerYmostrarRecursiva(lista);


    nodo * ultimo = buscarUltimo(lista);
    printf("Ultimo: %s",ultimo->dato.nombre);

    ///creamos una lista ordenada
    lista = CrearListaOrdenada(lista);
    recorrerYmostrar(lista);


    nodo * listaA;
    nodo * listaB;
    nodo * listaC;///esta sera la lista resultante
    listaA = inicLista();
    listaB = inicLista();
    listaC = inicLista();

    listaA=CrearListaOrdenada(listaA);///genero lista ordenada por edades creadas aleatoriamente
    listaB=CrearListaOrdenada(listaB);///genero lista ordenada por edades creadas aleatoriamente

    listaC=intercalarListas(listaA,listaB,listaC);

    recorrerYmostrar(listaC);

*/
    const char *nombreArchivo = ARCHIVO; /// Nombre del archivo
    generarArchivoDeTexto(nombreArchivo);


    lista = leerDeArchivoTextoALista(nombreArchivo, lista);

    recorrerYmostrar(lista);

    ///BORRAR_PANTALLA;
    system("pause");

    return 0;
}






