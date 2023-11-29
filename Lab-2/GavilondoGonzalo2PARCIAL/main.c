#include <stdio.h>
#include <stdlib.h>
#include "ArbolPeliculas.h"
#include "ListaGeneros.h"
#include "Pelicula.h"

/********************************************************************************************
*                                                                                           *
*  UTN - MAR DEL PLATA | Tecnicatura universitaria en Programacion                          *
*  Materia: Laboratorio 2                                                                   *
*  Comision: 10                                                                             *
*  Profesor: Lic. Aroca Adrian                                                              *
*  Ayudantes: Blanco Mariano, Martins Magdalena                                             *
*                                                                                           *
*  Nro. parcial: 2                                                                          *
*                                                                                           *
* ==========================================================================================*
*                                                                                           *
*********************************************************************************************
*****      >>>>> POR FAVOR, INGRESAR LOS DATOS QUE SE PIDEN A CONTINUACION <<<<<      *******
*********************************************************************************************
*
*  DATOS DEL ALUMNO:
*     - Apellido: Gavilondo
*     -   Nombre: Gonzalo Daniel
*     -      DNI: 40.666.672
*
*
*  Fecha que realizo este parcial: 21/11/2023
*
*********************************************************************************************
*/

int main()
{
    int contador = 0;
    ListaGeneros *lista = inic_list_lda();
    ArbolPeliculas *arbolPeliculas = inic_arbol_pelis();

    ///Ejercicio 1
    lista = archivo_to_lista();

    ///Ejercicio 2
    printf("--EJERCICIO 2--\n");
    contador = contar_peliculas_de_un_genero(lista);
    printf("\nLa cantidad de peliculas del genero seleccionado es: %d\n\n", contador);
    system("pause");
    system("cls || clear");

    ///Ejercicio 3
    printf("--EJERCICIO 3--\n");
    arbolPeliculas = eliminar_pelicula_en_lda(lista);
    system("pause");
    system("cls || clear");

    printf(" La pelicula que se elimino es: \n");
    muestra_pelicula(arbolPeliculas->p);
    system("pause");
    system("cls || clear");

    muestra_peliculas_en_lda(lista);

    system("pause");
    system("cls || clear");

    ///Ejercicio 4
    printf("--EJERCICIO 4--\n"); //No llegue :(

    return 0;
}
