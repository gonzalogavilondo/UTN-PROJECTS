#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int id;
    int codigo;
    int rubro; /// 1 - Televisores / 2 - Lavarropas / 3 - Cocinas / 4 - Calefactores
    char marca[30];
    char modelo[30];
    float precio;
} stArticulo;

stArticulo cargarUnArticulo();
void strRubro(int rubro,char strR[30]);
void mostrarUnArticulo(stArticulo a);

#endif // ARTICULO_H_INCLUDED
