#include "declaraciones.h"

/**
    a. Crear un arreglo estático de 30 elementos de esta estructura y cargarlo mediante una función.
    b. Hacer una función que cuente la cantidad de un género determinado.
    c. Hacer una función que copie los datos de todos los registros de un género determinado del arreglo anterior en
    otro arreglo del tamaño justo. Usar malloc dentro de la función y retornarlo o usar dos parámetros de tipo arreglo y
    crear el arreglo dinámico antes de la invocación.
**/

int main()
{
    const int size = 3;
    int cntMasculinos = 0;
    ///Declaramos un arreglo de personas
    persona personas[size];
    persona *masculinos = NULL;

    ///Cargamos los datos 3 personas
    cargarPersonas(personas, size);

    ///Contamos la cantidad de un genero en este caso masculino
//    cntMasculinos = contarGenero(personas, size, 'M');

    ///Llamamos a la funcion que copie todos los datos de un genero en un arreglo dinamico usando la funcion contarGenero
    masculinos = copiarGenero(personas, size, 'M', &cntMasculinos);

    system("pause");
    system("cls || clear");

    ///Imprimimos las personas
    printf("\t  ----TODAS LAS PERSONAS---\n");
    imprimirPersonas(personas, size);

    ///Imprimimos los masculinos
    printf("\n\t----PERSONAS DE GENERO MASCULINO---\n");
    imprimirPersonas(masculinos, cntMasculinos);

    printf("\nLa cantidad de hombres son: %d\n", cntMasculinos);

    ///Libero memoria
    free(masculinos);

    return 0;
}
