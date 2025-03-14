public class ItemVenta {
    private static int cntId = 0;
    private int id;
    private String descripcion;
    private int cantidad;
    private double precioUnitario;

    public ItemVenta() {
        this.id = ++cntId;
    }

    public ItemVenta(String descripcion, double precioUnitario, int cantidad) {
        this.id = ++cntId;
        this.descripcion = descripcion;
        this.precioUnitario = precioUnitario;
        this.cantidad = cantidad;
    }

    public int getId() {
        return id;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public int getCantidad() {
        return cantidad;
    }

    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }

    public double getPrecioUnitario() {
        return precioUnitario;
    }

    public void setPrecioUnitario(double precioUnitario) {
        this.precioUnitario = precioUnitario;
    }

    public double calcularPrecioTotal() {
        return precioUnitario * cantidad;
    }

    @Override
    public String toString() {
        return "ItemVenta{" +
                "id=" + id +
                ", descripcion='" + descripcion + '\'' +
                ", cantidad=" + cantidad +
                ", precioUnitario=" + precioUnitario +
                '}' +
                "\n";
    }

}

