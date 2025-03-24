import java.io.IOException;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) throws IOException {

        //Instanciando un objeto de la clase Autor
        Autor autor = new Autor("Joshua", "Bloch", "joshua@email.com", 'M');

        //Instanciando un objeto de la clase Libro
        Libro libro = new Libro("Effective Java", 450.00, 150, autor);

        //Se imprime por pantalla el autor y el libro
        System.out.println(autor.toString());
        System.out.println(libro.toString());

        //Pausa y limpia la pantalla
        pausarYLimpiar();

        //Se modifica el precio y se aumenta el stock
        libro.setPrecio(500.00);
        libro.aumentarStock(50);

        //Se imprime por pantalla el Autor, accediendo desde el libro
        System.out.println("Autor: " + libro.getAutor().toString());

        //Pausa y limpia la pantalla
        pausarYLimpiar();

        //Se imprime por pantalla el resumen
        libro.imprimir();
    }

    public static void pausarYLimpiar() throws IOException {
        System.out.println("Presione Enter para continuar...");
        System.in.read();
        for (int i = 0; i < 10; ++i) System.out.println();
    }
}