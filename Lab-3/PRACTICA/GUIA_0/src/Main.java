import java.util.Scanner;
/**
 * Autor: Gonzalo Gavilondo
 * Objetivos:
 *  Introducir datos usando la clase Scanner
 *  Mostrar datos y String.format
 *  Casteo para el ejercicio 1. Integer.valueOf(x)
 *
 */

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int ejercicio = 0;

        do
        {
            System.out.println("\nIngrese el numero de ejercicio a resolver o 0 para salir: ");
            ejercicio = scanner.nextInt();

            switch (ejercicio)
            {
                case 0:
                    System.out.println("\nEjecucion finalizada");
                    break;
                case 1:
                    System.out.println("\nEjercicio 1\n=================");
                    ejercicio1();
                    break;
                case 2:
                    System.out.println("\nEjercicio 2\n=================");
                    ejercicio2();
                    break;
                case 3:
                    System.out.println("\nEjercicio 3\n=================");
                    ejercicio3();
                    break;

                case 4:
                    System.out.println("\nEjercicio 4\n=================");
                    ejercicio4();
                    break;
                default:
                    System.out.println("\nIngreso una opcion incorrecta. Intentelo de nuevo");
            }

        }while(ejercicio != 0);
    }


    private static void ejercicio1() {
        /*
         Realizar un programa Java que realice lo siguiente: declarar una variable
         numN de tipo int, una variable numA de tipo double y una variable numC de
         tipo char y asigna a cada una un valor. A continuación muestra por pantalla:
         El valor de cada variable, la suma de numN + numA, la diferencia de numA -
         numN, el valor numérico correspondiente al carácter que contiene la
         variable numC.
         */

        int numN = 3;
        double numA = 25.36;
        char numC = 't';

        /*
        * En Java, para concatenar Strings, de la forma tradicional se usa el metodo String.format
         */
        System.out.println(String.format("numN: %s numA: %s numC: %s\n", numN, numA, numC));
        System.out.println(String.format("numN + numA: %s", numN + numA));
        System.out.println(String.format("numA - numN: %s", numA - numN));
        System.out.println(String.format("numC: %s\n", Integer.valueOf(numC)));
        System.out.println(String.format("numC: %s\n", Integer.valueOf(numC)));

        /*
         * En Java, para concatenar como generalmente se hace
         */
        System.out.println("La suma de " + numN + " + " +numA + " = " + (numN + numA));
        System.out.println("La resta de " + numN + " - " +numA + " = " + (numN - numA));
        System.out.println(String.format("c: %s", Integer.valueOf(numC)));
    }

    private static void ejercicio2() {
        int x = 10;
        int y = 20;
        double n = 2.0;
        double m = 120.5;

        Scanner scanner = new Scanner(System.in);

        System.out.println("Valores originales \n\n");
        System.out.println(String.format("x: %d, y: %d, n: %s, m: %s", x, y, n, m));

        System.out.println("Valores de operaciones\n\n");
        System.out.println(String.format("x: %s y: %s n: %s m: %s\n\n", x, y, n, m));
        System.out.println(String.format("x * y: %s", x*y));
        System.out.println(String.format("n + m: %s", n+m));
        System.out.println(String.format("m / x: %s", m/x));

        System.out.println("Ingrese el valor para x");
        x = scanner.nextInt();
        System.out.println("Ingrese el valor para y");
        y = scanner.nextInt();
        System.out.println("Ingrese el valor para n");
        n = scanner.nextDouble();
        System.out.println("Ingrese el valor para m");
        m = scanner.nextDouble();

        System.out.println("\n\nValores Nuevos \n\n");
        System.out.println(String.format("x: %d, y: %d, n: %s, m: %s", x, y, n, m));

        System.out.println("Valores de las operaciones nuevas \n\n");
        System.out.println(String.format("x * y: %s", x*y));
        System.out.println(String.format("n + m: %s", n+m));
        System.out.println(String.format("m / x: %s", m/x));

    }

    private static void ejercicio3() {
        int n = 10;

        //Lo vamos a hacer sin String.format (como seria en C), y vamos a hacerlo como en Java
        System.out.println("n = " + n);
        System.out.println("n + 77 = " + n + 77);
        System.out.println("n - 3 = " + (n - 3));
        System.out.println("n * 2 = " + n*2);

    }

    private static void ejercicio4() {
        int a = 10,
            b = 20,
            c = 30,
            d = 40;

        System.out.println(String.format("a: %s b: %s c: %s d: %s", a, b, c, d));
        b = c;
        System.out.println(String.format("b: %s ", b));
        c = a;
        System.out.println(String.format("c: %s ", c));
        a = d;
        System.out.println(String.format("a: %s ", a));
        d = b;
        System.out.println(String.format("d: %s ", d));
    }
}
