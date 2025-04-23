package distribuidora.liquidacion.empleado;

import distribuidora.liquidacion.configuracion.Areas;
import distribuidora.liquidacion.configuracion.Sueldos;

public class Administrador extends Empleado {

    private Areas area;

    public Administrador(String legajo, String nombre, Areas area) {
        super(legajo, nombre);
        super.setSueldo(Sueldos.BASE_ADMINISTRADOR.getMonto());
        this.area = area;
    }

    public Areas getArea() {
        return area;
    }

    public void setArea(Areas area) {
        this.area = area;
    }

    @Override
    protected void calcularSueldo() {
        super.setSueldo(Sueldos.BASE_ADMINISTRADOR.getMonto());
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
        return true;
    }

    @Override
    public boolean isSupervisable() {
        return false;
    }

    @Override
    public String toString() {
        return String.format("""
                                     ----------------------
                                     Administrador %s
                                     Legajo %s
                                     Sueldo mensual: $%.2f
                                     ----------------------
                                     """, super.getNombre(), super.getLegajo(), super.getSueldo());
    }
}
