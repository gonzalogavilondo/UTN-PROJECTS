#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    char apellido[30];
    int edad;
}stPersona;

typedef struct nodoDoble
{
    stPersona datos;
    struct nodoDoble* anterior;
    struct nodoDoble* siguiente;
}nodoDoble;

void mostrarLista(nodoDoble *lista);

nodoDoble * crearNodoDoble (stPersona datos);
nodoDoble  *cargarListaDoble(char nombreArch[], nodoDoble * lista);
nodoDoble * agregarEnOrdenDoble (nodoDoble * lista, nodoDoble * nuevo);
int capicua(nodoDoble *pri,nodoDoble *fin);
nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo);
nodoDoble *borrarNodoDoble(nodoDoble *lista,char nombre[20]);
void mostrarLista(nodoDoble *lista);
nodoDoble * buscarUltimoDobleRecursivo (nodoDoble * lista);
nodoDoble *puntoMedio(nodoDoble *listaDoble12,int contador);
int contarRecursivo(nodoDoble *lista);

int main()
{   int op;
    nodoDoble * listaDoble1=NULL;
    nodoDoble * listaDoble2=NULL;
    stPersona aux;
    char nombreArch[]="Personas.bin";
    char nombre[29];
    int contador=0,control=1;



    printf("\n 0. Hacer un programa que lea de un archivo datos y los inserte en una lista doble.\n");
    printf("\n 1. Modificar la funcion borrarNodo() de listas simples y transformarla para el caso de una lista doblemente vinculada.");
    printf("\n 2. Crear una funcion recursiva que determine si una lista doblemente vinculada es capicua. (Después de ver recursividad;");
    printf("\n 3. Dada una lista doblemente enlazada ordenada de enteros, eliminar el nodo que se encuentra en el punto medio de la lista, si la cantidad de nodos es par, eliminar el inmediatamente superior.");
    printf("\n ingrese una opcion \n");
    scanf("%i",&op);
    switch(op){
    case 0:
        system("cls");
        printf("\n 0. Hacer un programa que lea de un archivo datos y los inserte en una doble.\n");

        //mostrarArchivoPersonas(nombreArch);
        ///listas
        listaDoble1=cargarListaDoble(nombreArch,listaDoble1);
        mostrarLista(listaDoble1);


        break;
        case 1:
        system("cls");
        printf("\n 1. Modificar la funcion borrarNodo() de listas simples y transformarla para el caso de una lista doblemente vinculada.");
        listaDoble1=cargarListaDoble(nombreArch,listaDoble1);
        mostrarLista(listaDoble1);
        printf("\n que nombre desea eliminar de la lista \n");
        scanf("%s",nombre);
        listaDoble1=borrarNodoDoble(listaDoble1,nombre);
        mostrarLista(listaDoble1);


        break;
        case 2:
        system("cls");
        printf("\n 2. Crear una funcion recursiva que determine si una lista doblemente vinculada es capicua. (Después de ver recursividad;");
        printf("\n ingrese numeros para cargar la lista, 0 para terminar");
        while(control!=0){
            printf("\n ingrese un numero \n");
            scanf("%i",&control);
            if (control!=0){
                   aux.edad=control;
                   contador++;
                   listaDoble2=agregarPpioDoble(listaDoble2,crearNodoDoble(aux));

            }
        }
        if (capicua(listaDoble2,buscarUltimoDobleRecursivo(listaDoble2))==1)
            printf("\n \n la lista es capicua \n \n");
        else
            printf("\n \n la lista no es capicua ");
        mostrarLista(listaDoble2);



        printf("en la lista hay %i numeros multiplos de 10 \n",contarRecursivo(listaDoble2));
        break;
        case 3:
        system("cls");
        printf("\n 3. Dada una lista doblemente enlazada ordenada de enteros, eliminar el nodo que se encuentra en el punto medio de la lista, si la cantidad de nodos es par, eliminar el inmediatamente superior.");
        printf("\n ingrese numeros para cargar la lista, 0 para terminar");
        while(control!=0){
            printf("\n ingrese un numero \n");
            scanf("%i",&control);
            if (control!=0){
                   aux.edad=control;
                   contador++;
                   listaDoble2=agregarPpioDoble(listaDoble2,crearNodoDoble(aux));

            }
        }
            mostrarLista(listaDoble2);

        printf("\n \n elimino un nodo del medio   \n \n");

        listaDoble2=puntoMedio(listaDoble2,contador);

        mostrarLista(listaDoble2);






        break;

    }
    return 0;
}

/////////////////////////////////////////////
nodoDoble  *cargarListaDoble(char nombreArch[], nodoDoble * lista)
{
    stPersona auxPersona;


    FILE *pArchivo=fopen(nombreArch,"rb");
    if(fread(&auxPersona,sizeof(stPersona),1,pArchivo)>0)
    {
       while(!feof(pArchivo))
        {
          lista=agregarEnOrdenDoble(lista,crearNodoDoble(auxPersona));
          fread(&auxPersona,sizeof(stPersona),1,pArchivo);
        }
    }

    fclose(pArchivo);
    return lista;
}
///////////////////////
nodoDoble * crearNodoDoble (stPersona datos) {
    nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
    aux->datos = datos;
    //asigna valor NULL a los campos que contienen la dirección de memoria
    //de los nodos anterior y siguiente
    aux->anterior = NULL;
    aux->siguiente = NULL;
return aux;
}
/////////////////////////////////////
/*nodoDoble * agregarFinalDoble(nodoDoble * lista, nodoDoble * nuevo) {
    if(lista == NULL) {
        lista = nuevo;
    } else {
        nodoDoble * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    return lista;
}

///////*/
nodoDoble * agregarEnOrdenDoble (nodoDoble * lista, nodoDoble * nuevo) {


    if(lista == NULL) {
        lista = nuevo;
    }else {
        if(strcmp(nuevo->datos.nombre,lista->datos.nombre)<0){
            lista = agregarPpioDoble(lista, nuevo);
        } else {
        // se puede recorrer la lista utilizando un solo puntero??
            nodoDoble * ante = lista;
            nodoDoble * seg = lista->siguiente;
            while((seg != NULL) &&(strcmp(nuevo->datos.nombre,seg->datos.nombre)>0)) {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->anterior = ante;
            nuevo->siguiente = seg;
            if (seg!=NULL)
            seg->anterior=nuevo;
        }
    }
    return lista;
}

////////////////////////////////////////
void mostrarLista(nodoDoble *lista){
    nodoDoble *auxNodo;
    auxNodo=lista;
    while(auxNodo!=NULL)
    {
        printf(" \n%s %s %d \n", auxNodo->datos.nombre,auxNodo->datos.apellido,auxNodo->datos.edad);
        auxNodo=auxNodo->siguiente;
    }


}
//////////////////////////////////
nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo) {


    /*nuevo->siguiente = lista;
    if(lista != NULL)
        lista->anterior=nuevo;
return nuevo;*/


  if(lista == NULL)
        lista = nuevo;
    else{
        nuevo->siguiente = lista;
        nuevo->anterior=NULL;
        lista = nuevo;
        }

    return lista;

}
//////////////////////////////////////////////////////
nodoDoble * buscarUltimoDobleRecursivo (nodoDoble * lista) {
    nodoDoble * rta;
        if (lista==NULL)
            rta=NULL;
        else
            if(lista->siguiente==NULL)
                rta=lista;
            else
        rta=buscarUltimoDobleRecursivo(lista->siguiente);
return rta;
}
//////////////////////////////////////////////////+
nodoDoble *borrarNodoDoble(nodoDoble *lista,char nombre[20]){

nodoDoble *sig;
nodoDoble * act;
nodoDoble * ante; //apunta al nodo anterior que seg.

        if((lista != NULL) && (strcmp(nombre, lista->datos.nombre)==0 )) {
            nodoDoble * aux = lista;
            lista = lista->siguiente; //salteo el primer nodo.
            free(aux); //elimino el primer nodo.
        }else {
            act = lista;
            while((act != NULL) && (strcmp(nombre, act->datos.nombre)!=0 )) {
                    ante = act; //adelanto una posición la variable ante.
                    act = act->siguiente; //avanzo al siguiente nodo.
                    sig=act->siguiente;///tengo la posicion siguiente de la actual
            }
                //en este punto tengo en la variable ante la dirección de
                //memoria del nodo anterior al buscado, y en la variable seg,
                //la dirección de memoria del nodo que quiero borrar.
            if(act!=NULL) {
                ante->siguiente = act->siguiente;
                if (sig!=NULL)
                    sig->anterior=act->anterior;
                //salteo el nodo que quiero eliminar.
                free(act);
                //elimino el nodo.
            }
        }
return lista;

}
//////////////////////////////////////
int capicua(nodoDoble *pri,nodoDoble *fin){

    int capi=1;

    if (pri!=NULL && fin!=NULL){

        if(pri==fin || pri->anterior==fin){

          capi=1;

        }
        else{
            if(pri->datos.edad==fin->datos.edad){
                capi=capicua(pri->siguiente,fin->anterior);

            }
            else
                capi=0;
        }

    }
    return capi;
}

nodoDoble    *puntoMedio(nodoDoble *lista,int contador){

nodoDoble *sig;
nodoDoble * act;
nodoDoble * ante; //apunta al nodo anterior que seg.
            act = lista;

int  num=contador/2;
    printf("\n  asdasd  %i \n",num);


            if (contador%2==0){           // par
                for(int i=1;i<=num;i++){
                        ante=act;
                        act=act->siguiente;
                        sig=act->siguiente;
                        if(act==NULL)
                            free(sig);

                }


            }
            else{
                for(int i=1;i<num+1;i++){   //impar
                        ante=act;
                        act=act->siguiente;
                        sig=act->siguiente;

                }

            }
        ante->siguiente=act->siguiente;
        if (sig!=NULL)
                sig->anterior=act->anterior;

        free(act);



return lista;
}




///////////////////////
/*int contarRecursivo(nodoDoble *lista){

int contador=0;
nodoDoble *aux=lista;
	if(aux==NULL){

		return 0;

	}
	else {
	   if(aux->datos.edad %10==0)
            contador=contarRecursivo(aux->siguiente)+1;
	   else
		contador=contarRecursivo(aux->siguiente);
	}

    return contador;
}*/
int contarRecursivo(nodoDoble *lista){

int contador=0;


    if(lista!=NULL){

        if(lista->datos.edad %10==0)
            contador=contarRecursivo(lista->siguiente)+1;
	   else
		contador=contarRecursivo(lista->siguiente);
    }

return contador;
}
