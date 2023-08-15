#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define ESC 27


int main()
{
    Stack p;
    char opcion;
    int valor;

    do {
            system("cls");
            muestraMenu();

    opcion=getch();
    switch(opcion) {
    case 49:
        initStack(&p);
        printf("\n\nStack iniciado exitosamente.\n");
        system("pause");
        break;
    case 50:
        printf("\n\n");
        showStack(&p);
        system("pause");
        break;
    case 51:
        printf("Ingrese el valor a apilar: ");
        fflush(stdin);
        scanf("%i", &valor);
        push(&p, valor);
        break;
    case 52:
        valor = pull(&p);
        printf("\n\nSe ha desapilador el valor %i\n", valor);
        system("pause");
        break;
    case 53:
        valor = top(&p);
        printf("\n\nEl valor del tope de la pila es %i\n", valor);
        system("pause");
        break;
    case 54:
        valor = emptyStack(&p);
        if (valor == 1) {
            printf("\n\nLa pila esta vacia.\n");
        }else {
            printf("\n\nLa pila contiene datos.\n");
        }
        system("pause");
        break;

    }

    }while(opcion!=ESC);


    return 0;
}

void muestraMenu() {

    printf("\n\t\tTP 2 - Ejercicio 3 - Julio Missart\n");
    printf("\n1. Inicializar Pila.");
    printf("\n2. Mostrar Pila.");
    printf("\n3. Apilar");
    printf("\n4. Desapilar");
    printf("\n5. Tope");
    printf("\n6. Pila vacia.");
}
