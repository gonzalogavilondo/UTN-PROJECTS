#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define ESC 27
#define DIM 10

/**
1. Se tiene un arreglo de números enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe:
a. Hacer una función que inicialice las celdas del arreglo en –1.
b. Hacer una función que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.
c. Hacer una función que sume el contenido del arreglo y lo retorne.
d. Hacer una función que cuente la cantidad de valores ingresados.
e. Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio
usando las funciones anteriores (c y d).
f. Hacer la función main correspondiente.
*/

int positiveNumbers[DIM];
int vPosNumbers = 0;
int totalSuma = 0;
int quantValues = 0;
float promedio;

float promedioArray(int array[], int dim);

int main()
{
    char opcion;

    do{
        system("cls");

        muestraMenu();

        opcion = getch();

        switch(opcion){
    case 49:
        initializeNumericArray(positiveNumbers, DIM);
        vPosNumbers = 0;
        break;
    case 50:
        vPosNumbers = fillArray(positiveNumbers, vPosNumbers, DIM);
        break;
    case 51:
        totalSuma = totalArray(positiveNumbers, DIM);
        printf("\n\n\nLa suma del contenido del arreglo es: %i\n", totalSuma);
        system("pause");
        break;
    case 52:
        quantValues = qValues(positiveNumbers, DIM);
        printf("\n\n\nExisten un total de %i valores ingresados.\n", quantValues);
        system("pause");
        break;
    case 53:
        promedio = promedioArray(positiveNumbers, DIM);
        printf("\n\n\nEl promedio del arreglo es de %.2f\n", promedio);
        system("pause");
        break;
    case 54:
        printf("\n\n\n");
        showArray(positiveNumbers, DIM);
        system("pause");
        break;

        }

    }while(opcion!=ESC);



    return 0;
}

void muestraMenu() {
    printf("\n\t\tTrabajo Practico 1 - Ejercicio 01 - Enteros Positivos");
    printf("\n\n");
    printf("\n~ADVERTENCIA: Las celdas con valor negativo seran tomadas en cuenta como celdas vacías para las funciones.~");
    printf("\n\n");
    printf("\n1 - Inicializar celdas del arreglo en -1.");
    printf("\n2 - Ingresar valores al arreglo.");
    printf("\n3 - Sumar contenido del arreglo.");
    printf("\n4 - Contar cantidad de valores ingresados.");
    printf("\n5 - Promediar contenido total con la cantidad de valores ingresados.");
    printf("\n6 - Mostrar arreglo.");
}

void initializeNumericArray(int array[], int dim) {

    for (int i = 0; i < dim; i++) {
        array[i] = -1;
    }

}

void showArray(int array[], int dim) {

    for (int i = 0; i < dim; i++) {
        printf("%i | ", array[i]);
    }
}

int fillArray(int array[], int v, int dim) {

    char opcion;
    int flag = 0;
    int numero;

    while (v < dim && flag == 0) {
        system("cls");
        printf("\nIngrese un numero entero positivo: ");
        scanf(" %i", &numero);
        if (numero >= 0) {
            array[v] = numero;
            v++;
            printf("\nDesea cargar otro numero? s/n");
        } else {
            printf("\nError, el numero ingresado no es un entero positivo.");
            printf("\nDesea intentar nuevamente? s/n");
        }

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

int totalArray(int array[], int dim) {

    int totalSuma = 0;

    for (int i = 0; i < dim; i++) {
        if (array[i] != -1) {
        totalSuma = totalSuma + array[i];
        }
    }

    return totalSuma;

}

int qValues(int array[], int dim) {

    int values = 0;
    for (int i = 0; i < dim; i++) {

        if(array[i] != -1) {
            values++;
        }
    }
    return values;
}

float promedioArray(int array[], int dim) {

    int total;
    int quantity;
    float promedio;

    total = totalArray(array, dim);
    quantity = qValues(array, dim);
    promedio = (float) total / quantity;

    return promedio;
}
