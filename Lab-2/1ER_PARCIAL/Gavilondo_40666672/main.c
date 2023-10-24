#include "declaraciones.h"

int main()
{
    int cntNoSeleccionados;
    jugador *arregloResto = NULL;

    ///Creo el nodo
    nodoJugador *lista = inicLista();
    nodoJugador *listaSeleccionados = inicLista();

    ///Creo una lista en base al archivo binario
    lista = armaListaJugadores("jugadores.dat");

    ///Mostramos la lista de todos los jugadores
    muestraLista(lista);

    ///Armamos la lista de jugadores de boca y de river
    /**
        NOTA: EL MEMORY LEAK ESTA ACA, EN LA PROXIMA INVOCACION, NO SE PORQUE TENGO FUGA DE MEMORIA O BUCLE INFINITO EN ESTA
        FUNCION...NO SE SI ES LA MAQUINA O SIMPLEMENTE HAY ALGO QUE NO VEO, PERO ACA ES DONDE TENGO UN PROBLEMA DE MEMORIA
        O ALGO QUE SE CUELGA, POR LO DEMAS ESPERO QUE ESTE BIEN, YA QUE SEGUI DE IGUAL MANERA EL PARCIAL.
    **/
    listaSeleccionados = armaJugadoresSeleccionados(lista);

    ///Mostramos por pantalla la lista de jugadores de boca y de river
    printf("\n\n--JUGADORES DE BOCA Y DE RIVER--\n\n");
    muestraLista(listaSeleccionados);


    ///Agregamos en arregloResto los equipos que no esten en los mencionados
    ///Cuento la cantidad de no seleccionados y luego lo paso por parametro

    cntNoSeleccionados = contarNoSeleccionados(lista);
    arregloResto = restoEquipos(lista, cntNoSeleccionados);


    ///Mostramos el arreglo con el resto de los equipos
    muestraRestoEquipos(arregloResto, cntNoSeleccionados);


    ///Liberamos el arreglo dinamico
    free(arregloResto);

    return 0;
}
