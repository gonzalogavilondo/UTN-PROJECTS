#include "declaraciones.h"

int main()
{
    char control;
    do
    {
        int opcion = menu();
        ejecutarEjercicio(opcion);
        system("pause");
        system("cls || clean");
        printf("Desea probar otro ejercicio? Presione s/n <si/cualquier otra letra>: ");
        fflush(stdin);
        scanf("%c", &control);

    }while (control == 's' || control == 'S');

    return 0;
}
