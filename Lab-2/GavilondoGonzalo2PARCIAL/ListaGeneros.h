#ifndef LISTAGENEROS_H_INCLUDED
#define LISTAGENEROS_H_INCLUDED

#include "Pelicula.h"
#include "ArbolPeliculas.h"
#define ARCHIVO_PELICULAS "peliculas.bin"

///ESTE SERA NUESTRO LDA (LISTA DE ARBOLES)
typedef struct _ListaGeneros
{
    char genero [DIM_STR];
    ArbolPeliculas* pelis;
    struct _ListaGeneros* siguiente;
}ListaGeneros;


/**********************************************************************************/
/****************** FUNCIONES BASICAS PARA COMENZAR EL PARCIAL ********************/
/**********************************************************************************/

//INICIALIZA UNA LDA
ListaGeneros* inic_list_lda();
//CREA UN NODO LDA
ListaGeneros* nuevo_nodo_genero (const char* NUEVO_GENERO);

/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/
///Ejercicio 1
ListaGeneros* busca_genero(ListaGeneros *lista, char genero[]);
ListaGeneros* agregar_pelicula_en_lda(ListaGeneros *lista, Pelicula aux);
ListaGeneros* crear_genero(ListaGeneros *lista, char genero[]);
ListaGeneros* agregarAlInicio(ListaGeneros *lista, ListaGeneros *nuevo);
int buscarPosicionEnLista(ListaGeneros *lista, char genero[]);

///Ejercicio 2
ListaGeneros* archivo_to_lista();
int contar_peliculas_de_un_genero(ListaGeneros *lista);
int contadorDeNodos(ArbolPeliculas *arbol);
ArbolPeliculas *busca_por_genero(ListaGeneros *lista, char genero[]);

///Ejercicio 3
ArbolPeliculas * eliminar_pelicula_en_lda(ListaGeneros *lista);
void muestra_peliculas_en_lda(ListaGeneros *lista);
void inorder(ArbolPeliculas *arbol);

#endif // LISTAGENEROS_H_INCLUDED
