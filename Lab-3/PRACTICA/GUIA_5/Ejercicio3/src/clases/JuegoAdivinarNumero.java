package clases;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;
/**
 * Clase JuegoAdivinarNumero
 * Este programa permite al usuario adivinar un número aleatorio entre 1 y 500.
 * El usuario tiene que introducir números hasta que adivine el correcto.
 * Se le indicará si el número a adivinar es mayor o menor que el introducido.
 */
public class JuegoAdivinarNumero {

    public void jugar() {
        Random random = new Random();
        int numeroAdivinar = random.nextInt(500) + 1; // Número entre 1 y 500
        int intentos = 0;
        boolean adivinado = false;

        Scanner scanner = new Scanner(System.in);
        System.out.println("¡Adivina el número entre 1 y 500!");

        while (!adivinado) {
            System.out.print("Introduce un número: ");
            try {
                int numeroUsuario = scanner.nextInt();
                intentos++;

                if (numeroUsuario < 1 || numeroUsuario > 500) {
                    System.out.println("El número debe estar entre 1 y 500.");
                    continue;
                }

                if (numeroUsuario < numeroAdivinar) {
                    System.out.println("El número a adivinar es MAYOR.");
                } else if (numeroUsuario > numeroAdivinar) {
                    System.out.println("El número a adivinar es MENOR.");
                } else {
                    System.out.println("¡Correcto! Has adivinado el número.");
                    adivinado = true;
                }
            } catch (InputMismatchException e) {
                System.out.println("Eso no es un número válido.");
                intentos++;
                scanner.nextLine(); // Limpiar entrada incorrecta
            }
        }

        System.out.println("Número de intentos: " + intentos);
        scanner.close();
    }
}
