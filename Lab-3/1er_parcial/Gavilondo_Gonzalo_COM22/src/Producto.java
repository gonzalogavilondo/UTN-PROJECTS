public abstract class Producto implements Comparable<Producto> {
    private static int cntId = 0;
    private int id;
    private String nombre;
    private Categorias categoria;
    private double precio;
    private Marcas marca;

    /**
     * Constructor de la clase Producto
     */
    public Producto(String nombre, Categorias categoria, double precio, Marcas marca) {
        this.id = ++cntId;
        this.nombre = nombre;
        this.categoria = categoria;
        this.precio = precio;
        this.marca = marca;
    }

    /**
     * Getters and setters
     *
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setCategoria(Categorias categoria) {
        this.categoria = categoria;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public void setMarca(Marcas marca) {
        this.marca = marca;
    }

    public int getId() {
        return id;
    }

    public String getNombre() {
        return nombre;
    }

    public Categorias getCategoria() {
        return categoria;
    }

    public double getPrecio() {
        return precio;
    }

    public Marcas getMarca() {
        return marca;
    }

    /**
    * Metodo para comparar productos por precio
    */
    @Override
    public int compareTo(Producto otro) {
        return Double.compare(this.precio, otro.precio);
    }

    @Override
    public String toString() {
        return "ID: " + id + ", Nombre: " + nombre + ", Categoría: " + categoria + ", Precio: " + precio + ", Marca: " + marca;
    }
}