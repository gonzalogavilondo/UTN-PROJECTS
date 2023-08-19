#include "declaraciones.h"

int esPalindromo(char cadena[])
{
    int i = 0;
    int j = strlen(cadena) - 1;
    while (i < j)
    {
        if (cadena[i] != cadena[j])
        {
            return 0; // No es palíndromo
        }
        i++;
        j--;
    }
    return 1; // Es palíndromo
}
