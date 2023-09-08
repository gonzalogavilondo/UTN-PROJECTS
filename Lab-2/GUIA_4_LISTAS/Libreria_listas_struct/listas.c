#include "listas.h"

/**
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS
**/

nodo* inicLista()
{
    return NULL;
}

nodo * crearNodo(persona dato)
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

nodo* agregarAlInicio(nodo *nuevo, nodo *lista)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }

    return lista;
}

nodo* buscaUltimoLista(nodo *lista)
{
    nodo *seg = lista; ///seg es seguidor
    if(seg != NULL) ///Lista esta vacia?
    {
        while(seg->siguiente != NULL) ///Recorro la lista
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}

nodo* agregarAlFinal(nodo *nuevo, nodo *lista)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodo *ultimo = buscaUltimoLista(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}


nodo* agregarOrdenado(nodo *nuevoNodo, nodo *lista)
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
            lista = agregarAlInicio(nuevoNodo, lista);
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

nodo* agregarOrdenadoEdad(nodo *nuevoNodo, nodo *lista)
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
            lista = agregarAlInicio(nuevoNodo, lista);
        }
        else
        {
            ///printf("agrego en el medio/final...\n");
            ///busco el lugar en donde insertar el nuevo elemento.
            ///necesito mantener la dirección de memoria del nodo anterior
            ///al nodo que tiene un nombre mayor al del nuevo nodo.
            nodo *ante = lista;
            nodo *seg = lista->siguiente;
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

nodo *borrarNodo(nodo * lista, char nombre[20])
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


nodo* borrarPrimerNodo(nodo *lista)
{
    nodo *aux = lista;
    lista = lista->siguiente;
    free(aux);
    return lista;
}

nodo* borrarUltimoNodo(nodo *lista)
{
    nodo *aux;
    nodo *ante;
    if(lista != NULL)
    {
        if(lista->siguiente == NULL)
        {
            aux = lista;
            lista = lista->siguiente;
            free(aux);
        }
        else
        {
            aux = lista;
            while(aux->siguiente != NULL)
            {
                ante = aux;
                aux = aux->siguiente;
            }
            free(aux);
            ante->siguiente = NULL;
        }
    }
    return lista;
}

nodo *buscarNodo(nodo * lista, char nombre[20])
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

nodo* borrarLista(nodo *lista)
{
    nodo *proximo;
    nodo *seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente; ///tomo la dir del siguiente.
        free(seg); ///borro el actual.
        seg = proximo; ///actualizo el actual con la dir del siguiente, para avanzar.
    }
    return seg; ///retorna NULL a la variable lista del main()
}

void borrarListaRecur(nodo* lista)
{
    if(lista)
    {
        borrarListaRecur(lista->siguiente);
        free(lista);
    }
}

nodo *intercalarListas(nodo *lista_A, nodo *lista_B, nodo *lista_C)
{
    nodo *aux;

    while((lista_A != NULL) && (lista_B != NULL))
    {
        if(lista_A->dato.edad < lista_B->dato.edad)
        {
            aux = lista_A;
            lista_A = lista_A->siguiente;
            aux->siguiente = NULL;
            lista_C = agregarAlFinal(aux, lista_C);
        }
        else
        {
            aux = lista_B;
            lista_B = lista_B->siguiente;
            aux->siguiente = NULL;
            lista_C = agregarAlFinal(aux, lista_C);
        }
    }

    ///Si quedara algo en la lista A
    if(lista_A != NULL)
    {
        lista_C = agregarAlFinal(lista_A, lista_C);
    }
    ///Si quedara algo en la lista B
    else if(lista_B != NULL)
    {
        lista_C = agregarAlFinal(lista_B, lista_C);
    }

    return lista_C;
}

nodo* crearListaOrdenada(nodo *lista)
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
        lista = agregarOrdenadoEdad(nuevoNodo, lista);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continua);
        printf("\n");
    }
    return lista;
}

nodo* invertirLista(nodo *lista)
{
    /// la idea es extraer el primero de la lista original
    /// y luego agregarlo al principio de la nueva lista
    /// retornamos el puntero al inicio de la nueva lista
    /// para pisar la referencia del main

    nodo *listaInvertida = NULL;
    nodo *aux;
    while(lista != NULL)
    {
        /// extraemos el primero (se puede modularizar)
        aux = lista;

        lista = lista->siguiente;

        aux->siguiente = NULL;

        /// lo agregamos al principio de la nueva lista invertida
        listaInvertida = agregarAlInicio(aux, listaInvertida);
    }
    return listaInvertida;
}

void mostrarUnNodo(nodo *aux)
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

void mostrarListaStruct(nodo *lista)
{
    nodo * aux = lista;
    while(aux != NULL)
    {
        mostrarUnNodo(aux);
        aux = aux->siguiente;
    }
}

void recorrerYmostrarRecursiva(nodo *lista)
{
    if(lista != NULL)
    {
        mostrarUnNodo(lista);
        recorrerYmostrarRecursiva(lista->siguiente);
    }
}


int sumarEdadesLista(nodo *lista)
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

/*****************************************************************************************************
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS CON ARCHIVOS
******************************************************************************************************/

/**
    ENTEROS: ARCHIVOS BINARIOS ***********************************************************************
**/

void generaArchivoBin_struct(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "wb");

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

void lista2archivoBin_struct(nodo *lista, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "wb");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    nodo *actual = lista;
    while(actual != NULL)
    {
        fwrite(&(actual->dato), sizeof(persona), 1, archivo);
        actual = actual->siguiente;
    }

    fclose(archivo);
}


nodo* archivoBin2lista_struct(nodo *lista, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rb");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        exit(1); // Codigo de error
    }
    persona personaNueva;
    rewind(archivo);
    while(fread(&personaNueva, sizeof(persona), 1, archivo) > 0)
    {
        lista = agregarAlFinal(crearNodo(personaNueva), lista);
    }
    fclose(archivo);
    return lista;
}

/**
    ENTEROS: ARCHIVOS TXT ***********************************************************************
**/

void generaArchivoTxt_struct(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "w");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    persona *personaNueva;
    char continua = 's';

    while (continua == 's')
    {
        cargarPersona(&personaNueva);

        // Escribir en el archivo en formato de texto
        fprintf(archivo, "%s %d\n", personaNueva->nombre, personaNueva->edad);

        printf("Ingrese otro nombre (s/n): \n");
        fflush(stdin);
        scanf(" %c", &continua);  // Nota: se agrega un espacio antes de %c para ignorar los espacios en blanco

        // Si el usuario no ingresa 's', el bucle se detiene
        if (continua != 's')
            break;
    }

    /// Cerrar el archivo
    fclose(archivo);

    printf("Datos guardados en el archivo '%s'.\n", nombreArchivo);
}

void lista2archivoTxt_struct(nodo *lista, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "w");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    nodo *actual = lista;
    while (actual != NULL)
    {
        fprintf(archivo, "%s %d\n", actual->dato.nombre, actual->dato.edad);
        actual = actual->siguiente;
    }

    fclose(archivo);
}


nodo* archivoTxt2lista_struct(nodo *lista, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "r");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return NULL;  // Devolvemos NULL en caso de error
    }

    persona personaNueva;

    while (fscanf(archivo, "%s %d", personaNueva.nombre, &personaNueva.edad) == 2) //El 2 indica la cantidad de campos que tiene la estructura "persona"
    {
        lista = agregarAlFinal(crearNodo(personaNueva), lista);
    }

    fclose(archivo);
    return lista;
}
