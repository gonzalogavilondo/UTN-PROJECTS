import java.util.UUID;

public class Cliente {

    private String id;
    private String nombre;
    private String email;
    private double porcentajeDescuento;

    public Cliente() {
    }

    public Cliente(String nombre, String email, double porcentajeDescuento) {
        this.id = generarId();
        this.nombre = nombre;
        this.email = email;
        this.porcentajeDescuento = porcentajeDescuento;
    }

    public String getId() {
        return id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public double getPorcentajeDescuento() {
        return porcentajeDescuento;
    }

    public void setPorcentajeDescuento(double porcentajeDescuento) {
        this.porcentajeDescuento = porcentajeDescuento;
    }

    @Override
    public String toString() {
        return "Cliente{" +
                "id='" + id + '\'' +
                ", nombre='" + nombre + '\'' +
                ", email='" + email + '\'' +
                ", porcentajeDescuento=" + porcentajeDescuento +
                '}';
    }

    public String generarId() {
        return "C" + UUID.randomUUID().toString();
    }
}
