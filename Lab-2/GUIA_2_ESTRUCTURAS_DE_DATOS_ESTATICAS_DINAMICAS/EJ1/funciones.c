#include "declaraciones.h"

// a. Crear un arreglo est�tico de 30 elementos de esta estructura y cargarlo mediante una funci�n.
void cargarPersonas(persona arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("--INGRESE LOS DATOS DE LA %d%c PERSONA--\n\n", i+1, 167);
        printf("Ingrese nombre: ");
        scanf("%s", arreglo[i].nombre);
        printf("Ingrese genero (M/F): ");
        scanf(" %c", &arreglo[i].genero);
        printf("Ingrese edad: ");
        scanf("%d", &arreglo[i].edad);
        printf("\n");
    }
}

// b. Hacer una funci�n que cuente la cantidad de un g�nero determinado.
int contarGenero(persona arreglo[], int n, char generoBuscado)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arreglo[i].genero == generoBuscado)
        {
            count++;
        }
    }
    return count;
}


// c. Hacer una funci�n que copie los datos de un g�nero determinado en un arreglo din�mico.
persona* copiarGenero(persona arreglo[], int n, char generoBuscado, int* count)
{
    *count = contarGenero(arreglo, n, generoBuscado);
    persona* nuevoArreglo = (persona*)malloc(*count * sizeof(persona));
    if (nuevoArreglo != NULL)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (arreglo[i].genero == generoBuscado)
            {
                nuevoArreglo[j] = arreglo[i];
                j++;
            }
        }
    }
    return nuevoArreglo;
}

void imprimirPersonas(persona arreglo[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        printf("\n---------------DATOS DE LA %d%c PERSONA-----------------\n", i+1, 167);
        printf("Nombre: %s\n", arreglo[i].nombre);
        printf("Edad: %d\n", arreglo[i].edad);
        printf("Genero: %c\n", arreglo[i].genero);
        printf("--------------------------------------------------------\n");
    }
}
