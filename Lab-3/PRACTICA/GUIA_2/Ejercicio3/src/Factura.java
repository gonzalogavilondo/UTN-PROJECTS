import java.time.LocalDate;
import java.util.UUID;

public class Factura {
    private String id;
    private double montoTotal;
    private Cliente cliente;
    private String fecha;

    public Factura() {
        this.id = generarId();
        this.fecha = String.valueOf(LocalDate.now()); // Asigna la fecha y hora actual
    }

    public Factura(double montoTotal, Cliente cliente) {
        this.id = generarId();
        this.montoTotal = montoTotal;
        this.cliente = cliente;
        this.fecha = String.valueOf(LocalDate.now()); // Asigna la fecha y hora actual
    }

    public String getId() {
        return id;
    }

    public double getMontoTotal() {
        return montoTotal;
    }

    public void setMontoTotal(double montoTotal) {
        this.montoTotal = montoTotal;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    @Override
    public String toString() {
        return "Factura{" +
                "id='" + id + '\'' +
                ", montoTotal=" + montoTotal +
                ", fecha=" + fecha +
                '}' +
                ", cliente=" + cliente.toString()
                ;
    }

    public String generarId() {
        return "F" + UUID.randomUUID().toString();
    }

    //Metodo que calcule el monto final luego de aplicarle el descuento que posee el cliente.
    public double calcularMontoFinal() {
        return montoTotal - (montoTotal * cliente.getPorcentajeDescuento() / 100);
    }
}
