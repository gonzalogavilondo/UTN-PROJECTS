#include "listas.h"

int main()
{
    char archivoEnteros[] = "enteros.dat";
    char opcion;
    int detalle;

    ///Genero un archivo de enteros aleatorios
    generaArchivoEnteros(archivoEnteros);

    ///Declaro la lista
    nodo* lista;

    ///Inicializo la lista en NULL
    lista = inicLista();

    do
    {
        system("cls");
        mostrarMenu();
        opcion = getch(); //La función getch() lee un carácter desde la entrada estándar (generalmente el teclado) y devuelve el valor ASCII de ese carácter como un entero.
                          //El valor ASCII para '1' es 49, '2' es 50, '3' es 51, y así sucesivamente.
        switch(opcion)
        {
            case 49:
                generaArchivoEnteros(archivoEnteros);
                break;
            case 50:
                system("cls");
                muestraArchivoEnteros(archivoEnteros);
                system("pause");
                break;
            case 51:
                lista = archivo2lista(lista, archivoEnteros);
                break;
            case 52:
                system("cls");
                mostrarLista(lista);
                system("pause");
                break;
            case 53:
                lista = archivo2ListaOrdenado(lista, archivoEnteros);
                break;
            case 54:
                system("cls");
                printf("\nIngrese el dato que quiera borrar de la lista: ");
                scanf("%d", &detalle);
                lista = borrarNodo(detalle, lista);
                system("pause");
                break;
        }

    }while(opcion!=ESC);

    return 0;
}
