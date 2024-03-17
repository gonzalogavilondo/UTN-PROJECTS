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

        int n = 3;
        double a = 25.36;
        char c = 't';

        System.out.println(String.format("n: %s a: %s c: %s", n, a, c));
        System.out.println(String.format("n + a: %s", n + a));
        System.out.println(String.format("a - n: %s", a - n));
        System.out.println(String.format("c: %s", Integer.valueOf(c)));
    }

    private static void ejercicio2() {
        int x = 10;
        int y = 20;
        double n = 2.0;
        double m = 120.5;

        System.out.println(String.format("x: %s y: %s n: %s m: %s", x, y, n, m));
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