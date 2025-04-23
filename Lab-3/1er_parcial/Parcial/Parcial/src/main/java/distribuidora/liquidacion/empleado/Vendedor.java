package distribuidora.liquidacion.empleado;

import distribuidora.liquidacion.configuracion.Sueldos;

public class Vendedor extends Empleado implements Supervisable {

    private float ventas;
    private Supervisor supervisor;

    public Vendedor(String legajo, String nombre) {
        super(legajo, nombre);
    }

    public float getVentas() {
        return ventas;
    }

    public void setVentas(float ventas) {
        this.ventas = ventas;
        calcularSueldo();
        supervisor.calcularSueldo();
    }

    public Supervisor getSupervisor() {
        return supervisor;
    }

    @Override
    protected void calcularSueldo() {
        float comision;
        if (this.ventas <= Sueldos.TECHO_VENDEDORES_PRIMER_NIVEL.getMonto())
            comision = Sueldos.COMISION_VENDEDORES_PRIMER_NIVEL.getMonto();
        else if (this.ventas <= Sueldos.TECHO_VENDEDORES_SEGUNDO_NIVEL.getMonto())
            comision = Sueldos.COMISION_VENDEDORES_SEGUNDO_NIVEL.getMonto();
        else comision = Sueldos.COMISION_VENDEDORES_TERCER_NIVEL.getMonto();

        float sueldo = Sueldos.BASE_VENDEDOR.getMonto() + (this.ventas * comision);
        super.setSueldo(sueldo);
    }

    @Override
    public boolean isVendedor() {
        return true;
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
        return true;
    }

    @Override
    public String toString() {
        return String.format("""
                                     ----------------------
                                     Vendedor %s
                                     Legajo %s
                                     Ventas mensuales: $%.2f
                                     Sueldo mensual: $%.2f
                                     ----------------------
                                     """, super.getNombre(), super.getLegajo(), this.ventas, super.getSueldo());
    }

    @Override
    public void supervisar(Supervisor supervisor) {
        this.supervisor = supervisor;
        this.supervisor.addVendedor(this);
    }

    @Override
    public void liberar() {
        this.supervisor.removeVendedor(this);
        this.supervisor = null;
    }
}
