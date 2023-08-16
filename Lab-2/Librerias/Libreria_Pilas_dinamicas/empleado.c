#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

/**
    CargarUnEmpleado
    Parametros: Ninguno
**/
stEmpleado cargarUnEmpleado(void)
{
    stEmpleado e;
    int edad = 0;
    char *nombre   = NULL,
         *apellido = NULL;

    static int id=0;
    id++;
    e.id = id;

    ///Reservamos memoria para una cantidad de caracteres y luego reallocamos.
    nombre = (char*)malloc(sizeof(char) * LONGMAX);
    apellido = (char*)malloc(sizeof(char) * LONGMAX);

    ///Ingresamos por teclado los valores
    printf("\nIngrese el nombre del %d%c empleado: ", id, 167); ///El codigo ASCII del 167 es el caracter "�"
    fgets(nombre, LONGMAX, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';  ///Eliminamos el salto de l�nea (Al final hay una nota sobre esto)

    printf("Ingrese el apellido: ");
    fgets(apellido, LONGMAX, stdin);
    apellido[strcspn(apellido, "\n")] = '\0';  ///Eliminamos el salto de l�nea

    printf("Ingrese la edad: ");
    scanf("%d", &edad);

    ///Limpiamos el buffer
    fflush(stdin);

    ///Realocamos memoria si es necesario (opcional en este caso)
    nombre = (char*)realloc(nombre, sizeof(char) * (strlen(nombre) + 1));
    apellido = (char*)realloc(apellido, sizeof(char) * (strlen(apellido) + 1));

    strcpy(e.nombre, nombre);
    strcpy(e.apellido,apellido);
    e.edad = edad;

    ///Liberamos la memoria asignada
    free(nombre);
    free(apellido);

    /**
        Nota: Eliminar el salto de l�nea ('\n') capturado por fgets es una pr�ctica com�n cuando se lee una cadena de texto usando esta funci�n.
        La raz�n principal es que cuando el usuario ingresa un texto seguido de la tecla "Enter" (retorno de carro), el car�cter de salto de l�nea
        tambi�n se almacena en el b�fer junto con el texto ingresado.
        Esto puede causar problemas m�s adelante si est�s comparando o manipulando las cadenas de texto. Por ejemplo, si intentas comparar una cadena
        ingresada con otra cadena que has definido, la presencia del car�cter de salto de l�nea podr�a generar resultados inesperados.

        Al eliminar el car�cter de salto de l�nea utilizando la funci�n strcspn y sobrescribi�ndolo con el car�cter de terminaci�n de cadena ('\0'),
        te aseguras de que la cadena no contenga caracteres no deseados al final y puedas trabajar con ella de manera m�s confiable.
    **/

    return e;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

/**
    muestraUnEmpleado
    Parametros: Una estructura de tipo empleado.
**/
void muestraUnEmpleado(stEmpleado e)
{
    printf("\n ID:...........%d",e.id);
    printf("\n Apellido:.....%s",e.apellido);
    printf("\n Nombre:.......%s",e.nombre);
    printf("\n Edad:.........%d",e.edad);
    printf("\n ---------------------------------------");
}

char *empleadoToStr(stEmpleado e) ///no necesito recibir un string p/retornar(cocatenado), recibo solo el dom.
{
    char *s = (char *)malloc(sizeof(char)*200); ///creo un puntero llamado "s" (string) y le reservo espacio de memoria
    ///todo el string que se armo, se guarda en el espacio de memoria(no variable) "s"
    sprintf(s,"Id: %d - Apellido: %s - Nombre: %s - Edad: %d", e.id, e.apellido, e.nombre, e.edad);

    return s;///se retorna la dir de memoria (el puntero)
}
