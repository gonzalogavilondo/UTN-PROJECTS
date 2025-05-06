import java.util.ArrayList;

public class Pila<T> {
    private ArrayList<T> elementos;

    public Pila() {
        elementos = new ArrayList<>();
    }

    // Agrega un elemento a la pila
    public void apilar(T elemento) {
        elementos.add(elemento);
    }

    // Quita el último elemento de la pila
    public T desapilar() {
        if (estaVacia()) {
            throw new IllegalStateException("La pila está vacía");
        }
        return elementos.remove(elementos.size() - 1);
    }

    // Verifica si la pila está vacía
    public boolean estaVacia() {
        return elementos.isEmpty();
    }

    // Devuelve el número de elementos en la pila
    public int tamano() {
        return elementos.size();
    }

    // Muestra el elemento en la cima sin quitarlo
    public T cima() {
        if (estaVacia()) {
            throw new IllegalStateException("La pila está vacía");
        }
        return elementos.get(elementos.size() - 1);
    }
}
