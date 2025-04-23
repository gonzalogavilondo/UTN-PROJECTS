package distribuidora.liquidacion.empleado;

import distribuidora.liquidacion.configuracion.Sueldos;

import java.util.ArrayList;
import java.util.Objects;
import java.util.stream.Collectors;

public class Supervisor extends Empleado {
    private final ArrayList<Vendedor> vendedores;

    public Supervisor(String legajo, String nombre) {
        super(legajo, nombre);
        this.vendedores = new ArrayList<>();
    }

    public ArrayList<Vendedor> getVendedores() {
        return vendedores;
    }

    protected void addVendedor(Vendedor vendedor) {
        this.vendedores.add(vendedor);
        calcularSueldo();
    }

    public void removeVendedor(Vendedor vendedor) {
        this.vendedores.removeIf(v -> v.equals(vendedor));
        calcularSueldo();
    }

    @Override
    protected void calcularSueldo() {
        float ventas = this.vendedores.stream().mapToLong(vendedor -> (long) vendedor.getVentas()).sum();
        float sueldo = Sueldos.BASE_SUPERVISOR.getMonto() + (ventas * Sueldos.COMISION_SUPERVISORES.getMonto());
        super.setSueldo(sueldo);
    }

    @Override
    public boolean isVendedor() {
        return false;
    }

    @Override
    public boolean isRepartidor() {
        return false;
    }

    @Override
    public boolean isSupervisor() {
        return false;
    }

    @Override
    public boolean isAdministrador() {
        return false;
    }

    @Override
    public boolean isSupervisable() {
        return false;
    }

    @Override
    public String toString() {
        String vendedores;
        if (this.vendedores.isEmpty()) vendedores = """
                Sin vendedores asignados.
                ----------------------""";
        else vendedores = this.vendedores.stream().map(Vendedor::toString).collect(Collectors.joining("/n"));
        return String.format("""
                                     ----------------------
                                     Supervisor %s
                                     Legajo %s
                                     Sueldo mensual: $%.2f
                                     Vendedores:
                                     %s
                                     """, super.getNombre(), super.getLegajo(), super.getSueldo(), vendedores);
    }
}
