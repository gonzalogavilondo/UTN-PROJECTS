#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define ESC 27
#define FIL 12
#define COL 31

/**5. Sea una matriz de números enteros, de dimensiones: 12 filas y 31 columnas. Contienen las precipitaciones correspondientes a un año entero.
Las filas corresponden a los meses y las columnas a los días. Se pide:
a. Hacer una función para cargar la matriz de forma automática.
b. Hacer una función que retorne el día de máxima precipitación para un mes determinado.
c. Hacer una función que cargue en un arreglo de 12 posiciones el resultado de aplicar la fn anterior a cada
mes de año.
d. Hacer la función main con el menú correspondiente.
*/


void muestraMenu();
void cargaMatriz(int matriz[][COL]);
void muestraMatriz(int matriz[][COL]);
int diaMaximaPre(int mes, int matriz[][COL]);
void cargarArreglo(int arrayMayores[], int matriz[][COL]);
void muestraArray(int array[FIL]);

int matrizPre[FIL][COL];
int mes;
int mayor;
int arrayMayores[FIL];

int main()
{
    char opcion;

    do {
        system("cls");
        muestraMenu();

        opcion=getch();

        switch(opcion) {

    case 49:
        cargaMatriz(matrizPre);
        printf("\n\nMatriz cargada con exito.\n");
        system("pause");
        break;
    case 50:
        system("cls");
        muestraMatriz(matrizPre);
        system("pause");
        break;
    case 51:
        printf("\nIngrese el mes que desea analizar. Ejemplo: Enero = 1, Diciembre = 12..... ");
        scanf("%i", &mes);
        mayor = diaMaximaPre(mes-1, matrizPre);
        printf("El dia con mayor precipitaciones del mes %i es el %i.\n", mes, mayor);
        system("pause");
        break;
    case 52:
        system("cls");
        cargarArreglo(arrayMayores, matrizPre);
        muestraArray(arrayMayores);
        system("pause");
        break;
        }


    }while(opcion!=ESC);

    return 0;
}

void muestraMenu() {

    printf("\n\t\tTP 01 - Ejercicio 05 - Julio Missart\n\n");
    printf("\n1 - Carga de Matriz automatica.");
    printf("\n2 - Muestra Matriz.");
    printf("\n3 - Analiza mes.");
    printf("\n4 - Cargar arreglo con la funcion anterior.");


}

void cargaMatriz(int matriz[][COL]) {

    srand(time(0));
    for(int i=0;i<FIL;i++){
        for(int j=0;j<COL;j++){
            int random=rand()%100;
            matriz[i][j]=random;
        }
    }
}

void muestraMatriz(int matriz[][COL]){
 for(int i=0;i<FIL;i++){
        for(int j=0;j<COL;j++){
            switch(matriz[i][j]) {
            case 0 ... 9:
                printf("|  %i ", matriz[i][j]);
                break;
            case 10 ... 99:
                printf("| %i ", matriz[i][j]);
                break;
            case 100:
                printf("|%i ", matriz[i][j]);
                break;
            }
        }
        printf("|\n");
    }
    printf("\n");
}

int diaMaximaPre(int mes, int matriz[FIL][COL]) {

    int mayor = 0;
    int dia = 0;

    for (int i = 0; i < COL; i++){
        if(matriz[mes][i] > mayor){
            mayor = matriz[mes][i];
            dia = i+1;
        }
    }
    return dia;
}

void cargarArreglo(int arrayMayores[], int matriz[][COL]){

    for(int i=0; i<FIL; i++){
      arrayMayores[i] = diaMaximaPre(i, matriz);
    }

}

void muestraArray(int array[FIL]){

    for(int i=0; i<FIL; i++){
        printf("| %i ", array[i]);
    }
    printf("\n");
}
