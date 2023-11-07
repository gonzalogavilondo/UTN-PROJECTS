#include "declaraciones.h"

int main()
{
    int validos = 0;
    celda arreglo[MAXDIM];

    ///Ejercicio 1
    validos = archivo2ADA(arreglo);

    ///Ejercicio 2
    mostrarADA(arreglo, validos);

    char nombrePaciente[30];
    char apellidoPaciente[30];
    char nombreEspecialidad[30];
    char nombreArchivo[50];
    int opcion;
    int idEspecialidadBusqueda;

    do {
        printf("\n*** Menú de opciones ***\n");
        printf("1. Agregar nueva atención médica\n");
        printf("2. Buscar si un paciente fue atendido en una especialidad determinada\n");
        printf("3. Determinar qué especialidad médica tuvo más atenciones\n");
        printf("4. Realizar la persistencia de las atenciones médicas de una especialidad médica en particular\n");
        printf("5. Salir\n");
        printf("Ingrese la opción deseada: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                agregarNuevaAtencion(arreglo, validos);
                break;
            case 2:
                // Ejercicio 5: Buscar paciente en una especialidad
                printf("Ingrese el nombre del paciente (solo el nombre): ");
                getchar(); // Consumir el salto de línea pendiente del ingreso anterior
                fgets(nombrePaciente, sizeof(nombrePaciente), stdin);
                nombrePaciente[strcspn(nombrePaciente, "\n")] = '\0'; // Elimina el salto de línea

                printf("Ingrese el apellido del paciente: ");
                fgets(apellidoPaciente, sizeof(apellidoPaciente), stdin);
                apellidoPaciente[strcspn(apellidoPaciente, "\n")] = '\0'; // Elimina el salto de línea

                printf("Ingrese el ID de la especialidad médica: ");
                scanf("%d", &idEspecialidadBusqueda);
                int encontrado = buscarPacienteEnEspecialidad(arreglo, validos, nombrePaciente, apellidoPaciente, idEspecialidadBusqueda);
                if (encontrado)
                {
                    printf("El paciente fue atendido en la especialidad médica especificada.\n");
                }
                else
                {
                    printf("El paciente no fue atendido en la especialidad médica especificada.\n");
                }
                break;

            case 3:
                // Ejercicio 6: Determinar especialidad con más atenciones
                especialidadConMasAtenciones(arreglo, validos);
                break;
            case 4:
                // Ejercicio 7: Persistencia de atenciones de una especialidad
                printf("Ingrese el nombre de la especialidad médica: ");
                scanf("%s", nombreEspecialidad);
                printf("Ingrese el nombre del archivo de salida: ");
                scanf("%s", nombreArchivo);
                guardarEspecialidadEnArchivo(arreglo, validos, nombreEspecialidad, nombreArchivo);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, elija una opción válida.\n");
        }
        system("pause");

    } while (opcion != 5);

    return 0;
}
