package clases;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        // Crear una lista inicial de alumnos
        ArrayList<Alumno> listaAlumnos = new ArrayList<>();
        listaAlumnos.add(new Alumno("Juan", "Argentina"));
        listaAlumnos.add(new Alumno("Maria", "Chile"));

        // Crear una instancia de Colegio
        Colegio colegio = new Colegio(listaAlumnos);

        try {
            // Agregar un alumno con nacionalidad válida
            colegio.agregarAlumno(new Alumno("Pedro", "Perú"));
            System.out.println("Alumno agregado correctamente.");

            // Intentar agregar un alumno sin nacionalidad
            colegio.agregarAlumno(new Alumno("Ana", ""));
        } catch (IllegalArgumentException e) {
            System.out.println("Error al agregar alumno: " + e.getMessage());
        }

        try {
            // Ver nacionalidad
            colegio.verNacionalidad("Argentina");
            colegio.verNacionalidad(""); // Esto lanzará una excepción
        } catch (IllegalArgumentException e) {
            System.out.println("Error al consultar nacionalidad: " + e.getMessage());
        }

        try {
            // Borrar un alumno
            System.out.println(colegio.borrarAlumno("Maria"));
            System.out.println(colegio.borrarAlumno("Carlos")); // Esto lanzará una excepción
        } catch (IllegalArgumentException e) {
            System.out.println("Error al borrar alumno: " + e.getMessage());
        }

        try {
            // Mostrar nacionalidades
            colegio.mostrarNacionalidades();
        } catch (IllegalStateException e) {
            System.out.println("Error al mostrar nacionalidades: " + e.getMessage());
        }
    }
}