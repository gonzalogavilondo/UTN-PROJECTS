#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED


#include <conio.h>
#include <string.h>


///  CONSTANTE QUE DEFINIRA EL TAMAÑO
///  DE LOS STRINGS EN EL PROGRAMA
#define DIM_STR 50


///  ESTRUCTURA PARA LA FECHA
///  DE ESTRENO DE LAS PELICULAS
typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

///  ESTRUCTURA DEL REGISTRO QUE
///  GUARDARA LA INFORMACION DE
///  LAS PELICULAS
typedef struct
{
    int idPelicula;
    char genero [DIM_STR];
    char titulo [DIM_STR];
    float duracion;
    Fecha estreno;
}Pelicula;


/**********************************************************************************/
/****************** FUNCIONES BASICAS PARA COMENZAR EL PARCIAL ********************/
/**********************************************************************************/

//  CONVIERTE UNA ESTRUCTURA FECHA EN UN STRING Y LO RETORNA
char* fecha_to_string (Fecha f);
//  MUESTRA LAS PROPIEDADES DE UNA PELICULA
void muestra_pelicula (Pelicula p);

/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/


#endif // PELICULA_H_INCLUDED
