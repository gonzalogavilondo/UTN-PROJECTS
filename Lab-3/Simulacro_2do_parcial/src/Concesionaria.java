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
     * Metodos de filtro
     */


    /**
     * Filtra vehículos con precio > 100,000 y proveedor de Italia o Alemania
     */
    public List<Vehiculo> filtrarPorPrecioYProveedor() {
        List<Vehiculo> filtrados = new ArrayList<>();
        for (Vehiculo v : inventario.getElementos()) {
            String pais = v.getProveedor().getPais();
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
        for (Vehiculo v : inventario.getElementos()) {
            if (v instanceof Deportivo) {
                Deportivo d = (Deportivo) v;
                if (d.getPotencia() > 700) {
                    boolean tieneTurbo = false;
                    for (String c : d.getCaracteristicas()) {
                        if (c.equalsIgnoreCase("Turbo")) {
                            tieneTurbo = true;
                            break;
                        }
                    }
                    if (tieneTurbo) {
                        filtrados.add(d);
                    }
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
        for (Vehiculo v : inventario.getElementos()) {
            String pais = v.getProveedor().getPais();
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
        for (Vehiculo v : inventario.getElementos()) {
            if (v.getModelo().equalsIgnoreCase(modelo)) {
                return v;
            }
        }
        throw new VehiculoNoEncontradoException("Vehículo con modelo '" + modelo + "' no encontrado.");
    }
}