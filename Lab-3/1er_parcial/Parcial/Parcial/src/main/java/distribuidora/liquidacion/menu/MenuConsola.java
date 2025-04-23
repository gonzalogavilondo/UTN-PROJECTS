package distribuidora.liquidacion.menu;

import distribuidora.liquidacion.empleado.*;
import distribuidora.liquidacion.gestor.GestorEmpleados;

import java.util.Scanner;

public class MenuConsola implements Menu {
    private final Scanner scanner = new Scanner(System.in);
    private final GestorEmpleados gestorEmpleados;

    public MenuConsola(GestorEmpleados gestorEmpleados) {
        this.gestorEmpleados = gestorEmpleados;
    }

    /*
     * Ejecuta las opciones:
     * 1. Buscar empleado
     * 2. Listar empleados
     * 3. Finalizar
     */
    @Override
    public void ejecutarMenuPrincipal() {
        String menu = """
                                
                Sistema de liquidación de sueldos
                1. Buscar empleado
                2. Listar empleados
                3. Finalizar
                                
                """;
        int opcion;
        do {
            System.out.println(menu);
            opcion = scanner.nextInt();

            switch (opcion) {
                case 1 -> ejecutarBuscarEmpleado();
                case 2 -> ejecutarListarEmpleados();
                case 3 -> finalizar();
                default -> ejecutarOpcionIncorrecta();
            }
        } while (opcion != 3);
    }

    /*
     * Busca un empleado, muestra su información y ejecuta las opciones:
     * 1. Actualizar nombre
     * 2. Actualizar adicional mensual
     * 3. Eliminar empleado
     * 4. Finalizar
     */
    private void ejecutarBuscarEmpleado() {
        String menu = """
                                
                1. Actualizar nombre
                2. Actualizar adicional mensual
                3. Eliminar empleado
                4. Salir
                                
                """;
        int opcion;

        Empleado empleado = buscarEmpleado();
        if (empleado != null) {
            System.out.println(empleado);

            do {
                System.out.println(menu);
                opcion = scanner.nextInt();

                switch (opcion) {
                    case 1 -> ejecutarActualizarNombreEmpleado(empleado);
                    case 2 -> ejecutarActualizarAdicionalEmpleado(empleado);
                    case 3 -> {
                        if (ejecutarEliminarEmpleado(empleado)) return;
                    }
                    case 4 -> ejecutarRetroceso();
                    default -> ejecutarOpcionIncorrecta();
                }
            } while (opcion != 4);

        } else System.out.println("Empleado inexistente.");
    }

    private Empleado buscarEmpleado() {
        try {
            System.out.println("Legajo a buscar: ");
            String legajo = scanner.next();
            return gestorEmpleados.buscarEmpleado(legajo);
        } catch (Exception e) {
            ejecutarError();
            return null;
        }
    }

    private void ejecutarActualizarNombreEmpleado(Empleado empleado) {
        try {
            System.out.println("Nuevo nombre: ");
            String nombre = scanner.next();
            empleado.setNombre(nombre);
            System.out.println(empleado);
        } catch (Exception e) {
            ejecutarError();
        }
    }

    private void ejecutarActualizarAdicionalEmpleado(Empleado empleado) {
        if (empleado.isVendedor()) actualizarAdicionalEmpleado((Vendedor) empleado);
        else if (empleado.isRepartidor()) actualizarAdicionalEmpleado((Repartidor) empleado);
        else System.out.println("Tipo de empleado no soportado.");
    }

    private void actualizarAdicionalEmpleado(Vendedor vendedor) {
        try {
            System.out.println("Nuevo monto mensual de venta: ");
            float monto = scanner.nextFloat();
            vendedor.setVentas(monto);
            System.out.println(vendedor);
        } catch (Exception e) {
            ejecutarError();
        }
    }

    private void actualizarAdicionalEmpleado(Repartidor repartidor) {
        try {
            System.out.println("Nueva cantidad mensual de km recorridos: ");
            float cantidad = scanner.nextFloat();
            repartidor.setKmRecorridos(cantidad);
            System.out.println(repartidor);
        } catch (Exception e) {
            ejecutarError();
        }
    }

    private boolean ejecutarEliminarEmpleado(Empleado empleado) {
        boolean resultado = gestorEmpleados.eliminarEmpleado(empleado);
        if (resultado) System.out.println("Empleado eliminado.");
        else ejecutarError();
        return resultado;
    }

    /*
     * Ejecuta las siguientes opciones:
     * 1. Todos
     * 2. Vendedores
     * 3. Repartidores
     * 4. Administradores
     * 5. Supervisores
     * 6. Salir
     */
    private void ejecutarListarEmpleados() {
        String menu = """
                                
                1. Todos
                2. Vendedores
                3. Repartidores
                4. Administradores
                5. Supervisores
                6. Salir
                """;
        int opcion;

        do {
            System.out.println(menu);
            opcion = scanner.nextInt();

            switch (opcion) {
                case 1 -> {
                    for (Empleado empleado : gestorEmpleados.empleados()) {
                        System.out.println(empleado);
                    }
                }
                case 2 -> {
                    for (Vendedor vendedor : gestorEmpleados.filtrarVendedores()) {
                        System.out.println(vendedor);
                    }
                }
                case 3 -> {
                    for (Repartidor repartidor : gestorEmpleados.filtrarRepartidores()) {
                        System.out.println(repartidor);
                    }
                }
                case 4 -> {
                    for (Administrador administrador : gestorEmpleados.filtrarAdministradores()) {
                        System.out.println(administrador);
                    }
                }
                case 5 -> {
                    for (Supervisor supervisor : gestorEmpleados.filtrarSupervisores()) {
                        System.out.println(supervisor);
                    }
                }
                case 6 -> ejecutarRetroceso();
                default -> ejecutarOpcionIncorrecta();
            }

        } while (opcion != 6);
    }

    private void ejecutarOpcionIncorrecta() {
        System.out.println("Opción inválida.");
    }

    private void ejecutarError() {
        System.out.println("No se pudo realizar la acción.");
    }

    private void ejecutarRetroceso() {
        System.out.println("Saliendo.");
    }

    private void finalizar() {
        scanner.close();
        System.out.println("Programa finalizado.");
    }
}
