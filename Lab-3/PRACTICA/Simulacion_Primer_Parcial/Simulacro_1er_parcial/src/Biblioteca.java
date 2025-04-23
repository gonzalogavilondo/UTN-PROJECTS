import java.time.LocalDate;
import java.util.ArrayList;

public class Biblioteca {
    private ArrayList<Material> materiales;
    private ArrayList<Prestamo> prestamos;

    public Biblioteca() {
        this.materiales = new ArrayList<>();
        this.prestamos = new ArrayList<>();
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

    public void prestarMaterial(int id, LocalDate fechaDevolucion) {
        Material material = materiales.stream()
                .filter(m -> m.getId() == id)
                .findFirst()
                .orElse(null);

        if (material != null) {
            // Verificar si el material ya está prestado
            boolean yaPrestado = prestamos.stream()
                    .anyMatch(p -> p.getMaterial().getId() == id && p.getEstado() == EstadoPrestamo.PRESTADO);

            if (yaPrestado) {
                System.out.println("El material ya está prestado.");
            } else {
                Prestamo prestamo = new Prestamo(material, LocalDate.now(), fechaDevolucion);
                prestamos.add(prestamo);
                System.out.println("Material prestado: " + material.getTitulo());
            }
        } else {
            System.out.println("Material no encontrado.");
        }
    }

    public void devolverMaterial(int id) {
        Prestamo prestamo = prestamos.stream()
                .filter(p -> p.getMaterial().getId() == id && p.getEstado() == EstadoPrestamo.PRESTADO)
                .findFirst()
                .orElse(null);

        if (prestamo != null) {
            prestamo.setEstado(EstadoPrestamo.DISPONIBLE);
            System.out.println("Material devuelto: " + prestamo.getMaterial().getTitulo());
        } else {
            System.out.println("Préstamo no encontrado o el material ya fue devuelto.");
        }
    }

    public void mostrarPrestamos() {
        for (Prestamo prestamo : prestamos) {
            System.out.println(prestamo);
        }
    }
}