// Clase base Vehiculo
import java.util.List;

public abstract class Vehiculo implements Comparable<Vehiculo> {
    private String tipo;
    private String marca;
    private String modelo;
    private double precio;
    private int anio;
    private List<String> caracteristicas;
    private Proveedor proveedor;

    public Vehiculo(String tipo, String marca, String modelo, double precio, int anio, List<String> caracteristicas, Proveedor proveedor) {
        if (precio < 0) throw new PrecioNegativoException("El precio no puede ser negativo");
        this.tipo = tipo;
        this.marca = marca;
        this.modelo = modelo;
        this.precio = precio;
        this.anio = anio;
        this.caracteristicas = caracteristicas;
        this.proveedor = proveedor;
    }

    /**
     * Setters y getters
     * @return
     */

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public int getAnio() {
        return anio;
    }

    public void setAnio(int anio) {
        this.anio = anio;
    }

    public List<String> getCaracteristicas() {
        return caracteristicas;
    }

    public void setCaracteristicas(List<String> caracteristicas) {
        this.caracteristicas = caracteristicas;
    }

    public Proveedor getFabricante() {
        return proveedor;
    }

    public void setFabricante(Proveedor proveedor) {
        this.proveedor = proveedor;
    }

    @Override
    public String toString() {
        return "Vehiculo{" +
                "tipo='" + tipo + '\'' +
                ", marca='" + marca + '\'' +
                ", modelo='" + modelo + '\'' +
                ", precio=" + precio +
                ", anio=" + anio +
                ", caracteristicas=" + caracteristicas +
                ", fabricante=" + proveedor +
                '}';
    }

    /**
     * Metodo para comparar productos por precio
     */
    @Override
    public int compareTo(Vehiculo otro) {
        return Double.compare(this.precio, otro.precio);
    }

}