import java.util.ArrayList;

public class Almacenamiento <E> {
    private ArrayList<E> almacenamiento;

    public Almacenamiento(ArrayList<E> almacenamiento) {
        this.almacenamiento = almacenamiento;
    }

    public void agregar(E elemento) {
        almacenamiento.add(elemento);
    }

    public void quitar(E elemento) {
        almacenamiento.remove(elemento);
    }

    public void buscar(E elemento) {
        if (almacenamiento.contains(elemento)) {
            System.out.println("Elemento encontrado: " + elemento);
        } else {
            System.out.println("Elemento no encontrado: " + elemento);
        }
    }

    public int buscarIndice(E elemento) {
        return almacenamiento.indexOf(elemento);
    }

    public void mostrar() {
        for (E elemento : almacenamiento) {
            System.out.println(elemento);
        }
    }

}
