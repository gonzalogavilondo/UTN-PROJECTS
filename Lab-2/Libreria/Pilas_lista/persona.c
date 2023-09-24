#include "persona.h"
#include "listas.h"

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
