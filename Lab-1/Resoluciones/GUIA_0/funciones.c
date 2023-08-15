#include "declaraciones.h"

/***
    MENU
***/

int menu()
{
    int opcion;
    printf("GUIA 0 DE LABORATORIO I\n");
    printf("----------------------------------------------------------\n\n");
    printf("--SECUENCIALES--\n");
    printf("1 - Ejercicio 1\n");
    printf("2 - Ejercicio 2\n");
    printf("3 - Ejercicio 3\n\n");
    printf("--ESTRUCTURAS SELECTIVAS--\n");
    printf("4 - Ejercicio 1\n\n");
    printf("--SELECTIVOS SIMPLES--\n");
    printf("5 - Ejercicio 1\n");
    printf("6 - Ejercicio 2\n");
    printf("7 - Ejercicio 3\n");
    printf("8 - Ejercicio 4\n");
    printf("9 - Ejercicio 5\n\n");
    printf("--SELECTIVOS COMPUESTOS--\n");
    printf("10- Ejercicio 1\n");
    printf("11- Ejercicio 2\n\n");
    printf("--ESTRUCTURAS REPETITIVAS--\n");
    printf("12- Ejercicio 1\n\n");
    printf("--COMBINACION DE ESTRUCTURAS SELECTIVAS Y REPETITIVAS--\n");
    printf("13- Ejercicio 1\n\n");
    printf("--EJEMPLO PARA - HACER--\n");
    printf("14- Ejercicio 1\n");
    printf("15- Ejercicio 2\n");
    printf("16- Ejercicio 3\n");
    printf("17- Ejercicio 4\n");
    printf("18- Ejercicio 5\n");
    printf("19- Ejercicio 6\n\n");
    printf("--EJERCICIOS ADICIONALES--\n");
    printf("20- Ejercicio 1\n");
    printf("21- Ejercicio 2\n");
    printf("21- Ejercicio 3\n");
    printf("23- Ejercicio 4\n");
    printf("24- Ejercicio 5\n");
    printf("25- Ejercicio 6\n");
    printf("26- Ejercicio 7\n");
    printf("27- Ejercicio 8\n");
    printf("Ingrese una opcion <1...27>: ");
    scanf("%d", &opcion);
    system("cls");

    return opcion;
}

void ejecutarEjercicio(int opcion)
{
    switch(opcion)
    {
        case 1:
            ejercicio1();
            break;
        case 2:
            ejercicio2();
            break;
        case 3:
            ejercicio3();
            break;
        case 4:
            ejercicio4();
            break;
        case 5:
            ejercicio5();
            break;
        case 6:
            ejercicio6();
            break;
        case 7:
            ejercicio7();
            break;
        case 8:
            ejercicio8();
            break;
        case 9:
            ejercicio9();
            break;
        case 10:
            ejercicio10();
            break;
        case 11:
            ejercicio11();
            break;
        case 12:
            ejercicio12();
            break;
        case 13:
            ejercicio13();
            break;
        case 14:
            ejercicio14();
            break;
        case 15:
            ejercicio15();
            break;
        case 16:
            ejercicio16();
            break;
        case 17:
            ejercicio17();
            break;
        case 18:
            ejercicio18();
            break;
        case 19:
            ejercicio19();
            break;
        case 20:
            ejercicio20();
            break;
        case 21:
            ejercicio21();
            break;
        case 22:
            ejercicio22();
            break;
        case 23:
            ejercicio23();
            break;
        case 24:
            ejercicio24();
            break;
        case 25:
            ejercicio25();
            break;
        case 26:
            ejercicio26();
            break;
        case 27:
            ejercicio27();
            break;
        default:
                printf("Opcion incorrecta\n");
    }
}

/***
    EJERCICIOS SECUENCIALES
***/

void ejercicio1()
{
    /**
        Suponga que un individuo desea invertir su capital en un banco y desea saber cuanto dinero ganará en un mes si el banco paga
        a razon de un 2% mensual
    **/

    //Declaramos e inicializamos variables a utilizar
    float capital = 0.0,
          capitalGanado = 0.0;

    //Pedimos al usuario los datos necesarios
    printf("Ingrese el capital que desea invertir: ");
    scanf("%f", &capital);

    capitalGanado = (capital * TASA_GANANCIA);

    //Se muestra el resultado por pantalla
    printf("Dinero generado: $%.2f\n", capitalGanado);

}

void ejercicio2()
{
    /**
        Una tienda ofrece un descuento del 15% sobre el total de la compra y un cliente desea
        saber cuanto debera pagar finalmente por su compra
    **/

    //Declaramos e inicializamos variables a utilizar
    float montoTotal = 0.0;

    //Pedimos al usuario los datos necesarios
    printf("Ingrese el monto a pagar sin descuento: ");
    scanf("%f", &montoTotal);

    montoTotal -= (montoTotal * TASA_DESCUENTO);

    //Se muestra el resultado por pantalla
    printf("El monto total a pagar es: $%.2f\n", montoTotal);

}

void ejercicio3()
{
    /**
        Un maestro desea saber que porcentaje de hombres y que porcentaje de mujeres hay
        en un grupo de estudiantes
    **/

    //Declaramos e inicializamos las variables a utilizar
    int totalEstudiantes = 0,
        estudiantesM     = 0,
        estudiantesH     = 0;

    float porcentajeH = 0.0,
          porcentajeM = 0.0;

    //Consultamos cuantos estudiantes hay en su totalidad y cuantas mujeres y hombres
    printf("Ingrese el total de estudiantes: ");
    scanf("%d", &totalEstudiantes);

    do
    {
        printf("Ingrese el total de mujeres: ");
        scanf("%d", &estudiantesM);

        if(estudiantesM > totalEstudiantes)
        {
            printf("Error. No puede haber mas estudiantes mujeres que estudiantes en total. \n");
            system("pause");
            system("cls || clear");
        }

    }while(estudiantesM > totalEstudiantes);

    estudiantesH = totalEstudiantes - estudiantesM; //Asi no doy pie a que el usuario se pueda equivocar al ingresar la cantidad de estudiantes hombres.

    //Operacion a realizar
    porcentajeH = (estudiantesH * 100) / totalEstudiantes;
    porcentajeM = (100 - porcentajeH);

    //Mostramos el resultado por pantalla
    printf("El porcentaje de hombres es: %.2f%c\n", porcentajeH, 37); //37 es el codigo ASCII de "%"
    printf("El porcentaje de mujeres es: %.2f%c\n", porcentajeM, 37);

}


/***
    ESTRUCTURAS SELECTIVAS
***/

void ejercicio4()
{
    /**
        Realizar un algoritmo que permita ingresar un numero e informe numero mayor a cero, numero menor o igual a cero segun corresponda
    **/

    float numero;

    printf("Ingrese un numero: ");
    fflush(stdin);
    scanf("%f", &numero);

    if(numero > 0)
    {
        printf("El numero %.2f es mayor a cero\n", numero);
    }
    else
    {
        printf("El numero %.2f es menor o igual a cero\n", numero);
    }
}

void ejercicio5()
{
    /**
        Determinar si un alumno aprueba a reprueba un curso, sabiendo que aprobara si su promedio de tres calificaciones es mayor o igual a 7 y reprueba en caso contrario
    **/

    int contador = 0;
    float promedio = 0.0,
          suma     = 0.0,
          nota     = 0.0;

    while(contador < 3)
    {
        printf("Ingrese la nota del %d%c examen: ", contador + 1, 248); ///El 248 es el codigo ASCII del "º"
        fflush(stdin);
        scanf("%f", &nota);
        suma += nota;
        contador++;
    }
    promedio = suma / contador;

    if(promedio >= 7)
    {
        printf("El promedio del alumno es %.2f, por lo tanto APROBO la materia\n", promedio);
    }
    else
    {
        printf("El promedio del alumno es %.2f, por lo tanto DESAPROBO la materia\n", promedio);
    }
}

void ejercicio6()
{
    /**
        En un almacen se hace un 20% de descuento a los clientes cuya compra supere los $1000 ¿Cual sera la cantidad que pagara una persona por su compra?
    **/

    float totalCompra = 0.0,
          compra      = 0.0;

    printf("Ingrese el monto de la compra: ");
    fflush(stdin);
    scanf("%f", &compra);

    if(compra >= 1000)
    {
        totalCompra = compra - (compra * 0.2);
        printf("El cliente supero los $1000, el monto con descuento es: $%.2f\n", totalCompra);
    }
    else
    {
        printf("El cliente NO supero los $1000, el monto a pagar es el mismo: $%.2f\n", compra);
    }
}

void ejercicio7()
{
    /**
        Un obrero necesita calcular su salario semanal, el cual se obtiene de la siguiente manera:
            -Si trabaja 40 horas o menos se le paga $16 por hora.
            -Si trabaja mas de 40 horas se le paga $16 por cada una de las primeras 40 horas y $20 por cada hora extra.
    **/

    int cantHoras   = 0,
        horasExtras = 0;

    float sueldoTotal = 0.0,
          sueldoExtra = 0.0;

    printf("Ingrese la cantidad de horas trabajadas: ");
    fflush(stdin);
    scanf("%d", &cantHoras);

    if(cantHoras > 40)
    {
        horasExtras = cantHoras - 40;
        sueldoExtra = horasExtras * 20;
        sueldoTotal = (40 * 16) + sueldoExtra;
        printf("El empleado hizo mas de 40 horas, su salario total es: $%.2f de los cuales $%.2f son por trabajar horas extras\n", sueldoTotal, sueldoExtra);
    }
    else
    {
        sueldoTotal = cantHoras * 16;
        printf("El empleado no registra horas extras, su salario es de: $%.2f\n", sueldoTotal);
    }

}

void ejercicio8()
{
    /**
        Que lea dos numeros y los imprima en forma ascendente
    **/

    float n1 = 0.0,
          n2 = 0.0;

    printf("Ingrese el numero 1: ");
    fflush(stdin);
    scanf("%f", &n1);

    printf("Ingrese el numero 2: ");
    fflush(stdin);
    scanf("%f", &n2);

    printf("Numeros ordenados: ");
    if(n1 < n2)
    {
        printf("%.2f - %.2f\n", n1, n2);
    }
    else
    {
        printf("%.2f - %.2f\n", n2, n1);
    }

}

void ejercicio9()
{
    /**
        Hacer un algoritmo que calcule el total a pagar por la compra de camisas.
            -Si se compran tres camisas o mas se aplica un descuento del 20% sobre el total de la compra.
            -Si son menos de tres camisas un descuento del 10%.
    **/

    int cantCamisas = 0;

    float precioCamisa = 0.0,
          totalCamisas = 0.0;

    printf("Ingrese la cantidad de camisas: ");
    fflush(stdin);
    scanf("%d", &cantCamisas);

    for(int i = 0; i < cantCamisas; i++)
    {
        printf("Ingrese precio por la %d%c camisa: ", i + 1, 248); ///El 248 es el codigo ASCII del "º"
        fflush(stdin);
        scanf("%f", &precioCamisa);
        totalCamisas += precioCamisa;
    }

    if(cantCamisas >= 3)
    {
        totalCamisas -= totalCamisas * 0.2;
        printf("El cliente tiene un descuento del 20%c por lo tanto el total a pagar es: $%.2f\n", 37, totalCamisas); ///El 37 es el codigo ASCII del "%"
    }
    else
    {
       totalCamisas -= totalCamisas * 0.1;
       printf("El cliente tiene un descuento del 10%c por lo tanto el total a pagar es: $%.2f\n", 37, totalCamisas);
    }
}

void ejercicio10()
{
    /**
        Leer 2 numeros
         -Si son iguales que los multiplique
         -Si el primero es mayor que el segundo que los reste y si no que los sume.
    **/

    float n1        = 0.0,
          n2        = 0.0,
          resultado = 0.0;

    printf("Ingrese primer numero\n");
    fflush(stdin);
    scanf("%f", &n1);

    printf("Ingrese segundo numero\n");
    fflush(stdin);
    scanf("%f", &n2);

    if(n1 == n2)
    {
        resultado = n1 * n2;
    }
    else
    {
        if(n1 > n2)
        {
            resultado = n1 - n2;
        }
        else
        {
            resultado = n1 + n2;
        }
    }

    printf("El resultado de la operacion es: %.2f\n", resultado);

}

/***
    ESTRUCTURAS REPETITIVAS
***/

void ejercicio11()
{
    /***
        Leer tres números diferentes e imprimir el numero mayor de los tres.
    ***/

    float n1    = 0.0,
          n2    = 0.0,
          n3    = 0.0,
          mayor = 0.0;

    do
    {
        printf("Ingrese el primer numero: ");
        fflush(stdin);
        scanf("%f",&n1);

        printf("Ingrese el segundo numero: ");
        fflush(stdin);
        scanf("%f",&n2);

        printf("Ingrese el tercer numero: ");
        fflush(stdin);
        scanf("%f",&n3);

        if(n1 == n2 || n1 == n3 || n2 == n3)
        {
            printf("Error, hay dos o mas numeros que son iguales. Vuelva a ingresar los numeros\n");
            system("pause");
            system("cls || clean");
        }

    }while(n1 == n2 || n1 == n3 || n2 == n3);

    if(n1 < n2 && n2 < n3)
    {
        mayor = n3;
    }
    else
    {
        if(n1 < n2 && n3 < n2)
        {
            mayor = n2;
        }
        else
        {
            mayor = n1;
        }
    }

    printf("El mayor de %.2f, %.2f, %.2f es: %.2f\n", n1, n2, n3, mayor);
}

/***
    COMBINACION DE ESTRUCTURAS SELECTIVAS Y REPETITIVAS
***/

void ejercicio12()
{
    /**
        Realizar un algoritmo que permita realizar 3 veces lo siguiente:
            -Ingresar 2 numeros, calcular su suma e informar el resultado.
    **/

    float valorIngresado = 0.0,
          sumaTotal      = 0.0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("Ingrese el %d%c numero: ", j + 1, 248); ///El 248 es el codigo ASCII del "º"
            fflush(stdin);
            scanf("%f", &valorIngresado);
            sumaTotal += valorIngresado;
        }
        printf("El resultado de la suma de los dos numeros es: %.2f\n\n", sumaTotal);
        sumaTotal = 0.0;
    }
}

void ejercicio13()
{
    /**
        Realizar un algoritmo que permita ingresar 5 numeros e informe cuantos numeros ingresados son mayores a cero y cuantos menores a cero.
    **/

    float num = 0.0;

    int menores = 0,
        mayores = 0;

    for(int i = 0; i < 5; i++)
    {
        printf("Ingrese el %d%c numero: ", i + 1, 248); ///El 248 es el codigo ASCII del "º"
        fflush(stdin);
        scanf("%f", &num);

        if(num >= 0)
        {
            mayores++;
        }
        else
        {
            menores++;
        }
    }

    printf("En total se ingresaron %d numeros mayores a 0 y %d numeros menores a 0\n", mayores, menores);

}

/***
    EJEMPLOS PARA HACER
***/
void ejercicio14()
{
    /**
        Calcular el promedio de un alumno que tiene 7 calificaciones en la materia de Diseño Estructurado de Algoritmos
    **/

    int i = 0;
    float notas              = 0.0,
          sumaCalificaciones = 0.0,
          promedioNotas      = 0.0;

    for(i = 0; i < 7; i++)
    {
        printf("Ingrese nota %d: ", i+1);
        fflush(stdin);
        scanf("%f", &notas);

        sumaCalificaciones += notas;
    }

    promedioNotas = sumaCalificaciones/i;

    printf("El promedio de la materia Disenio Estructurado de Algoritmos es: %.2f\n", promedioNotas);
}

void ejercicio15()
{
    /**
        Leer 10 numeros y obtener su cubo y su cuarta
    **/

    float valor       = 0.0,
          valorCubo   = 0.0,
          valorCuarta = 0.0;

    for(int i = 0 ; i < 10; i++)
    {
        printf("Ingrese el valor %d: ", i+1);
        fflush(stdin);
        scanf("%f", &valor);

        valorCubo = valor * valor * valor;
        printf("\nEl cubo de %.2f es: %.2f\n", valor, valorCubo);
        valorCuarta = valorCubo * valor;
        printf("La cuarta de %.2f es: %.2f\n\n", valor, valorCuarta);
    }
}

void ejercicio16()
{
    /**
        Leer 10 numeros e imprimir solamente los numeros positivo
    **/

    int numeros;

    for(int i = 0; i < 10; i++)
    {
        printf("Ingrese un valor: ");
        fflush(stdin);
        scanf("%d", &numeros);

        if(numeros >= 0)
        {
            printf("El numero %d es positivo \n\n", numeros);
        }
        else
        {
            printf("El numero es negativo, no se muestra\n\n");
        }
    }

}

void ejercicio17()
{
    /**
        Leer 15 numeros negativos y convertirlos a positivos e imprimir dichos numeros
    **/
    int numero;
    int positivo;

    for(int i = 0; i <15; i++)
    {
        printf("Ingrese el %d%c numero: ", i+1, 248); ///El 248 es el codigo ASCII del "º"
        fflush(stdin);
        scanf("%d", &numero);
        while(numero >= 0)
        {
            printf("Ingrese un numero NEGATIVO: ");
            fflush(stdin);
            scanf("%d", &numero);
        }

        positivo = (-1) * numero;

        printf("El numero en positivo es: %d\n", positivo);
    }

}

void ejercicio18()
{
    /**
        Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos. Realizar un algoritmo
        para calcular la calificacion media y la calificacion mas baja de todo el grupo.
    **/

    float calificacion = 0.0,
          media        = 0.0,
          sumaMedia    = 0.0,
          notaMenor    = 300.0;

    int cantidad = 0;

    for(cantidad = 0; cantidad < 3; cantidad++)
    {
        printf("Ingrese nota del %d%c alumno: ", cantidad+1, 248);
        fflush(stdin);
        scanf("%f", &calificacion);

        if(notaMenor > calificacion)
        {
            notaMenor = calificacion;
        }
        sumaMedia += calificacion;
    }

    media = sumaMedia/cantidad;
    printf("La nota mas baja es: %.2f\n", notaMenor);
    printf("La media de las notas es: %.2f\n", media);

}

void ejercicio19()
{
    /**
        Calcular e imprimir la tabla de multiplicar de un numero cualquiera. Imprimir el multiplicando,
        el multiplicador y el producto
    **/

    int numero = 0;
    int multiplicador = 0;
    int resultado = 0;

    printf("Ingrese numero para mostrar su tabla de multiplicacion: ");
    fflush(stdin);
    scanf("%d", &numero);

    for(multiplicador = 1; multiplicador <= 10; multiplicador++)
    {
            resultado = numero * multiplicador;
            printf("%d x %d = %d\n", numero, multiplicador, resultado);
    }
}

void ejercicio20()
{
    /**
        Escriba un programa que genere y muestre todas las potencias de 2, desde la 0-ésima hasta la ingresada por el usuario:
    **/
    int   n = 0,
        res = 0;

    printf("Ingrese la potencia a la que desea elevar el numero 2: ");
    fflush(stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        res = pow(2, i);
        printf("2^%d = %d\n", i, res);
    }

}

void ejercicio21()
{
    /**
        Escriba un programa que muestre todos los divisores del número entero ingresado por el usuario
    **/
    int num = 0,
        cnt = 0;

    printf("Ingrese un numero: ");
    scanf("%d", &num);
    while(cnt != num)
    {
        cnt++;
        if(num%cnt == 0)
        {
            printf("%d ", cnt);
        }
    }
    printf("\n");
}

void ejercicio22()
{
    /**
        Al tirar un dado tenemos ⅙ de probabilidades de sacar 6. Si tiramos dos dados tenemos 1/36 probabilidades
        de sacar doble 6. Al aumentar el número de dados la probabilidad de sacar todos 6 es cada vez menor.
        Escriba un programa que calcule la probabilidad de sacar todos los dados 6 siendo que tiramos N dados
        (dato leído al usuario)
    **/

    int cntDados;
    float probabilidad = 0.0;
    printf("Cuantos dados va a tirar?: ");
    scanf("%d", &cntDados);

    ///La probabilidad es 1/6^cntDados
    probabilidad = 1/pow(6,cntDados);
    printf("La probabilidad de sacar una cantidad de %d seis es: %f\n", cntDados, probabilidad);

}

void ejercicio23()
{
    /**
        Leer valores del usuario hasta que introduzca un 0. Contar la cantidad de valores introducidos y al finalizar
        informarlo por pantalla:
        Ingrese un número: 9
        Ingrese un número: 7
        Ingrese un número: -1
        Ingrese un número: 1
        Ingrese un número: 0
        Cantidad de elementos ingresados: 4
    **/
    int num = 0,
        cnt = 0;
    do
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        cnt++;
    }while(num != 0);

    printf("Cantidad de elementos ingresados: %d\n", cnt-1); //Le resto 1 para no contar el 0

}

void ejercicio24()
{
    /**
        Leer valores del usuario hasta que introduzca un 0. El usuario puede introducir valores numéricos, tanto
        positivos como negativos. Contar la cantidad de valores introducidos que sean mayores a 0 y el porcentaje
        de positivos respecto del total:
        Ingrese un número: 9
        Ingrese un número: 7
        Ingrese un número: -1
        Ingrese un número: 1
        Ingrese un número: 0
        3 positivos, 75% del total

        cntNumeros ----- 100%
        cntPositivos ---- x = cntPositivos * 100 / cntNumeros
    **/

    int num          = 0,
        cnt          = 0,
        cntPositivos = 0;

    float porcentaje = 0.0;

    do
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        if(num > 0)
        {
            cntPositivos++;
        }
        cnt++;
    }while(num != 0);

    cnt -= 1; //-1 para no incluir al 0
    porcentaje = (cntPositivos * 100) / cnt;

    printf("\nCantidad de elementos ingresados: %d\n", cnt-1); //Le resto 1 para no contar el 0
    printf("%d positivos, %.2f%c del total\n", cntPositivos, porcentaje, 37); //El 37 es el codigo ASCII del %

}

void ejercicio25()
{
    /**
        Leer valores del usuario hasta que introduzca un 0. El usuario puede introducir valores numéricos, tanto
        positivos como negativos. Encontrar el máximo de los elementos que introdujo:
        Ingrese un número: 9
        Ingrese un número: 7
        Ingrese un número: -1
        Ingrese un número: 1
        Ingrese un número: 0
        El máximo es 9
    **/

    int num          = 0,
        cnt          = 0,
        numMax       = 0;

    do
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        if(num > numMax)
        {
            numMax = num;
        }
        cnt++;
    }while(num != 0);

    printf("\nCantidad de elementos ingresados: %d\n", cnt-1); //Le resto 1 para no contar el 0
    printf("El maximo es: %d\n", numMax);

}

void ejercicio26()
{
    /**
        En estadística descriptiva, se define el rango de un conjunto de datos reales como la diferencia entre el
        mayor y el menor de los datos.
        Por ejemplo, si los datos son:
        [5.96, 6.74, 7.43, 4.99, 7.20, 0.56, 2.80], entonces el rango es 7.43 − 0.56 = 6.87.
        Escriba un programa que:
        ● pregunte al usuario cuántos datos serán ingresados,
        ● pida al usuario ingresar los datos uno por uno, y
        ● entregue como resultado el rango de los datos.
        Suponga que todos los datos ingresados son válidos.
        ¿Cuantos valores ingresara? 7
        Valor 1: 5.96
        Valor 2: 6.74
        Valor 3: 7.43
        Valor 4: 4.99
        Valor 5: 7.20
        Valor 6: 0.56
        Valor 7: 2.80
        El rango es 6.87
    **/
    int cntDatos = 0;

    double   rango = 0.0,
             dato  = 0,
           numMax  = -1.0/0.0, //El numero minimo negativo que existe, asi aseguramos que entre al primer if.
           numMin  = 1.0/0.0;    //El numero maximo positivo que existe, asi aseguramos que entre al primer if.

    printf("Cuantos datos seran ingresados?: ");
    scanf("%d", &cntDatos);

    for(int i = 0; i < cntDatos; i++)
    {
        printf("Valor %d: ", i+1);
        scanf("%lf", &dato);
        if(dato > numMax)
        {
            numMax = dato;
        }
        else if(dato < numMin)
        {
            numMin = dato;
        }
    }
    rango = numMax - numMin;
    printf("El rango es: %.2f\n", rango);

}

void ejercicio27()
{
    /**
        Definir un algoritmo que permita adivinar un número entre 1 y 100.
        El algoritmo deberá determinar al azar el número a adivinar (utilizar función azar() de PSeInt,
        investigar su equivalente en lenguaje C).
        El usuario deberá ingresar primero un número, si acertó, el sistema le informará por pantalla el acierto y luego terminará.
        Si el número ingresado por el usuario es mayor o menor que el que tiene que adivinar, el sistema lo informará por pantalla y continuará hasta que adivine.
    **/

    int num_a_adivinar = 0,
        num_usuario    = 0;
    srand(time(0)); // Inicializar generador de números aleatorios con el tiempo actual
    num_a_adivinar = rand() % 100 + 1; // Generar número aleatorio entre 1 y 100
    printf("Adivina el numero entre 1 y 100.\n");
    do {
        printf("Ingrese un numero: ");
        scanf("%d", &num_usuario);
        if (num_usuario > num_a_adivinar)
        {
            printf("El numero ingresado es mayor que el numero a adivinar.\n");
        }
        else if (num_usuario < num_a_adivinar)
        {
            printf("El numero ingresado es menor que el numero a adivinar.\n");
        }
        else
        {
            printf("%cFelicitaciones, ha adivinado el numero!\n", 173); ///El 173 es el codigo ASCII del ¡
        }
    } while (num_usuario != num_a_adivinar);
}
