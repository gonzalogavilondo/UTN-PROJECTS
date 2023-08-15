#ifndef TREN_H_INCLUDED
#define TREN_H_INCLUDED

#include "vagon.h"

typedef struct {
   int nroTren;
   char categoria[20];
   nodoVagon * listaVagones;
}tren;

#endif // TREN_H_INCLUDED
