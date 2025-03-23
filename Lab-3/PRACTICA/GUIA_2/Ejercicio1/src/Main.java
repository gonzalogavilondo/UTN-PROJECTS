import java.util.ArrayList;
import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        //Scanner
        Scanner scanner = new Scanner(System.in);

        //Crear todos los tipos de empleados
        Empleado empleadoTiempoCompleto = new EmpleadoTiempoCompleto();
        Empleado empleadoPorHoras = new EmpleadoPorHoras();
        Empleado empleadoContratista = new EmpleadoContratista();

        //Lista de empleados
        ArrayList<Empleado> empleados = new ArrayList<>();

        //Menu de opciones
        int opcion;
        do {
            System.out.println("Bienvenido al sistema de nómina de empleados");
            System.out.println("1. Empleado de tiempo completo");
            System.out.println("2. Empleado por horas");
            System.out.println("3. Empleado contratista");
            System.out.println("4. Imprimir lista de empleados");
            System.out.println("5. Salir");
            System.out.println("Seleccione una opción: ");
            opcion = scanner.nextInt();

            switch (opcion) {
                case 1:
                    //Cargo empleado de tiempo completo
                    empleadoTiempoCompleto = cargarEmpleado(empleadoTiempoCompleto);
                    empleados.add(empleadoTiempoCompleto);
                    break;
                case 2:
                    //Cargar empleado por horas
                    empleadoPorHoras = cargarEmpleado(empleadoPorHoras);
                    empleados.add(empleadoPorHoras);
                    break;
                case 3:
                    //Cargo empleado contratista
                    empleadoContratista = (empleadoContratista);
                    empleados.add(empleadoContratista);
                    break;
                case 4:
                    //Imprimir lista de empleados
                    // Aca es donde se ve el polimorfismo, ya que dependiendo de la instancia se va
                    // a llamar al toString() de la clase correspondiente.
                    for (Empleado empleado: empleados) {
                        System.out.println(empleado.toString());
                    }
                    break;
                case 5:
                    //Salir
                    System.out.println("Gracias por usar el sistema de nómina de empleados");
                    break;
                default:
                    System.out.println("Opción no válida");
            }
        }while (opcion != 5) ;
    }


    public static Empleado cargarEmpleado(Empleado empleado) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese el nombre del empleado: ");
        String nombre = scanner.next();
        scanner.nextLine(); // Limpiar buffer

        System.out.println("Ingrese el salario del empleado: ");
        double salario = scanner.nextDouble();
        scanner.nextLine(); // Limpiar buffer

        if (empleado instanceof EmpleadoPorHoras) {
            System.out.println("Ingrese las horas trabajadas: ");
            int horasTrabajadas = scanner.nextInt();
            scanner.nextLine(); // Limpiar buffer
            EmpleadoPorHoras empleadoPorHoras = new EmpleadoPorHoras(nombre, salario, horasTrabajadas);
            return empleadoPorHoras;
        } else if (empleado instanceof EmpleadoContratista) {
            System.out.println("Ingrese las horas trabajadas: ");
            int horasTrabajadas = scanner.nextInt();
            scanner.nextLine(); // Limpiar buffer

            System.out.println("Ingrese la tarifa por proyecto: ");
            double tarifaPorProyecto = scanner.nextDouble();
            scanner.nextLine(); // Limpiar buffer
            EmpleadoContratista empleadoContratista = new EmpleadoContratista(nombre, salario, horasTrabajadas, tarifaPorProyecto);
            return empleadoContratista;
        }
        EmpleadoTiempoCompleto empleadoTiempoCompleto = new EmpleadoTiempoCompleto(nombre, salario);
        return empleadoTiempoCompleto;
    }
}