#include "stack.h"


void initStack(Stack * p){
    int *aux;
    aux = malloc(sizeof(int)*50);
    p->valores = aux; /// (*p).valores = aux;
    p->validos = 0;
    p->dim = 50;
}

void push(Stack * p, int valor){
    if(p->validos == p->dim) {
        p->dim+=50; /// p->dim = p->dim+50;
        p->valores = realloc(p->valores, sizeof(int) * p->dim);
    }
    p->valores[p->validos] = valor;
    p->validos++;
}

int pull(Stack * p){
    int aux = p->valores[p->validos-1];
    p->validos--;
    return aux;
}

int top(Stack * p){
    int aux = p->valores[p->validos-1];
    p->validos--;
    return aux;
}

int emptyStack(Stack * p){
    int flag=1;

    if (p->validos > 0) {
        flag = 0;
    }

    return flag;
}

void showStack(Stack * p) {

    for (int i = 0; i < p->validos; i++){

        printf("| %i ", p->valores[i]);

    }
    printf("|\n");
}
