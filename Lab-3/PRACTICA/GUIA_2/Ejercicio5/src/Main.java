import java.util.ArrayList;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        // Instanciamos 4 estudiantes diferentes
        Estudiante estudiante = new Estudiante("Juan", "juan@email.com", "Calle 123", "12345678", "Perez", 2020, "Ingenieria", 1000);
        Estudiante estudiante2 = new Estudiante("Pedro", "pedro@email.com", "Calle 456", "87654321", "Gomez", 2021, "Medicina", 2000);
        Estudiante estudiante3 = new Estudiante("Pablo", "pablo@email.com", "Calle 789", "45678912", "Lopez", 2019, "Derecho", 1500);
        Estudiante estudiante4 = new Estudiante("Martin", "martin@email.com", "Calle 159", "78912345", "Garcia", 2018, "Arquitectura", 1800);

        // Instanciamos 4 staffs diferentes
        Staff staff = new Staff("Ramon", "ramon@email.com", "ramon@email.com", "98765432", "Gonzalez", "Noche", 5000);
        Staff staff2 = new Staff("Roberto", "roberto@email.com", "roberto@email.com", "99965432", "Gardel", "Maniana", 6000);
        Staff staff3 = new Staff("Julian", "julian@email.com", "julian@email.com", "98765432", "Romero", "Noche", 5500);
        Staff staff4 = new Staff("Yoel", "yoel@email.com", "yoel@email.com", "98765432", "Fernandez", "Maniana", 7650);

        ArrayList<Persona> personal = new ArrayList<>();



    }
}