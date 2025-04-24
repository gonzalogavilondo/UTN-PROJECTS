package Clases;

import Enumeradores.Genero;

import java.util.ArrayList;
import java.util.List;

public class Biblioteca {

    private ArrayList<Material> catalogo;

    public Biblioteca() {
        this.catalogo = new ArrayList<>();
    }

    public void agregarMaterial(Material m){
        catalogo.add(m);
    }

    public String eliminarMaterial(String titulo){
        String mensaje ="El elemento a eliminar no se encontro en la lista";
        for (Material m : catalogo){
            if (m.getTitulo().equals(titulo)){
                catalogo.remove(m);
                mensaje="El elemento se encontro y se elimino correctamente";
            }
        }
        return mensaje;
    }

    public List<Libro> filtrarLibrosPorGenero(Genero genero){
        List<Libro> librosFiltrados = new ArrayList<>();

        for (Material m : catalogo){
            if (m instanceof Libro l){
                if (l.getGenero().equals(genero)){
                    librosFiltrados.add(l);
                }
            }
        }

        return librosFiltrados;
    }
}
