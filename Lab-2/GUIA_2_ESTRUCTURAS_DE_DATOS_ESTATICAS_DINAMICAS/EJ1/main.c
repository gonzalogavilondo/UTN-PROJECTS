#include "declaraciones.h"

/**
    a. Crear un arreglo est�tico de 30 elementos de esta estructura y cargarlo mediante una funci�n.
    b. Hacer una funci�n que cuente la cantidad de un g�nero determinado.
    c. Hacer una funci�n que copie los datos de todos los registros de un g�nero determinado del arreglo anterior en
    otro arreglo del tama�o justo. Usar malloc dentro de la funci�n y retornarlo o usar dos par�metros de tipo arreglo y
    crear el arreglo din�mico antes de la invocaci�n.
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
