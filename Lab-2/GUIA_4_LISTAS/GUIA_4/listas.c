#include "listas.h"

void mostrarMenu()
{
    printf("\n\t\t - Trabajo Practico 4 - Listas Simples - Gavilondo Gonzalo - \n");
    printf("\n1. - Genera un nuevo archivo de enteros con 10 datos (Borra el anterior si ya existe).");
    printf("\n2. - Mostrar archivo de Enteros.");
    printf("\n3. - Leer archivo y agregar elementos a la lista.");
    printf("\n4. - Mostrar Lista.");
    printf("\n5. - Leer archivo e insertar elementos en lista de forma ordenada.");
    printf("\n6. - Borrar nodo.");
    printf("\n7. - Intercalar dos listas aleatorias.");
    printf("\n8. - Invertir una lista aleatoria.\n");
    printf("\nIngrese una opcion o ESC para salir: ");

}

void generaArchivoEnteros(char archivo[])
{
    FILE *pArchEnteros = fopen(archivo, "wb");

    srand(time(0));

    if (pArchEnteros)
    {

        for (int i = 0; i < 10; i++)
        {
            int random = rand()%100;
            fwrite(&random, sizeof(int), 1, pArchEnteros);
        }
        fclose(pArchEnteros);
    }
}

void muestraUnEntero(int dato)
{
    printf(" %d -", dato);
}

void muestraArchivoEnteros(char archivo[])
{
    FILE *pArchEnteros = fopen(archivo, "rb");
    int aux;

    if (pArchEnteros)
    {
        while (fread(&aux, sizeof(int), 1, pArchEnteros) > 0)
        {
            muestraUnEntero(aux);
        }
        fclose(pArchEnteros);
    }
    printf("\n");
}

nodo* inicLista()
{
    return NULL;
}

nodo* archivo2lista(nodo *lista, char archivo[])
{
    FILE *pArch = fopen(archivo, "rb");
    int entero;

    if (pArch)
    {
        while (fread(&entero, sizeof(int), 1, pArch) > 0)
        {
            lista = agregarAlFinal(crearNodo(entero), lista);
        }
        fclose(pArch);
    }
    return lista;
}

nodo* crearNodo(int entero)
{
    nodo *nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = entero;
    nuevo->siguiente = NULL;

    return nuevo;
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

nodo* agregarAlFinal(nodo *lista, nodo *nuevo)
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


nodo *agregarOrdenado(nodo *nuevo, nodo *lista)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        if(nuevo->dato < lista->dato)
        {
            lista = agregarAlInicio(nuevo, lista);
        }
        else
        {
            nodo *ante = lista;
            nodo *aux = lista;
            while(aux && nuevo->dato > aux->dato)
            {
                ante = aux;
                aux = aux->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->siguiente = aux;
        }
    }

    return lista;
}

void mostrarListaEnteros(nodo *lista)
{
    nodo *aux = lista;
    printf("| ");
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->siguiente;
    }
    printf("|\n");
}

nodo* archivo2ListaOrdenado(nodo *lista, char archivo[])
{
    FILE *pArch = fopen(archivo, "rb");
    int entero;

    if (pArch)
    {
        while (fread(&entero, sizeof(int), 1, pArch) > 0)
        {
            lista = agregarOrdenado(crearNodo(entero), lista);
        }
        fclose(pArch);
    }
    return lista;
}

nodo* borrarNodo(int entero, nodo *lista)
{
    nodo* aux;
    nodo* ante;
    if ((lista != NULL) && (entero == lista->dato))
    {
        aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        aux = lista;
        while(aux && entero != aux->dato)
        {
            ante = aux;
            aux = aux->siguiente;
        }

        if(aux)
        {
            ante->siguiente = aux->siguiente;
            free(aux);
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

nodo* buscarNodo(int dato, nodo *lista)
{
    nodo *seg = lista;

    while ((seg != NULL) && (seg->dato != dato))
    {
        seg = seg->siguiente;
    }

    return seg;
}

nodo* borrarLista(nodo *lista)
{
    nodo *proximo;
    nodo *seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}

nodo *intercalarListas(nodo *lista_A, nodo *lista_B, nodo *lista_C)
{
    nodo *aux;

    while((lista_A != NULL) && (lista_B != NULL))
    {
        if(lista_A->dato < lista_B->dato)
        {
            aux = lista_A;
            lista_A = lista_A->siguiente;
            aux->siguiente = NULL;
            lista_C = agregarAlFinal(lista_C, aux);
        }
        else
        {
            aux = lista_B;
            lista_B = lista_B->siguiente;
            aux->siguiente = NULL;
            lista_C = agregarAlFinal(lista_C, aux);
        }
    }

    //Si quedara algo en la lista A
    if(lista_A != NULL)
    {
        lista_C = agregarAlFinal(lista_C, lista_A);
    }
    //Si quedara algo en la lista B
    else if(lista_B != NULL)
    {
        lista_C = agregarAlFinal(lista_C, lista_B);
    }

    return lista_C;
}

nodo* listaRandomOrdenado(nodo *lista, int cntElementos)
{
    int cnt = 0;

    if(lista == NULL)
    {
        while (cnt < cntElementos)
        {
            lista = agregarOrdenado(crearNodo(rand() % 99), lista);
            cnt++;
        }
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
