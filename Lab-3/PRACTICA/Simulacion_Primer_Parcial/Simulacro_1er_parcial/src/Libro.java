public class Libro extends Material {
    private Genero genero;

    public Libro(int id, String titulo, String autor, int anioPublicacion, Genero genero) {
        super(id, titulo, autor, anioPublicacion);
        this.genero = genero;
    }

    public Genero getGenero() {
        return genero;
    }

    @Override
    public String toString() {
        return super.toString() + ", Género: " + genero;
    }
}