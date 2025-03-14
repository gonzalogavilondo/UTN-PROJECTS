public class Libro {

    private static int cntId = 0;
    private int id;
    private String titulo;
    private String autor;
    private double precio;
    private int cntCopias;

    public Libro(String titulo, double precio, String autor, int cntCopias) {
        this.id = ++cntId;
        this.titulo = titulo;
        this.precio = precio;
        this.autor = autor;
        this.cntCopias = cntCopias;
    }

    public int getId() {
        return id;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getCntCopias() {
        return cntCopias;
    }

    public void setCntCopias(int cntCopias) {
        this.cntCopias = cntCopias;
    }

    @Override
    public String toString() {
        return "Libro{" +
                "id=" + id +
                ", titulo='" + titulo + '\'' +
                ", autor='" + autor + '\'' +
                ", precio=" + precio +
                ", cantidad=" + cntCopias +
                '}';
    }

    public int venderLibro(int cntCopias) {
        if (cntCopias > this.cntCopias) {
            System.out.println("No hay suficientes libros en estos momentos hay " + getCntCopias() + " " + "libros en stock");
            return this.cntCopias;
        }
        this.cntCopias -= cntCopias;
        return this.cntCopias;
    }

    public void comprarLibro(int cantidad) {
        this.cntCopias += cantidad;
    }
}
