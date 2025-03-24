public class Libro {
    private String titulo;
    private double precio;
    private int stock;
    private Autor autor;

    public Libro() {
    }

    public Libro(String titulo, double precio, int stock, Autor autor) {
        this.titulo = titulo;
        this.precio = precio;
        this.stock = stock;
        this.autor = autor;
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

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    public Autor getAutor() {
        return autor;
    }

    public void setAutor(Autor autor) {
        this.autor = autor;
    }

    @Override
    public String toString() {
        return "Libro{" +
                "titulo='" + titulo + '\'' +
                ", precio=" + precio +
                ", stock=" + stock +
                ", " + autor.toString() +
                '}' +
                "\n"
                ;
    }

    public void aumentarStock(int cantidad) {
        this.stock += cantidad;
    }

    public void imprimir() {
        System.out.println("El libro " + this.titulo + " de " + this.autor.getApellido() + " " + this.autor.getNombre() + ", tiene un precio de " + this.precio + "\n");
    }
}
