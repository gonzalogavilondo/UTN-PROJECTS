#include "funciones_aritmeticas.h"
#include "algoritmos.h"

/**
    Se tiene un arreglo de números enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe:
    a. Hacer una función que inicialice las celdas del arreglo en –1.
    b. Hacer una función que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.
    c. Hacer una función que sume el contenido del arreglo y lo retorne.
    d. Hacer una función que cuente la cantidad de valores ingresados.
    e. Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio
    usando las funciones anteriores (c y d).
    f. Hacer la función main correspondiente.
**/

int main()
{
    int *vector      = NULL;
    int cntElementos = 0,
        res          = 0;
    float promedio   = 0.0;

    ///Reservamos memoria para el vector con MAXDIM.
    vector = ReservarMemoria(MAXDIM);

    ///a. Realizamos una funcion para que inicialice las celdas en -1
    InicializarVector(vector, MAXDIM);

    ///b. Cargamos el vector, no se sabe cuantos elementos va a tener, y en esa misma funcion voy a reallocar la memoria que se utiliza y me devuelve la cantidad de elementos.
    cntElementos = CargarVector(vector);

    ///Mostramos el vector
    MostrarVector(vector, cntElementos);

    ///c. Función que sume el contenido del arreglo y lo retorne.
    res = SumaContenidoVector(vector, cntElementos);
    printf("La suma del contenido del vector es: %d", res);

    ///d. Ya lo tenemos en cntElementos ya que la funcion CargarVector me devuelve la cantidad de elementos validos ingresados.


    ///e.Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio usando las funciones anteriores (c y d).
    ///Nota: A la funcion le paso la cantidad de elementos validos porque ya lo tengo de otra funcion, esto lo hace mas facil aun.
    promedio = PromedioVector(vector, cntElementos);
    printf("\nEl promedio del contenido del vector es: %.2f\n", promedio);


    return 0;
}
