#include "alumnos.h"

void mostrarUnaNota(stNotaAlumno n){
    printf("\n Legajo.........: %d ",n.legajo);
    printf("\n Alumno.........: %s ",n.apeNom);
    printf("\n Nota...........: %d \n",n.nota);
    //replicante('_',50);
}

void cargarAlumno(stNotaAlumno **alumno)
{
    *alumno = (stNotaAlumno *)malloc(sizeof(stNotaAlumno)); // Asigna memoria para la nueva persona

    if (*alumno == NULL)
    {
        perror("Error al asignar memoria");
        return;
    }

    printf("Ingrese el legajo: \n");
    scanf("%d", &((*alumno)->legajo)); ///Utiliza -> para acceder a campos de la estructura
    printf("Ingrese el nombre: \n");
    scanf("%s", (*alumno)->apeNom); ///Utiliza -> para acceder a campos de la estructura
    printf("Ingrese la edad: \n");
    scanf("%d", &((*alumno)->nota)); ///Utiliza & para obtener la dirección de edad
}
