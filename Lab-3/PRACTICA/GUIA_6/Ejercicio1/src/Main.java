import java.util.ArrayList;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        // Crear una instancia de Almacenamiento con un ArrayList de tipo String
        Almacenamiento<String> almacenamiento = new Almacenamiento<>(new ArrayList<>());

        // Agregar elementos al almacenamiento
        almacenamiento.agregar("Elemento 1");
        almacenamiento.agregar("Elemento 2");
        almacenamiento.agregar("Elemento 3");

        // Mostrar los elementos en el almacenamiento
        System.out.println("Elementos en el almacenamiento:");
        almacenamiento.mostrar();

        // Buscar un elemento
        almacenamiento.buscar("Elemento 2");

        // Quitar un elemento
        almacenamiento.quitar("Elemento 2");

        // Mostrar los elementos después de quitar uno
        System.out.println("Elementos en el almacenamiento después de quitar:");
        almacenamiento.mostrar();


        /**
         * Ejemplo de uso de Almacenamiento con un ArrayList de tipo Integer
         */

        // Crear una instancia de Almacenamiento con un ArrayList de tipo Integer
        Almacenamiento<Integer> almacenamientoNumeros = new Almacenamiento<>(new ArrayList<>());

        // Agregar elementos al almacenamiento
        almacenamientoNumeros.agregar(1);
        almacenamientoNumeros.agregar(2);
        almacenamientoNumeros.agregar(3);

        // Mostrar los elementos en el almacenamiento
        System.out.println("Elementos en el almacenamiento de números:");
        almacenamientoNumeros.mostrar();

        // Buscar un elemento
        almacenamientoNumeros.buscar(2);

        // Quitar un elemento
        almacenamientoNumeros.quitar(2);

        // Mostrar los elementos después de quitar uno
        System.out.println("Elementos en el almacenamiento de números después de quitar:");
        almacenamientoNumeros.mostrar();

    }
}