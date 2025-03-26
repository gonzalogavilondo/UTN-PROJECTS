public class Staff extends Persona {
    private String turno;
    private double salario;

    public Staff() {
        super();
    }

    public Staff(String nombre, String email, String direccion, String dni, String apellido, String turno, double salario) {
        super(nombre, email, direccion, dni, apellido);
        this.turno = turno;
        this.salario = salario;
    }

    public String getTurno() {
        return turno;
    }

    public void setTurno(String turno) {
        this.turno = turno;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    @Override
    public String toString() {
        return "Staff{" +
                "turno='" + turno + '\'' +
                ", salario=" + salario +
                '}';
    }
}
