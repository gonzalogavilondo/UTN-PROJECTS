#include "Canciones.h"



///========FUNCIONES CANCIONES==========
void cargaArchiCanciones(){
    stCancion a;
    int opcion=0;
    a.idCancion=buscaUltimoIdCancion();
    while(opcion!=27){
        system("cls");
        a.idCancion++;
        printf("<<<<<<CARGA CANCION>>>>>>\n");
        printf("Ingrese el titulo: ");
        fflush(stdin);
        gets(a.titulo);
        printf("\nIngrese artista: ");
        fflush(stdin);
        gets(a.artista);
        printf("\nIngrese duracion: ");
        fflush(stdin);
        scanf("%d",&a.duracion);
        printf("\nIngrese album: ");
        fflush(stdin);
        gets(a.album);
        printf("\nIngrese anio: ");
        fflush(stdin);
        scanf("%d",&a.anio);
        printf("\nIngrese genero: ");
        fflush(stdin);
        gets(a.genero);
        printf("\nIngrese comentario: ");
        fflush(stdin);
        gets(a.comentario);
        a.eliminado=0;
        guardarCancion(a);
        printf("ESC para salir\n");
        fflush(stdin);
        opcion=getch();
    }
}
void guardarCancion(stCancion a){
    FILE*pArchCancion = fopen(arCanciones,"ab");
    if(pArchCancion!=NULL){
        fwrite(&a,sizeof(stCancion),1,pArchCancion);
        fclose(pArchCancion);
    }
}

///Mostrar cancion no eliminadas
void mostrarCanciones(){
    stCancion a;
    FILE*pArchCancion=fopen(arCanciones,"rb");
    if(pArchCancion!=NULL){
        while(fread(&a,sizeof(stCancion),1,pArchCancion)>0){
            muestraUnaCancion(a);
    }
    fclose(pArchCancion);
    }
}

void muestraUnaCancion(stCancion a){
    if(a.eliminado==0){
    printf("==========================================\n");
    printf("\n id:..........%d",a.idCancion);
    printf("\n titulo:......%s",a.titulo);
    printf("\n artista:.....%s",a.artista);
    printf("\n duracion:....%d",a.duracion);
    printf("\n album:.......%s",a.album);
    printf("\n anio:........%d",a.anio);
    printf("\n genero:......%s",a.genero);
    printf("\n comentario:..%s",a.comentario);
    printf("\n estado:......%d",a.eliminado);
    printf("\n==========================================\n");
    }
}

void muestraUnaCancionAcotado(stCancion a){
    int i=0;
    int x=0;
    int y=0;
    int dim=cantSong();
    while(i<dim){
        while(i<15){
            if(a.eliminado==0){
                gotoxy(x,y);
                y++;
                printf("\n================================\n");
                gotoxy(x,y);
                y++;
                printf("\nid:..........%d",a.idCancion);
                gotoxy(x,y);
                y++;
                printf("\ntitulo:......%s",a.titulo);
                i++;
            }

        }
        x=x+32;
        x=0;
    }

}
///Mostrar cancion eliminadas
void mostrarCancionesEliminada(){
    stCancion a;
    FILE*pArchCancion=fopen(arCanciones,"rb");
    if(pArchCancion!=NULL){
        while(fread(&a,sizeof(stCancion),1,pArchCancion)>0){
            muestraUnaCancionEliminada(a);
    }
    fclose(pArchCancion);
}
}
void muestraUnaCancionEliminada(stCancion a){
    if(a.eliminado==1){
    printf("==========================================\n");
    printf("\n id:..........%d",a.idCancion);
    printf("\n titulo:......%s",a.titulo);
    printf("\n artista:.....%s",a.artista);
    printf("\n duracion:....%d",a.duracion);
    printf("\n album:.......%s",a.album);
    printf("\n anio:........%d",a.anio);
    printf("\n genero:......%s",a.genero);
    printf("\n comentario:..%s",a.comentario);
    printf("\n estado:......%d",a.eliminado);
    printf("\n==========================================\n");
    }
}
int buscaUltimoIdCancion(){
    stCancion a;
    int idcancion=-1;
    FILE*pArchCancion=fopen(arCanciones,"rb");
    if(pArchCancion!=NULL){
        fseek(pArchCancion,sizeof(stCancion)*(-1),SEEK_END);
        if(fread(&a,sizeof(stCancion),1,pArchCancion)>0){
              idcancion=a.idCancion;
              }
              fclose(pArchCancion);
    }
    return idcancion;
}
///CANCIONES RECOMENDADAS
void cancionesRecomendadas(){
    srand(time(NULL));
    int i,j,k;
    int min=1;
    int max=50;
    int flag=0;
    i=rand()%(max-min)+min;
    j=rand()%(max-min)+min;
    k=rand()%(max-min)+min;

    ConsultaCancionxID(i);

    while(flag==0){
        if(j!=i){
            ConsultaCancionxID(j);
            flag=1;
        }else{
            j=rand()%(max-min)+min;
        }
    }

    flag=0;

    while(flag==0){
        if(k!=i){
            if(k!=j){
                ConsultaCancionxID(k);
                flag=1;
            }else{
                k=rand()%(max-min)+min;
            }
        }else {
            k=rand()%(max-min)+min;
        }
    }while(flag==0);
}


///FUNCIONES CANCIONES TIPEOS:
void modificarTituloCancion(char tituloN[],int idIngresado){
    stCancion a;
    int flag=0;
    FILE*pArchiCancion = fopen(arCanciones,"r+b");
    if(pArchiCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchiCancion)>0){
                if(a.idCancion==idIngresado){
                    fseek(pArchiCancion,sizeof(stCancion)*(-1),SEEK_CUR);
                    strcpy(a.titulo,tituloN);
                    fwrite(&a,sizeof(stCancion),1,pArchiCancion);
                    flag=1;
    }
    }
    fclose(pArchiCancion);
}
}

void modificarArtistaCancion(char artistaN[],int idIngresado){
    stCancion a;
    int flag=0;
    FILE*pArchiCancion = fopen(arCanciones,"r+b");
    if(pArchiCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchiCancion)>0){
                if(a.idCancion==idIngresado){
                    fseek(pArchiCancion,sizeof(stCancion)*(-1),SEEK_CUR);
                    strcpy(a.artista,artistaN);
                    fwrite(&a,sizeof(stCancion),1,pArchiCancion);
                    flag=1;
    }
    }
    fclose(pArchiCancion);
}
}

void modificarDuracionCancion(int duracionN,int idIngresado){
    stCancion a;
    int flag=0;
    FILE*pArchiCancion = fopen(arCanciones,"r+b");
    if(pArchiCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchiCancion)>0){
                if(a.idCancion==idIngresado){
                    fseek(pArchiCancion,sizeof(stCancion)*(-1),SEEK_CUR);
                    a.duracion=duracionN;
                    fwrite(&a,sizeof(stCancion),1,pArchiCancion);
                    flag=1;
        }
    }
    fclose(pArchiCancion);
}
}

void modificarAlbumCancion(char albumN[],int idIngresado){
    stCancion a;
    int flag=0;
    FILE*pArchiCancion = fopen(arCanciones,"r+b");
    if(pArchiCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchiCancion)>0){
                if(a.idCancion==idIngresado){
                    fseek(pArchiCancion,sizeof(stCancion)*(-1),SEEK_CUR);
                    strcpy(a.album,albumN);
                    fwrite(&a,sizeof(stCancion),1,pArchiCancion);
                    flag=1;
    }
    }
   fclose(pArchiCancion);
}
}

void modificarAnioCancion(int anioN,int idIngresado){
    stCancion a;
    int flag=0;
    FILE*pArchiCancion = fopen(arCanciones,"r+b");
    if(pArchiCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchiCancion)>0){
                if(a.idCancion==idIngresado){
                    fseek(pArchiCancion,sizeof(stCancion)*(-1),SEEK_CUR);
                    a.anio=anioN;
                    fwrite(&a,sizeof(stCancion),1,pArchiCancion);
                    flag=1;
    }
    }
    fclose(pArchiCancion);
}
}

void modificarGeneroCancion(char generoN[],int idIngresado){
    stCancion a;
    int flag=0;
    FILE*pArchiCancion = fopen(arCanciones,"r+b");
    if(pArchiCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchiCancion)>0){
                if(a.idCancion==idIngresado){
                    fseek(pArchiCancion,sizeof(stCancion)*(-1),SEEK_CUR);
                    strcpy(a.genero,generoN);
                    fwrite(&a,sizeof(stCancion),1,pArchiCancion);
                    flag=1;
    }
    }
        fclose(pArchiCancion);
}
}

void modificarComentarioCancion(char comentarioN[],int idIngresado){
    stCancion a;
    int flag=0;
    FILE*pArchiCancion = fopen(arCanciones,"r+b");
    if(pArchiCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchiCancion)>0){
                if(a.idCancion==idIngresado){
                    fseek(pArchiCancion,sizeof(stCancion)*(-1),SEEK_CUR);
                    strcpy(a.comentario,comentarioN);
                    fwrite(&a,sizeof(stCancion),1,pArchiCancion);
                    flag=1;
    }
    }
        fclose(pArchiCancion);
}
}

void elimininarCancion(char nombreCancion[]){
    stCancion a;
    int flag=0;
    FILE*pArchiCancion = fopen(arCanciones,"r+b");
    if(pArchiCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchiCancion)>0){
                if(strcmp(a.titulo,nombreCancion)==0){
                    fseek(pArchiCancion,sizeof(stCancion)*(-1),SEEK_CUR);
                    a.eliminado=1;
                    fwrite(&a,sizeof(stCancion),1,pArchiCancion);
                    flag=1;
    }
    }
fclose(pArchiCancion);
}
   if(flag==0){
        system("cls");
        printf("[*ERROR*] \nLa cancion no existe!...\n");
    }

}

void recuperarCancion(char nombreCancion[]){
    stCancion a;
    int flag=0;
    FILE*pArchiCancion = fopen(arCanciones,"r+b");
    if(pArchiCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchiCancion)>0){
                if(strcmp(a.titulo,nombreCancion)==0){
                    fseek(pArchiCancion,sizeof(stCancion)*(-1),SEEK_CUR);
                    a.eliminado=0;
                    fwrite(&a,sizeof(stCancion),1,pArchiCancion);
                    flag=1;
    }
    }
        fclose(pArchiCancion);
}
    if(flag==0){
        system("cls");
        printf("[*ERROR*] \nLa cancion no se encuentra en el eliminada!...\n");
    }

}

///CONSULTA CANCION x ID
void ConsultaCancionxID(char id){
    stCancion a;
    int flag=0;
    FILE*pArchCancion=fopen(arCanciones,"rb");
    if(pArchCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchCancion)>0){
           if(id==a.idCancion){
                muestraUnaCancion(a);
                flag=1;
        }
    }
    fclose(pArchCancion);
    }
}

///CONSULTA CANCION
void ConsultaCancion(char titulo[]){
    stCancion a;
    int flag=0;
    FILE*pArchCancion=fopen(arCanciones,"rb");
    if(pArchCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchCancion)>0){
           if(strcmp(titulo,a.titulo)==0){
                muestraUnaCancion(a);
                flag=1;
        }
    }
    fclose(pArchCancion);
    }
}

///VALIDACION
int validacionCancionXId(int id){
    stCancion a;
    int flag=0;
    FILE*pArchCancion=fopen(arCanciones,"rb");
    if(pArchCancion!=NULL){
        while(flag==0&&fread(&a,sizeof(stCancion),1,pArchCancion)>0){
           if(id==a.idCancion){
                flag=1;
        }
    }
    fclose(pArchCancion);
    }
    return flag;
}

///ordenacion canciones
int posMenorTitulo (stCancion a[], int pos, int cant)
{

    int i = pos+1;
    int posMenor=pos;
    char menortitulo[40];
    strcpy(menortitulo,a[pos].titulo);

    while(i<cant){
        if(strcmpi(menortitulo,a[i].titulo)>0){
            strcpy(menortitulo,a[i].titulo);
            posMenor=i;
        }
        i++;
    }
    return posMenor;
}

void ordenarTitulo(stCancion a[], int cant)
{
    int i=0;
    int menor;
    stCancion aux;

    while(i<cant)
    {
        menor = posMenorTitulo(a,i,cant);
        aux=a[menor];
        a[menor]=a[i];
        a[i]=aux;
        i++;
    }
}

int posMenorGenero (stCancion a[], int pos, int cant)
{

    int i = pos+1;
    int posMenor=pos;
    char menorGenero[40];
    strcpy(menorGenero,a[pos].genero);

    while(i<cant){
        if(strcmpi(menorGenero,a[i].genero)>0){
            strcpy(menorGenero,a[i].genero);
            posMenor=i;
        }
        i++;
    }
    return posMenor;
}

void ordenarGenero(stCancion a[], int cant)
{
    int i=0;
    int menor;
    stCancion aux;

    while(i<cant)
    {
        menor = posMenorGenero(a,i,cant);
        aux=a[menor];
        a[menor]=a[i];
        a[i]=aux;
        i++;
    }
}


int passTOarchivoCanciones(stCancion b[],int dimension,int validos){
    int i=0;
    stCancion a;

    FILE*archiCancion=fopen(arCanciones,"rb");
    if(archiCancion!=NULL){
        while(fread(&a,sizeof(stCancion),1,archiCancion)>0&&i<dimension){
            b[i]=a;
            i++;
        }
        fclose(archiCancion);
    }
    return i;
}

void mostrarArregloCanciones(stCancion a[],int validos){
    for(int i=0;i<validos;i++){
        printf("\n===========================================\n");
        printf("ID:         %d\n",a[i].idCancion);
        printf("TITULO:     %s\n",a[i].titulo);
        printf("ARTISTA:    %s\n",a[i].artista);
        printf("DURACION:   %d\n",a[i].duracion);
        printf("ALBUM:      %s\n",a[i].album);
        printf("ANIO:       %d\n",a[i].anio);
        printf("GENERO:     %s\n",a[i].genero);
        printf("COMENTARIO: %s\n",a[i].comentario);
        printf("ELIMINADO:  %d\n",a[i].eliminado);
        printf("\n===========================================\n");
    }
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////

nodoArbolCancion*inicArbol(){
    return NULL;
}

nodoArbolCancion*crearNodoArbol(stCancion a){
    nodoArbolCancion*nuevoNodo=(nodoArbolCancion*)malloc(sizeof(nodoArbolCancion));
    nuevoNodo->cancion=a;
    nuevoNodo->der=NULL;
    nuevoNodo->izq=NULL;
    return nuevoNodo;
}

nodoArbolCancion*ingresarNodoArbolOrdenado(nodoArbolCancion*arbol,nodoArbolCancion*nuevoNodo){
    if(arbol==NULL){
        arbol=nuevoNodo;
    }else{
        if(arbol->cancion.idCancion<nuevoNodo->cancion.idCancion){
            arbol->der=ingresarNodoArbolOrdenado(arbol->der,nuevoNodo);
        }else{
            //if(arbol->cancion.idCancion>nuevoNodo->cancion.idCancion){
                arbol->izq=ingresarNodoArbolOrdenado(arbol->izq,nuevoNodo);
            //}
        }
    }
return arbol;
}

void mostrarPreorder(nodoArbolCancion*arbol){
    if(arbol){
        muestraUnaCancion(arbol->cancion);
        mostrarPreorder(arbol->izq);
        mostrarPreorder(arbol->der);
    }
}

void mostrarInorder(nodoArbolCancion*arbol){
    if(arbol){
        mostrarInorder(arbol->izq);
        muestraUnaCancion(arbol->cancion);
        mostrarInorder(arbol->der);
    }
}

void mostrarPosorder(nodoArbolCancion*arbol){
    if(arbol){
        mostrarPosorder(arbol->izq);
        mostrarPosorder(arbol->der);
        muestraUnaCancion(arbol->cancion);
    }
}void mostrarPosorderEnColumna(nodoArbolCancion*arbol){
    if(arbol){
        mostrarPosorderEnColumna(arbol->izq);
        mostrarPosorderEnColumna(arbol->der);
        muestraUnaCancionAcotado(arbol->cancion);
    }
}

nodoArbolCancion*buscarXIdCancion(nodoArbolCancion*arbol,int id){
    if(arbol){
        if(arbol->cancion.idCancion!=id){
            buscarXIdCancion(arbol->izq,id);
        }else{
            if(arbol->cancion.idCancion!=id){
                buscarXIdCancion(arbol->der,id);
            }
        }
    }
    return arbol;
}

nodoArbolCancion*borrarNodoArbolCancion(nodoArbolCancion*arbol,int id){
    arbol=borrarID(arbol,id);
    return arbol;
}



nodoArbolCancion*borrarID(nodoArbolCancion*arbol,int id){
    if(arbol!=NULL){
            if(arbol->cancion.idCancion==id){
                if(arbol->izq!=NULL){
                    nodoArbolCancion*masDer=NMD(arbol->izq);
                    arbol->cancion.idCancion=masDer->cancion.idCancion;
                    arbol->der=borrarID(arbol->izq,masDer->cancion.idCancion);
                }else if(arbol->der!=NULL){
                    if(arbol->der!=NULL){
                        nodoArbolCancion*masIzq=NMI(arbol->der);
                        arbol->cancion.idCancion=masIzq->cancion.idCancion;
                        arbol->der=borrarID(arbol->der,masIzq->cancion.idCancion);
                        }
                    }else{
                        free(arbol);
                        arbol=NULL;
                    }
            }
        }
    return arbol;
}
nodoArbolCancion*NMD(nodoArbolCancion*arbol){
    if(arbol->der!=NULL){
        NMD(arbol->der);
    }
    return arbol;
}

nodoArbolCancion*NMI(nodoArbolCancion*arbol){
    if(arbol->izq!=NULL){
        NMI(arbol->izq);
    }
    return arbol;
}

nodoArbolCancion*array2Arbol(nodoArbolCancion*arbol){
    int dimension=100;
    stCancion ArrayP[dimension];
    int validos=0;
    validos=passTOarchivoCanciones(ArrayP,dimension,validos);
    ordenarTitulo(ArrayP,validos);
    //mostrarArregloCanciones(ArrayP,validos);
    arbol=passArray2Arbol(arbol,ArrayP,validos);
return arbol;
}

nodoArbolCancion*passArray2Arbol(nodoArbolCancion*arbol,stCancion arr[],int validos){
    int i=0;
    while(i<validos){
        nodoArbolCancion*nuevoNodo=crearNodoArbol(arr[i]);
        arbol=ingresarNodoArbolOrdenado(arbol,nuevoNodo);
        i++;
    }
return arbol;
}

int cantSong(){
    FILE*pArchCan=fopen("Canciones.dat","rb");
    int i=0;
    if(pArchCan){
        stCancion c;
        while(fread(&c,sizeof(stCancion),1,pArchCan)>0){
            i++;
    }
    }
return i;
}
