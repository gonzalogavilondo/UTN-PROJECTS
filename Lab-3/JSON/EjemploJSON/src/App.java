import clases.Biblioteca;
import clases.Director;
import clases.Libro;

public class App {
    public static void main(String[] args) {

        Director director = new Director("Ana María López", 45, "Literatura");
        Biblioteca biblioteca = new Biblioteca("Biblioteca Central", "Calle Principal 123", director);

        biblioteca.getLibros().add(new Libro("Cien Años de Soledad", "Gabriel García Márquez", "978-0307474728", 1967));
        biblioteca.getLibros().add(new Libro("Don Quijote de la Mancha", "Miguel de Cervantes", "978-8491051685", 1605));
        biblioteca.getLibros().add(new Libro("La Sombra del Viento", "Carlos Ruiz Zafón", "978-8408172166", 2001));
        biblioteca.getLibros().add(new Libro("El Amor en los Tiempos del Cólera", "Gabriel García Márquez", "978-0307389732", 1985));


    }
}
