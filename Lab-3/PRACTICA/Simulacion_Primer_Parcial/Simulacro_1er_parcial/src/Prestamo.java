import java.time.LocalDate;

public class Prestamo {
    private Material material;
    private LocalDate fechaPrestamo;
    private LocalDate fechaDevolucion;
    private EstadoPrestamo estado;

    public Prestamo(Material material, LocalDate fechaPrestamo, LocalDate fechaDevolucion) {
        this.material = material;
        this.fechaPrestamo = fechaPrestamo;
        this.fechaDevolucion = fechaDevolucion;
        this.estado = EstadoPrestamo.PRESTADO; // Estado inicial al crear un préstamo.
    }

    public void setMaterial(Material material) {
        this.material = material;
    }

    public void setFechaPrestamo(LocalDate fechaPrestamo) {
        this.fechaPrestamo = fechaPrestamo;
    }

    public void setFechaDevolucion(LocalDate fechaDevolucion) {
        this.fechaDevolucion = fechaDevolucion;
    }

    public Material getMaterial() {
        return material;
    }

    public LocalDate getFechaPrestamo() {
        return fechaPrestamo;
    }

    public LocalDate getFechaDevolucion() {
        return fechaDevolucion;
    }

    @Override
    public String toString() {
        return "Material: " + material.getTitulo() + ", Fecha de Préstamo: " + fechaPrestamo + ", Fecha de Devolución: " + fechaDevolucion;
    }

    public void setEstado(EstadoPrestamo estadoPrestamo) {
        if (estadoPrestamo == EstadoPrestamo.DEVUELTO) {
            // Lógica para marcar el préstamo como devuelto
            System.out.println("El material ha sido devuelto.");
        } else if (estadoPrestamo == EstadoPrestamo.PRESTADO) {
            // Lógica para marcar el préstamo como prestado
            System.out.println("El material ha sido prestado.");
        }
    }

    public EstadoPrestamo getEstado() {
        return estado;
    }
}