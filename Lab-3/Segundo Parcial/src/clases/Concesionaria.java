package clases;

public class Concesionaria {
    private String nombre;
    private String ubicacion;
    private Inventario<Vehiculo> inventario;

    public Concesionaria() {
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getUbicacion() {
        return ubicacion;
    }

    public void setUbicacion(String ubicacion) {
        this.ubicacion = ubicacion;
    }

    public Inventario<Vehiculo> getInventario() {
        return inventario;
    }

    public void setInventario(Inventario<Vehiculo> inventario) {
        this.inventario = inventario;
    }

    public void filtrado1(double precio){
        System.out.println(inventario.filtrarXPrecioYProveedor(precio));
    }

    public void filtrado2(int potencia,String caracteristica){
        System.out.println(inventario.filtrarDeportivos(potencia,caracteristica));
    }

    public void filtrado3(int anio,String nombreProveedor){
        System.out.println(inventario.filtrarXAnioXProveedorYCaracteristicas(anio,nombreProveedor));
    }
    @Override
    public String toString() {
        return "Concesionaria{" +
                "nombre='" + nombre + '\'' +
                ", ubicacion='" + ubicacion + '\'' +
                '}';
    }
}
