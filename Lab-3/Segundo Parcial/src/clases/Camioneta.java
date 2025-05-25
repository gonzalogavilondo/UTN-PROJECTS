package clases;

public class Camioneta extends Vehiculo{
    private String traccion;

    public Camioneta() {
    }

    public String getTraccion() {
        return traccion;
    }

    public void setTraccion(String traccion) {
        this.traccion = traccion;
    }

    @Override
    public String toString() {
        return "Camioneta{" +
                "traccion='" + traccion + '\'' +
                "} " + super.toString();
    }
}
