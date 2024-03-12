package com.company;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        OperacionesBasicas object = new OperacionesBasicas();
        int option;

        do {
            System.out.println("MENU PRINCIPAL");
            System.out.println("1. Suma");
            System.out.println("2. Resta");
            System.out.println("3. División");
            System.out.println("4. Multiplicación");
            System.out.println("5. Salir");
            System.out.print("Seleccione una opción: ");
            option = scanner.nextInt();

            switch (option) {
                case 1:
                    object.suma();
                    break;
                case 2:
                    object.resta();
                    break;
                case 3:
                    object.division();
                    break;
                case 4:
                    object.multiplicacion();
                    break;
                case 5:
                    break;
                default:
                    System.out.println("La opción " + option + " es incorrecta");
            }
        } while (option != 5);
    }
}

