import java.util.List;
import java.util.Scanner;

public class Menu {
    private Concesionaria concesionaria;
    private Scanner sc;

    public Menu(Concesionaria concesionaria) {
        this.concesionaria = concesionaria;
        this.sc = new Scanner(System.in);
    }

    private int leerEntero() {
        while (!sc.hasNextInt()) {
            System.out.print("Ingrese un número válido: ");
            sc.next();
        }
        int val = sc.nextInt();
        sc.nextLine(); // limpiar buffer
        return val;
    }

    private double leerDouble() {
        while (!sc.hasNextDouble()) {
            System.out.print("Ingrese un número válido: ");
            sc.next();
        }
        double val = sc.nextDouble();
        sc.nextLine(); // limpiar buffer
        return val;
    }

    public void mostrar() {
        int opcion;
        do {
            System.out.println("\n=== MENÚ ===");
            System.out.println("1. Listar inventario");
            System.out.println("2. Agregar vehículo");
            System.out.println("3. Eliminar vehículo");
            System.out.println("4. Filtrar por precio y proveedor (Italia/Alemania)");
            System.out.println("5. Filtrar deportivos por potencia y característica 'Turbo'");
            System.out.println("6. Filtrar por año, proveedor y cantidad de características");
            System.out.println("0. Salir");
            System.out.print("Opción: ");
            opcion = leerEntero();

            switch (opcion) {
                case 1:
                    listarInventario();
                    break;
                case 2:
                    agregarVehiculo();
                    break;
                case 3:
                    eliminarVehiculo();
                    break;
                case 4:
                    filtrarPorPrecioYProveedor();
                    break;
                case 5:
                    filtrarDeportivos();
                    break;
                case 6:
                    filtrarPorAnioProveedorYCaracteristicas();
                    break;
                case 0:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opción inválida.");
            }
        } while (opcion != 0);
    }

    private void listarInventario() {
        System.out.println("\n--- Inventario ---");
        for (Vehiculo v : concesionaria.getVehiculos()) {
            System.out.println(v);
        }
    }

    private void agregarVehiculo() {
        try {
            System.out.println("\nTipo de vehículo a agregar:");
            System.out.println("1. Auto");
            System.out.println("2. Deportivo");
            System.out.println("3. Camioneta");
            System.out.print("Opción: ");
            int tipo = leerEntero();

            System.out.print("Marca: ");
            String marca = sc.nextLine();
            System.out.print("Modelo: ");
            String modelo = sc.nextLine();
            System.out.print("Año: ");
            int anio = leerEntero();
            System.out.print("Precio: ");
            double precio = leerDouble();

            System.out.print("Ingrese características separadas por coma: ");
            String caracteristicasInput = sc.nextLine();
            List<String> caracteristicas = List.of(caracteristicasInput.split(","));

            System.out.print("Nombre del proveedor: ");
            String nombreProveedor = sc.nextLine();
            System.out.print("País del proveedor: ");
            String paisProveedor = sc.nextLine();
            Proveedor proveedor = new Proveedor(nombreProveedor, paisProveedor);

            Vehiculo nuevo = null;

            switch (tipo) {
                case 1: // Auto
                    System.out.print("Cantidad de puertas: ");
                    int puertas = leerEntero();
                    // Constructor esperado: public Auto(String marca, String modelo, double precio, int anio, List<String> caracteristicas, Proveedor proveedor)
                    nuevo = new Auto(marca, modelo, precio, anio, caracteristicas, proveedor);
                    break;
                case 2: // Deportivo
                    System.out.print("Potencia (HP): ");
                    int potencia = leerEntero();
                    System.out.print("Tipo de motor: ");
                    String motor = sc.nextLine();
                    // Constructor esperado:  public Deportivo(String marca, String modelo, double precio, int anio, List<String> caracteristicas, Proveedor proveedor, int potencia)
                    //        super("Deportivo", marca, modelo, precio, anio, caracteristicas, proveedor);
                    nuevo = new Deportivo(marca, modelo, precio, anio, caracteristicas, proveedor, potencia);
                    break;
                case 3: // Camioneta
                    System.out.print("Tracción (ej: 4x4): ");
                    String traccion = sc.nextLine();
                    // Constructor: Camioneta(String marca, String modelo, double precio, int anio, List<String> caracteristicas, Proveedor proveedor, String traccion)
                    nuevo = new Camioneta(marca, modelo, precio, anio, caracteristicas, proveedor, traccion);
                    break;
                default:
                    System.out.println("Tipo inválido.");
                    return;
            }

            concesionaria.agregarVehiculo(nuevo);
            System.out.println("Vehículo agregado exitosamente.");
        } catch (Exception e) {
            System.out.println("Error al agregar vehículo: " + e.getMessage());
        }
    }

    private void eliminarVehiculo() {
        try {
            List<Vehiculo> vehiculos = concesionaria.getVehiculos();
            if (vehiculos.isEmpty()) {
                System.out.println("No hay vehículos para eliminar.");
                return;
            }
            System.out.println("\n--- Eliminar Vehículo ---");
            for (int i = 0; i < vehiculos.size(); i++) {
                System.out.println((i + 1) + ". " + vehiculos.get(i));
            }
            System.out.print("Ingrese el número del vehículo a eliminar: ");
            int idx = leerEntero();
            if (idx < 1 || idx > vehiculos.size()) {
                System.out.println("Índice inválido.");
                return;
            }
            Vehiculo eliminado = vehiculos.remove(idx - 1);
            System.out.println("Vehículo eliminado: " + eliminado);
        } catch (Exception e) {
            System.out.println("Error al eliminar vehículo: " + e.getMessage());
        }
    }

    /**
     * Filtros
     */
    private void filtrarPorPrecioYProveedor() {
        try {
            System.out.print("Ingrese el precio mínimo: ");
            double precio = leerDouble();
            List<Vehiculo> filtrados = concesionaria.getInventario().filtrarXPrecioYProveedor(precio);
            mostrarListaFiltrada(filtrados);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private void filtrarDeportivos() {
        try {
            System.out.print("Ingrese la potencia mínima: ");
            int potencia = leerEntero();
            List<Deportivo> filtrados = concesionaria.getInventario().filtrarDeportivos(potencia, "Turbo");
            mostrarListaFiltrada(new java.util.ArrayList<>(filtrados));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private void filtrarPorAnioProveedorYCaracteristicas() {
        try {
            System.out.print("Ingrese el año mínimo: ");
            int anio = leerEntero();
            System.out.print("Ingrese el nombre del proveedor a excluir: ");
            String nombreProveedor = sc.nextLine();
            List<Vehiculo> filtrados = concesionaria.getInventario().filtrarXAnioXProveedorYCaracteristicas(anio, nombreProveedor);
            mostrarListaFiltrada(filtrados);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
    /**
     * Metodo genérico para mostrar lista filtrada
     */
    private void mostrarListaFiltrada(List<? extends Vehiculo> lista) {
        if (lista == null || lista.isEmpty()) {
            System.out.println("No se encontraron vehículos con ese filtro.");
        } else {
            for (Vehiculo v : lista) {
                System.out.println(v);
            }
        }
    }
}