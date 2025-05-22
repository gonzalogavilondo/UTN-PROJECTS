import org.json.JSONException;

import java.util.List;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        /**
         * Levanto el archivo JSON utilizando Persistencia
         *
         */
        // Cargar los datos de la concesionaria al iniciar
        Concesionaria concesionaria = null;
        try {
            concesionaria = Persistencia.cargarConcesionaria();
        } catch (JSONException e) {
            throw new RuntimeException(e);
        }

        if (concesionaria != null) {
            // Acceder a la lista de vehículos
            for (Vehiculo v : concesionaria.getVehiculos()) {
                System.out.println(v.toString());
            }

            // Modificar datos de un vehículo (ejemplo)
            Vehiculo vehiculoModificado = concesionaria.getVehiculos().get(0);
            vehiculoModificado.setPrecio(123456);

            //Ejemplo de utilizacion de filtros
            List<Vehiculo> vehiculosFiltrados = concesionaria.filtrarPorPrecioYProveedor();
            System.out.println("Vehículos filtrados:");
            for (Vehiculo v : vehiculosFiltrados) {
                System.out.println(v.toString());
            }

            //Ejemplo de utilizacion de los filtros
            List<Vehiculo> vehiculosFiltrados2 = concesionaria.filtrarPorAnioCaracteristicasYProveedor();
            System.out.println("Vehículos filtrados por año y caracteristicas de proveedor:");
            for (Vehiculo v : vehiculosFiltrados2) {
                System.out.println(v.toString());
            }

            //Ejemplo de utilizacion de los filtros
            List<Deportivo> vehiculosFiltrados3 = concesionaria.filtrarDeportivosPotentesConTurbo();
            System.out.println("Vehículos filtrados por año y caracteristicas:");
            for (Vehiculo v : vehiculosFiltrados3) {
                System.out.println(v.toString());
            }


            // Guardar los cambios en el backup
            try {
                Persistencia.guardarConcesionaria(concesionaria, "backup.json");
            } catch (JSONException e) {
                throw new RuntimeException(e);
            }
        } else {
            System.out.println("No se pudo cargar la concesionaria.");
        }

    }
}