import java.util.ArrayList;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        try {
            // Crear un conjunto de enteros y probar funciones
            Conjunto<Integer> conjunto = new Conjunto<>(new ArrayList<>());
            conjunto.agregar(1);
            conjunto.agregar(2);
            conjunto.agregar(3);
            System.out.println("Conjunto de enteros: " + conjunto.getLista());
            conjunto.eliminar(2);
            System.out.println("Después de eliminar 2: " + conjunto.getLista());
            System.out.println("Contiene 3: " + conjunto.contiene(3));
            System.out.println("Contiene 2: " + conjunto.contiene(2));
            System.out.println("Tamaño del conjunto: " + conjunto.getLista().size());

            // Crear un conjunto de cadenas y probar funciones
            Conjunto<String> conjuntoCadenas = new Conjunto<>(new ArrayList<>());
            conjuntoCadenas.agregar("Hola");
            conjuntoCadenas.agregar("Mundo");
            //conjuntoCadenas.agregar("Hola"); // No se agrega porque ya existe
            System.out.println("Conjunto de cadenas: " + conjuntoCadenas.getLista());
            conjuntoCadenas.eliminar("Mundo");
            System.out.println("Después de eliminar 'Mundo': " + conjuntoCadenas.getLista());
            System.out.println("Contiene 'Hola': " + conjuntoCadenas.contiene("Hola"));
            System.out.println("Contiene 'Mundo': " + conjuntoCadenas.contiene("Mundo"));
            System.out.println("Tamaño del conjunto de cadenas: " + conjuntoCadenas.getLista().size());

            // Crear un conjunto de objetos y probar funciones
            Conjunto<Persona> conjuntoPersonas = new Conjunto<>(new ArrayList<>());
            Persona persona1 = new Persona("Juan", 25);
            Persona persona2 = new Persona("Ana", 30);
            conjuntoPersonas.agregar(persona1);
            conjuntoPersonas.agregar(persona2);
            //conjuntoPersonas.agregar(new Persona("Juan", 25)); // No se agrega porque ya existe
            System.out.println("Conjunto de personas: " + conjuntoPersonas.getLista());
            //conjuntoPersonas.eliminar(new Persona("Ana", 30));
            conjuntoPersonas.eliminar(persona1);
            System.out.println("Después de eliminar 'Ana': " + conjuntoPersonas.getLista());
            System.out.println("Contiene 'Juan': " + conjuntoPersonas.contiene(persona1));
            System.out.println("Contiene 'Ana': " + conjuntoPersonas.contiene(persona2));
            System.out.println("Tamaño del conjunto de personas: " + conjuntoPersonas.getLista().size());


        } catch (RuntimeException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Error inesperado: " + e.getMessage());
        } finally {
            System.out.println("--------------------------------------------------------------");
            System.out.println("\nFin del programa");
        }

    }

}