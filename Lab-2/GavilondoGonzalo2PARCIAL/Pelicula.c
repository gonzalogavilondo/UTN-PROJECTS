#include <stdio.h>
#include <stdlib.h>


#include "Pelicula.h"


/**********************************************************************************/
/****************** FUNCIONES BASICAS PARA COMENZAR EL PARCIAL ********************/
/**********************************************************************************/

//  CONVIERTE UNA ESTRUCTURA FECHA EN UN STRING Y LO RETORNA
char* fecha_to_string (Fecha f)
{
    char* stringFecha = (char*) malloc(sizeof(char) * DIM_STR);

    sprintf(stringFecha, "%02d/%02d/%02d", f.dia, f.mes, f.anio);

    return stringFecha;
}


//  MUESTRA LAS PROPIEDADES DE UNA PELICULA
void muestra_pelicula (Pelicula p)
{
    char* fechaEstreno = fecha_to_string(p.estreno);

    printf("\n                  ID: %d", p.idPelicula);
    printf("\n                  Titulo: %s", p.titulo);
    printf("\n        Fecha de estreno: %s", fechaEstreno);
    printf("\n                Duracion: %.2f\n", p.duracion);

    free(fechaEstreno);
}

/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/

