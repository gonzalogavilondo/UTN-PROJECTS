public class Main {
    public static void main(String[] args) {

        // Creamos dos objetos de la clase Libro y les asignamos valores con el constructor
        Libro libro1 = new Libro("El Quijote", 500, "Miguel de Cervantes", 10);
        Libro libro2 = new Libro("Cien Años de Soledad", 700, "Gabriel García Márquez", 5);

        // Imprimimos el detalle de cada libro
        System.out.println("\nSe imprime el detalle de cada libro");
        System.out.println(libro1.toString());
        System.out.println(libro2.toString());

        // Vende 3 copias del primer libro.
        libro1.venderLibro(3);
        libro2.venderLibro(3);

        // Imprime los detalles del primer libro.
        System.out.println("\n\nDespués de vender 3 copias del primer libro");
        System.out.println(libro1.toString());

        // Intentamos vender 8 copias del segundo libro
        System.out.println("\n\nIntentamos vender 8 copias del segundo libro");
        libro2.venderLibro(8);

        // Incrementamos en 5 la cantidad de copias disponibles del segundo libro
        libro2.comprarLibro(5);

        // Imprimimos los detalles del segundo libro
        System.out.println("\n\nDespués de incrementar en 5 la cantidad de copias disponibles del segundo libro");
        System.out.println(libro2.toString());

    }
}