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
            try {
                vehiculoModificado.setPrecio(-100); // Ejemplo de precio inválido
            } catch (PrecioNegativoException e) {
                System.out.println("Error: " + e.getMessage());
            }

            try {
                Vehiculo buscado = concesionaria.buscarVehiculoPorModelo("F8 Tributo");
                System.out.println(buscado);
            } catch (VehiculoNoEncontradoException e) {
                System.out.println("Advertencia: " + e.getMessage());
            }

            //Utilizacion de filtro
            // Acceder al inventario desde la concesionaria cargada
            System.out.println("\n\nFILTRADOS\n\n");
            Inventario<Vehiculo> inventario = concesionaria.getInventario();

            try {
                // Filtro por precio y proveedor
                List<Vehiculo> filtrados1 = inventario.filtrarXPrecioYProveedor(50000);
                System.out.println("Filtrados por precio y proveedor:");
                for (Vehiculo v : filtrados1) {
                    System.out.println(v);
                }

                // Filtro de deportivos potentes con turbo
                List<Deportivo> filtrados2 = inventario.filtrarDeportivos(400, "Turbo");
                System.out.println("Deportivos potentes con turbo:");
                for (Deportivo d : filtrados2) {
                    System.out.println(d);
                }

                // Filtro por año, proveedor y características
                List<Vehiculo> filtrados3 = inventario.filtrarXAnioXProveedorYCaracteristicas(2020, "Toyota");
                System.out.println("Filtrados por año, proveedor y características:");
                for (Vehiculo v : filtrados3) {
                    System.out.println(v);
                }
            } catch (VehiculoNoEncontradoException | PrecioNegativoException e) {
                System.out.println("Error en filtro: " + e.getMessage());
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

        System.out.println("\n\n");
        System.out.println(concesionaria.toString());

    }
}