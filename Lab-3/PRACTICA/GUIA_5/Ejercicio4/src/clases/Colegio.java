package clases;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Colegio {
    private ArrayList<Alumno> alumnos;

    public Colegio(ArrayList<Alumno> alumnos) {
        if (alumnos == null) {
            throw new IllegalArgumentException("La lista de alumnos no puede ser nula.");
        }
        this.alumnos = new ArrayList<>(alumnos);
    }

    /**
     * Metodo para agregar el alumno
     */
    public void agregarAlumno(Alumno alumno) {
        if (alumno == null) {
            throw new IllegalArgumentException("El alumno no puede ser nulo.");
        }
        if (alumno.getNacionalidad() == null || alumno.getNacionalidad().isEmpty()) {
            throw new IllegalArgumentException("El alumno debe tener una nacionalidad válida.");
        }
        alumnos.add(alumno);
    }

    /**
     * Muestra la nacionalidad y el
     * número de alumnos de esa nacionalidad
     * @param nacionalidad
     */
    public void verNacionalidad(String nacionalidad) {
        if (nacionalidad == null || nacionalidad.isEmpty()) {
            throw new IllegalArgumentException("La nacionalidad no puede ser nula o vacía.");
        }
        int contador = 0;
        for (Alumno alumno : alumnos) {
            if (alumno.getNacionalidad().equalsIgnoreCase(nacionalidad)) {
                contador++;
            }
        }
        System.out.println("La nacionalidad " + nacionalidad + " tiene " + contador + " alumnos.");
    }

    /**
     * Muestra cuántas nacionalidades diferentes existen en el
     * colegio.
     */
    public void cuantos() {
        if (alumnos.isEmpty()) {
            throw new IllegalStateException("No hay alumnos en el colegio.");
        }
        List<String> nacionalidades = new ArrayList<>();
        for (Alumno alumno : alumnos) {
            if (alumno.getNacionalidad() == null || alumno.getNacionalidad().isEmpty()) {
                throw new IllegalStateException("Todos los alumnos deben tener una nacionalidad válida.");
            }
            if (!nacionalidades.contains(alumno.getNacionalidad())) {
                nacionalidades.add(alumno.getNacionalidad());
            }
        }
        System.out.println("El colegio tiene " + nacionalidades.size() + " nacionalidades diferentes.");
    }

    /**
     * Borrar alumno
     * @param nombre
     * @return
     */
    public String borrarAlumno(String nombre) {
        if (nombre == null || nombre.isEmpty()) {
            throw new IllegalArgumentException("El nombre no puede ser nulo o vacío.");
        }
        for (Alumno alumno : alumnos) {
            if (Objects.equals(alumno.getNombre(), nombre)) {
                alumnos.remove(alumno);
                return "El alumno se encontró y se eliminó correctamente.";
            }
        }
        throw new IllegalArgumentException("El alumno con el nombre " + nombre + " no se encontró en el listado del colegio.");
    }

    /**
     * Muestra las distintas nacionalidades y el número de
     * alumnos que existen por nacionalidad.
     */
    public void mostrarNacionalidades() {
        if (alumnos.isEmpty()) {
            throw new IllegalStateException("No hay alumnos en el colegio.");
        }
        List<String> nacionalidades = new ArrayList<>();
        for (Alumno alumno : alumnos) {
            if (alumno.getNacionalidad() == null || alumno.getNacionalidad().isEmpty()) {
                throw new IllegalStateException("Todos los alumnos deben tener una nacionalidad válida.");
            }
            if (!nacionalidades.contains(alumno.getNacionalidad())) {
                nacionalidades.add(alumno.getNacionalidad());
            }
        }
        for (String nacionalidad : nacionalidades) {
            verNacionalidad(nacionalidad);
        }
    }
}