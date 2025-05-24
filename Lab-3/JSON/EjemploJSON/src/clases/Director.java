package clases;

public class Director {
    private String nombre;
    private int edad;
    private String especialidad;

    // Constructor
    public Director(String nombre, int edad, String especialidad) {
        this.nombre = nombre;
        this.edad = edad;
        this.especialidad = especialidad;
    }

    // Getters y Setters
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getEspecialidad() {
        return especialidad;
    }

    public void setEspecialidad(String especialidad) {
        this.especialidad = especialidad;
    }

    @Override
    public String toString() {
        return "Director{" +
                "nombre='" + nombre + '\'' +
                ", edad=" + edad +
                ", especialidad='" + especialidad + '\'' +
                '}';
    }
}
