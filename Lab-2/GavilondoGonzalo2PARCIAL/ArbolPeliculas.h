#ifndef ARBOLPELICULAS_H_INCLUDED
#define ARBOLPELICULAS_H_INCLUDED


#include "Pelicula.h"


///CONSTANTES PARA LA APERTURA DE ARCHIVOS
#define LEER_AR "rb"
#define CREAR_Y_ESCRIBIR_AR "ab"
#define LEER_Y_ESCRIBIR_AR "a+b"
#define SOBREESCRIBIR_O_CREAR_AR "wb"



///  ESTA SERA NUESTRA ESTRUCTURA
///  PARA GUARDAR LAS PELICULAS
typedef struct _ArbolPeliculas
{
    Pelicula p;
    struct _ArbolPeliculas* izq;
    struct _ArbolPeliculas* der;
}ArbolPeliculas;


/**********************************************************************************/
/****************** FUNCIONES BASICAS PARA COMENZAR EL PARCIAL ********************/
/**********************************************************************************/

////INICIALIZA UN ARBOL
ArbolPeliculas* inic_arbol_pelis ();
////Carga datos en un arbol
Pelicula cargarDatoArbol(Pelicula aux);
////CREA UN NODO DE ARBOL
ArbolPeliculas* nuevo_nodo_pelicula(Pelicula nuevaPeli);
////AGREGA UNA PELICULA A UN ARBOL
ArbolPeliculas* agregar_pelicula_en_arbol (ArbolPeliculas* peliculas, Pelicula nuevaPeli);
////CARGA LAS PELICULAS DEL ARBOL A UN FILE*
//void arbol_to_archi (/* ?? */, /* ?? */);
////CARGA LAS PELICULAS DEL ARBOL A UN ARCHIVO
//void persistir_arbol (/* ?? */, /* ?? */);
//OBTIENE EL ULTIMO NODO IZQUIERDO DE UN ARBOL
ArbolPeliculas* get_last_left_node (ArbolPeliculas* movies);
//OBTIENE EL ULTIMO NODO DERECHO DE UN ARBOL
ArbolPeliculas* get_last_right_node (ArbolPeliculas* movies);
//BORRA UN NODO BUSCADO POR ID EN EL ARBO
ArbolPeliculas* borrar_nodo_pelicula (ArbolPeliculas* pelis, int idPelicula);

/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/

ArbolPeliculas* crearNodoArbol(Pelicula aux);

#endif // ARBOLPELICULAS_H_INCLUDED
