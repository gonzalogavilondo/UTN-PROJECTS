#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "string.h"
#include "time.h"
#include "Canciones.h"
#include "Usuarios.h"

#define arPlaylist "Playlist.dat"

typedef struct
{
    int idPlaylist;
    int idUsuario;
    int idCancion;
} stPlaylist;

void cargarArchivoPlaylist(int idUsuario,int idCancion);
void guardarArchivoPlaylist(stPlaylist a);
void mostrarArchivoPlaylist();
stCancion encuentraID(int idCancion);
void mostrarPlaylist(int idUser);



#endif // PLAYLIST_H_INCLUDED
