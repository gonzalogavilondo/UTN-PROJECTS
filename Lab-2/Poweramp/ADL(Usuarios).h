#ifndef ADL(USUARIOS)_H_INCLUDED
#define ADL(USUARIOS)_H_INCLUDED

#include "Usuarios.h"
#include "Canciones.h"
#include "Playlist.h"



typedef struct{
    stCancion c;
    struct _nodoListaCancion * sig;
} nodoListaCancion;

nodoListaCancion*inicLista();
nodoListaCancion*crearNodo();
nodoListaCancion*agregarPPio(nodoListaCancion*lista,nodoListaCancion*nuevoNodo);
nodoListaCancion*agregarFinal(nodoListaCancion*lista, nodoListaCancion*nuevoNodo);
nodoListaCancion*buscarUltimo(nodoListaCancion*lista);
void recorrerYmostrar(nodoListaCancion* lista);
void mostrarNodo(nodoListaCancion*lista);
nodoListaCancion * borrarNodo(nodoListaCancion * lista, char nombre[20]);
stCancion retornarCancionXID(int id);

/// ///////////////////////////////////////////////////////////////////////////



typedef struct {
    stUser a;
    nodoListaCancion*listaDeCanciones;
}stCeldaUsuarios;

int archivo2adl(stCeldaUsuarios adl[], int validos, int dim);
int alta (stCeldaUsuarios adl[], stUser u, stCancion c, int validos);
int agregar(stCeldaUsuarios adl[], stUser u, int validos);
int buscaPos(stCeldaUsuarios adl[], stUser u, int validos);
void mostrarADL(stCeldaUsuarios adl[], int validos);
stCancion retornarCancionXID(int id);
void mostrarADL(stCeldaUsuarios adl[], int validos);
void pasarDeAdlToArchivo(stCeldaUsuarios adl[],int validos);

int cargarADLmanual(stCeldaUsuarios adl[],int validos,int dim);
int altaUsuario (stCeldaUsuarios adl[], stUser u, int validos);

void elimininarUserADL(stCeldaUsuarios adl[],int validos,int idUser);
void recuperarUserADL(stCeldaUsuarios adl[],int validos,int idUser);

///MODIFICACION ADL USUARIO/////////////////////////////////
void elimininarUserADL(stCeldaUsuarios adl[],int validos,int idUser);
void modificarEstadoNADL(stCeldaUsuarios adl[],int validos,int nuevoEstado, int id);
void modificarGeneroADL(stCeldaUsuarios adl[],int validos,char nuevoGenero, int id);
void ModificarPaisADL(stCeldaUsuarios adl[],int validos,char nombrePais[], int id);
void modificarAnioNADL(stCeldaUsuarios adl[],int validos,int nuevoAnio, int id);
void modificarPasswordfADL(stCeldaUsuarios adl[],int validos,char nuevaPassword[], int id);
void modificarNombreADL(stCeldaUsuarios adl[],int validos,char nombreNuevo[], int id);

int ValidacionUsuarioXIdADL(int id,stCeldaUsuarios adl[],int validos);
#endif // ADL(USUARIOS)_H_INCLUDED
