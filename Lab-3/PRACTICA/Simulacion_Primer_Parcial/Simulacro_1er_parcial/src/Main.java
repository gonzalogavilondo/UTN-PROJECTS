import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Biblioteca biblioteca = new Biblioteca();

        biblioteca.agregarMaterial(new Libro(1, "Cien Años de Soledad", "Gabriel García Márquez", 1967, Genero.NOVELA));
        biblioteca.agregarMaterial(new EBook(2, "El Principito", "Antoine de Saint-Exupéry", 1943, "https://ebook.com/principito"));
        biblioteca.agregarMaterial(new Revista(3, "National Geographic", "Varios", 2023, 150));

        System.out.println("Materiales en la biblioteca:");
        biblioteca.mostrarMateriales();

        System.out.println("\nMateriales ordenados por título:");
        biblioteca.ordenarPorTitulo();
        biblioteca.mostrarMateriales();

        System.out.println("\nBuscando materiales con 'Cien':");
        ArrayList<Material> resultados = biblioteca.buscarPorTitulo("Cien");
        for (Material material : resultados) {
            System.out.println(material);
        }
    }
}