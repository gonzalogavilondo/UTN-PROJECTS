#include "persona.h"
#include "listas.h"
#include <string.h> // Para usar strcpy

void mostrarPersona(persona per)
{
    printf("Nombre: %s\n",per.nombre);
    printf("Edad: %d\n",per.edad);
}

void cargarPersona(persona **personaNueva)
{
    *personaNueva = (persona *)malloc(sizeof(persona)); // Asigna memoria para la nueva persona

    if (*personaNueva == NULL)
    {
        perror("Error al asignar memoria");
        return;
    }

    printf("Ingrese el nombre: \n");
    scanf("%s", (*personaNueva)->nombre); ///Utiliza -> para acceder a campos de la estructura
    printf("Ingrese la edad: \n");
    scanf("%d", &((*personaNueva)->edad)); ///Utiliza & para obtener la dirección de edad
}

persona* arrays2Struct(persona *personaNueva, int *edades, char *nombres[], int cntElementos)
{
    for(int i = 0; i < cntElementos; i++)
    {
        personaNueva[i].edad = edades[i];
        strcpy(personaNueva[i].nombre, nombres[i]);
    }

    return personaNueva;
}

persona *ReservarMemoriaStruct(int cntPersonas)
{
    persona *personaNueva = NULL;

    // Asigna memoria para el nuevo arreglo de personas
    personaNueva = (persona *)malloc(cntPersonas * sizeof(persona));

    if (personaNueva == NULL)
    {
        perror("Error al asignar memoria");
        return NULL;
    }

    return personaNueva;
}



persona createPersona(int edad, const char *nombre)
{
    persona nuevaPersona;
    nuevaPersona.edad = edad;

    // Asegúrate de que el nombre no exceda el tamaño de tu arreglo
    if (nombre != NULL) {
        strncpy(nuevaPersona.nombre, nombre, sizeof(nuevaPersona.nombre));
    } else {
        nuevaPersona.nombre[0] = '\0'; // Si no se proporciona un nombre, se establece como cadena vacía
    }

    return nuevaPersona;
}
