import java.util.ArrayList;
import java.util.List;

public class Concesionaria {
    private String nombre;
    private String ubicacion;
    private List<Vehiculo> vehiculos;

    public Concesionaria(String nombre, String ubicacion, List<Vehiculo> vehiculos) {
        this.nombre = nombre;
        this.ubicacion = ubicacion;
        this.vehiculos = vehiculos;
    }

    /**
     * Getters and setters
     * @return
     */

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

    public List<Vehiculo> getVehiculos() {
        return vehiculos;
    }

    public void setVehiculos(List<Vehiculo> vehiculos) {
        this.vehiculos = vehiculos;
    }

    @Override
    public String toString() {
        return "Concesionaria{" +
                "nombre='" + nombre + '\'' +
                ", ubicacion='" + ubicacion + '\'' +
                ", vehiculos=" + vehiculos +
                '}';
    }

    /**
     * Metodos de filtro
     */


    /**
     * Filtra vehículos con precio > 100,000 y proveedor de Italia o Alemania
     */
    public List<Vehiculo> filtrarPorPrecioYProveedor() {
        List<Vehiculo> filtrados = new ArrayList<>();
        for (Vehiculo v : vehiculos) {
            String pais = v.getFabricante().getPais();
            if (v.getPrecio() > 100000 && (pais.equalsIgnoreCase("Italia") || pais.equalsIgnoreCase("Alemania"))) {
                filtrados.add(v);
            }
        }
        return filtrados;
    }

    /**
     * Filtra deportivos con más de 700 caballos y característica "Turbo"
     */
    public List<Deportivo> filtrarDeportivosPotentesConTurbo() {
        List<Deportivo> filtrados = new ArrayList<>();
        for (Vehiculo v : vehiculos) {
            if (v instanceof Deportivo d) {
                if (d.getPotencia() > 700 && d.getCaracteristicas().stream().anyMatch(c -> c.equalsIgnoreCase("Turbo"))) {
                    filtrados.add(d);
                }
            }
        }
        return filtrados;
    }

    /**
     * Filtra vehículos fabricados después de 2020, con al menos 3 características y proveedor distinto de EEUU
     */
    public List<Vehiculo> filtrarPorAnioCaracteristicasYProveedor() {
        List<Vehiculo> filtrados = new ArrayList<>();
        for (Vehiculo v : vehiculos) {
            String pais = v.getFabricante().getPais();
            if (v.getAnio() > 2020 && v.getCaracteristicas().size() >= 3 && !pais.equalsIgnoreCase("EEUU")) {
                filtrados.add(v);
            }
        }
        return filtrados;
    }

    /**
     * Busca vehiculo por modelo
     * @param modelo
     * @return
     * @throws VehiculoNoEncontradoException
     */
    public Vehiculo buscarVehiculoPorModelo(String modelo) throws VehiculoNoEncontradoException {
        for (Vehiculo v : vehiculos) {
            if (v.getModelo().equalsIgnoreCase(modelo)) {
                return v;
            }
        }
        throw new VehiculoNoEncontradoException("Vehículo con modelo '" + modelo + "' no encontrado.");
    }
}