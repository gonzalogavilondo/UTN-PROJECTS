//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        Pila<Integer> pilaEnteros = new Pila<>();

        try {
            System.out.println("Desapilando de pila vacía...");
            pilaEnteros.desapilar();  // Esto lanza una excepción
        } catch (IllegalStateException e) {
            System.out.println("Excepción capturada: " + e.getMessage());
        }

        try {
            pilaEnteros.apilar(10);
            pilaEnteros.apilar(20);
            pilaEnteros.apilar(30);
            System.out.println("Cima de pilaEnteros: " + pilaEnteros.cima()); // 30
            System.out.println("Tamaño de pilaEnteros: " + pilaEnteros.tamano()); // 3
            pilaEnteros.desapilar();
            System.out.println("Tamaño después de desapilar: " + pilaEnteros.tamano()); // 2

            // Pila de cadenas
            Pila<String> pilaCadenas = new Pila<>();
            pilaCadenas.apilar("Hola");
            pilaCadenas.apilar("Mundo");
            System.out.println("Cima de pilaCadenas: " + pilaCadenas.cima()); // Mundo
            pilaCadenas.desapilar();
            System.out.println("Nueva cima: " + pilaCadenas.cima()); // Hola


            pilaEnteros.apilar(10);
            pilaEnteros.apilar(20);
            System.out.println("Cima: " + pilaEnteros.cima());


            // Pila de objetos personalizados
            class Persona {
                String nombre;
                Persona(String nombre) { this.nombre = nombre; }
                public String toString() { return nombre; }
            }

            Pila<Persona> pilaPersonas = new Pila<>();
            pilaPersonas.apilar(new Persona("Ana"));
            pilaPersonas.apilar(new Persona("Luis"));
            System.out.println("Persona en la cima: " + pilaPersonas.cima()); // Luis

        } catch (IllegalStateException e) {
            System.out.println("Excepción capturada: " + e.getMessage());
        }
    }
}