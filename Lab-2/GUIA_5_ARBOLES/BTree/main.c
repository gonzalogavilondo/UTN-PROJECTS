#include "Abtree.h"

int main()
{
    ///Cambiar el nro para ejecutar la prueba.
    int nro = 0;

    void (*prueba[])() =
    {
      pruebaArbolBinario, ///nro=0
      pruebaArbolBinarioDeBusqueda,///nro=1
      pruebaEliminaEnABB, ///nro=2
    };

    (*prueba[nro])();

}
