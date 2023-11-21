#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idEquipo;
    char nombreEquipo[30];
} stEquipo;

typedef struct
{
    int IdJugador;
    int NroCamisetaJugador;
    char nombreJugador[30];
    int PuntosAnotados;
} stJugador;

typedef struct
{
    int idEquipo;
    char nombreEquipo[30];
    int idJugador;
    int NroCamisetaJugador;
    char nombreJugador[30];
    int PuntosAnotados;
} stJugadorEquipo;

/// Estructura para un nodo de jugador
typedef struct NodoJugador
{
    stJugador jugador;
    struct NodoJugador* siguiente;
} NodoJugador;

/// Estructura para un equipo con su lista de jugadores
typedef struct
{
    stEquipo equipo;
    NodoJugador* jugadores; /// aca esta lista de jugadores
    struct EquipoConJugadores* siguiente;
} EquipoConJugadores;


///PROTOTIPADO
void agregarJugador(EquipoConJugadores* equipo, stJugador jugador) ;
EquipoConJugadores* leerDatosDesdeArchivo(const char* nombreArchivo) ;
void liberarMemoria(EquipoConJugadores* listaEquipos) ;
EquipoConJugadores* altaJugador(EquipoConJugadores* listaEquipos);
EquipoConJugadores* agregarEquipo(EquipoConJugadores* listaEquipos, int idEquipo, const char* nombreEquipo);
EquipoConJugadores* buscarEquipo(EquipoConJugadores* listaEquipos, int idEquipo);
void imprimoEquipos(EquipoConJugadores* listaEquipos);
void obtenerGoleadores(EquipoConJugadores* listaEquipos, stJugador* arregloGoleadores, int dim);
void calcularPorcentajeEquipo(EquipoConJugadores* listaEquipos, int idEquipo);
void generarArchivoEquiposJugadores(const char *nombreArchivo);



///===================================================================================================================

int main()
{


    char* nombreArchivo = "registroJugador.dat";
    EquipoConJugadores* listaEquipos = leerDatosDesdeArchivo(nombreArchivo);



    /// imprimo la lista de listas
    imprimoEquipos(listaEquipos);

    getchar();
    system("cls");

    /*

            ///borro la lista de jugadores para cargarla desde cero con lo que se ingrese por teclado

            printf("Voy a borrar la lista de jughadores cargada desde el archivo...\n");
            getchar();
            listaEquipos = NULL;
            system("cls");

            /// realizo el alta de 1 jugador
            listaEquipos = altaJugador(listaEquipos);

            /// imprimo la lista de listas
            imprimoEquipos(listaEquipos);
    */


    /// creamos un arreglo de goleadores (suponemos que no hay mas de 100)
    stJugador arregloGoleadores[100];

    /// obtener a los goleadores
    obtenerGoleadores(listaEquipos, arregloGoleadores, 100);

    /*
    /// Imprimir la info del arreglo de goleadores
    printf("\nArreglo de Goleadores:\n");
    int i = 0;
    while (i < 100)
    {
        if(arregloGoleadores[i].IdJugador != 0)
        {
            printf("Nombre: %s, Puntos: %d, Camiseta: %d\n", arregloGoleadores[i].nombreJugador, arregloGoleadores[i].PuntosAnotados, arregloGoleadores[i].NroCamisetaJugador);
        }
        i++;
    }
*/


    getchar();
    system("cls");

    /// calculamos y mostramos el porcentaje de jugadores de un equipo específico
    calcularPorcentajeEquipo(listaEquipos, 6);
    getchar();

    /// Pasar jugadores con un número de camiseta a un archivo binario
    pasarDeLaListaAlArchivo(listaEquipos, 9);


    /// Liberar la memoria (lujo)
    liberarMemoria(listaEquipos);


    return 0;
}

///===================================================================================================================



/// funcion para agregar un nuevo jugador a la lista de jugadores de un equipo
void agregarJugador(EquipoConJugadores* equipo, stJugador jugador)
{
    NodoJugador* nuevoJugador = (NodoJugador*)malloc(sizeof(NodoJugador));
    nuevoJugador->jugador = jugador;
    nuevoJugador->siguiente = equipo->jugadores;
    equipo->jugadores = nuevoJugador;
}

/// funcion principal para leer datos del archivo y construir la lista de listas
EquipoConJugadores* leerDatosDesdeArchivo(const char* nombreArchivo)
{
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return(1);
    }

    EquipoConJugadores* listaEquipos = NULL;

    stJugadorEquipo jugadorEquipo;

    while (fread(&jugadorEquipo, sizeof(stJugadorEquipo), 1, archivo) == 1)
    {
        /// Buscar el equipo en la lista
        EquipoConJugadores* equipoActual = listaEquipos;
        while (equipoActual != NULL && equipoActual->equipo.idEquipo != jugadorEquipo.idEquipo)
        {
            equipoActual = equipoActual->siguiente;
        }

        /// Si el equipo no existe, agregarlo a la lista principal
        if (equipoActual == NULL)
        {
            EquipoConJugadores* nuevoEquipo = (EquipoConJugadores*)malloc(sizeof(EquipoConJugadores));
            nuevoEquipo->equipo.idEquipo = jugadorEquipo.idEquipo;
            strcpy(nuevoEquipo->equipo.nombreEquipo, jugadorEquipo.nombreEquipo);
            nuevoEquipo->jugadores = NULL;
            nuevoEquipo->siguiente = listaEquipos;
            listaEquipos = nuevoEquipo;
            equipoActual = nuevoEquipo;
        }

        /// Agregar el jugador al equipo
        stJugador jugador;
        jugador.IdJugador = jugadorEquipo.idJugador;
        jugador.NroCamisetaJugador = jugadorEquipo.NroCamisetaJugador;
        strcpy(jugador.nombreJugador, jugadorEquipo.nombreJugador);
        jugador.PuntosAnotados = jugadorEquipo.PuntosAnotados;

        agregarJugador(equipoActual, jugador);
    }

    fclose(archivo);

    return listaEquipos;
}

/// funcion para liberar la memoria utilizada por la lista de listas
void liberarMemoria(EquipoConJugadores* listaEquipos)
{
    while (listaEquipos != NULL)
    {
        NodoJugador* nodoJugador = listaEquipos->jugadores;
        while (nodoJugador != NULL)
        {
            NodoJugador* siguiente = nodoJugador->siguiente;
            free(nodoJugador);
            nodoJugador = siguiente;
        }

        EquipoConJugadores* siguienteEquipo = listaEquipos->siguiente;
        free(listaEquipos);
        listaEquipos = siguienteEquipo;
    }
}

EquipoConJugadores* altaJugador(EquipoConJugadores* listaEquipos)
{
    stJugador nuevoJugador;

    printf("Ingrese el ID del jugador: ");
    scanf("%d", &nuevoJugador.IdJugador);

    printf("Ingrese el Nro de Camiseta del jugador: ");
    scanf("%d", &nuevoJugador.NroCamisetaJugador);

    printf("Ingrese el nombre del jugador: ");
    scanf("%s", nuevoJugador.nombreJugador);

    printf("Ingrese los puntos anotados por el jugador: ");
    scanf("%d", &nuevoJugador.PuntosAnotados);

    /// pregunto por el equipo al que pertenece el jugador
    int idEquipo;
    printf("Ingrese el ID del equipo al que pertenece el jugador: ");
    scanf("%d", &idEquipo);

    /// Buscar si el equipo existe
    EquipoConJugadores* equipoExistente = buscarEquipo(listaEquipos, idEquipo);

    /// Si el equipo no existe, agregarlo a la lista de equipos
    if (equipoExistente == NULL)
    {
        char nombreEquipo[30];
        printf("Ingrese el nombre del nuevo equipo: ");
        scanf("%s", nombreEquipo);

        listaEquipos = agregarEquipo(listaEquipos, idEquipo, nombreEquipo);
        equipoExistente = buscarEquipo(listaEquipos, idEquipo); /// Obtener el equipo recién agregado
    }

    /// Agregar al jugador a la lista de jugadores de ese equipo
    agregarJugador(equipoExistente, nuevoJugador);

    return listaEquipos;
}

EquipoConJugadores* agregarEquipo(EquipoConJugadores* listaEquipos, int idEquipo, const char* nombreEquipo)
{
    EquipoConJugadores* nuevoEquipo = (EquipoConJugadores*)malloc(sizeof(EquipoConJugadores));
    nuevoEquipo->equipo.idEquipo = idEquipo;
    strcpy(nuevoEquipo->equipo.nombreEquipo, nombreEquipo);
    nuevoEquipo->jugadores = NULL;
    nuevoEquipo->siguiente = listaEquipos;

    return nuevoEquipo;
}

EquipoConJugadores* buscarEquipo(EquipoConJugadores* listaEquipos, int idEquipo)
{
    while (listaEquipos != NULL)
    {
        if (listaEquipos->equipo.idEquipo == idEquipo)
        {
            return listaEquipos; /// Devolver el equipo (si se encuentra)
        }
        listaEquipos = listaEquipos->siguiente;
    }
    return NULL; /// Devolver NULL si el equipo no se encuentra
}

void imprimoEquipos(EquipoConJugadores* listaEquipos)
{
    while (listaEquipos != NULL)
    {
        printf("Equipo: %s (ID: %d)\n", listaEquipos->equipo.nombreEquipo, listaEquipos->equipo.idEquipo);

        NodoJugador* nodoJugador = listaEquipos->jugadores;
        while (nodoJugador != NULL)
        {
            printf("  Jugador: %s (ID: %d, Camiseta: %d, Puntos: %d)\n", nodoJugador->jugador.nombreJugador, nodoJugador->jugador.IdJugador, nodoJugador->jugador.NroCamisetaJugador, nodoJugador->jugador.PuntosAnotados);
            nodoJugador = nodoJugador->siguiente;
        }

        listaEquipos = listaEquipos->siguiente;
    }
}

/// funcion para pasar a un arreglo a los goleadores de cada equipo
void obtenerGoleadores(EquipoConJugadores* listaEquipos, stJugador* arregloGoleadores, int dim)
{

    void mostrarJugador(stJugador jugador)///la declaro a nivel local (solo p/prueba)
    {
        printf("ID: %d\n", jugador.IdJugador);
        printf("Nro de Camiseta: %d\n", jugador.NroCamisetaJugador);
        printf("Nombre: %s\n", jugador.nombreJugador);
        printf("Puntos Anotados: %d\n", jugador.PuntosAnotados);
    }


    int i = 0;

    while (listaEquipos != NULL)///recorro por equipos...
    {

        system("cls");
        printf("Equipo: %s \n\n",listaEquipos->equipo.nombreEquipo);

        NodoJugador* nodoJugador = listaEquipos->jugadores;
        stJugador goleador;
        /// Inicializamos los campos del goleador (p/este equipo)
        goleador.IdJugador=0;
        goleador.NroCamisetaJugador=0;
        strcpy(goleador.nombreJugador,"");
        goleador.PuntosAnotados=0;

        while (nodoJugador != NULL)///recorro por c/jugador...
        {
            if (nodoJugador->jugador.PuntosAnotados > goleador.PuntosAnotados ||
                    (nodoJugador->jugador.PuntosAnotados == goleador.PuntosAnotados &&
                     nodoJugador->jugador.NroCamisetaJugador > goleador.NroCamisetaJugador))
            {
                goleador = nodoJugador->jugador;
                printf("Habemus Goleador!\n");
                mostrarJugador(goleador);
                getchar();
            }
            nodoJugador = nodoJugador->siguiente;
        }

        if (goleador.IdJugador != 0 && i < dim)
        {
            arregloGoleadores[i] = goleador;
            printf("Goleador almacenado en el Arreglo: %s",arregloGoleadores[i].nombreJugador);
            getchar();
            i++;
        }
        listaEquipos = listaEquipos->siguiente;
    }
}

/// funcion para calcular el porcentaje de jugadores de un equipo con respecto al total
void calcularPorcentajeEquipo(EquipoConJugadores* listaEquipos, int idEquipo)
{
    int totalJugadoresTorneo = 0;
    int totalJugadoresEquipo = 0;

    /// calculamos el total de jugadores del torneo y del equipo específico
    while (listaEquipos != NULL)
    {
        NodoJugador* nodoJugador = listaEquipos->jugadores;
        while (nodoJugador != NULL)
        {
            totalJugadoresTorneo++;
            if (listaEquipos->equipo.idEquipo == idEquipo)
            {
                totalJugadoresEquipo++;
            }
            nodoJugador = nodoJugador->siguiente;
        }
        listaEquipos = listaEquipos->siguiente;
    }

    /// calculamos el porcentaje y mostramos la info por pantalla
    if (totalJugadoresTorneo > 0)
    {
        float porcentaje = (float)totalJugadoresEquipo / totalJugadoresTorneo * 100;
        printf("\nInfo del Equipo (ID: %d):\n", idEquipo);
        printf("Total de jugadores del torneo: %d\n", totalJugadoresTorneo);
        printf("Total de jugadores del equipo: %d\n", totalJugadoresEquipo);
        printf("Porcentaje con respecto al total: %.2f%%\n", porcentaje);
    }
    else
    {
        printf("\nNo hay jugadores en el torneo.\n");
    }
}

/// funcion para pasar jugadores con un nro de camiseta a un archivo binario
void pasarDeLaListaAlArchivo(EquipoConJugadores* listaEquipos, int numeroCamiseta)
{
    FILE* archivoSalida = fopen("jugadoresPorCamiseta.dat", "wb");
    if (archivoSalida == NULL)
    {
        printf("\nError al abrir el archivo de salida.\n");
        return(1);
    }

    while (listaEquipos != NULL)
    {
        NodoJugador* nodoJugador = listaEquipos->jugadores;
        while (nodoJugador != NULL)
        {
            if (nodoJugador->jugador.NroCamisetaJugador == numeroCamiseta)
            {
                stJugadorEquipo jugadorEquipo;
                jugadorEquipo.idEquipo = listaEquipos->equipo.idEquipo;
                strcpy(jugadorEquipo.nombreEquipo, listaEquipos->equipo.nombreEquipo);
                jugadorEquipo.idJugador = nodoJugador->jugador.IdJugador;
                jugadorEquipo.NroCamisetaJugador = nodoJugador->jugador.NroCamisetaJugador;
                strcpy(jugadorEquipo.nombreJugador, nodoJugador->jugador.nombreJugador);
                jugadorEquipo.PuntosAnotados = nodoJugador->jugador.PuntosAnotados;

                fwrite(&jugadorEquipo, sizeof(stJugadorEquipo), 1, archivoSalida);
            }
            nodoJugador = nodoJugador->siguiente;
        }

        listaEquipos = listaEquipos->siguiente;
    }

    fclose(archivoSalida);
    system("cls");
    printf("Jugadores con la camiseta: %d, pasaron al archivo: jugadoresPorCamiseta.dat",numeroCamiseta);
    getchar();
}

///esta funcion no se pide, esta para crear el archivo de jugadores nuevamente (por las dudas)
void generarArchivoEquiposJugadores(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        return(1);
    }

    /// le mandamo' cumbia perro!
    stJugadorEquipo jugadores[] =
    {
        {1, "Equipo A", 1, 10, "Jugador 1", 20},
        {1, "Equipo A", 2, 11, "Jugador 2", 15},
        {1, "Equipo A", 3, 12, "Jugador 3", 25},
        {2, "Equipo Z", 4, 13, "Jugador 4", 18},
        {2, "Equipo Z", 5, 14, "Jugador 5", 22},
        {2, "Equipo Z", 6, 15, "Jugador 6", 30},
    };

    /// guardamos la info en el archivo
    fwrite(jugadores, sizeof(stJugadorEquipo), sizeof(jugadores) / sizeof(stJugadorEquipo), archivo);

    fclose(archivo);
}
