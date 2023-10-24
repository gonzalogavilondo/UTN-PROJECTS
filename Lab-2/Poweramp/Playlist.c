#include "Playlist.h"

void cargarArchivoPlaylist(int idUsuario,int idCancion){
    stPlaylist a;
    a.idCancion=idCancion;
    a.idUsuario=idUsuario;
    a.idPlaylist=buscarUltimoIdPlaylist();
    a.idPlaylist++;
    guardarArchivoPlaylist(a);
}

void mostrarArchivoPlaylist(){
    stPlaylist a;
    FILE*pArchi=fopen(arPlaylist,"rb");
    if(pArchi){
        while(fread(&a,sizeof(stPlaylist),1,pArchi)>0){
        printf("\n===================");
        printf("\nID USER:.....%d\n",a.idUsuario);
        printf("\nID SONG:.....%d\n",a.idCancion);
        printf("\nID PLAYLIST:.%d\n",a.idPlaylist);
        }
            fclose(pArchi);
    }
}
void guardarArchivoPlaylist(stPlaylist a){
    FILE*pArchi= fopen(arPlaylist,"ab");
    if(pArchi!=NULL){
        fwrite(&a,sizeof(stPlaylist),1,pArchi);
        fclose(pArchi);
    }
}



void mostrarPlaylist(int idUser){
    stPlaylist a;
    stCancion aux;
    FILE*pArchi=fopen(arPlaylist,"rb");
    if(pArchi){
        while(fread(&a,sizeof(stPlaylist),1,pArchi)>0){
            if(idUser==a.idUsuario){
                aux=encuentraID(a.idCancion);
                muestraUnaCancion(aux);
            }
        }
        fclose(pArchi);
    }
}

stCancion encuentraID(int idCancion){
    stCancion a;
    stCancion aux;
    FILE*pArchi=fopen(arCanciones,"rb");
        if(pArchi){
            while(fread(&a,sizeof(stCancion),1,pArchi)>0){
                if(a.idCancion==idCancion){
                    aux=a;
                }
            }
        fclose(pArchi);
        }
    return aux;
}
int buscarUltimoIdPlaylist(){
    stPlaylist a;
    int ultimo=-1;
    FILE*pArchi=fopen(arPlaylist,"rb");
    if(pArchi){
            fseek(pArchi,sizeof(stPlaylist)*(-1),SEEK_END);
            if(fread(&a,sizeof(stPlaylist),1,pArchi)>0){
                ultimo=a.idPlaylist;
            }
        fclose(pArchi);
    }
    return ultimo;
}



//void mostrarPlaylistUser(stCeldaUsuarios adl[],int validos,int idUser){

