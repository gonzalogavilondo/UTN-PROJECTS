package clases;

import java.util.ArrayList;
import java.util.List;

public class Biblioteca {
    private String nombre;
    private String direccion;
    private Director director; // Objeto de otra clase
    private List<Libro> libros; // Colección de objetos de otra clase

    // Constructor
    public Biblioteca(String nombre, String direccion, Director director) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.director = director;
        this.libros = new ArrayList<>();
    }

    // Getters y Setters
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public Director getDirector() {
        return director;
    }

    public void setDirector(Director director) {
        this.director = director;
    }

    public List<Libro> getLibros() {
        return libros;
    }

    public void setLibros(List<Libro> libros) {
        this.libros = libros;
    }

    @Override
    public String toString() {
        return "Library{" +
                "nombre='" + nombre + '\'' +
                ", direccion='" + direccion + '\'' +
                ", director=" + director +
                ", libros=" + libros +
                '}';
    }
}
