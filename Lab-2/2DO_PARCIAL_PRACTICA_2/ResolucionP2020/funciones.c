#include "declaraciones.h"

/**
*   Ejercicio 1
**/
int archivo2ADA(celda arreglo[])
{
    int validos = 0;
    FILE *buf = fopen("registroMedico.dat", "rb");

    stRegistroMedico aux;

    if(buf)
    {
        while(fread(&aux, sizeof(stRegistroMedico), 1, buf) > 0 && validos < MAXDIM) //Donde, MAXDIM es una constante definida en declaraciones.h, la cual es 10 como indica el enunciado.
        {
            validos = alta(arreglo, validos, aux);
        }
        fclose(buf);
    }

    return validos;
}

int alta(celda arreglo[], int validos, stRegistroMedico aux)
{
    int pos = buscarPosicion(arreglo, validos, aux.idEspecialidad);

    if(pos == -1)
    {
        validos = agregarEspecialidad(arreglo, validos, aux.idEspecialidad, aux.especialidadMedica, aux.diagnostico, aux.fechaAtencion, aux.nombreDoctor);
        pos = validos - 1;
    }
    nodoArbol *nuevo = crearNodoArbol(aux);
    arreglo[pos].arbolPacientes = insertarNodo(arreglo[pos].arbolPacientes, nuevo);

    return validos;
}

nodoArbol* crearNodoArbol(stRegistroMedico aux)
{
    nodoArbol *nuevo = malloc(sizeof(nodoArbol));

    nuevo->dato = cargarDatoArbol(aux);
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

stPaciente cargarDatoArbol(stRegistroMedico aux)
{
    stPaciente nuevo;

    nuevo.idPaciente = aux.idPaciente;
    strcpy(nuevo.nombrePaciente, aux.nombrePaciente);
    strcpy(nuevo.apellidoPaciente, aux.apellidoPaciente);

    return nuevo;
}

int buscarPosicion(celda arreglo[], int validos, int idEspecialidad)
{
    int pos = -1;
    int i = 0;

    while(i < validos && pos == -1)
    {
        if(arreglo[i].especialidad.idEspecialidad == idEspecialidad)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

int agregarEspecialidad(celda arreglo[], int validos, int idEspecialidad, char especialidadMedica[], char diagnostico[], char fechaAtencion[], char nombreDoctor[])
{
    arreglo[validos].especialidad.idEspecialidad = idEspecialidad;
    strcpy(arreglo[validos].especialidad.especialidadMedica, especialidadMedica);
    strcpy(arreglo[validos].especialidad.diagnostico, diagnostico);
    strcpy(arreglo[validos].especialidad.fechaAtencion, fechaAtencion);
    strcpy(arreglo[validos].especialidad.nombreDoctor, nombreDoctor);
    arreglo[validos].arbolPacientes = inicArbol();
    validos++;

    return validos;
}

nodoArbol *inicArbol()
{
    return NULL;
}

nodoArbol *insertarNodo(nodoArbol *arbol, nodoArbol *nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(strcmp(nuevo->dato.nombrePaciente, arbol->dato.nombrePaciente) > 0)
        {
            arbol->der = insertarNodo(arbol->der, nuevo);
        }
        else
        {
            arbol->izq = insertarNodo(arbol->izq, nuevo);
        }
    }

    return arbol;
}

/**
*   Ejercicio 2
**/
void mostrarADA(celda arreglo[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("------------------------------------\n");
        printf("Especialidad %s (ID %i)\nDiagnostico: %s\nFecha Atencion: %s\nNombreDoctor: %s\n", arreglo[i].especialidad.especialidadMedica, arreglo[i].especialidad.idEspecialidad, arreglo[i].especialidad.diagnostico, arreglo[i].especialidad.fechaAtencion, arreglo[i].especialidad.nombreDoctor );
        printf("------------------------------------\n");
        printf("------------------------------------\n");
        inorder(arreglo[i].arbolPacientes);
    }
}

void inorder(nodoArbol *arbol)
{
    if(arbol)
    {
        inorder(arbol->izq);
        mostrarPaciente(arbol->dato);
        inorder(arbol->der);
    }
}

void mostrarPaciente(stPaciente aux)
{
    printf("ID: %d\n", aux.idPaciente);
    printf("Nombre y apellido: %s %s\n", aux.nombrePaciente, aux.apellidoPaciente);
    printf("--------------------------------------------------\n");
}

/**
    Ejercicio 4
**/
void agregarNuevaAtencion(celda arreglo[], int validos)
{
    stRegistroMedico nuevaAtencion;
    printf("Ingrese el ID del paciente: ");
    scanf("%d", &nuevaAtencion.idPaciente);

    // Aquí puedes agregar más solicitudes de datos al usuario según la estructura del registro médico

    printf("Ingrese la especialidad médica: ");
    scanf("%s", nuevaAtencion.especialidadMedica);

    printf("Ingrese el diagnóstico: ");
    scanf("%s", nuevaAtencion.diagnostico);

    // Puedes continuar solicitando y asignando los datos necesarios a 'nuevaAtencion'

    int pos = buscarPosicion(arreglo, validos, nuevaAtencion.idEspecialidad);

    if (pos == -1)
    {
        validos = agregarEspecialidad(arreglo, validos, nuevaAtencion.idEspecialidad, nuevaAtencion.especialidadMedica, nuevaAtencion.diagnostico, nuevaAtencion.fechaAtencion, nuevaAtencion.nombreDoctor);
        pos = validos - 1;
    }
    nodoArbol* nuevo = crearNodoArbol(nuevaAtencion);
    arreglo[pos].arbolPacientes = insertarNodo(arreglo[pos].arbolPacientes, nuevo);

    printf("Atención agregada exitosamente.\n");
}


/**
    Ejercicio 5
**/
int buscarPacienteEnEspecialidad(celda arreglo[], int validos, char nombrePaciente[], char apellidoPaciente[], int idEspecialidad)
{
    for (int i = 0; i < validos; i++)
    {
        if (arreglo[i].especialidad.idEspecialidad == idEspecialidad)
        {
            nodoArbol* pacienteEncontrado = buscarPacienteEnArbol(arreglo[i].arbolPacientes, nombrePaciente, apellidoPaciente);
            if (pacienteEncontrado != NULL)
            {
                return 1; // Encontrado
            }
        }
    }
    return 0; // No encontrado
}

nodoArbol* buscarPacienteEnArbol(nodoArbol* arbol, char nombrePaciente[], char apellidoPaciente[])
{
    if (arbol == NULL)
    {
        return NULL;
    }
    int comparacion = strcmp(nombrePaciente, arbol->dato.nombrePaciente);
    if (comparacion < 0)
    {
        return buscarPacienteEnArbol(arbol->izq, nombrePaciente, apellidoPaciente);
    }
    else if (comparacion > 0)
    {
        return buscarPacienteEnArbol(arbol->der, nombrePaciente, apellidoPaciente);
    }
    else
    {
        comparacion = strcmp(apellidoPaciente, arbol->dato.apellidoPaciente);
        if (comparacion == 0)
        {
            return arbol; // Paciente encontrado
        }
    }
    return NULL;
}

/**
    Ejercicio 6
**/
void especialidadConMasAtenciones(celda arreglo[], int validos)
{
    int maxAtenciones = 0;
    char especialidadMasAtendida[30];

    for (int i = 0; i < validos; i++)
    {
        int atencionesEnEspecialidad = contarAtencionesEnEspecialidad(arreglo[i].arbolPacientes);
        if (atencionesEnEspecialidad > maxAtenciones)
        {
            maxAtenciones = atencionesEnEspecialidad;
            strcpy(especialidadMasAtendida, arreglo[i].especialidad.especialidadMedica);
        }
    }

    printf("La especialidad con más atenciones es: %s (%d atenciones)\n", especialidadMasAtendida, maxAtenciones);
}

int contarAtencionesEnEspecialidad(nodoArbol* arbol)
{
    if (arbol == NULL)
    {
        return 0;
    }
    return 1 + contarAtencionesEnEspecialidad(arbol->izq) + contarAtencionesEnEspecialidad(arbol->der);
}


/**
    Ejercicio 7
**/
void guardarEspecialidadEnArchivo(celda arreglo[], int validos, char nombreEspecialidad[], char nombreArchivo[])
{
    for (int i = 0; i < validos; i++)
    {
        if (strcmp(arreglo[i].especialidad.especialidadMedica, nombreEspecialidad) == 0)
        {
            FILE* archivoSalida = fopen(nombreArchivo, "wb");
            if (archivoSalida)
            {
                guardarArbolEnArchivo(arreglo[i].arbolPacientes, archivoSalida);
                fclose(archivoSalida);
                printf("Datos de la especialidad '%s' guardados en '%s'.\n", nombreEspecialidad, nombreArchivo);
            }
            else
            {
                printf("No se pudo abrir el archivo de salida.\n");
            }
            return;
        }
    }
    printf("Especialidad no encontrada: '%s'\n", nombreEspecialidad);
}

void guardarArbolEnArchivo(nodoArbol* arbol, FILE* archivo)
{
    if (arbol)
    {
        fwrite(&arbol->dato, sizeof(stPaciente), 1, archivo);
        guardarArbolEnArchivo(arbol->izq, archivo);
        guardarArbolEnArchivo(arbol->der, archivo);
    }
}


