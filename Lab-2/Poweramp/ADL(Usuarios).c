#include "ADL(Usuarios).h"

nodoListaCancion*inicLista(){
    return NULL;
}

nodoListaCancion*crearNodo(stCancion c){
    nodoListaCancion * aux = (nodoListaCancion*)malloc(sizeof(nodoListaCancion));
    aux->c= c;
    aux->sig = NULL;
    return aux;
}
nodoListaCancion * agregarEnOrden(nodoListaCancion * lista, nodoListaCancion * nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        if(strcmp(nuevoNodo->c.titulo,lista->c.titulo)<0){
            lista = agregarFinal(lista, nuevoNodo);
        }else{
            nodoListaCancion* ante = lista;
            nodoListaCancion* seg = lista->sig;
            while( (seg != NULL)&&(strcmp(nuevoNodo->c.titulo,seg->c.titulo)>=0) )
            {
                ante = seg;
                seg = seg->sig;
            }
            nuevoNodo->sig = seg;
            ante->sig = nuevoNodo;
        }
    }
    return lista;

}

nodoListaCancion*agregarPPio(nodoListaCancion*lista,nodoListaCancion*nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodoListaCancion*agregarFinal(nodoListaCancion*lista, nodoListaCancion*nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }
    else{
        nodoListaCancion* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevoNodo;
    }
    return lista;
}

nodoListaCancion*buscarUltimo(nodoListaCancion*lista){
    nodoListaCancion* seg = lista;
    if(seg)
        while(seg->sig != NULL)
        {
            seg = seg->sig;
        }
    return seg;
}
void recorrerYmostrar(nodoListaCancion* lista){
    nodoListaCancion*seg = lista;
    while (seg != NULL){
        mostrarNodo(seg);
        seg= seg->sig;
    }
}

void mostrarNodo(nodoListaCancion*lista){
    nodoListaCancion*seg=lista;
    if(seg!=NULL){
        muestraUnaCancion(seg->c);
        mostrarNodo(seg->sig);
    }
}

nodoListaCancion * borrarNodo(nodoListaCancion * lista, char nombre[20]){
    nodoListaCancion * seg;
    nodoListaCancion * ante;
    if((lista != NULL) && (strcmp(nombre, lista->c.titulo)==0 )){
        nodoListaCancion* aux = lista;
        lista = lista->sig;
        free(aux);
    }else{
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->c.titulo)!=0 )){
            ante = seg;
            seg = seg->sig;
        }

        if( seg!= NULL){
            ante->sig = seg->sig;
            free(seg);
        }
    }
    return lista;
}


/// ///////////////////////////////////////////////////////////////////////////////////////

int agregar(stCeldaUsuarios adl[], stUser u, int validos){
    adl[validos].a = u;
    adl[validos].listaDeCanciones = inicLista();
    validos++;
    return validos;
}


int alta (stCeldaUsuarios adl[], stUser u, stCancion c, int validos){
    nodoListaCancion* aux = crearNodo(c);
    int pos = buscaPosUser(adl,u,validos);
    if(pos==-1){
        validos=agregar(adl,u,validos);
        pos=validos-1;
    }
    adl[pos].listaDeCanciones=agregarFinal(adl[pos].listaDeCanciones, aux);
    return validos;
}


int buscaPosUser(stCeldaUsuarios adl[], stUser u, int validos){
    int rta=-1;
    int i=0;
    while((i<validos)&&(rta==-1)){
        if(strcmp(adl[i].a.nombreUsuario,u.nombreUsuario)==0){
            rta=i;
        }
        i++;
    }
    return rta;
}
int archivo2adl(stCeldaUsuarios adl[], int validos, int dim){

    FILE* archUser=fopen(arUser, "rb");
    FILE* archPlay=fopen(arPlaylist, "rb");
    int i=buscarUltimoIdPlaylist();
    int flag=0;
    if(archUser){
        stUser u;
        if(archPlay){
        stPlaylist p;
        while(fread(&u,sizeof(stUser),1,archUser)>0&&validos<dim){
                rewind(archPlay);
                flag=0;
                while(fread(&p,sizeof(stPlaylist),1,archPlay)>0){
                    if(u.idUsuario==p.idUsuario){
                        stCancion auxC=retornarCancionXID(p.idCancion);
                        validos=alta(adl,u,auxC,validos);
                        flag=1;
                    }
                }
                    if(flag==0){
                        validos=altaUsuario(adl,u,validos);
                    }
                }
                }
            }
//        }
    fclose(archUser);
    fclose(archPlay);
    return validos;
}

stCancion retornarCancionXID(int id){
    stCancion aux;
    FILE*pArchi=fopen(arCanciones,"rb");
    stCancion a;
    if(pArchi){
        while(fread(&a,sizeof(stCancion),1,pArchi)>0){
            if(id==a.idCancion){
                aux=a;
            }
        }
    fclose(pArchi);
    }
return aux;
}

void mostrarADL(stCeldaUsuarios adl[], int validos){
    printf("\nMostrando el arreglo de listas: \n");
    int i=0;
    while(i<validos){
        printf("\n\nUsuario %d: %s",adl[i].a.idUsuario,adl[i].a.nombreUsuario);
        printf("\nListado de : %d\n");
        printf("==============================================================\n");
        mostrarNodo(adl[i].listaDeCanciones);
        i++;
    }
}

void pasarDeAdlToArchivo(stCeldaUsuarios adl[],int validos){
    int i=0;
    FILE*pArchiUser=fopen(arUser,"wb");
    FILE*pArchiPlay=fopen(arPlaylist,"wb");
    if(pArchiUser){
        stUser u;
        stPlaylist p;
        while(i<validos){
            u=adl[i].a;
            fwrite(&u,sizeof(stUser),1,pArchiUser);
                while(adl[i].listaDeCanciones!=NULL){
                    cargarArchivoPlaylist(adl[i].a.idUsuario,adl[i].listaDeCanciones->c.idCancion);
                    adl[i].listaDeCanciones=adl[i].listaDeCanciones->sig;
                }
                i++;
            }


            }
        fclose(pArchiUser);
        fclose(pArchiPlay);
    }
//}

///MODIFICACION ADL USUARIO/////////////////////////////////

void modificarNombreADL(stCeldaUsuarios adl[],int validos,char nombreNuevo[], int id){
    int i=0;
    int flag=0;
    while(i<validos&&flag==0){
        if(adl[i].a.idUsuario==id){
            strcpy(adl[i].a.nombreUsuario,nombreNuevo);
            flag=1;
        }
        i++;
    }
}

void modificarPasswordfADL(stCeldaUsuarios adl[],int validos,char nuevaPassword[], int id){
    int i=0;
    int flag=0;
    while(i<validos&&flag==0){
        if(adl[i].a.idUsuario==id){
            strcpy(adl[i].a.password,nuevaPassword);
            flag=1;
        }
        i++;
    }
}

void modificarAnioNADL(stCeldaUsuarios adl[],int validos,int nuevoAnio, int id){
    int i=0;
    int flag=0;
    while(i<validos&&flag==0){
        if(adl[i].a.idUsuario==id){
            adl[i].a.anioNacimiento=nuevoAnio;
            flag=1;
        }
        i++;
    }
}

void ModificarPaisADL(stCeldaUsuarios adl[],int validos,char nombrePais[], int id){
    int i=0;
    int flag=0;
    while(i<validos&&flag==0){
        if(adl[i].a.idUsuario==id){
            strcpy(adl[i].a.pais,nombrePais);
            flag=1;
        }
        i++;
    }
}

void modificarGeneroADL(stCeldaUsuarios adl[],int validos,char nuevoGenero, int id){
    int i=0;
    int flag=0;
    while(i<validos&&flag==0){
        if(adl[i].a.idUsuario==id){
            adl[i].a.genero=nuevoGenero;
            flag=1;
        }
        i++;
    }
}
void modificarEstadoNADL(stCeldaUsuarios adl[],int validos,int nuevoEstado, int id){
    int i=0;
    int flag=0;
    while(i<validos&&flag==0){
        if(adl[i].a.idUsuario==id){
            adl[i].a.Ueliminado=nuevoEstado;
            flag=1;
        }
        i++;
    }
}

int cargarADLmanual(stCeldaUsuarios adl[],int validos,int dim){
    stUser a;
    int flag=1;
    stCancion c;
    if(validos<=dim){
            while(flag==1){
            printf("\nIngrese el nombre del Usuario: ");
            fflush(stdin);
            gets(a.nombreUsuario);
                if(buscaPosUser(adl,a,validos)==-1){
                    flag=0;
                }else{
                    printf("El Usuario ya se encuentra en el sistema, intente nuevamente");
                    flag=1;
                }
            }
            printf("\nIngrese su contrasenia: ");
            fflush(stdin);
            scanf("%s",a.password);
            printf("\nIngrese su anio de nacimiento: ");
            fflush(stdin);
            scanf("%i",&a.anioNacimiento);
            printf("\nCual es su genero(H/M): ");
            fflush(stdin);
            scanf("%c",&a.genero);
            printf("\nIngrese su pais de nacimiento: ");
            fflush(stdin);
            scanf("%s",a.pais);
            a.Ueliminado=0;
            a.idUsuario=validos;
            validos=altaUsuario(adl,a,validos);
    }
    return validos;
}

int altaUsuario (stCeldaUsuarios adl[], stUser u, int validos){
    int pos = buscaPosUser(adl,u,validos);
    if(pos==-1){
        validos=agregar(adl,u,validos);
        pos=validos-1;

    }
    return validos;
}



void ConsultaUserADL(stCeldaUsuarios adl[],int validos,int id){
    int i=0;
    int flag=0;
    while(i<validos&&flag==0){
        if(id==adl[i].a.idUsuario){
            MuestraUnUserCualquiera(adl[i].a);
            flag=1;
        }
        i++;
    }
}

void elimininarUserADL(stCeldaUsuarios adl[],int validos,int idUser){
    int i=0;
    int flag=0;
    while(i<validos&&flag==0){
        if(adl[i].a.idUsuario==idUser){
            adl[i].a.Ueliminado=1;
            flag=1;
        }
        i++;
    }
}
void recuperarUserADL(stCeldaUsuarios adl[],int validos,int idUser){
    int i=0;
    int flag=0;
    while(i<validos&&flag==0){
        if(adl[i].a.idUsuario==idUser){
            adl[i].a.Ueliminado=1;
            flag=0;
        }
        i++;
    }
}
void mostrarUsuarioADLxID(stCeldaUsuarios adl[],int validos,int idUserAElim){
    int i=0;
    int flag=0;
    while(i<validos&&flag==0){
        if(adl[i].a.idUsuario==idUserAElim){
            MuestraUnUser(adl[i].a);
            flag=1;
        }
        i++;
    }
}
int ValidacionUsuarioXIdADL(int id,stCeldaUsuarios adl[],int validos){
    int i=0;
    int flag=0;
        while(i<validos){
           if(id==adl[i].a.idUsuario){
                flag=1;
        }
        i++;
    }
    return flag;
}
