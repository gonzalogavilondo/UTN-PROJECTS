import java.util.Scanner;

public class EmpleadoTiempoCompleto extends Empleado {

    public EmpleadoTiempoCompleto(String nombre, double salario) {
        super(nombre, salario);
    }

    public EmpleadoTiempoCompleto() {
        super(null, 0);
    }

    @Override
    public String toString() {
        return  "\n" +
                "EmpleadoTiempoCompleto{}" +
                "\n" +
                super.toString() +
                "\n" +
                "Pago=" + calcularPago() +
                "\n";
    }

    @Override
    public double calcularPago() {
        return this.getSalario();
    }

}
