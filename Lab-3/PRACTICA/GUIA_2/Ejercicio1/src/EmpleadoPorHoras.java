public class EmpleadoPorHoras extends Empleado{
    private int horasTrabajadas;

    public EmpleadoPorHoras(String nombre, double salario, int horasTrabajadas) {
        super(nombre, salario);
        this.horasTrabajadas = horasTrabajadas;
    }

    public EmpleadoPorHoras() {
        super(null, 0);
    }

    public int getHorasTrabajadas() {
        return horasTrabajadas;
    }

    public void setHorasTrabajadas(int horasTrabajadas) {
        this.horasTrabajadas = horasTrabajadas;
    }

    @Override
    public String toString() {
        return  "\n" +
                "EmpleadoPorHoras{" +
                "horasTrabajadas=" + horasTrabajadas +
                '}' +
                "\n" +
                super.toString() +
                "\n" +
                "Pago=" + calcularPago() +
                "\n";
    }

    @Override
    public double calcularPago() {
        //Suponiendo que una jornada completa son 40 horas al mes
        return (double)((horasTrabajadas * getSalario())/ 40);
    }
}
