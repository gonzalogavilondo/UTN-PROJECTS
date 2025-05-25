package clases;

import excepciones.PrecioInvalidoException;
import excepciones.VehiculoInexistenteException;

import java.util.ArrayList;
import java.util.List;

public class Inventario <T extends Vehiculo>{
    private List<T> vehiculos;

    public Inventario() {
        this.vehiculos=new ArrayList<>();
    }

    public List<T> getVehiculos() {
        return vehiculos;
    }

    public void setVehiculos(List<T> vehiculos) {
        this.vehiculos = vehiculos;
    }

    public List<Vehiculo> filtrarXPrecioYProveedor(double precio){
        if (precio<0){
            throw new PrecioInvalidoException("El precio no puede ser menor a 0");
        }
        List<Vehiculo> vehiculosFiltrados = new ArrayList<>();

        for (Vehiculo v : vehiculos){

            if (v.getPrecio()>=precio && v.getProveedor().getPais().equals("Italia") || v.getProveedor().getPais().equals("Alemania") ){
                    vehiculosFiltrados.add(v);
            }
        }

        if (vehiculosFiltrados.isEmpty()){
            throw new VehiculoInexistenteException("No existe un vehiculo con las caracteristicas indicadas");
        }

        return vehiculosFiltrados;
    }

    public List<Deportivo> filtrarDeportivos(int potencia,String caracteristica){
        List<Deportivo> deportivosFiltrados = new ArrayList<>();

        for (Vehiculo v : vehiculos){
            if (v instanceof Deportivo d){
                if (d.getPotencia()>potencia && d.getCaracteristicas().contains("Turbo")){
                    deportivosFiltrados.add(d);
                }
            }
        }

        if (deportivosFiltrados.isEmpty()){
            throw new VehiculoInexistenteException("No existe un vehiculo con las caracteristicas indicadas");
        }

        return deportivosFiltrados;
    }

    public List<Vehiculo> filtrarXAnioXProveedorYCaracteristicas(int anio,String nombreProveedor){
        List<Vehiculo> vehiculosFiltrados = new ArrayList<>();

        for (Vehiculo v: vehiculos){
            if (v.getAnio()>=anio && !v.getProveedor().getNombre().equals(nombreProveedor) && v.getCaracteristicas().size()>=3 ){
                vehiculosFiltrados.add(v);
            }
        }

        if (vehiculosFiltrados.isEmpty()){
            throw new VehiculoInexistenteException("No existe un vehiculo con las caracteristicas indicadas");
        }

        return vehiculosFiltrados;
    }

    @Override
    public String toString() {
        return "Inventario{" +
                "vehiculos=" + vehiculos +
                '}';
    }
}
