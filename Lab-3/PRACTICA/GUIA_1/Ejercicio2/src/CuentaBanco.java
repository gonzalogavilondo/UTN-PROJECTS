public class CuentaBanco {
    private int id;
    private String nombre;
    private double balance;

    public CuentaBanco(int id, String nombre, double balance) {
        this.id = id;
        this.nombre = nombre;
        this.balance = balance;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public double credito(double cantidad) {
        this.balance += cantidad;

        return this.balance;
    }

    public double debito(double cantidad) {

        if(cantidad > this.balance){
            System.out.println("Saldo insuficiente. No se puede retirar la cantidad solicitada");
        }
        else {
            this.balance -= cantidad;
        }
        return this.balance;
    }

    public String toString() {
        return "CuentaBanco[id=" + id + ",nombre=" + nombre + ",balance=" + balance + "]";
    }
}
