public class Main {
    public static void main(String[] args) {

        Empleado empleado = new Empleado("Carlos", "Gutierrez", 23456345, 25000);
        Empleado empleado2 = new Empleado("Ana", "Sanchez", 34234123, 27500);

        System.out.println(empleado.toString());
        System.out.println(empleado2.toString());

        System.out.println("\nSe aumenta el salario de " + empleado.getApellido() + ", " + empleado.getNombre());
        empleado.aumentarSalario(15);

        System.out.println(empleado.toString());
        System.out.println("\nEl salario anual de " + empleado.getApellido() + ", " + empleado.getNombre() + " es: " + empleado.calcularSalarioAnual());

    }
}