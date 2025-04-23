package distribuidora.liquidacion.empleado;

import distribuidora.liquidacion.configuracion.Sueldos;

public class Repartidor extends Empleado {

    private float kmRecorridos;

    public Repartidor(String legajo, String nombre) {
        super(legajo, nombre);
    }

    public float getKmRecorridos() {
        return kmRecorridos;
    }

    public void setKmRecorridos(float kmRecorridos) {
        this.kmRecorridos = kmRecorridos;
        calcularSueldo();
    }

    @Override
    protected void calcularSueldo() {
        float sueldo = Sueldos.BASE_REPARTIDOR.getMonto() + (this.kmRecorridos * Sueldos.VIATICOS_REPARTIDORES.getMonto());
        super.setSueldo(sueldo);
    }

    @Override
    public boolean isVendedor() {
        return false;
    }

    @Override
    public boolean isRepartidor() {
        return true;
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
        return String.format("""
                                     ----------------------
                                     Repartidor %s
                                     Legajo %s
                                     Km recorridos: %.2f
                                     Sueldo mensual: $%.2f
                                     ----------------------
                                     """, super.getNombre(), super.getLegajo(), this.kmRecorridos, super.getSueldo());
    }
}
