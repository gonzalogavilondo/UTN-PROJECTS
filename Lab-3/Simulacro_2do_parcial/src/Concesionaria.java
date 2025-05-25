import java.util.ArrayList;
import java.util.List;

public class Concesionaria {
    private String nombre;
    private String ubicacion;
    private Inventario<Vehiculo> inventario;

    public Concesionaria(String nombre, String ubicacion, List<Vehiculo> vehiculos) {
        this.nombre = nombre;
        this.ubicacion = ubicacion;
        this.inventario = new Inventario<>();
        for (Vehiculo v : vehiculos) {
            this.inventario.agregar(v);
        }
    }


    /**
     * Getters and setters
     * @return
     */

    public void agregarVehiculo(Vehiculo v) {
        inventario.agregar(v);
    }

    public void eliminarVehiculo(Vehiculo v) {
        inventario.eliminar(v);
    }
    public List<Vehiculo> getVehiculos() {
        return inventario.getElementos();
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

    public void mostrarVehiculos() {
        for (Vehiculo v : inventario.getElementos()) {
            System.out.println(v);
        }
    }

    public Inventario<Vehiculo> getInventario() {
        return inventario;
    }

    public void setInventario(Inventario<Vehiculo> inventario) {
        this.inventario = inventario;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Concesionaria{")
                .append("nombre='").append(nombre).append('\'')
                .append(", ubicacion='").append(ubicacion).append('\'')
                .append(", vehiculos=[");
        sb.append(inventario.imprimir());
        sb.append("\n]}");
        return sb.toString();
    }

    /**
     * Busca vehiculo por modelo
     * @param modelo
     * @return
     * @throws VehiculoNoEncontradoException
     */
    public Vehiculo buscarVehiculoPorModelo(String modelo) throws VehiculoNoEncontradoException {
        for (Vehiculo v : inventario.getElementos()) {
            if (v.getModelo().equalsIgnoreCase(modelo)) {
                return v;
            }
        }
        throw new VehiculoNoEncontradoException("Vehículo con modelo '" + modelo + "' no encontrado.");
    }
}