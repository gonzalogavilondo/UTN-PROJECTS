#include "declaraciones.h"
#include "listas.h"

int main()
{
/**
    EJ 1 AL 3
**/
//    int *vec    = NULL,
//        *vecBin = NULL,
//        *vecTxt = NULL;
//
//    int cntElementos = 0,
//        sizeBin      = 0,
//        sizeTxt      = 0;
//
//    nodo *lista;
//
//    lista = inicLista();
//
//    lista = agregarOrdenado(crearNodo(5), lista);
//    lista = agregarOrdenado(crearNodo(2), lista);
//    lista = agregarOrdenado(crearNodo(3), lista);
//    lista = agregarOrdenado(crearNodo(6), lista);
//    lista = agregarOrdenado(crearNodo(5), lista);
//
//    ///Reservo memoria primero para un vector de dimension maxima
//    vec = ReservarMemoria(MAXDIM);
//
//    ///Cargo el vector de manera dinamica y devuelvo la cantidad de elementos
//    cntElementos = CargarVector(vec);
//    printf("\nVECTOR ORIGINAL\n\n");
//    MostrarVector(vec, cntElementos);
//
//    ///Guardo el vector en un archivo binario y txt
//    Vector2ArchivoBin(vec, cntElementos, "vector.dat");
//    Vector2ArchivoTxt(vec, cntElementos, "vector.txt");
//
//    ///Levanto el archivo binario al vector
//    sizeBin = ArchivoBin2Vector(&vecBin, "vector.dat");
//    sizeTxt = ArchivoTxt2Vector(&vecTxt, "vector.txt");
//
//    ///Mostramos los vectores
//    printf("\nVECTOR BIN\n\n");
//    MostrarVector(vecBin, sizeBin);
//
//    printf("\nVECTOR TXT\n\n");
//    MostrarVector(vecTxt, sizeTxt);
//
//    ///Liberamos memoria:
//    free(vec);
//    free(vecBin);
//    free(vecTxt);

/**
    EJ 4
**/
//    int cntNodosBorrados;
//    nodo *lista;
//    int numAborrar;
//
//    lista = inicLista();
//
//    lista = agregarOrdenado(crearNodo(5), lista);
//    lista = agregarOrdenado(crearNodo(2), lista);
//    lista = agregarOrdenado(crearNodo(3), lista);
//    lista = agregarOrdenado(crearNodo(6), lista);
//    lista = agregarOrdenado(crearNodo(5), lista);
//    lista = agregarAlInicio(crearNodo(1), lista);
//    lista = agregarAlFinal(crearNodo(1), lista);
//
//    ///Muestro la lista original
//    mostrarListaEnteros(lista);
//
//    ///Elijo el numero a borrar de la lista
//    numAborrar = 1;
//
//    ///Elimino los nodos y devuelvo cuantos nodos borre
//    cntNodosBorrados = borrarNodosRepetidos(numAborrar, &lista);
//
//    ///Muestro la lista final
//    mostrarListaEnteros(lista);
//
//    printf("La cantidad de %d borrados es: %d", numAborrar, cntNodosBorrados);

/**
    EJ 5
**/
//    ///Declaramos el vector y la lista
//    int *vec = NULL;
//    int cntElementos;
//    nodo *lista;
//
//    ///Resevamos memoria e inicializamos
//    vec = ReservarMemoria(MAXDIM); ///Reservo memoria inicialmente para 10 elementos
//
//    ///MostrarVector(vec, 11);
//
//    lista = inicLista();
//
//    lista = listaRandom50(lista, 52);
//
//    cntElementos = recorrerLista(lista, &vec);
//
//    printf("--LISTA--\n");
//    mostrarListaEnteros(lista);
//
//    printf("\n--VECTOR--\n");
//    MostrarVector(vec, cntElementos);

/**
    EJ6
**/

    /**
        Escribir un programa que lea edades de un arreglo dinámico de 10 posiciones para combinarlas con 10 nombres leídos de otro arreglo
        estático de 10 posiciones. Una vez leídos ambos datos, debe generar un registro con esa info, el cual será agregado a una lista ordenada
        que finalmente mostrará por pantalla. Luego, guardar esa lista en un archivo de texto o binario y eliminar la lista. Finalmente mostrar
        el archivo resultante. Modularizar.
    **/

    int cntElementos;
    int *edades = NULL;
    char *nombres[] = {"Gonzalo", "Carlos", "Camila", "Micaela", "Romina",
                        "Pedro", "Pablo", "Melina", "Julio", "Nicolas"};
    persona *personaNueva;
    nodoSt *lista = inicListaSt();


    edades = ReservarMemoria(10); //Arreglo de 10 posiciones de arreglos

    printf("Ingresar las edades\n");
    cntElementos = CargarVector(edades);

    ///Reservo memoria para 10 personas
    personaNueva = ReservarMemoriaStruct(10);

    ///Guardo en una estructura generada por el array de edades y nombres
    personaNueva = arrays2Struct(personaNueva, edades, nombres, cntElementos);

    ///Agrego la estructura a una lista ordenada
    for(int i = 0; i < cntElementos; i++)
    {
       lista = agregarOrdenadoEdadSt(crearNodoSt(personaNueva[i]), lista);
    }

    ///Mostramos lista por pantalla
    mostrarListaStruct(lista);

    ///La guardamos en un archivo txt
    lista2archivoTxt_struct(lista, "PersonasOrdenado.txt");


    return 0;
}
