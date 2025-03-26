public class Estudiante extends Persona{
    private int anioIngreso;
    private double cuotaMensual;
    private String carrera;

    public Estudiante() {
        super();
    }

    public Estudiante(String nombre, String email, String direccion, String dni, String apellido, int anioIngreso, String carrera, double cuotaMensual) {
        super(nombre, email, direccion, dni, apellido);
        this.anioIngreso = anioIngreso;
        this.carrera = carrera;
        this.cuotaMensual = cuotaMensual;
    }

    public int getAnioIngreso() {
        return anioIngreso;
    }

    public void setAnioIngreso(int anioIngreso) {
        this.anioIngreso = anioIngreso;
    }

    public String getCarrera() {
        return carrera;
    }

    public void setCarrera(String carrera) {
        this.carrera = carrera;
    }

    public double getCuotaMensual() {
        return cuotaMensual;
    }

    public void setCuotaMensual(double cuotaMensual) {
        this.cuotaMensual = cuotaMensual;
    }

    @Override
    public String toString() {
        return "Estudiante{" +
                "anioIngreso=" + anioIngreso +
                ", cuotaMensual=" + cuotaMensual +
                ", carrera='" + carrera + '\'' +
                '}';
    }
}
