import Clases.*;
import Enumeradores.Genero;
import Enumeradores.TipoMaterial;

public class App {
    public static void main(String[] args) {

        Biblioteca biblioteca = new Biblioteca();

        biblioteca.agregarMaterial(new Libro("Cien Años de Soledad", "Gabriel García Márquez", "1967", TipoMaterial.LIBRO, "417", Genero.NOVELA));
        biblioteca.agregarMaterial(new Libro("1984", "George Orwell", "1949", TipoMaterial.LIBRO, "328", Genero.DISTOPIA));
        biblioteca.agregarMaterial(new Libro("El Quijote", "Miguel de Cervantes", "1605", TipoMaterial.LIBRO, "863", Genero.CLASICO));
        biblioteca.agregarMaterial(new Libro("Crimen y Castigo", "Fiódor Dostoyevski", "1866", TipoMaterial.LIBRO, "671", Genero.NOVELA));
        biblioteca.agregarMaterial(new Libro("Orgullo y Prejuicio", "Jane Austen", "1813", TipoMaterial.LIBRO, "279", Genero.ROMANCE));

        biblioteca.agregarMaterial(new Ebook("El Hobbit", "J.R.R. Tolkien", "1937", TipoMaterial.EBOOK, "PDF"));
        biblioteca.agregarMaterial(new Ebook("El Señor de los Anillos", "J.R.R. Tolkien", "1954", TipoMaterial.EBOOK, "EPUB"));
        biblioteca.agregarMaterial(new Ebook("Juego de Tronos", "George R.R. Martin", "1996", TipoMaterial.EBOOK, "MOBI"));
        biblioteca.agregarMaterial(new Ebook("El Nombre del Viento", "Patrick Rothfuss", "2007", TipoMaterial.EBOOK, "PDF"));
        biblioteca.agregarMaterial(new Ebook("Dune", "Frank Herbert", "1965", TipoMaterial.EBOOK, "AZW3"));

        biblioteca.agregarMaterial(new Revista("National Geographic", "Varios Autores", "2023", TipoMaterial.REVISTA, true));
        biblioteca.agregarMaterial(new Revista("TIME", "Varios Autores", "2023", TipoMaterial.REVISTA, false));
        biblioteca.agregarMaterial(new Revista("Forbes", "Varios Autores", "2023", TipoMaterial.REVISTA, true));
        biblioteca.agregarMaterial(new Revista("Nature", "Varios Autores", "2023", TipoMaterial.REVISTA, true));
        biblioteca.agregarMaterial(new Revista("Scientific American", "Varios Autores", "2023", TipoMaterial.REVISTA, false));

        System.out.println(biblioteca.filtrarLibrosPorGenero(Genero.NOVELA));
    }
}
