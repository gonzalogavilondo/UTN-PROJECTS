#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArbolPeliculas.h"


/**********************************************************************************/
/****************** FUNCIONES BASICAS PARA COMENZAR EL PARCIAL ********************/
/**********************************************************************************/

//INICIALIZA UN ARBOL
ArbolPeliculas* inic_arbol_pelis ()
{
    return NULL;
}

Pelicula cargarDatoArbol(Pelicula aux)
{
    Pelicula nuevo;

    nuevo.duracion = aux.duracion;
    nuevo.estreno = aux.estreno;
    strcpy(nuevo.genero, aux.genero);
    nuevo.idPelicula = aux.idPelicula;
    strcpy(nuevo.titulo, aux.titulo);

    return nuevo;
}

//CREA UN NODO DE ARBOL
ArbolPeliculas* nuevo_nodo_pelicula (Pelicula nuevaPeli)
{
    ArbolPeliculas* nuevoNodo = (ArbolPeliculas*) malloc (sizeof (ArbolPeliculas));

    nuevoNodo->p = cargarDatoArbol(nuevaPeli);

    nuevoNodo->der = inic_arbol_pelis ();
    nuevoNodo->izq = inic_arbol_pelis ();

    return nuevoNodo;
}


//AGREGA UNA PELICULA A UN ARBOL
ArbolPeliculas* agregar_pelicula_en_arbol (ArbolPeliculas* peliculas, Pelicula nuevaPeli)
{
    if (!peliculas)
        {
        peliculas = nuevo_nodo_pelicula (nuevaPeli);
        }
    else
        {
        if ((nuevaPeli.idPelicula) > (peliculas->p.idPelicula))
            {
            peliculas->der = agregar_pelicula_en_arbol (peliculas->der, nuevaPeli);
            }
        else
            {
            peliculas->izq = agregar_pelicula_en_arbol (peliculas->izq, nuevaPeli);
            }
        }

    return peliculas;
}


//OBTIENE EL ULTIMO NODO IZQUIERDO DE UN ARBOL
ArbolPeliculas* get_last_left_node (ArbolPeliculas* movies)
{
    ArbolPeliculas* lastLeft = movies;

    if ((movies) && (movies->izq))
    {
        lastLeft = get_last_left_node (movies->izq);
    }

    return lastLeft;
}


//OBTIENE EL ULTIMO NODO DERECHO DE UN ARBOL
ArbolPeliculas* get_last_right_node (ArbolPeliculas* movies)
{
    ArbolPeliculas* lastRight = movies;

    if ((movies) && (movies->der))
        {
        lastRight = get_last_right_node (movies->der);
        }

    return lastRight;
}


//BORRA UN NODO (BUSCADO POR ID) EN EL ARBOL
ArbolPeliculas* borrar_nodo_pelicula (ArbolPeliculas* pelis, int idPelicula)
{
    if (pelis)
        {
        if (pelis->p.idPelicula == idPelicula)
        {
            if (pelis->izq)
            {
                ArbolPeliculas* lastRight = get_last_right_node (pelis->izq);

                pelis->p = lastRight->p;

                free (lastRight);
            }
            else
                {
                if (pelis->der)
                    {
                    ArbolPeliculas* lastLeft = get_last_left_node (pelis->der);

                    pelis->p = lastLeft->p;

                    free (lastLeft);
                    }
                else
                    {
                    free(pelis);
                    }
                }
            }
        else
            {
            if (idPelicula > pelis->p.idPelicula)
                {
                pelis->der = borrar_nodo_pelicula (pelis->der, idPelicula);
                }
            else
                {
                pelis->izq = borrar_nodo_pelicula (pelis->izq, idPelicula);
                }
            }
        }

    return pelis;
}


////CARGA LAS PELICULAS DEL ARBOL A UN FILE*
//void arbol_to_archi (/* ?? */, /* ?? */)
//{
//    if ((/* ?? */) && (/* ?? */))
//        {
//        ///???
//
//        arbol_to_archi(/* ?? */, /* ?? */);
//        arbol_to_archi(/* ?? */, /* ?? */);
//        }
//}



////CARGA LAS PELICULAS DEL ARBOL A UN ARCHIVO
//void persistir_arbol (/* ?? */, /* ?? */)
//{
//    FILE* pelisFile = fopen(/* ?? */, /* ?? */);
//
//    if (/* ?? */)
//        {
//        arbol_to_archi(/* ?? */, /* ?? */);
//
//        ///???
//        }
//}

/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/
