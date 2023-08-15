#include "declaraciones.h"

void interfazConsola()
{
    printf(" _____________________________________________\n");
    printf("|                                             |\n");
    printf("|                 CALCULADORA                 |\n");
    printf("|_____________________________________________|\n");
    printf("|                                             |\n");
    printf("|  ___________ ___________ ___________ _______|\n");
    printf("| |     7     |     8     |     9     |   /   |\n");
    printf("| |___________|___________|___________|_______|\n");
    printf("| |     4     |     5     |     6     |   *   |\n");
    printf("| |___________|___________|___________|_______|\n");
    printf("| |     1     |     2     |     3     |   -   |\n");
    printf("| |___________|___________|___________|_______|\n");
    printf("| |     0     |     .     |     =     |   +   |\n");
    printf("| |___________|___________|___________|_______|\n");
    printf("|                                             |\n");
    printf("|_____________________________________________|\n\n");

}

char elegirOperacion()
{
    char operacion;
    int operacionValida = 0;

    do
    {
        printf("Ingrese la operacion (+, -, *, /) o 'q' para salir: ");
        fflush(stdin);
        scanf("%c", &operacion);

        if (operacion == 'q')
        {
            printf("Saliendo de la calculadora...\n");
            operacionValida = 1;
        }
        else if (operacion == '+' || operacion == '-' || operacion == '*' || operacion == '/')
        {
            operacionValida = 1;
        }
        else
        {
            printf("Operacion no valida.\n");
        }

    } while(!operacionValida);

    return operacion;
}

float realizarOperacion(char operacion, float num1, float num2)
{
    float resultado = 0.0;
    switch (operacion)
    {
        case '+':
            resultado = suma(num1, num2);
            break;
        case '-':
            resultado = resta(num1, num2);
            break;
        case '*':
            resultado = multiplicacion(num1, num2);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("No se puede dividir por cero.\n");
            }
            else
            {
                resultado = division(num1, num2);
            }
            break;
        default:
            printf("Operacion invalida.\n");
    }
    return resultado;
}

float suma(float n1, float n2)
{
    return n1 + n2;
}

float resta(float n1, float n2)
{
    return n1 - n2;
}

float multiplicacion(float n1, float n2)
{
    return n1 * n2;
}

float division(float n1, float n2)
{
    return n1 / n2;
}
