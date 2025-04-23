public class Libro extends Material {
    private Genero genero;

    public Libro(String titulo, String autor, int anioPublicacion, Genero genero) {
        super(titulo, autor, anioPublicacion);
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