#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27

typedef struct{
     int valores[100];
     int posTope;
} Pila;

void apilar(Pila x, int valor);
int desapilar(Pila x);
int tope(Pila x);
int pilavacia(Pila x);
void mostrar(Pila x);
void leer (Pila x);
void inicpila(Pila x);
void muestraMenu();

int main()
{
    char opcion;
    int vacia;
    int valor;
    Pila x;

    do{
        system("cls");
        muestraMenu();
        opcion = getch();

        switch(opcion){
    case 49:
        inicpila(x);
        printf("\nPila inicializada exitosamente.\n");
        system("pause");
        break;
    case 50:
        vacia = pilavacia(x);
        if(vacia == 1) {
            printf("\nLa pila esta vacia.");
        }else{
            printf("\nLa pila contiene datos.");
            }
            system("pause");
            break;
    case 51:
        mostrar(x);
        system("pause");
        break;
    case 52:
        valor = desapilar(x);
        if(valor==0){
            printf("No se ha desapilado nada porque la pila ya esta vacia.");
        }else{
            printf("\nSe ha desapilado el valor %i, y se ha perdido en el olvido.", valor);
        }
        break;
    case 53:
        valor = tope(x);
        if(valor==0){
            printf("\nLa pila no contiene ningun valor almacenado.");
        }else{
            printf("\El valor del tope es: %i", valor);
        }
        break;
    case 54:
        leer(x);
        break;
    }
    }while(opcion!=ESC);

    return 0;

}

void muestraMenu() {

    printf("\n\t\tTP 2 - Ejercicio 3 - Missart Julio\n");
    printf("\n1. Inicializar Pila.");
    printf("\n2. Pila Vacia.");
    printf("\n3. Mostrar.");
    printf("\n4. Desapilar.");
    printf("\n5. Tope.");
    printf("\n6. Leer.");

}


void apilar(Pila x, int valor) {

    if(x.posTope < 100) {
    x.valores[x.posTope] = valor;
    x.posTope++;
    }
}

int desapilar(Pila x) {

    int valor=0;
    if (pilavacia(x) == 0) {
    valor = x.valores[x.posTope-1];
    x.valores[x.posTope-1] = 0;
    x.posTope--;
    }

    return valor;
}

int tope(Pila x) {

    int valorTope;
    valorTope = x.valores[x.posTope-1];

    return valorTope;

}

int pilavacia(Pila x) {

    int boolean=1;

    for (int i = 0; i < 100; i++) {
        if (x.valores[i]!=0) {
            boolean = 0;
        }
    }
    return boolean;
}

void mostrar(Pila x) {

    if(pilavacia(x) == 0) {
        for (int i = 0; i < x.posTope; i++) {
            printf("| %i ",x.valores[i]);
        }
    }
    printf("\n");
}

void leer(Pila x) {

    int valor;

    printf("\nIngrese un valor: ");
    fflush(stdin);
    scanf("%i", &valor);

    apilar(x, valor);
}

void inicpila(Pila x) {

    for (int i=0; i<100; i++) {
        x.valores[i] = 0;
    }
}
