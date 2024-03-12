package com.company;

import java.util.Scanner;

public class OperacionesBasicas {
    // Creamos las variables que necesitaremos.
    double number1;
    double number2;
    double resultado;

    // Luego haremos el constructor de la clase OperacionesBasicas
    public OperacionesBasicas() {
        number1 = 0;
        number2 = 0;
        resultado = 0;
    }

    // Creamos los métodos que utilizaremos (suma, resta, división y multiplicación)
    public void suma() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite el primer valor: ");
        number1 = scanner.nextDouble();
        System.out.print("Digite el segundo valor: ");
        number2 = scanner.nextDouble();
        resultado = number1 + number2;
        System.out.println("El resultado es " + resultado);
    }

    public void resta() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite el primer valor: ");
        number1 = scanner.nextDouble();
        System.out.print("Digite el segundo valor: ");
        number2 = scanner.nextDouble();
        resultado = number1 - number2;
        System.out.println("El resultado es " + resultado);
    }

    public void division() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite el primer valor: ");
        number1 = scanner.nextDouble();
        System.out.print("Digite el segundo valor: ");
        number2 = scanner.nextDouble();
        resultado = number1 / number2;
        System.out.println("El resultado es " + resultado);
    }

    public void multiplicacion() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite el primer valor: ");
        number1 = scanner.nextDouble();
        System.out.print("Digite el segundo valor: ");
        number2 = scanner.nextDouble();
        resultado = number1 * number2;
        System.out.println("El resultado es " + resultado);
    }
}
