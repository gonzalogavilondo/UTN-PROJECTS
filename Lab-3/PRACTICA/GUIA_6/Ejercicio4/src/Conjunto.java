import java.util.ArrayList;

public class Conjunto <E>{
    private ArrayList<E> lista;

    public Conjunto(ArrayList<E> lista) {
        this.lista = lista;
    }

    public ArrayList<E> getLista() {
        return lista;
    }

    public void setLista(ArrayList<E> lista) {
        this.lista = lista;
    }

    // Agregar un elemento al conjunto solo si no existe y sino, que lance una excepcion
    public void agregar(E elemento) {
        if (!lista.contains(elemento)) {
            lista.add(elemento);
        } else {
            throw new IllegalArgumentException("El elemento ya existe en el conjunto");
        }
    }

    public void eliminar(E elemento) {
        // Eliminar el elemento solo si existe en la lista, si no existe, que lance una excepcion
        if (lista.contains(elemento)) {
            lista.remove(elemento);
        } else {
            throw new IllegalArgumentException("El elemento no existe en el conjunto");
        }
    }

    public boolean contiene(E elemento) {
        return lista.contains(elemento);
    }
}
