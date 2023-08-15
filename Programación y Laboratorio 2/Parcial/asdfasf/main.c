#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t s;
int x, r;
int r=1;

void *curly () {
    while(r==1){
        Sleep(2);
        sem_wait( &s );
        x = 99;
        x = x+1;
        printf("\n%d", x);
        sem_post( &s );
    }
}
void *larry () {
    while(r==1){
        Sleep(30);
        sem_wait( &s );
        x = 400;
        x = 400 / 2;
        printf("\n%d", x);
        sem_post( &s );
    }
}
void *moe () {
    while(r==1){
        Sleep(15);
        sem_wait( &s );
        x = 150;
        x = 150 * 2;
        printf("\n%d", x);
        sem_post( &s );
    }
}


int main()
{
    pthread_t hCurly, hLarry, hMoe;

    sem_init(&s, 0, 3);
    pthread_create(&hCurly, NULL, curly(), NULL);
    pthread_create(&hLarry, NULL, larry(), NULL);
    pthread_create(&hMoe, NULL, moe(), NULL);

    Sleep(500);

    return 0;

    return 0;
}
