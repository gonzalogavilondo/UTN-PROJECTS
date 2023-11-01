#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int idRegistro;
    int nroJugador;
    char nombreJugador[30];
    char apellidoJugador[30];
    int clase; ///año de nacimiento.
    char puestoJugador[30];///Delantero-Medio-Defensor-Arquero/
    char nombreEquipo[30];
    int puntosGanados;
}stRegistroJugador;


typedef struct
{
    int nroJugador;
    char nombreJugador[30];
    char apellidoJugador[30];
    int clase;
    char puestoJugador[30];
} stJugador;

typedef struct nodoListaJugador
{
    stJugador j;
    struct nodoListaJugador * sig;
} nodoListaJugador;

typedef struct
{
    int idEquipo; //(generarlo, no está en el archivo)
    char nombreEquipo[30];
    int puntosGanados;
} stEquipo;
typedef struct
{
    stEquipo e;
    nodoListaJugador * listaJugadores;
} arregloEquipo;
//////////////////////////////////

nodoListaJugador *inicLista();
nodoListaJugador *crearNodoJugador(stRegistroJugador jugador);
int buscaPosicionEquipo(arregloEquipo arreglo[],int validos ,stRegistroJugador aux);
nodoListaJugador *insertaNodoR(nodoListaJugador *lista,nodoListaJugador *jugador);
stEquipo crearEquipo(stRegistroJugador aux,int id);
int alta(arregloEquipo arreglo[],int validos,stRegistroJugador registro);
int   cargaArreglo(arregloEquipo arreglo[],int dimension);
void mostrarArreglo(arregloEquipo arreglo[],int validos);
void mostrarLista(nodoListaJugador *lista);

void buscar(arregloEquipo arreglo[],int validos);
int buscaJugador(nodoListaJugador *lista,stRegistroJugador aux);


/////////////////
int main()
{
    int dimension=100;
    arregloEquipo arreglo[dimension];
    int validos=0;
    validos=cargaArreglo(arreglo,dimension);

    printf("\n Total %i",validos);
    mostrarArreglo(arreglo,validos);
    buscar(arreglo,validos);

}


/////////////////
nodoListaJugador *inicLista(){
return NULL;
}

nodoListaJugador *crearNodoJugador(stRegistroJugador jugador)
{
    nodoListaJugador *aux=(nodoListaJugador*)malloc(sizeof(nodoListaJugador));

    aux->sig=NULL;

    strcpy(aux->j.apellidoJugador,jugador.apellidoJugador);
    strcpy(aux->j.nombreJugador,jugador.nombreJugador);
    strcpy(aux->j.puestoJugador,jugador.puestoJugador);
    aux->j.clase=jugador.clase;
    aux->j.nroJugador=jugador.nroJugador;

return aux;
}

nodoListaJugador *insertaNodoR(nodoListaJugador *lista,nodoListaJugador *jugador){

    if(lista==NULL){
        lista=jugador;
    }
    else{
        if( strcmp(lista->j.apellidoJugador,jugador->j.apellidoJugador)>0){
            jugador->sig=lista;
            lista=jugador;
        }
        else{
            lista->sig=insertaNodoR(lista->sig,jugador);
        }

    }
return lista;
}

int buscaPosicionEquipo(arregloEquipo arreglo[],int validos,stRegistroJugador aux){


    int encontrado=-1;
    int i=0;
    while(i<validos && encontrado==-1){
        if(  strcmp(arreglo[i].e.nombreEquipo,aux.nombreEquipo)==0 ){
            encontrado=i;
        }
            i++;
    }
return encontrado;
}




stEquipo crearEquipo(stRegistroJugador aux,int id){

    stEquipo equipo;
    equipo.idEquipo=id;
    strcpy(equipo.nombreEquipo,aux.nombreEquipo);
    equipo.puntosGanados=aux.puntosGanados;

return equipo;
}

int alta(arregloEquipo arreglo[],int validos,stRegistroJugador registro){

 int total=validos;

    int pos=buscaPosicionEquipo(arreglo,validos,registro);

    if(pos==-1){
        arreglo[validos].e=crearEquipo(registro,validos);
        arreglo[validos].listaJugadores=insertaNodoR(NULL,crearNodoJugador(registro));
        total++;
    }
    else{
       arreglo[pos].listaJugadores=insertaNodoR(arreglo[pos].listaJugadores,crearNodoJugador(registro));

    }
return total;
}



int   cargaArreglo(arregloEquipo arreglo[],int dimension){

    FILE *arch=fopen("registroJugador.dat","rb");
    stRegistroJugador aux;
    int validos=0;
    while( fread(&aux,sizeof(stRegistroJugador),1,arch)>0 && validos<dimension){
        printf("\n nombre equipo %s  nombre jugador :%s ",aux.nombreEquipo,aux.nombreJugador );
        validos=alta(arreglo,validos,aux);
    printf("\n Total %i",validos);

    }
    fclose(arch);
      //  printf("\n lei algo ? %i",validos);
return validos;
}




void mostrarArreglo(arregloEquipo arreglo[],int validos){

    int i=0;
    while(i<validos){
            printf("\n\n------ NOMBRE DEL EQUIPO :%s ID :%i   PUNTOS GANADOS :%i ------\n\n",arreglo[i].e.nombreEquipo,arreglo[i].e.idEquipo,arreglo[i].e.puntosGanados);
            mostrarLista(arreglo[i].listaJugadores);
        i++;
    }
}


void mostrarLista(nodoListaJugador *lista){

    if(lista!=NULL){
        mostrarLista(lista->sig);
        printf("\nNombre :%s     Apellido:%s    NRO :%i   Puesto :%s",lista->j.nombreJugador,lista->j.apellidoJugador,lista->j.nroJugador,lista->j.puestoJugador);
    }
}





void buscar(arregloEquipo arreglo[],int validos){

    printf("\n\n\n\n");
    stRegistroJugador aux;
    char equipo[30];
    char nombre[30];
    char apellido[30];
    int pos=-1;
    printf("\n Ingrese el nombre del equipo para buscar al jugador\n");
    fflush(stdin);
    gets(equipo);
    printf("\n Ingrese el nombre del jugador\n");
    fflush(stdin);
    gets(nombre);
    printf("\nIngrese el apellido \n");
    fflush(stdin);
    gets(apellido);
    strcpy(aux.nombreEquipo,equipo);
    strcpy(aux.nombreJugador,nombre);
    strcpy(aux.apellidoJugador,apellido);

    pos=buscaPosicionEquipo(arreglo,validos,aux);

    if(pos==-1){
        printf("\n No se encontro el equipo");
    }
    else{
        pos=buscaJugador(arreglo[pos].listaJugadores,aux);

        if(pos!=-1)
            printf("\n -------------El jugador es el numero %i  ------------",pos);
        else
            printf("\n ---------------No se encontro jugador--------------");

    }

}




int buscaJugador(nodoListaJugador *lista,stRegistroJugador aux){

    int pos=-1;

    if(lista!=NULL){

            if( strcmp(lista->j.nombreJugador,aux.nombreJugador)==0 && strcmp(lista->j.apellidoJugador,aux.apellidoJugador)==0    )
                pos=lista->j.nroJugador;
            else
                pos=buscaJugador(lista->sig,aux);
    }
return pos;
}






























































