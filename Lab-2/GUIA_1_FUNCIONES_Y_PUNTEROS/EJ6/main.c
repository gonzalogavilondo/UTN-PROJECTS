#include "declaraciones.h"


/**
    Dada una cadena de caracteres, hacer una función que determine si dicha cadena es palíndromo
    (se lee de igual forma de adelante para atrás como viceversa) o no. La función recibe como parámetro
    la cadena y retorna 1 o 0 según sea la respuesta.
**/

int main()
{
    char *cadena = NULL;

    ///Reservamos memoria para 100 lugares
    cadena = (char *)malloc(sizeof(char)*100);

    printf("Ingrese una cadena: ");
    scanf("%s", cadena);

    ///Reallocamos la memoria asignada por lo que se ingreso
    cadena = (char *)realloc(cadena, sizeof(char)*strlen(cadena));

    if (esPalindromo(cadena))
    {
        printf("La cadena es un palindromo.\n");
    }
    else
    {
        printf("La cadena no es un palindromo.\n");
    }

    free(cadena);

    return 0;
}
