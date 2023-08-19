#include "declaraciones.h"


/**
    Dada una cadena de caracteres, hacer una funci�n que determine si dicha cadena es pal�ndromo
    (se lee de igual forma de adelante para atr�s como viceversa) o no. La funci�n recibe como par�metro
    la cadena y retorna 1 o 0 seg�n sea la respuesta.
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
