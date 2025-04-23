package distribuidora.liquidacion.gestor;

import distribuidora.liquidacion.configuracion.Areas;
import distribuidora.liquidacion.empleado.*;
import distribuidora.liquidacion.excepciones.EmpleadoInexistenteException;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

/*
 * Clase gestora de los empleados.
 * Proveé métodos para agregar y eliminar empleados a la gestión
 * También métodos para filtrar por tipos de empleado y por legajo
 */
public class GestorEmpleados {

    private final ArrayList<Empleado> empleados = new ArrayList<>();
    /*
     * Indica si el gestor se ejecuta con datos ficticios
     */
    private boolean demo = false;

    public GestorEmpleados() {
    }

    public GestorEmpleados(boolean demo) {
        this.demo = demo;
        if (demo) {
            int cantidad = generarDatosFicticios();
            System.out.printf("Gestor iniciado con %d datos ficticios.\n", cantidad);
        }
    }

    /*
     * Busca el empleado por legajo. Si no lo encuentra, devuelve null
     */
    public Empleado buscarEmpleado(String legajo) throws EmpleadoInexistenteException {
        Optional<Empleado> optional = this.empleados.stream().filter(empleado -> empleado.equals(legajo)).findFirst();
        if(!optional.isPresent()) throw new EmpleadoInexistenteException(legajo);
        return optional.orElse(null);
    }

    /*
     * Busca al vendedor por legajo. Si no lo encuentra, devuelve null
     */
    public Vendedor buscarVendedor(String legajo) {
        Optional<Empleado> optional = this.empleados.stream().filter(vendedor -> vendedor.equals(legajo) && vendedor.isVendedor()).findFirst();
        return (Vendedor) optional.orElse(null);
    }

    /*
     * Busca al repartidor por legajo. Si no lo encuentra, devuelve null
     */
    public Repartidor buscarRepartidor(String legajo) {
        Optional<Empleado> optional = this.empleados.stream().filter(vendedor -> vendedor.equals(legajo) && vendedor.isRepartidor()).findFirst();
        return (Repartidor) optional.orElse(null);
    }

    /*
     * Busca al administrador por legajo. Si no lo encuentra, devuelve null
     */
    public Administrador buscarAdministrador(String legajo) {
        Optional<Empleado> optional = this.empleados.stream().filter(vendedor -> vendedor.equals(legajo) && vendedor.isAdministrador()).findFirst();
        return (Administrador) optional.orElse(null);
    }

    /*
     * Busca al supervisor por legajo. Si no lo encuentra, devuelve null
     */
    public Supervisor buscarSupervisor(String legajo) {
        Optional<Empleado> optional = this.empleados.stream().filter(vendedor -> vendedor.equals(legajo) && vendedor.isSupervisor()).findFirst();
        return (Supervisor) optional.orElse(null);
    }

    /*
     * Busca todos los vendedores
     */
    public List<Vendedor> filtrarVendedores() {
        return this.empleados.stream().filter(Empleado::isVendedor).map(v -> (Vendedor) v).collect(Collectors.toList());
    }

    /*
     * Busca todos los repartidores
     */
    public List<Repartidor> filtrarRepartidores() {
        return this.empleados.stream().filter(Empleado::isRepartidor).map(r -> (Repartidor) r).collect(Collectors.toList());
    }

    /*
     * Busca todos los administradores
     */
    public List<Administrador> filtrarAdministradores() {
        return this.empleados.stream().filter(Empleado::isAdministrador).map(a -> (Administrador) a).collect(Collectors.toList());
    }

    /*
     * Busca todos los supervisores
     */
    public List<Supervisor> filtrarSupervisores() {
        return this.empleados.stream().filter(Empleado::isSupervisor).map(s -> (Supervisor) s).collect(Collectors.toList());
    }

    /*
     * Devuelve todos los empleados
     */
    public List<Empleado> empleados() {
        return this.empleados;
    }

    /*
     * Agrega un empleado a la gestión. Devuelve un booleano indicando si efectivamente se agregó
     */
    public boolean agregarEmpleado(Empleado empleado) {
        return this.empleados.add(empleado);
    }

    /*
     * Elimina un empleado de la gestión. Devuelve un booleano indicando si efectivamente se eliminó
     */
    public boolean eliminarEmpleado(String legajo) {
        return this.empleados.removeIf(empleado -> empleado.equals(legajo));
    }

    /*
     * Elimina un empleado de la gestión. Devuelve un booleano indicando si efectivamente se eliminó
     */
    public boolean eliminarEmpleado(Empleado empleado) {
        if (empleado.isSupervisable()) ((Supervisable) empleado).liberar();
        return this.empleados.remove(empleado);
    }

    private int generarDatosFicticios() {
        Vendedor vendedor = new Vendedor("V1010", "Juan");
        agregarEmpleado(vendedor);

        Repartidor repartidor = new Repartidor("R1010", "Jose");
        agregarEmpleado(repartidor);

        Administrador administrador = new Administrador("A10100", "Pedro", Areas.FINANZAS);
        agregarEmpleado(administrador);

        Supervisor supervisor = new Supervisor("S1010", "Javier");
        agregarEmpleado(supervisor);

        vendedor.supervisar(supervisor);

        return this.empleados.size();
    }
}
