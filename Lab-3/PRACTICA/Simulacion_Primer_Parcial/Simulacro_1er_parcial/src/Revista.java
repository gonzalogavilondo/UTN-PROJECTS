public class Revista extends Material {
    private int numeroEdicion;

    public Revista(int id, String titulo, String autor, int anioPublicacion, int numeroEdicion) {
        super(id, titulo, autor, anioPublicacion);
        this.numeroEdicion = numeroEdicion;
    }

    public int getNumeroEdicion() {
        return numeroEdicion;
    }

    @Override
    public String toString() {
        return super.toString() + ", Número de Edición: " + numeroEdicion;
    }
}