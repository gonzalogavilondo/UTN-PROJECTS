#include "declaraciones.h"

nodoJugador* inicLista()
{
    return NULL;
}

/**
   1.Crear la función (crearNodoJugador), que reciba como parámetro un registro de tipo jugador, y
    devuelva un nodo de tipo nodoPedido
**/

nodoJugador* crearNodoJugador(jugador registro)
{
    nodoJugador *nuevo = (nodoJugador*) malloc(sizeof(nodoJugador));
    if(nuevo == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }

    nuevo->UnJugador.dni = registro.dni;
    strcpy(nuevo->UnJugador.nombre_apellido, registro.nombre_apellido);
    nuevo->UnJugador.edad = registro.edad;
    strcpy(nuevo->UnJugador.equipo, registro.equipo);
    nuevo->sig = NULL;

    return nuevo;
}

/**
    2.Crear la función (agregarNodoJugador), que reciba la lista y un registro del tipo jugador y agregue ese
    nodo de manera ordenada segun dni. No recuerdo como hacerlo ordenado, lo inserto al ifnal
**/
nodoJugador* agregarNodoJugador(nodoJugador *lista, jugador registro)
{
    nodoJugador *nuevo = crearNodoJugador(registro); ///Creo el nodo con la funcion anterior, con el registro que paso por parametro

    if(lista == NULL) ///Si la lista esta vacia, agrego en la posicion del primer elemento.
    {
        lista = nuevo;
    }
    else
    {
        nodoJugador *ultimo = buscaUltimoLista(lista);
        ultimo->sig = nuevo;
    }

    return lista;
}

nodoJugador* buscaUltimoLista(nodoJugador *lista)
{
    nodoJugador *seg = lista;
    if(seg != NULL)
    {
        while(seg->sig != NULL)
        {
            seg = seg->sig;
        }
    }
    return seg;
}

/**
    3.Crea la funcion armaListaJugadores y recibe como parametro "jugadores.dat"
**/

nodoJugador* armaListaJugadores(const char *nombreArchivo)
{
    nodoJugador *lista = inicLista();
    jugador jugadorNuevo; ///Registro donde voy a guardar lo levantado
    FILE *archivo = fopen(nombreArchivo, "rb");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        exit(1); ///Codigo de error = 1
    }

    rewind(archivo);
    while(fread(&jugadorNuevo, sizeof(jugadorNuevo), 1, archivo) > 0) ///fread devuelve el numero de datos leidos
    {
        lista = agregarNodoJugador(lista, jugadorNuevo);
    }
    fclose(archivo);
    return lista;
}

/**
    4.Crear una función (muestraLista) que permita recorrer y mostrar la lista. La misma debe ser recursiva
**/

void mostrarUnNodo(nodoJugador *lista)
{
    if (lista != NULL)
    {
        printf("Dni: %d\n", lista->UnJugador.dni);
        printf("Nombre y apellido: %s\n", lista->UnJugador.nombre_apellido);
        printf("Edad: %d\n", lista->UnJugador.edad);
        printf("Equipo: %s\n", lista->UnJugador.equipo);
        puts("\n");
    }
    else
    {
        printf("Nodo no válido.\n");
    }
}

void muestraLista(nodoJugador *lista)
{
    if(lista != NULL)
    {
        mostrarUnNodo(lista);
        muestraLista(lista->sig);
    }
}

/**
    5. Crea la funcion (armaJugadoresSeleccionados) la cual debera recorrer la lista listaJugadores y a partir de ella
    armar la lista listaSeleccionados (lista simple) la cual contendra a los jugadores de RIVER PLATE y BOCA JUNIORS
**/

nodoJugador* armaJugadoresSeleccionados(nodoJugador *listaJugadores)
{
    nodoJugador *listaSeleccionados = inicLista();

    /**
        Nota del main: Aca es donde se rompe el programa, no se si es un memory leak o donde es que esta esa fuga de memoria
        o bucle infinito, no lo pude detectar... intente hacer el resto de la funcionalidad sin poder ver esto.
    **/

    while(listaJugadores != NULL)
    {
        ///Comparo si un jugador es de Boca juniors o de river plate, si es asi guardo en listaSeleccionados
        if( (strcmp(listaJugadores->UnJugador.equipo, "Boca Juniors") == 0) ||
            (strcmp(listaJugadores->UnJugador.equipo, "River Plate") == 0))
        {
            //listaSeleccionados = agregarNodoJugador(listaJugadores, listaJugadores->UnJugador);
            listaSeleccionados = agregarNodoJugador(listaSeleccionados, listaJugadores->UnJugador);

        }
        listaJugadores = listaJugadores->sig;
        mostrarUnNodo(listaJugadores);
    }

    return listaSeleccionados;
}

/**
    6. Crear la funcion restoEquipos, la cual genere un arreglo dinamico llamado arregloResto, quien contendra a todos los jugadores que no pertenezcan a los equipos mencionaods en el ejercicio anterior. La
    funcion debe recibir como parametro la listaJugadores y retornar un puntero al arreglo. Modularizar mediante la funcion
    int contarNoSeleccionados, la cual recorrera la listaJugadores y devolvera la cantidad de ellos que no pertenecen a los equipos
    mencionados
**/

jugador* restoEquipos(nodoJugador *listaJugadores, int cntJugadores)
{
    int cnt = 0;

    jugador* arregloResto = (jugador*)malloc(cntJugadores * sizeof(jugador));
    if(arregloResto == NULL)
    {
        perror("No se ha podido reservar memoria.\n");
        exit(1);
    }

    while(cnt < cntJugadores)
    {
        ///Si un jugador es de boca juniors o de river plate
        if( (strcmp(listaJugadores->UnJugador.equipo, "Boca Juniors") == 0) ||
            (strcmp(listaJugadores->UnJugador.equipo, "River Plate") == 0))
        {
            lista2array(listaJugadores, &arregloResto[cnt]);
            cnt++;
        }
    }

    return arregloResto;
}

int contarNoSeleccionados(nodoJugador* lista)
{
    int cnt = 0;

    while(lista != NULL)
    {
        ///Si un jugador es de boca juniors o de river plate
        if( (strcmp(lista->UnJugador.equipo, "Boca Juniors") == 0) ||
            (strcmp(lista->UnJugador.equipo, "River Plate") == 0))
        {
            ///Es de boca o de river
        }
        else
        {
            cnt++;
        }

    }

    return cnt;
}

///Funcion para pasar de una lista a un arreglo
void lista2array(nodoJugador *lista, jugador *registro)
{
    if(lista != NULL)
    {
        registro->dni = lista->UnJugador.dni;
        strcpy(registro->nombre_apellido, lista->UnJugador.nombre_apellido);
        registro->edad = lista->UnJugador.edad;
        strcpy(registro->equipo, lista->UnJugador.equipo);
    }
}

void muestraRestoEquipos(jugador *arregloResto, int cntRegistros)
{
    for(int i = 0; i < cntRegistros; i++)
    {
        printf("Dni: %d\n", arregloResto[i].dni);
        printf("Nombre y apellido: %s\n", arregloResto[i].nombre_apellido);
        printf("Edad: %d\n", arregloResto[i].edad);
        printf("Equipo: %s\n", arregloResto[i].equipo);
        puts("\n");
    }
}

void imprimirFila(fila filaSeleccion)
{
    nodoJugadorD *actual = filaSeleccion.pri;
    printf("\nImprimiendo la FILA SELECCION...\n");
    while (actual != NULL)
    {
         printf("DNI: %d, Nombre: %s, Edad: %d, Equipo: %s\n",
         actual->UnJugador.dni,
         actual->UnJugador.nombre_apellido,
         actual->UnJugador.edad,
         actual->UnJugador.equipo);
         actual = actual->siguiente;
    }
}

void inicializarFila(fila* miFila)
{
    miFila->pri = NULL;
    miFila->ult = NULL;
}

fila armaSeleccion(nodoJugador* listaSeleccionados)
{
    fila filaJugadores; ///Declarar la FILA
    inicializarFila(&filaJugadores); ///Inicializar la FILA

    ///Recorrer la lista de jugadores pedidos
    nodoJugador* actual = listaSeleccionados;
    while (actual != NULL)
    {
        if (listaSeleccionados->UnJugador.edad < 30)
        {
            ///Si la edad de un jugador es menor a 30
            poneFila(&filaJugadores, actual);
        }
        actual = actual->sig;
    }

    return filaJugadores; ///Devolver la FILA con los jugadores con edad menor a 30
}

void buscarJugador(fila* filaJugador, int dni)
{
    nodoJugadorD* actual = filaJugador->pri;
    int encontrado = 0; ///Bandera para verificar si se encontró

    while (actual != NULL)
    {
        if (actual->UnJugador.dni == dni)
        {
            ///Si se encuentra el jugador, lo muestro
            printf("Nombre y apellido: %s\n", actual->UnJugador.nombre_apellido);
            printf("Pedido encontrado:\n");
            printf("Dni: %d\n", actual->UnJugador.dni);
            printf("Edad: %d\n", actual->UnJugador.edad);
            printf("Equipo: %s\n", actual->UnJugador.equipo);
            encontrado = 1; ///Establecer la bandera a 1 para indicar que se encontró el jugador pedido
            break; ///Salir del bucle una vez que se encuentra el jugador (No es lo recomendable un break, pero dada las circunstancias...)
        }
        actual = actual->siguiente;
    }

    if (!encontrado)
    {
        printf("Jugador con número de dni %d no encontrado en la FILA.\n", dni);
    }
}

/**
    8 y 9. Funciones adicionales para terminar el ejercicio
**/
void poneFila(fila* f, nodoJugador* jug)
{
    nodoJugadorD* nuevo = crearNodoD(jug);

    if (vaciaFila(f))
    {
        f->pri = nuevo;
        f->ult = nuevo;
    }
    else
    {
        f->ult->siguiente = nuevo;
        nuevo->anterior = f->ult;
        f->ult = nuevo;
    }
}

int vaciaFila(fila* f)
{
    return (f->pri == NULL);
}

nodoJugadorD* crearNodoD(nodoJugador* jug)
{
    nodoJugadorD* nuevo = (nodoJugadorD*)malloc(sizeof(nodoJugadorD));
    nuevo->UnJugador = jug->UnJugador;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

