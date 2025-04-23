package distribuidora.liquidacion.configuracion;

public enum Sueldos {
    BASE_VENDEDOR("Sueldo base para vendedores", 400000),
    BASE_REPARTIDOR("Sueldo base para repartidores", 200000),
    BASE_ADMINISTRADOR("Sueldo base para administradores", 600000),
    BASE_SUPERVISOR("Sueldo base para supervisores", 600000),
    TECHO_VENDEDORES_PRIMER_NIVEL("Viático por km recorrido por los repartidores", 500000),
    TECHO_VENDEDORES_SEGUNDO_NIVEL("Viático por km recorrido por los repartidores", 1000000),
    COMISION_VENDEDORES_PRIMER_NIVEL("% de comisión de los vendedores si las ventas mensuales no superan $500.000", 0.1f),
    COMISION_VENDEDORES_SEGUNDO_NIVEL("% de comisión de los vendedores si las ventas mensuales no superan $1.000.000", 0.15f),
    COMISION_VENDEDORES_TERCER_NIVEL("% de comisión de los vendedores si las ventas mensuales superan $1.000.000", 0.2f),
    VIATICOS_REPARTIDORES("Viático por km recorrido por los repartidores", 5000),
    COMISION_SUPERVISORES("% de comisión de los supervisores por las ventas mensuales de sus vendedores a cargo", 0.03f);

    private final String descripcion;
    private final float monto;

    Sueldos(String descripcion, float monto) {
        this.descripcion = descripcion;
        this.monto = monto;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public float getMonto() {
        return monto;
    }
}
