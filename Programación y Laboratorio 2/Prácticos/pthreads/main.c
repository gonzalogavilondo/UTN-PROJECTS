#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <pthread.h>


int a = 10;

void *codigo_funcion1(void *arg)
{
Sleep(10);
a = a - 2;
printf("Soy el hilo A y la variable a vale %d\n", a);
pthread_exit(0);
}

void *codigo_funcion2(void *arg)
{
Sleep(5);
a++;
printf("Soy el hilo B y la variable a vale %d\n", a);
pthread_exit(0);
}

int main(void)
{
pthread_t hiloA, hiloB;
pthread_create(&hiloA, NULL, codigo_funcion1, NULL);
pthread_create(&hiloB, NULL, codigo_funcion2, NULL);

pthread_join(hiloA, NULL);
pthread_join(hiloB, NULL);

}
