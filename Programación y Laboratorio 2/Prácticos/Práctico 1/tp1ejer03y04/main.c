#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ESC 27
#define DIM 20

/**
3. Hacer una función que reciba como parámetro un arreglo de números enteros de un dígito y retorne el valor decimal de dicho número.
Por ejemplo, un arreglo que tiene cargados los valores 3, 2, 8 y 9, la fn retorna el valor 3289.
4. Hacer una función que retorne la posición del valor máximo de un arreglo de números enteros.
*/

int numbers[DIM];
int vNumbers;
char opcion;
int decimal = 0;
int pos = 0;

int muestraMenu();
int fillArray(int array[], int v, int dim);
void showArray(int array[], int v);
int array2Decimal(int array[], int v);
int posValorMax(int array[], int v);

int main()
{

    do {
        system("cls");
        muestraMenu();

        opcion = getch();
        switch(opcion){
    case 49:
        vNumbers = 0;
        vNumbers = fillArray(numbers, vNumbers, DIM);
        break;
    case 50:
        decimal = array2Decimal(numbers, vNumbers);
        printf("\n\n\nDecimal: %i\n", decimal);
        system("pause");
        break;
    case 51:
        printf("\n\n\n");
        showArray(numbers, vNumbers);
        system("pause");
        break;
    case 52:
        pos = posValorMax(numbers, vNumbers);
        printf("\n\n\n");
        showArray(numbers, vNumbers);
        printf("\n\n");
        printf("\nLa posicion del valor maximo en el arreglo es: %i\n", pos+1);
        system("pause");
        break;
        }

    }while(opcion!=ESC);


    return 0;
}

int muestraMenu() {

    printf("\n\t\tTrabajo Practico 1 - Ejercicio 03 - Arreglo de enteros a decimal");
    printf("\n\n");
    printf("\n1 - Cargar arreglo.");
    printf("\n2 - Convertir a decimal.");
    printf("\n3 - Mostrar arreglo.");
    printf("\n4 - Posicion del valor maximo.");
}

int fillArray(int array[], int v, int dim) {

    char opcion;
    int flag = 0;
    int numero;

    while (v < dim && flag == 0) {
        system("cls");
        printf("\nIngrese un numero natural: ");
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

void showArray(int array[], int v) {

    for (int i = 0; i < v; i++) {
        printf("%i | ", array[i]);
    }
}

int array2Decimal(int array[], int v) {

    int starter = 1;
    int multiplier = 10;
    int total = 0;

    for (int j = v-1; j >= 0; j--) {

        total = total + (array[j] * starter);
        starter = starter * multiplier;

    }

    return total;
}

int posValorMax(int array[], int v) {

    int pos;
    int min = 0;

    for (int i = 0; i < v; i++) {

        if (array[i] > min) {
            min = array[i];
            pos = i;
        }
    }

    return pos;
}
