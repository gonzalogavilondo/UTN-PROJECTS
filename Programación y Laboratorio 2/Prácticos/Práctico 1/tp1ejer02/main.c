#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESC 27
#define DIM 50

/**
2. Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma:
a. Hacer una función para la carga del arreglo.
b. Hacer una función para invertir el arreglo.
c. Hacer una función para mostrar el contenido del arreglo.
d. Hacer la función main con el menú correspondiente.
*/

char string[DIM];
int vString;

int main()
{
    char opcion;

    do{
        system("cls");
        muestraMenu();

        opcion = getch();

        switch(opcion){
    case 49:
        vString = 0;
        vString = fillArray(string, vString, DIM);
        break;
    case 50:
        inverseArray(string, vString);
        break;
    case 51:
        system("cls");
        showArray(string, vString);
        system("pause");
        break;
        }

    }while(opcion != ESC);

    return 0;
}

void muestraMenu() {
    printf("\n\t\tTrabajo Practico 1 - Ejercicio 02 - Invertir Arreglo");
    printf("\n\n");
    printf("\n1 - Cargar arreglo.");
    printf("\n2 - Invertir arreglo.");
    printf("\n3 - Mostrar arreglo.");
}

int fillArray(char array[], int v, int dim) {
    char opcion;
    char value;
    int flag = 0;

    while (v < dim && flag == 0) {
        system("cls");
        printf("Ingrese un caracter: ");
        fflush(stdin);
        scanf("%c", &value);
        array[v] = value;
        v++;

        printf("\nDesea ingresar otro caracter? s/n ");
        do {
        opcion = getch();
        }while(opcion != 's' && opcion != 'n');

        if (opcion == 's') {
            flag = 0;
        }
        else {
            flag = 1;
        }
    }
    return v;
}

void showArray(char array[], int v) {

    for (int i = 0; i < v; i++){
        printf("%c", array[i]);
    }
    printf("\n\n");
}

void inverseArray(char array[], int v) {

    char aux[v];
    int j = v-1;

    for (int i = 0; i < v; i++) {
        aux[j] = array[i];
        j--;
    }

    for (int i = 0; i < v; i++) {
        array[i] = aux[i];
    }

}
