#include "declaraciones.h"

/**
    5. Realice una pequeña calculadora, utilizando funciones (una función de suma, una de
    multiplicación, una de resta, una de división...)
**/
int main()
{
    ///Declaramos e inicializamos variables a utilizar
    char opcion;
    float resultado = 0.0,
          num1      = 0.0,
          num2      = 0.0;

    ///Llamamos a la interfaz grafica
    interfazConsola();

    ///Pedimos al usuario los numeros
    printf("\nIngrese el primer numero: ");
    scanf("%f", &num1);

    ///Vemos que operacion quiere realizar el usuario
    opcion = elegirOperacion();

    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);

    ///Llamamos aa la operacion a realizar
    resultado = realizarOperacion(opcion, num1, num2);

    ///Imprimimos el resultado
    printf("\nEl resultado es: %.2f\n", resultado);

    return 0;
}
