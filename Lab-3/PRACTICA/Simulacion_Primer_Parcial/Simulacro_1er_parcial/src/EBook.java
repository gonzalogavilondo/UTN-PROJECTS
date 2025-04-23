public class EBook extends Material implements LecturaInmediata {
    private String url;

    public EBook(String titulo, String autor, int anioPublicacion, String url) {
        super(titulo, autor, anioPublicacion);
        this.url = url;
    }

    public String getUrl() {
        return url;
    }

    @Override
    public void leer() {
        System.out.println("Leyendo el eBook desde: " + url);
    }

    @Override
    public String toString() {
        return super.toString() + ", URL: " + url;
    }
}