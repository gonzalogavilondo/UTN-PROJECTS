public class EmpleadoContratista extends Empleado{
    private int horasTrabajadas;
    private double tarifaPorProyecto;

    public EmpleadoContratista(String nombre, double salario, int horasTrabajadas, double tarifaPorProyecto) {
        super(nombre, salario);
        this.horasTrabajadas = horasTrabajadas;
        this.tarifaPorProyecto = tarifaPorProyecto;
    }

    public EmpleadoContratista() {
        super(null, 0);
    }

    public int getHorasTrabajadas() {
        return horasTrabajadas;
    }

    public void setHorasTrabajadas(int horasTrabajadas) {
        this.horasTrabajadas = horasTrabajadas;
    }

    public double getTarifaPorProyecto() {
        return tarifaPorProyecto;
    }

    public void setTarifaPorProyecto(double tarifaPorProyecto) {
        this.tarifaPorProyecto = tarifaPorProyecto;
    }

    @Override
    public String toString() {
        return  "\n" +
                "EmpleadoContratista{" +
                "cantidadHoras=" + horasTrabajadas +
                ", tarifaPorProyecto=" + tarifaPorProyecto +
                '}' +
                "\n" + super.toString() +
                "Pago=" + calcularPago() +
                "\n";
    }

    @Override
    public double calcularPago() {
        //Suponiendo que la jornada completa son 40 horas al mes
        return (double) ((horasTrabajadas * tarifaPorProyecto * getSalario())/40);
    }
}
