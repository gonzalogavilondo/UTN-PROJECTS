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

    nodo* lista_A;
    nodo* lista_B;
    nodo* lista_C;

    ///Inicializo la lista en NULL
    lista = inicLista();

    lista_A = inicLista();
    lista_B = inicLista();
    lista_C = inicLista();

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
                mostrarListaEnteros(lista);
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
            case 55:
                system("cls");
                ///Lista A
                lista_A = listaRandomOrdenado(lista_A, 5);
                printf("-LISTA A-\n");
                mostrarListaEnteros(lista_A);

                ///Lista B
                lista_B = listaRandomOrdenado(lista_B, 5);
                printf("\n-LISTA B-\n");
                mostrarListaEnteros(lista_B);

                ///Lista C
                lista_C = intercalarListas(lista_A, lista_B, lista_C);
                printf("\n-LISTA C-\n");
                mostrarListaEnteros(lista_C);
                printf("\n");
                system("pause");
                break;
            case 56:
                system("cls");
                lista = listaRandomOrdenado(lista, 7);
                printf("\n-LISTA A INVERTIR-\n");
                mostrarListaEnteros(lista);
                printf("\n");
                lista = invertirLista(lista);
                printf("\n-LISTA INVERTIDA-\n");
                mostrarListaEnteros(lista);


                system("pause");
                break;
        }

    }while(opcion != ESC);

    ///Libero memoria de lista
    free(lista);
    //free(lista_C);
    free(lista_A);
    free(lista_B);

    return 0;
}
