import java.util.ArrayList;

public class Biblioteca {
    private ArrayList<Material> materiales;

    public Biblioteca() {
        this.materiales = new ArrayList<>();
    }

    public void agregarMaterial(Material material) {
        materiales.add(material);
    }

    public void eliminarMaterial(int id) {
        materiales.removeIf(material -> material.getId() == id);
    }

    public ArrayList<Material> buscarPorTitulo(String titulo) {
        ArrayList<Material> resultados = new ArrayList<>();
        for (Material material : materiales) {
            if (material.getTitulo().toLowerCase().contains(titulo.toLowerCase())) {
                resultados.add(material);
            }
        }
        return resultados;
    }

    public void ordenarPorTitulo() {
        materiales.sort((m1, m2) -> m1.getTitulo().compareToIgnoreCase(m2.getTitulo()));
    }

    public void ordenarPorAnio() {
        materiales.sort((m1, m2) -> Integer.compare(m1.getAnioPublicacion(), m2.getAnioPublicacion()));
    }

    public void mostrarMateriales() {
        for (Material material : materiales) {
            System.out.println(material);
        }
    }
}