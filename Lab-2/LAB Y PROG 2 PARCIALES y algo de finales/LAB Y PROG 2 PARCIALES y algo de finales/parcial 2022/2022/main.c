#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
typedef struct { int legajo;
char nombre[20]; char apellido [20]; char dni[10];
int edad; char genero;
int cantMateriasAprobadas; /// total de materias aprobadas del estudiante en la carrera (máximo 20)
float promedioSinAplazos; /// indica el promedio de estudiante, sin tener en cuenta aplazos float
float promedioConAplazos; /// indica el promedio de estudiante, teniendo en cuenta aplazos
} estudiante;


typedef struct  nodoEstudiante {
    estudiante datos;
    struct nodoEstudiante *siguiente;
} nodoEstudiante;


typedef struct nodoDoble{

  estudiante datos;
  struct nodoDoble *siguiente;
  struct nodoDoble *anterior;
}nodoDoble;

/////////////////////////////////////
///ejercicio 1 //////////////////////
nodoEstudiante * inicListaEstudiante (); //51
nodoEstudiante *buscaUltimo(nodoEstudiante *lista);
nodoEstudiante *crearNodo(estudiante datos);

nodoEstudiante *agregaUltimo(nodoEstudiante *lista,nodoEstudiante *nodo);
nodoEstudiante *cargaLista(nodoEstudiante *lista,char nombre[]);
void muestraLista(nodoEstudiante *lista);
//////////////////////////////3/////////////////////////
int cantEstudiantes(nodoEstudiante *lista);
int cantEstudiantesPromedio(nodoEstudiante *lista,float valor);
void porcentajesInforma(nodoEstudiante *lista);
/////////////////////////4
int mayorPromedioLegajo(nodoEstudiante *lista);
nodoDoble *creaNodoDoble(estudiante datos);
nodoDoble *agregaUltimoDoble(nodoDoble *listaDoble, nodoDoble *nodo);

estudiante  eliminaLegajo(nodoEstudiante **lista,int legajo);
nodoDoble *iniciaListaDoble();
void muestraListaDoble(nodoDoble **listaDoble);
/////////////////6///////////

Pila cargaPila(nodoEstudiante *lista);
int  cuentaPila(Pila pilaA);
void muestraPila(Pila pilaA);
//////////////////////////////////////



int main()
{
    Pila pilaA;
    int legajo;
    int contador;
    estudiante datos;
    nodoDoble *listaDoble=iniciaListaDoble();
    nodoEstudiante *lista=inicListaEstudiante();
    char nombre[]="EstudiantesTUP.dat";
    lista=cargaLista(lista,nombre);
    muestraLista(lista);
    porcentajesInforma(lista);

    for(int i=0;i<=9;i++){
        legajo=mayorPromedioLegajo(lista);
        datos=eliminaLegajo(&lista,legajo);

        listaDoble=agregaUltimoDoble(listaDoble,creaNodoDoble(datos));


    }

    muestraListaDoble(&listaDoble);

   /// muestraLista(lista);
   printf("/////// parte de pila /////////");

    inicpila(&pilaA);
    pilaA=cargaPila(lista);
    contador=cuentaPila(pilaA);
    printf("\n en total hay %i alumnos con mas de 10 materias aprobadas \n",contador);

    muestraPila(pilaA);



    return 0;
}





////////////////////////////////////////
nodoEstudiante * inicListaEstudiante ()
{
    return NULL;
}
///////////////////////////////////////

nodoEstudiante *crearNodo(estudiante datos){

 nodoEstudiante *aux=(nodoEstudiante*)malloc(sizeof(nodoEstudiante));

 aux->datos=datos;
 aux->siguiente=NULL;
 return aux;

}


//////////////////////////////
nodoEstudiante *buscaUltimo(nodoEstudiante *lista){

nodoEstudiante *seg=lista;

    if(seg!=NULL){
        while(seg->siguiente!=NULL)
            seg=seg->siguiente;

    }

return seg;




}

/////////////////////////////
nodoEstudiante *agregaUltimo(nodoEstudiante *lista,nodoEstudiante *nodo){


     if(lista==NULL)
        lista=nodo;
     else{
        nodoEstudiante *ultimo=buscaUltimo(lista);
        ultimo->siguiente=nodo;

     }
return lista;
}


/////////////////////
nodoEstudiante *cargaLista(nodoEstudiante *lista, char nombre[]){

  estudiante   aux;

  FILE  *parch=fopen(nombre,"rb");

  if(fread(&aux,sizeof(estudiante),1,parch)>0){

    while(!feof(parch)){
         lista=agregaUltimo(lista,crearNodo(aux));
         fread(&aux,sizeof(estudiante),1,parch);
    }


  }
   else{
    printf("error al abrir el archivo ");
   }





return lista;

}



////////////
void muestraLista(nodoEstudiante *lista){
    nodoEstudiante *aux=lista;

    printf("\n");
    while(aux!=NULL){
        printf("Legajo:%i ,Nombre:%s ,Apellido:%s ,DNI:%s ,Edad:%i ,Genero:%c ,CantMatAp:%i ,PromedioSA:%2.2f , PromedioCA:%2.2f \n",aux->datos.legajo,aux->datos.nombre,aux->datos.apellido,aux->datos.dni,aux->datos.edad,aux->datos.genero,aux->datos.cantMateriasAprobadas,aux->datos.promedioSinAplazos,aux->datos.promedioConAplazos);
        aux=aux->siguiente;
    }

}


/////////////////////ejercicio 3 /////////////////

int cantEstudiantes(nodoEstudiante *lista){


 nodoEstudiante  *aux=lista;
 int contador=0;
 while(aux!=NULL){
    contador++;
    aux=aux->siguiente;

 }
return contador;
}
/////////////////
int cantEstudiantesPromedio(nodoEstudiante *lista,float valor){


    nodoEstudiante *aux=lista;
    int contador=0;

    while(aux!=NULL){
        if(aux->datos.promedioConAplazos>valor)
            contador++;
        aux=aux->siguiente;


    }



return contador;

}

void porcentajesInforma(nodoEstudiante *lista){

 float valor;

 printf("\n en total hay %i  estudiantes en la lista",cantEstudiantes(lista));
 if(cantEstudiantes(lista)!=0){
 printf("\n ingrese un valor para buscar la cantidad de alumnos que superan ese valor en promedio con aplazaos \n");
 scanf("%f",&valor);
 printf("\n en total hay %i alumnos que superan el valor %2.2f en su promedio con aplazasos \n",cantEstudiantesPromedio(lista,valor),valor);
 printf("\n y el porcentaje de alumnos que superan dicho valor es %2.2f porciento \n",(100*cantEstudiantesPromedio(lista,valor))/(float)(cantEstudiantes(lista)));
 }
}
///////////////////////////////////4/////////////////////////////

int mayorPromedioLegajo(nodoEstudiante *lista){

    nodoEstudiante *aux=lista;
    float mayorPromedio=0;
    int mayorLegajo;


    while(aux!=NULL){
        if(aux->datos.promedioSinAplazos>mayorPromedio){
            mayorPromedio=aux->datos.promedioSinAplazos;
            mayorLegajo=aux->datos.legajo;
        }


         aux=aux->siguiente;

    }


return mayorLegajo;

}

/////////////////////////////////
estudiante  eliminaLegajo(nodoEstudiante **lista,int legajo){

    nodoEstudiante *actual;
    nodoEstudiante *aux;
    estudiante datos;

    if ( ((*lista)!=NULL) && (((*lista)->datos.legajo)==legajo)){

        actual=(*lista);
        (*lista)=(*lista)->siguiente;


    }
    else{
        actual=(*lista);
        while((actual!=NULL) && ((actual->datos.legajo)!=legajo)){
            aux=actual;
            actual=actual->siguiente;
        }

        if(actual!=NULL){
            aux->siguiente=actual->siguiente;

        }


        strcpy(datos.apellido,actual->datos.apellido);
        strcpy(datos.nombre,actual->datos.nombre);
        strcpy(datos.dni,actual->datos.dni);
        datos.genero=actual->datos.genero;
        datos.legajo=actual->datos.legajo;
        datos.edad=actual->datos.edad;
        datos.cantMateriasAprobadas=actual->datos.cantMateriasAprobadas;
        datos.promedioConAplazos=actual->datos.promedioConAplazos;
        datos.promedioSinAplazos=actual->datos.promedioSinAplazos;



        free(actual);
    }

    /*
    nodoEstudiante* actual=(*lista);
    nodoEstudiante* anterior=(*lista);
    estudiante alumno;
    if(actual!=NULL)
    {
        while(actual!=NULL && actual->datos.legajo!=legajo )
        {
           anterior=actual;
           actual=actual->siguiente;
        }
        if(actual==(*lista))///primero de la lista
        {
            (*lista)=actual->siguiente;
        }
        else
        {
            anterior->siguiente=actual->siguiente;
        }
        strcpy(alumno.apellido,actual->datos.apellido);
        strcpy(alumno.nombre,actual->datos.nombre);
        strcpy(alumno.dni,actual->datos.dni);
        alumno.genero=actual->datos.genero;
        alumno.legajo=actual->datos.legajo;
        alumno.edad=actual->datos.edad;
        alumno.cantMateriasAprobadas=actual->datos.cantMateriasAprobadas;
        alumno.promedioConAplazos=actual->datos.promedioConAplazos;
        alumno.promedioSinAplazos=actual->datos.promedioSinAplazos;
        free(actual);
    }
    return alumno;*/

return datos;

}
/////////////////////////
nodoDoble *iniciaListaDoble(){
    return NULL;
}
////////////////////
nodoDoble *creaNodoDoble(estudiante datos){

 nodoDoble  *aux=(nodoDoble*)malloc(sizeof(nodoDoble));

     aux->datos=datos;
     aux->siguiente=NULL;
     aux->anterior=NULL;
 return aux;



}
/////////////////////////////////
nodoDoble *buscaUltimoDoble(nodoDoble *listaDoble){

    nodoDoble *seg=listaDoble;

    if(seg!=NULL){
        while(seg->siguiente!=NULL)
            seg=seg->siguiente;

    }

return seg;


}


///////////////////////
nodoDoble *agregaUltimoDoble(nodoDoble *listaDoble, nodoDoble *nodo){

    if(listaDoble==NULL){
        listaDoble=nodo;
    }
    else{

        nodoDoble *ultimo=buscaUltimoDoble(listaDoble);
        ultimo->siguiente=nodo;
        nodo->anterior=ultimo;

    }

return listaDoble;
}




/////////////////////////////////////








/////////////////////////////////////
void muestraListaDoble(nodoDoble **listaDoble){

    nodoDoble *aux=(*listaDoble);

    if((aux)!=NULL){
        muestraListaDoble(&aux->siguiente);
        printf("Legajo:%i ,Nombre:%s ,Apellido:%s ,DNI:%s ,Edad:%i ,Genero:%c ,CantMatAp:%i ,PromedioSA:%2.2f , PromedioCA:%2.2f \n",aux->datos.legajo,aux->datos.nombre,aux->datos.apellido,aux->datos.dni,aux->datos.edad,aux->datos.genero,aux->datos.cantMateriasAprobadas,aux->datos.promedioSinAplazos,aux->datos.promedioConAplazos);

    }


}
/////////////////////////////////////////////
Pila cargaPila(nodoEstudiante *lista){


    Pila auxPila;
    inicpila(&auxPila);
    nodoEstudiante *aux=lista;

    while(aux!=NULL){
        if(aux->datos.cantMateriasAprobadas>10){
            apilar(&auxPila,aux->datos.legajo);
        }
        aux=aux->siguiente;
    }




return auxPila;
}
//////////////
int  cuentaPila(Pila pilaA) {


    Pila aux;
    inicpila(&aux);
    int contador=0;
    while(!pilavacia(&pilaA)){
        apilar(&aux,desapilar(&pilaA));
        contador++;
    }


return contador;

}
/////////////////////////////
void muestraPila(Pila pila){
    int dato;

    if(!pilavacia(&pila)){
        dato=desapilar(&pila);
        printf(" \n legajo %i \n",dato);
        muestraPila(pila);
        apilar(&pila, dato);
    }



}
