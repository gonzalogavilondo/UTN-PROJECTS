import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {
        Biblioteca biblioteca = new Biblioteca();

        // Agregar materiales
        biblioteca.agregarMaterial(new Libro("Cien Años de Soledad", "Gabriel García Márquez", 1967, Genero.NOVELA));
        biblioteca.agregarMaterial(new EBook("El Principito", "Antoine de Saint-Exupéry", 1943, "https://ebook.com/principito"));
        biblioteca.agregarMaterial(new Revista("National Geographic", "Varios", 2023, 150));
        biblioteca.agregarMaterial(new Libro("Drácula", "Bram Stoker", 1897, Genero.TERROR));

        System.out.println("Materiales en la biblioteca:");
        biblioteca.mostrarMateriales();

        // Buscar materiales por título
        System.out.println("\nBuscando materiales que contengan 'El':");
        biblioteca.buscarPorTitulo("El").forEach(System.out::println);

        // Ordenar materiales por título
        System.out.println("\nOrdenando materiales por título:");
        biblioteca.ordenarPorTitulo();
        biblioteca.mostrarMateriales();

        // Ordenar materiales por año de publicación
        System.out.println("\nOrdenando materiales por año de publicación:");
        biblioteca.ordenarPorAnio();
        biblioteca.mostrarMateriales();

        // Prestar un material
        System.out.println("\nPrestando material con ID 1:");
        biblioteca.prestarMaterial(1, LocalDate.now().plusDays(15));

        // Intentar prestar el mismo material nuevamente
        System.out.println("\nIntentando prestar el mismo material con ID 1:");
        biblioteca.prestarMaterial(1, LocalDate.now().plusDays(15));

        // Mostrar préstamos actuales
        System.out.println("\nPréstamos actuales:");
        biblioteca.mostrarPrestamos();

        // Devolver un material
        System.out.println("\nDevolviendo material con ID 1:");
        biblioteca.devolverMaterial(1);

        // Intentar devolver un material que ya fue devuelto
        System.out.println("\nIntentando devolver el material con ID 1 nuevamente:");
        biblioteca.devolverMaterial(1);

        // Mostrar préstamos actuales después de la devolución
        System.out.println("\nPréstamos actuales después de la devolución:");
        biblioteca.mostrarPrestamos();
    }
}