package distribuidora.liquidacion.empleado;

import java.util.Objects;

public abstract class Empleado {
    private final String legajo;
    private String nombre;
    private float sueldo;

    public Empleado(String legajo, String nombre) {
        this.legajo = legajo;
        this.nombre = nombre;
    }

    public String getLegajo() {
        return legajo;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public float getSueldo() {
        return sueldo;
    }

    protected void setSueldo(float sueldo) {
        this.sueldo = sueldo;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if ((o instanceof Vendedor vendedor)) return Objects.equals(legajo, vendedor.getLegajo());
        else if ((o instanceof Repartidor repartidor)) return Objects.equals(legajo, repartidor.getLegajo());
        else if ((o instanceof Administrador administrador)) return Objects.equals(legajo, administrador.getLegajo());
        else if ((o instanceof Supervisor supervisor)) return Objects.equals(legajo, supervisor.getLegajo());
        else return Objects.equals(legajo, o);
    }

    @Override
    public int hashCode() {
        return Objects.hash(legajo);
    }

    protected abstract void calcularSueldo();

    public abstract boolean isVendedor();

    public abstract boolean isRepartidor();

    public abstract boolean isSupervisor();

    public abstract boolean isAdministrador();

    public abstract boolean isSupervisable();
}
