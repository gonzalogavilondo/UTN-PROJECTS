#include "Abtree.h"

int main()
{
    ///Cambiar el nro para ejecutar la prueba.
    int nro = 0;

    void (*prueba[])() =
    {
      pruebaArbolBinarioSt, ///nro=0
      pruebaArbolBinarioDeBusquedaSt,///nro=1
      pruebaEliminaEnABBSt, ///nro=2
    };

    (*prueba[nro])();

}
