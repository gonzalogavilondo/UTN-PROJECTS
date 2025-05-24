import java.util.ArrayList;
import java.util.List;

public class Inventario<T> {
    private List<T> elementos;

    public Inventario() {
        this.elementos = new ArrayList<>();
    }

    public void agregar(T elemento) {
        elementos.add(elemento);
    }

    public void eliminar(T elemento) {
        elementos.remove(elemento);
    }

    public List<T> getElementos() {
        return elementos;
    }

    public int cantidad() {
        return elementos.size();
    }

    public String imprimir() {
        StringBuilder sb = new StringBuilder();
        for (T elemento : elementos) {
            sb.append("\n  ").append(elemento.toString());
        }
        return sb.toString();
    }
}