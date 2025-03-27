import java.util.ArrayList;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        // Instanciamos 4 estudiantes diferentes
        Persona estudiante = new Estudiante("Juan", "juan@email.com", "Calle 123", "12345678", "Perez", 2020, "Ingenieria", 1000);
        Persona estudiante2 = new Estudiante("Pedro", "pedro@email.com", "Calle 456", "87654321", "Gomez", 2021, "Medicina", 2000);
        Persona estudiante3 = new Estudiante("Pablo", "pablo@email.com", "Calle 789", "45678912", "Lopez", 2019, "Derecho", 1500);
        Persona estudiante4 = new Estudiante("Martin", "martin@email.com", "Calle 159", "78912345", "Garcia", 2018, "Arquitectura", 1800);

        // Instanciamos 4 staffs diferentes
        Persona staff = new Staff("Ramon", "ramon@email.com", "ramon@email.com", "98765432", "Gonzalez", "Noche", 5000);
        Persona staff2 = new Staff("Roberto", "roberto@email.com", "roberto@email.com", "99965432", "Gardel", "Maniana", 6000);
        Persona staff3 = new Staff("Julian", "julian@email.com", "julian@email.com", "98765432", "Romero", "Noche", 5500);
        Persona staff4 = new Staff("Yoel", "yoel@email.com", "yoel@email.com", "98765432", "Fernandez", "Maniana", 7650);

        //Crear arreglo generico y agregar las 8 instancias creadas antes
        ArrayList<Persona> personal = new ArrayList<>();

        //Estudiantes
        personal.add(estudiante);
        personal.add(estudiante2);
        personal.add(estudiante3);
        personal.add(estudiante4);

        //Staff
        personal.add(staff);
        personal.add(staff2);
        personal.add(staff3);
        personal.add(staff4);

        int cntEstudiantes = 0;
        int cntStaff = 0;
        double totalIngresos = 0.0;

        //Recorrer el arreglo, contar la cantidad de estudiantes y staff. Además sumar los ingresos de los estudiantes
        for(Persona p : personal) {
            if (p instanceof Estudiante) {
                //Sumar total de ingresos
                totalIngresos += ((Estudiante) p).getCuotaMensual();

                cntEstudiantes++;
            } else if (p instanceof Staff) {
                cntStaff++;
            }
        }

        System.out.println("Cantidad de estudiantes = " + cntEstudiantes);
        System.out.println("\nCantidad de miembros de staff = " + cntStaff);
        System.out.println("Total de ingresos = " + totalIngresos);

    }
}