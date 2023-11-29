#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ListaGeneros.h"


/**********************************************************************************/
/****************** FUNCIONES BASICAS PARA COMENZAR EL PARCIAL ********************/
/**********************************************************************************/

//INICIALIZA LA LDA
ListaGeneros* inic_list_lda ()
{
    return NULL;
}


//CREA UN NODO LDA
ListaGeneros* nuevo_nodo_genero (const char* NUEVO_GENERO)
{
    ListaGeneros* nuevoNodo = (ListaGeneros*) malloc (sizeof(ListaGeneros));

    strcpy(nuevoNodo->genero, NUEVO_GENERO);

    nuevoNodo->pelis = inic_arbol_pelis();
    nuevoNodo->siguiente = inic_list_lda();

    return nuevoNodo;
}

/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/

/**
    Ejercicio 1
**/
///Busca generos y devuelve el nodo cuando sea igual a genero o cuando sea NULL
ListaGeneros* busca_genero(ListaGeneros *lista, char genero[])
{
    ListaGeneros *seg = lista;

    while (seg != NULL && strcmp(seg->genero, genero) != 0)
    {
        seg = seg->siguiente;
    }

    return seg;
}

////Inciso c
ListaGeneros* agregar_pelicula_en_lda(ListaGeneros *lista, Pelicula aux)
{
    int pos = buscarPosicionEnLista(lista, aux.genero); ////Decidi usar esta otra funcion para luego poder agregarlo en la posicion correcta a la pelicula, teniendo la posicion

    if (pos == -1)
    {
        // Si no se encuentra el genero, agregar uno nuevo al inicio de la lista (1.b)
        lista = crear_genero(lista, aux.genero);
    }

    ArbolPeliculas *nuevo = nuevo_nodo_pelicula(aux);
    ListaGeneros *celdaActual = lista;
    for (int i = 0; i < pos; i++)
    {
        celdaActual = celdaActual->siguiente;
    }

    celdaActual->pelis = agregar_pelicula_en_arbol(celdaActual->pelis, nuevo->p);

    return lista;
}

////Recibe la lista y un genero para agregarlo en la LDA
ListaGeneros* crear_genero(ListaGeneros *lista, char genero[])
{
    ListaGeneros *nuevoGenero = malloc(sizeof(ListaGeneros));
    if (nuevoGenero)
    {
        strcpy(nuevoGenero->genero, genero);
        nuevoGenero->pelis = inic_arbol_pelis();
        nuevoGenero->siguiente = NULL;  // La nueva celda será el último elemento

        // Agregar al inicio de la lista usando las funciones proporcionadas
        lista = agregarAlInicio(lista, nuevoGenero);
    }
    else
    {
        // Manejo de error: no se pudo asignar memoria para la nueva celda
        printf("\nNo se pudo asignar memoria para la nueva celda.\n");
        return lista;
    }

    return lista;
}

ListaGeneros* agregarAlInicio(ListaGeneros *lista, ListaGeneros *nuevo)
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

int buscarPosicionEnLista(ListaGeneros *lista, char genero[])
{
    int pos = -1;
    int i = 0;
    ListaGeneros *seg = lista;

    while (seg != NULL && pos == -1)
    {
        if (strcmp(seg->genero, genero) == 0)
        {
            pos = i;
        }
        else
        {
            seg = seg->siguiente;
            i++;
        }
    }

    return pos;
}

/**
    Ejercicio 2
**/
////Inciso a: Carga los registros almacenados en el archivo de peliculas.
ListaGeneros* archivo_to_lista()
{
    ListaGeneros *lista = NULL;
    FILE *buf = fopen(ARCHIVO_PELICULAS, "rb");

    Pelicula aux;

    if (buf)
    {
        while (fread(&aux, sizeof(Pelicula), 1, buf) > 0)
        {
            lista = agregar_pelicula_en_lda(lista, aux);
        }
        fclose(buf);
    }

    return lista;
}

////Inciso b: Debe pedirle al usuario el genero de las peliculas que se quieran contar en la LDA y contar SU ARBOL,
//para luego mostrarlo por pantalla crear una funcion que cuenta cada nodo del arbol de peliculas
int contar_peliculas_de_un_genero(ListaGeneros *lista)
{
    int contador = 0;
    char genero [DIM_STR];
    ArbolPeliculas *arbolPeliculas = inic_arbol_pelis();

    printf("Que genero desea buscar para saber cuales y cuantas hay?: ");
    fflush(stdin);
    gets(genero);

    arbolPeliculas = busca_por_genero(lista, genero);

    ///Ahora, con el arbol que se encuentra apuntando la lista del genero que le pedimos al usuario:
    contador = contadorDeNodos(arbolPeliculas);

    ///Mostramos el arbol
    inorder(arbolPeliculas);

    return contador;
}

int contadorDeNodos(ArbolPeliculas *arbol)
{
    int cnt = 0;

    if(arbol != NULL)
    {
        cnt = 1 + contadorDeNodos(arbol->izq) + contadorDeNodos(arbol->der);
    }

    return cnt;
}

ArbolPeliculas *busca_por_genero(ListaGeneros *lista, char genero[])
{
    ListaGeneros *seg = lista;

    while (seg != NULL && strcmp(seg->genero, genero) != 0)
    {
        seg = seg->siguiente;
    }

    return seg->pelis;
}


///Ejercicio 3
ArbolPeliculas * eliminar_pelicula_en_lda(ListaGeneros *lista)
{
    int id = 0;
    char genero [DIM_STR];
    ArbolPeliculas *arbolPeliculas = inic_arbol_pelis();
    ArbolPeliculas *nodoEliminado = inic_arbol_pelis();

    printf("La pelicula de que genero desea eliminar?:  ");
    fflush(stdin);
    gets(genero);

    arbolPeliculas = busca_por_genero(lista, genero);

    //Mostramos las peliculas que hay para que sea mas facil para el usuario identificarla
    inorder(arbolPeliculas);

    //Le pedimos el ID de la pelicula que quiere eliminar
    printf("Ingrese el ID de la pelicula a eliminar: ");
    scanf("%d", &id);

    nodoEliminado = borrar_nodo_pelicula(arbolPeliculas, id);

    return nodoEliminado;
}

void muestra_peliculas_en_lda(ListaGeneros *lista)
{
    while (lista)
    {
        printf("\n------------------------------------\n");
        printf("Genero %s \n", lista->genero);
        printf("------------------------------------\n");
        printf("------------------------------------\n");
        inorder(lista->pelis);
        lista = lista->siguiente;
    }
}

void inorder(ArbolPeliculas *arbol)
{
    if (arbol)
    {
        inorder(arbol->izq);
        muestra_pelicula(arbol->p);
        inorder(arbol->der);
    }
}

